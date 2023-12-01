#include <vector>
#include <iostream>
using namespace std; 

int main(){
    string st;
    int firstDigit, lastDigit, aux, result;
    aux = result = 0; 
    while(cin >> st and st != "amongus"){
        for(int i = 0; i < st.length(); i++){
            if(st[i] > '0' and st[i] <= '9'){
                int a = st[i] - '0';
                if(firstDigit == 0) firstDigit = a; 
                else lastDigit = a; 
            }
            else if(st[i] == 'o'){
                if(i+1 <= st.length() and st[i+1] == 'n'){
                    if(i+2 <= st.length() and st[i+2] == 'e'){
                        if(firstDigit == 0) firstDigit = 1; 
                        else lastDigit = 1;
                        i = i+1; 
                    }
                }
            }
            else if(st[i] == 't'){
                if(i+1 <= st.length() and st[i+1] == 'w'){
                    if(i+2 <= st.length() and st[i+2] == 'o'){
                        if(firstDigit == 0) firstDigit = 2; 
                        else lastDigit = 2;
                        i = i+1;
                    }
                }
                else if(i+1 <= st.length() and st[i+1] == 'h'){
                    if(i+2 <= st.length() and st[i+2] == 'r'){
                        if(i+3 <= st.length() and st[i+3] == 'e'){
                            if(i+4 <= st.length() and st[i+4] == 'e'){
                                if(firstDigit == 0) firstDigit = 3; 
                                else lastDigit = 3;
                                i = i+3;
                            }
                        }
                    }
                }
            }
            else if(st[i] == 'f'){
                if(i+1 <= st.length() and st[i+1] == 'o'){
                    if(i+2 <= st.length() and st[i+2] == 'u'){
                        if(i+3 <= st.length() and st[i+3] == 'r'){
                            if(firstDigit == 0) firstDigit = 4; 
                            else lastDigit = 4;
                            i = i+2;
                        }
                    }
                }
                else if(i+1 <= st.length() and st[i+1] == 'i'){
                        if(i+2 <= st.length() and st[i+2] == 'v'){
                            if(i+3 <= st.length() and st[i+3] == 'e'){
                                if(firstDigit == 0) firstDigit = 5; 
                                else lastDigit = 5;
                                i = i+2;
                            }
                        }
                    }
            }
            else if(st[i] == 's'){
                if(i+1 <= st.length() and st[i+1] == 'i'){
                    if(i+2 <= st.length() and st[i+2] == 'x'){
                        if(firstDigit == 0) firstDigit = 6; 
                        else lastDigit = 6;
                        i = i+1;
                    }
                }
                if(i+1 <= st.length() and st[i+1] == 'e'){
                    if(i+2 <= st.length() and st[i+2] == 'v'){
                        if(i+3 <= st.length() and st[i+3] == 'e'){
                            if(i+4 <= st.length() and st[i+4] == 'n'){
                                if(firstDigit == 0) firstDigit = 7; 
                                else lastDigit = 7;
                                i = i+3;
                                
                            }
                        }
                    }
                }
            }
            else if(st[i] == 'e'){
                if(i+1 <= st.length() and st[i+1] == 'i'){
                    if(i+2 <= st.length() and st[i+2] == 'g'){
                        if(i+3 <= st.length() and st[i+3] == 'h'){
                            if(i+4 <= st.length() and st[i+4] == 't'){
                                if(firstDigit == 0) firstDigit = 8; 
                                else lastDigit = 8;
                                i = i+3;
                                
                            }
                        }
                    }
                }
            }
            else if(st[i] == 'n'){
                    if(i+1 <= st.length() and st[i+1] == 'i'){
                        if(i+2 <= st.length() and st[i+2] == 'n'){
                            if(i+3 <= st.length() and st[i+3] == 'e'){
                                if(firstDigit == 0) firstDigit = 9; 
                                else lastDigit = 9;
                                i = i+2;
                                
                            }
                        }
                    }
                }
        }
        if(lastDigit == 0) lastDigit = firstDigit; 
        aux += lastDigit; 
        aux += 10 * firstDigit;
        result += aux;  
        //cout << "He leido:" << firstDigit << lastDigit  << " y aux es " << aux << endl;
        aux = 0; 
        lastDigit = 0; 
        firstDigit = 0; 
        
    }
    cout << result;
}
