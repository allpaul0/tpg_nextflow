#!/usr/bin/ruby

require 'fileutils'

### Script description ###

# For a given TPG (TPG/XXX in the hierarchy), using the SEED passed as input param,
# launch the program MainSeedsGraphTraversal 
# See the corresponding README.md in TPG

def check_exit_status(code)
    if code != 0
      puts "\033[1;91mERROR\033[0m --- Something wrong happened, last exit code is #{code}, exiting script"
      exit 1
    end
end

def training_done?(d)
    training_dir = File.join(d, 'training')
    if File.directory?(training_dir)
      true
    else
      puts "\033[1;36mSkip #{d} \033[1;31m(training dir is missing)\033[0m\n"
      false
    end
end
  
def codegen_done?(d)
    codegen_dir = File.join(d, 'CodeGen')
    if File.directory?(codegen_dir)
      true
    else
      puts "\033[1;36mSkip #{d} \033[0m(CodeGen is missing)\n"
      false
    end
end

def precalcul_done?(d)
    precalcul_dir = File.join(d, 'precalul')
    if File.directory?(precalcul_dir)
      puts "\033[1;36mSkip #{d} \033[0m(precalul already done)\n"
      true
    else
      false
    end
end
  

### Script ###

# Check if script is called properly
if ARGV.length < 3
    puts "Usage: ruby script_name.rb <verbose: true/false> <seed> <name of TPG dir (default: \"TPG\")>"
    exit 1
end
  
# Convert the string input to boolean value for verbose
verbose = ARGV[0].casecmp('true').zero?

# Extract seed from command line argument
seed = ARGV[1].to_i

# Ensure the third argument is a non-empty string
TPG_dir = ARGV[2]
if TPG_dir.nil? || TPG_dir.strip.empty?
    puts "Error: The name of TPG dir must be a non-empty string."
    puts "Usage: ruby script_name.rb <verbose: true/false> <seed> <name of TPG dir (default: \"TPG\")>"
    exit 1
end

system("pwd")
    

# move from the current dir to Trainer-Generator 
script_dir = File.expand_path(File.dirname(__FILE__))
Dir.chdir(File.join(script_dir, '..'))
check_exit_status($?.to_i)

# Trainer-Generator CMake configuration 
FileUtils.rm_r('Trainer-Generator/bin')
check_exit_status($?.to_i)

FileUtils.mkdir('Trainer-Generator/bin')
check_exit_status($?.to_i)

Dir.chdir('Trainer-Generator/bin')
check_exit_status($?.to_i)

# launch Cmake command
trainor_cmake_string = "cmake .."
unless (verbose)
  trainor_cmake_string += " > /dev/null 2>&1"
end
system(trainor_cmake_string)
check_exit_status($?.to_i)

# go to TPG dir
TPG_dir_absolute = File.expand_path("../../#{TPG_dir}")
if Dir.exist?(TPG_dir_absolute)
  Dir.chdir(TPG_dir_absolute)
  check_exit_status($?.to_i)
else
  puts "\033[1;91mERROR\033[0m --- The directory #{TPG_dir_absolute} does not exist, exiting script."
  exit 1
end


# Select directories for which there is a need to do CodeGen
dirs = Dir.entries('.').reject { |d| d == '.' || d == '..' || d == 'README.md'}

  
# check if the object is a dir, if training has been done 
# (required) and if codegen has as well already been done
dirs = dirs.reject do |d|
    if File.directory?(d) && training_done?(d) # && !precalcul_done?(d) # codegen_done?(d)
        false
        #puts "Valid dir #{d}"
    else
        true #reject
    end
end


Dir.chdir('..') 
check_exit_status($?.to_i)


#Do mainSeedsGraphTraversal
dirs.each do |d|
    # Be aware that folder name #{d} can cause encoding problems during the copy operation
    puts "\033[1;36mMainSeedsGraphTraversal for #{d}\033[0m"

    # required files for inference on x86
    system("cp #{TPG_dir}/#{d}/src/instructions.cpp Trainer-Generator/src/")
    check_exit_status($?.to_i)
    system("cp #{TPG_dir}/#{d}/src/params.json Trainer-Generator/")
    check_exit_status($?.to_i)
  
    Dir.chdir('Trainer-Generator/bin') do

        trainor_cmake_string = "cmake"
        
        # Specify that we are doing mainSeedsGraphTraversal on int data type
        # the data needs to be scaled accordingly
        if d.include?('int')   
            trainor_cmake_string += " -DTYPE_INT=1 .."
        else
            trainor_cmake_string += " -DTYPE_INT=0 .."
        end

        unless (verbose)
            trainor_cmake_string += " > /dev/null 2>&1"
        end
        
        system(trainor_cmake_string)
        check_exit_status($?.to_i)

        trainor_compilation_string = "make SeedsGraphTraversal"
        unless (verbose)
            trainor_compilation_string += " > /dev/null 2>&1"
        end

        system(trainor_compilation_string)
        check_exit_status($?.to_i)

        Dir.chdir('Release') do

            # Launch SeedsGraphTraversal           
            system("./SeedsGraphTraversal ../../../#{TPG_dir}/#{d}/CodeGen/best_root_pruned.dot #{seed}")# best root training
            check_exit_status($?.to_i)
            
            # Results of the SeedsGraphTraversal saved by the program into the concerned TPG dir
            # system("mv Results/LE_states.h ../../../#{TPG_dir}/#{d}/precalul/.")
            check_exit_status($?.to_i)
        
        end
    end
end
