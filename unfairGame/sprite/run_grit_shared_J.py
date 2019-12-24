# Jeffrey - 23/12/2019
# Credits to Sebastiaan
# Changed to use my system path
# Based on sebastiaans script
# Avoid grit at all costs

import os
import subprocess

# grit pic1.png pic2.png kul.png '-ftc -pS -gB8 -O shared.c'
PATH_TO_USED_PNG = 'C:/Google_Drive/SchakelIIW/CPP/Project/gba-sprite-engine/unfairGame/sprite/'
GRIT_COMMAND = 'grit.exe'
GRIT_PARAMETERS = ' -ftc -pS -gB8 -O shared.c'
SUBFOLDER = 'Used/'

# Generate files
all_files = os.listdir(PATH_TO_USED_PNG + SUBFOLDER)

files_as_subdirectories = []

for file in  all_files:
    files_as_subdirectories.append('./' + SUBFOLDER + file + " ")

combined_arguments = files_as_subdirectories
combined_arguments.append(GRIT_PARAMETERS)
subprocess.call([GRIT_COMMAND, combined_arguments])

# Concat all .c files when there is no // in front of line
# source https://stackoverflow.com/questions/3964681/find-all-files-in-a-directory-with-extension-txt-in-python
data_file = open("./sprite_data/combined_data.h", "w+")
data_file.write("// Created by Python script (run_grit_shared.py) to avoid using grit \n")
data_file.write("\n")
data_file.write("#ifndef GBA_SPRITE_ENGINE_PROJECT_COMBINED_DATA_H \n")
data_file.write("#define GBA_SPRITE_ENGINE_PROJECT_COMBINED_DATA_H \n")
for file in os.listdir(PATH_TO_USED_PNG):
    if file.endswith(".c"):
        opened_file = open(file, "r")
        for line in opened_file:
            if not line.startswith("//") and len(line) > 1:
                data_file.write(line)
        opened_file.close()

data_file.write("#endif \n")
# Now remove all the unneeded generated files
# This might be dangerous but who cares right?
for file in os.listdir(PATH_TO_USED_PNG):
    if file.endswith(".c") or file.endswith(".h"):
        os.remove(file)