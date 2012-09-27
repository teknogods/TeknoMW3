#!/usr/bin/python
#the following functions will extract elements from function declaration
#the expected format is something like:
# virtual const char *GetIPCountry() = 0;
import sys
import re

def Get_RetVal(line):
    virt = line.find("virtual")
    x = line.find("(")
    ret_plus_func_name = line[virt+8:x]
    sp = ret_plus_func_name.split(" ")
    ret_val = ""
    for i in sp:
        if i != sp[-1]:
            ret_val+=i+" "

    func_name = Get_FuncName_helper(line)
    if "*" in func_name:
        return ret_val+"*"
    return ret_val

def Get_FuncName(line):
    func_name = Get_FuncName_helper(line)
    func_name = Get_FuncName_helper_2(func_name)
    return func_name

def Get_FuncName_helper(line):
    virt = line.find("(")
    func_name= line[:virt].split(None)[-1]
    return func_name

def Get_FuncName_helper_2(func_name):
    if "*" in func_name:
        return func_name[1:]
    return func_name
        

def Get_ArgsList(line):
    rev = line[::-1]
    args_end_rev = rev.find(")")
    args_end = len(line) - args_end_rev;
    args =  line[ line.find("(") +1: args_end-1]
    return args.split(",")

def Get_ParamNameFromArg(arg):
    last = arg.split(None)[-1]
    return last.split("*")[-1]

def IsStringParam(arg):
    m = re.search("char[ \t]*", arg)
    if (m == None):
        return False
    return True

def Analyze(file_name, out_file):
    class_name = "unkown_class"
    wrapper_name = "unkown_wrapper"
    class_started = False
    #inside_function = False
    current_function = ""

    f = open(file_name, 'r')
    o = open(out_file, 'w')
    #f = open(file_name)

    o.write("#include \"" + file_name + "\"\n\n")    

    while True:
        line = f.readline()
        if not line:
            break
        if "class I" in line:
            class_started = True
            class_name = line.split(" ")[1][:-1]
            wrapper_name = class_name+"_wrapper"
            o.write( "class " + wrapper_name + "\n{\npublic:\n" )    
        elif "virtual" in line:
            if "~" in line:
                o.write("\tvirtual ~" + wrapper_name + "();\n")            
                continue

            # ##########################################################
            # accumlate entire function declaration
            
            current_function = line[:-1] #remove the ending \n

            while not ";" in line:
                if not line:
                    break
                line = f.readline()
                current_function+= line[:-1] #remove the ending \n

            line = current_function

            # ##########################################################

            o.write("\tvirtual ")
            ret_type =  Get_RetVal(line)
            o.write(ret_type + " ")
            func_name = Get_FuncName(line)   
            o.write(func_name + " (")
            args = Get_ArgsList(line)
            for a in args:            
                o.write(a)
                if a != args[-1]:
                    o.write(", ")
            o.write(")\t{\n\t\t");            
            non_void_ret = False
            if not "void" in ret_type or "*" in ret_type:
                non_void_ret = True

            #print args
            o.write("char log[1024];\n")
            o.write("\t\tsprintf(log,\""+func_name+"() ")
            args_count = 0
            for a in args:
                if a.split(None)==[]:
                    continue
                args_count+=1
                param_name = Get_ParamNameFromArg(a)
                o.write( param_name )
                if (IsStringParam(a)):
                    o.write( "=%s " )
                else:
                    o.write( "=0x%X " )
            if args_count > 0:
                o.write("\",\n")
                for a in args:
                    if a.split(None)==[]:
                        continue
                    param_name = Get_ParamNameFromArg(a)
                    o.write("\t\t\t"+param_name)
                    if a != args[-1]:
                        o.write(",\n")
            else:
                o.write('"')

            o.write("\t\t);\n")
            o.write("\t\tOutputDebugStringA(log);\n")                            
            o.write("\t\t")

            if non_void_ret:                
                o.write( ret_type + " ret = m_pWrapper->" + Get_FuncName(line) +"(" )
            for a in args:
                if a.split(None)==[]:
                    continue
                param_name = Get_ParamNameFromArg(a)
                o.write(param_name)
                if a != args[-1]:
                    o.write(", ")
            o.write(");\n")

            if non_void_ret:
                o.write('\t\tsprintf(log," returned 0x%X",ret);\n')
                o.write("\t\tOutputDebugStringA(log);\n")
            o.write('\t\tOutputDebugStringA("\\n");\n')
                

            if non_void_ret:
                o.write("\t\treturn ret;\n")
            o.write("\t}\n")
        else:
            if class_started==True and len(line)>3 and class_name in line:
                if not "#" in line and not "class" in line:
                    #constructor
                    o.write("\t"+wrapper_name+"();\n")
    o.write("};\n")

if len(sys.argv) < 3:
    print "Please provide input file to read and an output file"

Analyze(sys.argv[1], sys.argv[2])

#Analyze("ISteamClient007.h")
#GetISteamMatchmakingServers

 