#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream> 

void encryption (int shift, int numShift, std::string in, std::string out);
void decryption (int shift, int numShift, std::string in, std::string out);

int main (int argc, char** argv){
    int shift, numShift;
    std::string flag;
    std::string in, out;

    flag = argv[1];
    shift = atoi(argv[2]);
    numShift = atoi(argv[3]);//Number used to shift digits
    in = argv[4];
    out = argv[5];

    if (flag == "-e"){
        encryption(shift, numShift, in, out);
    }
    else if (flag == "-d"){
        decryption(shift, numShift, in, out);
    }
    return 0;
}

void encryption (int shift, int numShift, std::string in, std::string out){
    std::ifstream f(in);
    std::ofstream w(out);
    std::string text;
    while ( getline(f, text) ) 
    {
        int length = text.length();
        char letters [length + 1];
        char encrypted [length + 1];

        strcpy(letters, text.c_str());

        std::cout << "Encrypted Message: ";
       
        for(int i =  0; i < length; i++){
            letters[i] = letters[i];
            int convert = (int) letters[i];
            //Shfits numbers 
            if (convert <= 57 && convert >= 48){
                convert += numShift;
            }
            else{
                if(shift < 0){
                    //Converting lower case letters
                    if(convert >= 97 && convert <= 122 && convert != 32){
                        for (int j = 0; j > shift; j--){
                            if(convert == 97){
                                convert = 122;
                            }
                            else{
                                convert--;
                            }
                        }
                    }
                    else if(convert != 32){
                        for (int j = 0; j > shift; j--){
                            if(convert == 65){
                                convert = 90;
                            }
                            else{
                                convert--;
                            }
                        }
                    }
                }

                if(shift > 0){ 
                    if(convert >= 97 && convert <= 122 && convert != 32){
                        for (int j = 0; j < shift; j++){
                            if(convert == 122){
                                convert = 97;
                            }
                            else{
                                convert++;
                            }
                        }
                    }
                    else if(convert != 32){
                        for (int j = 0; j < shift; j++){
                            if(convert == 90){
                                convert = 65;
                            }
                            else{
                                convert++;
                            }
                        }
                    }
            
                }
            }
            encrypted[i] = (char) convert;
            std::cout<< encrypted[i];
            w << encrypted[i];
        }
        std::cout<<std::endl;
        w << std::endl;
    }
    w.close();
    f.close(); 
}

void decryption (int shift, int numShift, std::string in, std::string out){
    shift = shift * -1;

    std::ifstream f(in);
    std::ofstream w(out);
    std::string text;
    while ( getline(f, text) ) 
    {
        int length = text.length();
        char letters [length + 1];
        char encrypted [length + 1];

        strcpy(letters, text.c_str());

        std::cout << "Decrypted Message: ";

        for(int i =  0; i < length; i++){
            letters[i] = toupper(letters[i]);
            int convert = (int) letters[i];
            if (convert <= 57 && convert >= 48){
                convert -= numShift;
            }
            else{
                if(shift < 0){
                    if(convert >= 97 && convert <= 122 && convert != 32){
                        for (int j = 0; j > shift; j--){
                            if(convert == 97){
                                convert = 122;
                            }
                            else{
                                convert--;
                            }
                        }
                    }
                    else if(convert != 32){
                        for (int j = 0; j > shift; j--){
                            if(convert == 65){
                                convert = 90;
                            }
                            else{
                                convert--;
                            }
                        }
                    }
                }

                if(shift > 0){ 
                    if(convert >= 97 && convert <= 122 && convert != 32){
                        for (int j = 0; j < shift; j++){
                            if(convert == 122){
                                convert = 97;
                            }
                            else{
                                convert++;
                            }
                        }
                    }
                    else if(convert != 32){
                        for (int j = 0; j < shift; j++){
                            if(convert == 90){
                                convert = 65;
                            }
                            else{
                                convert++;
                            }
                        }
                    }
            
                }
            }
            encrypted[i] = (char) convert;
            std::cout<< encrypted[i];
            w << encrypted[i];
        }
        std::cout<<std::endl;
        w << std::endl;
    }
    w.close();
    f.close(); 
}