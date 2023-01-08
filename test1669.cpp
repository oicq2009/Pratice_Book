#include <iostream>
#include <string>
using namespace std;


int main(void) {
    string url1("htto");
    string& url = url1;

    string protocol;
    size_t pos1 = url.find("://");
    if (pos1 != string::npos) {
        protocol = url.substr(0, pos1);
        cout << "協議: " << protocol << endl;
        
    } else {
        cout << "非法url" << endl;
    }

    string domain();
    find(pos + 3, '/');

    return 0;
}

