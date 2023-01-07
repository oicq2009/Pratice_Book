/* 簡易的滑鼠連點機器

十幾行程式就可以搞定的

2023年1月7日22:47:41  
*/

#include <stdio.h>
#include <windows.h>

int main(void) {
    while(1) {
        if(GetAsyncKeyState(VK_SPACE)) {
            while(1) {
                mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
                Sleep(100);
                if(GetAsyncKeyState(VK_ESCAPE)) {
                    return 0;
                }
            }
        }
    }
    return 0;
}

  
