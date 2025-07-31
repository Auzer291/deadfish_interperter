#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class interperter {
    public:
        int cell = 0;

        string read_file(const string path){
            ifstream file(path);
            if(!file.is_open()){
                cerr << "Could not open file!"<<endl;
                return "";
            }
            
            stringstream buf;
            buf << file.rdbuf();
            file.close();
            return buf.str();
        }

        void interpert(string str){
            vector<char>cmd_list = {'i','d','o','s','n','c','p','t'};
            for(int i=0; i < str.size(); i++){
                if(find(cmd_list.begin(), cmd_list.end(), str[i]) == cmd_list.end() && str[i] != ' ' && str[i] != '\n' && str[i] != '\t'){
                    cout << "Invalid character '" << str[i] << "' at index " << i <<"\n";
                    return;
                }
            }
            for(int i=0; i < str.size(); i++){
                if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'){
                    continue;
                }
                if(cell < 0 || cell > 255){cell = 0;}
                if(str[i] == 'i'){cell += 1;}
                if(str[i] == 'd'){cell -= 1;}
                if(str[i] == 's'){cell =cell * cell;}
                if(str[i] == 'o'){cout << cell;}
                if(str[i] == 'c'){cout << char(cell);}
                if(str[i] == 'n'){cout << '\n';}
                if(str[i] == 'p'){cout << ' ';}
                if(str[i] == 't'){cout << '\t';}
            }
            cout << '\n';
            cell = 0;
            return ;
        }
};


int main(int argc, char *argv[]){
    string str;
    interperter itpt;
    if(argc < 2){cerr << "Not enough argument!\nIt should be either of the following commands:\n'run': Run the interperter\n'interpert': Interper the code inside the given file"<<"\n";return 1;}
    const string command = argv[1];
    try{
        if(command == "interpert"){
            const string path = argv[2];
            if(path.size() > 3){
                if(path.substr(path.size() - 3) == ".df"){
                    str = itpt.read_file(path);
                    itpt.interpert(str);
                }else{
                    cerr << "Invalid file path!"<<endl;
                }
            }else{
                cerr << "Invalid file path!"<<endl;
            }
        }
        else if(command == "run"){
            while(true){
                cout << ">> ";
                getline(cin , str);
                itpt.interpert(str);
            }
        }
        else{
            cerr << "Unknown command: "<< command << "\n";
        }
    }catch(...){
        cout << "Unexpected error occured!"<<endl;
    }
    return 0;
}