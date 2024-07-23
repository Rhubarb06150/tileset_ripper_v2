//Started 21/07/24
#include <iostream>
#include <unistd.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <filesystem>
#include <fstream>

#include "colors.h"
//Color codes

std::string str_replace(const std::string&from,const std::string&to,std::string str) {
	size_t start_pos=0;
	while((start_pos=str.find(from,start_pos))!=std::string::npos){
	str.replace(start_pos,from.length(),to);
	start_pos+=to.length();
	};
	return str;
};

int main(int argc,char** argv){
	std::string version="0.0";//Build version

	//Init values
	std::string tileset_path="";
	std::string output_path="";
	int tile_size=16;
	int tile_size_x=0;
	int tile_size_y=0;
	int tile_offset=0;
	int tile_offset_x=0;
	int tile_offset_y=0;
	int b_offset_x=0;
	int b_offset_y=0;
	int columns=0;
	int rows=0;
	int start_col=0;
	int start_row=0;
	std::string colors_to_rm="";
	std::string tile_name="tile-";
	if(argc>1){
		if(strcmp(argv[1],"-rip")==0){
			for(int i=2;i<argc;i++){
				std::string arg;
				arg=argv[i];
				if(arg.rfind("-tp-",0)==0){
					arg=str_replace("-tp-","",arg);
					if(!std::filesystem::is_regular_file(arg)){
	 					std::cout<<RED<<"error: cannot find the image \""<<arg<<"\", exit."<<RESET<<std::endl;
					}else{
						tileset_path=arg;
					};
				}else if(arg.rfind("-ts-",0)==0){
					arg=str_replace("-ts-","",arg);
					try{
						tile_size=std::stoi(arg);
					}catch(...){
						std::cout<<RED<<"error: cannot convert \""<<arg<<"\" value to numeric value, exit."<<RESET<<std::endl;
					};
				}else{
					std::cout<<RED<<"error: unknown argument \""<<arg<<"\", exit."<<RESET<<std::endl;
					exit(2);
					return 2;
				};
			};
			exit(0);
			return 0;
		}else if(strcmp(argv[1],"--help")==0){
			std::cout<<"Troubleshooting page"<<std::endl<<std::endl;
			std::cout<<"-rip:"<<std::endl;
			std::cout<<GREEN<<"    if not specified, num values are in pixels"<<RESET<<std::endl;
			std::cout<<GREEN<<"    arguments and arguments values need to separated by a - e.g. -> -tp-tileset.png"<<RESET<<std::endl;
			std::cout<<"    -tp <path> : path of the tileset image"<<std::endl;
			std::cout<<"    -o <path>  : path of the output directory"<<std::endl;
			std::cout<<"    -ts <num>  : tile size (default 16)"<<std::endl;
			std::cout<<"    -tsh <num> : horizontal tile size (do not work if -ts given)"<<std::endl;
			std::cout<<"    -tsv <num> : vertical tile size in (do not work if -ts given)"<<std::endl;
			std::cout<<"    -of <num>  : offset bewteen tiles (default 0)"<<std::endl;
			std::cout<<"    -xo <num>  : horizontal offset bewteen tiles (default 0) (do not work if -of given)"<<std::endl;
			std::cout<<"    -yo <num>  : vertical offset bewteen tiles (default 0) (do not work if -of given)"<<std::endl;
			std::cout<<"    -bxo <num> : begin horizontal offset (default 0)"<<std::endl;
			std::cout<<"    -byo <num> : begin vertical offset (default 0)"<<std::endl;
			std::cout<<"    -c <num>   : number of columns (default max)"<<std::endl;
			std::cout<<"    -r <num>   : number of rows (default max)"<<std::endl;
			std::cout<<"    -bc <num>  : first column (default 0)"<<std::endl;
			std::cout<<"    -br <num>  : first row (default 0)"<<std::endl;
			std::cout<<"    -rmc <hex> : remove specified colors (hex code spaced by \",\")"<<std::endl;
			std::cout<<"    -n <name>  : tile name (default name 'tile')"<<std::endl;
		}else{
			std::cout<<"Unknown command \""<<RED<<argv[1]<<RESET<<"\", type --help for help."<<std::endl;
			exit(1);
			return 1;
		};
	}else{s
		std::cout<<"Tileset ripper by Rhubarb"<<std::endl;
		std::cout<<"Visit repo at github.com/Rhubarb06150/tileset_ripper_v2"<<std::endl<<std::endl;
		std::cout<<"Commands:"<<std::endl;
		std::cout<<"    -rip     Ripping a tileset"<<std::endl;
		std::cout<<"    --help   Troubleshooting"<<std::endl<<std::endl;
		std::cout<<"Build version: "<<version<<std::endl;
		exit(0);
		return 0;
	};
};
