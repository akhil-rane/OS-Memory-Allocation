#include <windows.h>
#include<stdlib.h>
#include<cstring>
const char g_szClassName[] = "myWindowClass";

#define button1 101
#define button2 102
#define button3 103
#define button4 104
#define IDC_MAIN_EDIT 105

HWND hEdit,hTextBox;

int g=0;
int a[80];
int full1=0;
int o=0,am=81,set=0;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN hpen;
    RECT m;
    int i,j,x=17,y=10;
    int flag1=0;
    HBRUSH brush1=CreateSolidBrush(RGB(255,250,250));
    HBRUSH brush2=CreateSolidBrush(RGB(30,144,255));
    RECT rct[80];
    int t,n,n1,n2;
    int ff=0,bf=0,wf=0;
    int f1=0,f2=0,f3=0;
    int b1=0,b2=0,b3=0,b4=100;
    int w1=0,w2=0,w3=0,w4=0;
    
    switch(msg)
    {
        case WM_CREATE:
	    {
           HWND hWndButton1=CreateWindowEx(NULL,
				"BUTTON",
				"START/RESET",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				80,
				160,
				110,
				50,
				hwnd,
				(HMENU)button1,
				GetModuleHandle(NULL),
				NULL);
			
				
			HWND hWndButton2=CreateWindowEx(NULL,
				"BUTTON",
				"FIRST FIT",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				240,
				160,
				110,
				50,
				hwnd,
				(HMENU)button2,
				GetModuleHandle(NULL),
				NULL);
            
            HWND hWndButton3=CreateWindowEx(NULL,
				"BUTTON",
				"BEST FIT",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				400,
				160,
				110,
				50,
				hwnd,
				(HMENU)button3,
				GetModuleHandle(NULL),
				NULL);
             
             HWND hWndButton4=CreateWindowEx(NULL,
				"BUTTON",
				"WORST FIT",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				550,
				160,
				110,
				50,
				hwnd,
				(HMENU)button4,
				GetModuleHandle(NULL),
				NULL);
               
                hEdit=CreateWindowEx(WS_EX_CLIENTEDGE,
				"EDIT",
				"",
				WS_CHILD|WS_VISIBLE|
				ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,
				390,
				108,
				30,
				20,
				hwnd,
				(HMENU)IDC_MAIN_EDIT,
				GetModuleHandle(NULL),
				NULL);
			HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);
			SendMessage(hEdit,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));
			SendMessage(hEdit,
				WM_SETTEXT,
				NULL,
				(LPARAM)"0");           
         }
	    break;
        
        case WM_COMMAND:
        {
            if(button1 == LOWORD(wParam))
            { 
              InvalidateRect( hwnd, NULL, TRUE );
              g=1;          
              full1=0;
              goto xyz;
            }
            else if(button2 == LOWORD(wParam))
            {        
                 int len= (int)SendMessage(hEdit, WM_GETTEXTLENGTH, 0, 0);            
                 char *buffer= new char[len];
                 SendMessage(hEdit, WM_GETTEXT, (WPARAM)len+1, (LPARAM)buffer);
                 if(len==1)
                 {
                   n=atoi(&buffer[0]);
                 }              
                 else
                {
                   n=atoi(&buffer[0]);  
                }
               if(n!=0)  
               {  
                 for(i=0;i<80;i++)
                 {
                    if(a[i]==0)
                    {
                        if(f1==0)
                        {
                           f2=i;
                           f1=1;
                        }
                        f3++;  
                        if(f3==n||n==0)
                        {
                           o=f2;
                           
                           set=1;
                           break;
                        }
                    }
                    else
                    { 
                         f3=0;  
                         f1=0;
                    }
                 }
                 
                 if(n>=am||set==0)
                 {
                         MessageBox(NULL, "MEMORY NOT AVAILABLE","ERROR",
                       MB_ICONEXCLAMATION | MB_OK);
                       g=2;
                       goto pqr;
                       return 0;
                 }
                 }
                 ff=1;    
                 InvalidateRect( hwnd, NULL, TRUE );
                 g=2;          
                 goto pqr;
               }
            
            else if(button4 == LOWORD(wParam))
            {        
                 int len= (int)SendMessage(hEdit, WM_GETTEXTLENGTH, 0, 0);            
                 char *buffer= new char[len];
                 SendMessage(hEdit, WM_GETTEXT, (WPARAM)len+1, (LPARAM)buffer);            
                 if(len==1)
                 {
                   n=atoi(&buffer[0]);
                 }              
                 else
                 {
                     n1=atoi(&buffer[0]);
                     n2=atoi(&buffer[1]);  
                     n=(n1*10)+n2;
                 }
               if(n!=0)  
               {  
                 for(i=0;i<80;i++)
                 {
                    if(a[i]==0)
                    {
                        if(w1==0)
                        {
                           w2=i;
                           w1=1;
                        }
                        w3++;  
                       if(i==79&&w3>w4&&w3>=n)    
                       {
                           w4=w3;
                           o=w2; 
                           set=1;
                           break;
                       } 
                    }
                    
                    else
                    { 
                         if(w3>w4&&w3>=n)
                         {
                           w4=w3;
                           o=w2; 
                           set=1;
                         }
                         w3=0;  
                         w1=0;
                    }
                 }
                 
                 if(n>=am||set==0)
                 {
                       MessageBox(NULL, "MEMORY NOT AVAILABLE","ERROR",
                       MB_ICONEXCLAMATION | MB_OK);
                       g=2;
                       goto pqr;
                       return 0;                       
                 }
               }
                 wf=1;    
                 InvalidateRect( hwnd, NULL, TRUE );
                 g=2;          
                 goto pqr;
                 
            }
            
            else if(button3 == LOWORD(wParam))
            {        
                 int len= (int)SendMessage(hEdit, WM_GETTEXTLENGTH, 0, 0);            
                 char *buffer= new char[len];
                 SendMessage(hEdit, WM_GETTEXT, (WPARAM)len+1, (LPARAM)buffer);            
                 if(len==1)
                 {
                   n=atoi(&buffer[0]);
                 }              
                 else
                 {
                     n1=atoi(&buffer[0]);
                     n2=atoi(&buffer[1]);  
                     n=(n1*10)+n2;
                 }
               if(n!=0)  
               {  
                 for(i=0;i<80;i++)
                 {
                    if(a[i]==0)
                    {
                        if(b1==0)
                        {
                           b2=i;
                           b1=1;
                        }
                        b3++;  
                        if(i==79&&b3-n<b4-n&&b3>=n)    
                       {
                           b4=b3;
                           o=b2; 
                           set=1;
                           break;
                       }
                                                           
                    }
                    else
                    { 
                         if(b3-n<b4-n&&b3>=n)
                         {
                           b4=b3;
                           o=b2; 
                           set=1;
                         }
                         b3=0;  
                         b1=0;
                    }
                 }
                 
                 if(n>=am||set==0)
                 {
                         MessageBox(NULL, "MEMORY NOT AVAILABLE","ERROR",
                       MB_ICONEXCLAMATION | MB_OK);
                       
                       goto pqr;
                       g=2;
                       return 0;
                 }
                 }
                 bf=1;    
                 InvalidateRect( hwnd, NULL, TRUE );
                 g=2;          
                 goto pqr;
           }
        }
        
        break;
        case WM_PAINT: 
            if(g==0)
            {
            hdc = BeginPaint(hwnd, &ps); 
            SetBkColor(hdc, RGB(102,102,102));
            TextOut(hdc, 330,75, "MEMORY", 6); 
            TextOut(hdc, 6,54, "0", 1);
            TextOut(hdc, 92,54, "10", 2);
            TextOut(hdc, 181,54, "20", 2);
            TextOut(hdc, 271,54, "30", 2);
            TextOut(hdc, 361,54, "40", 2);
            TextOut(hdc, 451,54, "50", 2);
            TextOut(hdc, 541,54, "60", 2);
            TextOut(hdc, 631,54, "70", 2);
            TextOut(hdc, 721,54, "80", 2);
            TextOut(hdc, 230,110, "Enter Memory Required:", 22);
            
            hpen = CreatePen(PS_SOLID, -1, RGB(0, 0, 0));
           
            SelectObject(hdc, hpen);
            for(i=0;i<80;i++)
            {  
               rct[i].left=x;
               rct[i].right=y;
               rct[i].top=50;
               rct[i].bottom=20;
               FillRect(hdc, &rct[i], brush1);
              x+=9;
              y+=9;
            }
            EndPaint(hwnd, &ps); 
            }
            
            xyz:
            if(g==1)
            {
            hdc = BeginPaint(hwnd, &ps); 
            SetBkColor(hdc, RGB(102,102,102));
            TextOut(hdc, 330,75, "MEMORY", 6); 
            TextOut(hdc, 6,54, "0", 1);
            TextOut(hdc, 92,54, "10", 2);
            TextOut(hdc, 181,54, "20", 2);
            TextOut(hdc, 271,54, "30", 2);
            TextOut(hdc, 361,54, "40", 2);
            TextOut(hdc, 451,54, "50", 2);
            TextOut(hdc, 541,54, "60", 2);
            TextOut(hdc, 631,54, "70", 2);
            TextOut(hdc, 721,54, "80", 2);
            TextOut(hdc, 230,110, "Enter Memory Required:", 22);
            
            hpen = CreatePen(PS_SOLID, -1, RGB(255, 0, 0));
           
            SelectObject(hdc, hpen);
            for(i=0;i<80;i++)
            {  
               rct[i].left=x;
               rct[i].right=y;
               rct[i].top=50;
               rct[i].bottom=20;
               t=rand();
               t=t%2;
               if(t==0)
               {
                   FillRect(hdc, &rct[i], brush1);
                   a[i]=0;
               }
               else 
               { 
                   FillRect(hdc, &rct[i], brush2);
                   a[i]=1;
               }
              x+=9;
              y+=9;
            }
            ff=bf=wf=set=0;
            f1=f2=f3=0;
            w1=w2=w3=w4=0;
            b1=b2=b3=0;
            b4=100;
            am=80;
            EndPaint(hwnd, &ps); 
            }
            
            pqr:
            if(g==2)
            {                                                           
            hdc = BeginPaint(hwnd, &ps); 
            SetBkColor(hdc, RGB(102,102,102));
            TextOut(hdc, 330,75, "MEMORY", 6); 
            TextOut(hdc, 6,54, "0", 1);
            TextOut(hdc, 92,54, "10", 2);
            TextOut(hdc, 181,54, "20", 2);
            TextOut(hdc, 271,54, "30", 2);
            TextOut(hdc, 361,54, "40", 2);
            TextOut(hdc, 451,54, "50", 2);
            TextOut(hdc, 541,54, "60", 2);
            TextOut(hdc, 631,54, "70", 2);
            TextOut(hdc, 721,54, "80", 2);
            TextOut(hdc, 230,110, "Enter Memory Required:", 22);
            hpen = CreatePen(PS_SOLID, -1, RGB(255, 0, 0));
           
            SelectObject(hdc, hpen);
            for(i=0;i<80;i++)
            {  
               rct[i].left=x;
               rct[i].right=y;
               rct[i].top=50;
               rct[i].bottom=20;
               
               if(a[i]==0)
               {
                   FillRect(hdc, &rct[i], brush1);
                   a[i]=0;
                   
               }
               else if(a[i]==1) 
               { 
                   FillRect(hdc, &rct[i], brush2);
                   a[i]=1;
               }
              x+=9;
              y+=9;
            }
               
           if(ff==1|bf==1|wf==1)   
           { 
               for(i=o;i<n+o;i++)
               {
                    FillRect(hdc, &rct[i], brush2);
                    a[i]=1;
                    am--;   
               }
           }
            ff=bf=wf=set=0;
            f1=f2=f3=0;
            b1=b2=b3=b4=0;
            w1=w2=w3=0;
            w4=100;
            full1=0;
            EndPaint(hwnd, &ps); 
            } 
            return 0; 

        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            track:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc,wc1;
    HWND hwnd;
    MSG Msg;
    HBRUSH brush3=CreateSolidBrush(RGB(102,102,102));
   
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = brush3;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
   
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "MEMORY MANAGEMENT SIMULATOR",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 760,300,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

   
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
