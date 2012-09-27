import sys, string, os

def change_extension(file_name):
    ret = ""
    sp = file_name.split(".")
    for a in sp:
        if a!=sp[-1]:
            ret+= a+"."
        else:
            ret+="cpp"
    return ret

def run():
    os.system("del *.cpp")
    for subdir, dirs, files in os.walk("./"):
        for file in files:
            #print file
            ext = file.split(".")[-1]
            if ext=="h" or ext=="H":
                print file
                os.system("GenWrapper.py "+file+"  "+change_extension(file))

run()