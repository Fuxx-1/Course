#include <stdio.h>
#include <windows.h>

int WINAPI WinMain(HINSTANCE hlinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    //1.注册窗口类
    WNDCLASSA wnd;
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    wnd.hbrBackground = (HBRUSH)(GetStockObject(GRAY_BRUSH)); //背景色
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW); //光标
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION); //图标
    wnd.IpfnWndProc = DefWindowProc;//窗口过程函数，用于处理消息
    wnd.IpszClassName = "GUI"; //窗口类名
    

}

// /*
// 	Microsoft Visual Studio 2017中的Visual C++集成开发平台是开发Windows应用（不需要任何虚拟机直接在Windows上
// 	运行的程序或动态连接库DLL）的利器，加上有微软基础类库（Microsoft Foundation Classes）MFC的支持，更是如虎
// 	添翼，不可一世。
// 	现在讲解基础理论篇的第一个例子，用Win32API创建简单的窗口应用。

// 	由于MFC是对Win32API的封装，所以Win32API是MFC的重要基基石，MFC的许多函数直接来自Win32API，为了理解MFC类库
// 	体系结构的本质，我们有必要直接从使用Win32API创建一个尽可能简单的窗口应用开始讲起。
// */

// //这里的“windows.h”是用Win32API创建窗口应用需要包含的头文件。
// #include <windows.h>

// /*
// 	这是窗口过程LRESULT CALLBACK WndProc()的原型声明，即当事件发生时供系统回调的窗口过程函数（此处由CALLBACK
// 	来标识函数的回调性质）。
// 	函数的形参说明：
// 		hwnd--窗口句柄（一个唯一标识窗口的32位数）。
// 		message--消息ID（一个用来标识消息类型的32位数）
// 		wParam、lParam--在特定消息类型上的附加数据
// */
// LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

// /*
// 	这里的int APIENTRY WinMain()是Win32程序的执行入口（由APIENTRY来标识）。

// 	一、函数的形参说明：
// 		hInstance--标识应用程序的实例句柄。
// 		hPrevInstance--标识应用程序的先前实例句柄（对于32位程序，该参数总为nullptr）。
// 		lpszCmdLine--指向应用程序命令行字符串的指针（注意这里不包括执行文件名）。
// 		nCmdShow--指明窗口显示方式的参数,可以是下列值之一：
// 			SW_HIDE--隐藏窗口（并且激活另外一个窗口）。
// 			SW_MINIMIZE--最小化窗口（并且激活在系统表中的顶层窗口）。
// 			SW_RESTORE--激活并显示窗口（如果窗口已经最小化或最大化，则恢复到原来的尺寸和位置）。
// 			SW_SHOW--激活窗口并以原来的尺寸和位置显示。
// 			SW_SHOWMAXIMIZED--激活窗口并且将其最大化。
// 			SW_SHOWMINIMIZED--激活窗口并将其最小化（以图标显示）。
// 			SW_SHOWMINNOACTIVE--将一个窗口显示为图标（激活窗口维持活动状态）。
// 			SW_SHOWNA--以窗口的当前状态显示（激活窗口保持活动状态）。
// 			SW_SHOWNOACTIVATE--以窗口的最近一次的尺寸和位置显示（不激活窗口）。
// 			SW_SHOWNORMAL--同SW_RESTORE。

// 	二、应用的执行流程（这里在WinMain()中调用的函数暂时都属于Win32API的函数）：
// 		1、首先在WinMain()中调用RegisterClass()，注册一个包含窗口大量重要特性的WNDCLASS结构变量。
// 		2、利用上述注册的WNDCLASS结构变量，接着调用CreateWindow()完成应用程序窗口的创建。
// 		3、按照WinMain()参数中的nCmdShow参数设定的方式，调用ShowWindow()显示所创建的窗口。
// 		4、然后调用UpdateWindow()向窗口发送一个WM_PAINT消息，使我们有机会在窗口中绘制并输出有关信息。
// 		5、最后进入应用的消息循环，调用GetMessage()、TranslateMessage()和DispatchMessage()进行消息的获取、转换与调度。
// 	三、为简单起见，这里的WinMain()没有进行有关的错误处理。

// 	下面我们就来按照应用的执行流程，来详细分析程序代码的功能。
// */
// int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
// 	//1、声明并注册一个包含窗口重要特性（如窗口过程地址、默认背景色以及图标等）的WNDCLASS结构变量wc。
// 	WNDCLASS wc;
// 	wc.style = 0; //字段style表示从WNDCLASS派生的窗口具有的样式或称风格，这里初始化为0。
// 	wc.lpfnWndProc = (WNDPROC)WndProc; //字段lpfnWndProc为窗口过程地址，这里初始化为WndProc。
// 	//下面的两个字段被当成预留的字节数，程序可以根据需要来使用预留空间（由于这里没有使用它们，所以初始化为0）。
// 	wc.cbClsExtra = 0;
// 	wc.cbWndExtra = 0;
// 	wc.hInstance = hInstance; //字段hInstance为应用程序的实例句柄，这里初始化为WinMain()的第一个参数hInstance。
// 	//下面的3个字段分别为窗口图标句柄、光标句柄与背景画刷句柄（这里都初始化为系统预定义的值）。
// 	wc.hIcon = LoadIcon(nullptr, IDI_WINLOGO); //通过LoadIcon()返回。
// 	wc.hCursor = LoadCursor(nullptr, IDC_ARROW); //通过LoadCursor()返回。
// 	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
// 	wc.lpszMenuName = nullptr; //字段lpszMenuName为菜单名称指针（nullptr表示窗口没有菜单）
// 	wc.lpszClassName = "MyWindClass"; //字段lpszClassName表示本WNDCLASS自己的名称指针，这里被初始化为"MyWindClass"

// 	RegisterClass(&wc); //在这里注册WNDCLASS

// 	//2、用CreateWindow()创建窗口，如函数执行成功返回创建的窗口句柄，否则返回nullptr。
// 	HWND hwnd = CreateWindow(
// 		"MyWindClass", //第一个参数为所使用的WNDCLASS名称，窗口将由此WNDCLASS模板生成。
// 		"Windows API Application", //第二个参数为窗口标题栏中显示的文本
// 		/*
// 			下面的参数指定窗口的样式,可以是下列样式通过"|"运算的任意组合：
// 			WS_BORDER--带边框的窗口。
// 			WS_CAPTION--有标题栏的窗口（包括WS_BORDER）。
// 			WS_CHILD--一个子窗口（不能与WS_POPUP合用）。
// 			WS_CHILDWINDOW--同WS_CHILD。
// 			WS_CLIPCHILDREN--在父窗口内绘图时排除子窗口区域（在创建父窗口时使用）。
// 			WS_CLIPSIBLINGS--排除子窗口之间的相对区域。
// 			WS_DISABLED--初始状态为禁止的子窗口（一个禁止状态的窗口不能接受来自用户的输入信息）。
// 			WS_DLGFRAME--带对话框边框样式的窗口（这种样式的窗口不能带标题栏）。
// 			WS_GROUP--指定一组控制的第一个控制。
// 			WS_HSCROL--有水平滚动条的窗口。
// 			WS_ICONIC--最小化状态的窗口。
// 			WS_MAXIMIZE--最大化状态的窗口。
// 			WS_MAXIMIZEBOX--具有最大化按钮的窗口（不能与WS_EX_CONTEXTHELP同时出现，同时必须指定WS_SYSMENU）。
// 			WS_MINIMIZE--同WS_ICONIC。
// 			WS_OVERLAPPED--WS_CAPTION|WS_BORDER（具有标题栏和边框）。
// 			WS_OVERLAPPEDWINDOW--WS_OVERLAPPED|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX。
// 			WS_POPUP--弹出式窗口（相当于顶层窗口，故不能与WS_CHILD同时使用）。
// 			WS_POPUPWINDOW--WS_BORDER|WS_POPUP|WS_SYSMENU（必须同时设定WS_CAPTION才能使系统菜单可见）。
// 			WS_SIZEBOX--可调边框的窗口。
// 			WS_SYSMENU--在标题栏上带有系统菜单的窗口（必须同时设定WS_CAPTION）。
// 			WS_TABSTOP--创建一个控制，这个控制在用户按下Tab键时可以获得键盘焦点。
// 			WS_THICKFRAME--同WS_SIZEBOX。
// 			WS_TILED--同WS_OVERLAPPED。
// 			WS_TILEDWINDOW--同WS_OVERLAPPEDWINDOW。
// 			WS_VISIBLE--初始状态为可见的窗口。
// 			WS_VSCROLL--有垂直滚动条的窗口。
// 		*/
// 		WS_OVERLAPPEDWINDOW, //相当于WS_OVERLAPPED|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX的组合。

// 		//以下的4个参数用系统的默认值指定了窗口的初始位置和大小（左上角坐标x, y及其宽度nWidth与高度nHeight）。
// 		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

// 		HWND_DESKTOP, //这个参数为父窗口句柄（HWND_DESKTOP表示这个窗口没有父窗口，即为顶层窗口）。
// 		nullptr, //这个参数为与窗口联系的菜单句柄（nullptr表示这个窗口没有菜单）。
// 		hInstance, //这个参数为应用程序实例句柄（用来让程序员区分是程序自身还是DLL模块的值）。
// 		nullptr //这个参数为指向一个值的无类型指针，该值会传递给窗口的WM_CREATE消息处理程序。
// 	);

// 	/*
// 		3、按照WinMain()参数中的nCmdShow参数设定的方式，调用ShowWindow()显示所创建的窗口。
// 		为了使用"nCmdShow"这个如何显示窗口的参数，上述创建的窗口不含WS_VISIBLE样式，所以此时的窗口暂不可见，
// 		执行下面的的ShowWindow()函数不仅使“nCmdShow”这个如何显示窗口的参数派上用场，而且使窗口立即可见。
// 	*/
// 	ShowWindow(hwnd, nCmdShow);

// 	//4、调用UpdateWindow()向窗口发送一个WM_PAINT消息，使我们有机会在窗口中绘制并输出有关信息。
// 	UpdateWindow(hwnd);

// 	/*
// 		5、进入应用的消息循环，调用GetMessage()、TranslateMessage()和DispatchMessage()进行消息的获取、转换与调度。

// 		Window是一个事件驱动的操作系统，在其上运行的窗口应用同样需要事件驱动。即所谓以消息为基础，事件驱动之就是这
// 		个意思。事件可以是一次击键、一次鼠标单击或是要求窗口更新的命令以及其它别的事情。消息通过事件转化而来并存入
// 		消息队列中，一个典型的窗口应用绝大部分的操作是在响应它收到的消息，此外，除了等待下一个消息的到达外它几乎什
// 		么也不做。下面声明的msg就是用来存储消息的一个结构变量。
// 		在消息循环循环中，GetMessage()负责从消息队列里收取调用线程窗口的消息，并将收取的消息存入msg中，被收取的消
// 		息将从队列中立即删除（但WM_PAINT消息直到被处理完毕时才被清除）,如队列中没有调用线程窗口的消息，GetMessage()
// 		将一直等待到消息的到来。当获取WM_QUIT消息时，GetMessage()将返回零值从而结束消息循环，接着WinMain()结束，整
// 		个应用程序终止运行。
// 	*/
// 	MSG msg;
// 	while (GetMessage(&msg, nullptr, 0, 0)) {
// 		TranslateMessage(&msg); //TranslateMessage()将一个指示字符键的键盘消息，转换为更容易使用的WM_CHAR消息。
// 		DispatchMessage(&msg); //DispatchMessage()调度的消息将生成对窗口过程WndProc()的调用。
// 	}

// 	return msg.wParam; //在执行PostQuitMessage()时的唯一参数会存入msg.wParam中，在此作为程序的退出码(ExitCode)。
// }

// /*
// 	这是窗口过程WndProc()的定义。
// 	虽然WinMain()是Win32程序的执行入口，但是大多数的操作是在以下称为窗口过程WndProc()的回调函数中进行的。
// 	为简单起见，函数在此仅处理了WM_SIZE、WM_PAINT与WM_DESTROY三个消息类型，所有其它类型的消息都由DefWindowProc()默认函数处理。

// 	下面我们就来详细分析程序代码的功能。
// */
// LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
// 	//通过开关语句分类处理不同的消息。
// 	switch (message) {
// 	case WM_SIZE: //开始处理窗口大小改变的消息（该消息在窗口大小被改变后产生）。
// 		//这里的InvalidateRect()使窗口客户区无效，并向消息队列中发送一个WM_PAINT消息，最终达到强制系统重绘窗口的目的。
// 		InvalidateRect(
// 			hwnd, //窗口句柄。
// 			nullptr, //该参数为一个RECT结构变量的指针,这里使用nullptr值，表示使窗口的整个客户区无效。
// 			TRUE //这个参数表示重画时是否擦除背景，这里的TRUE表示重画时擦除背景。
// 		);
// 		return 0;
// 	case WM_PAINT: //开始处理要求窗口绘制的消息（该消息在窗口客户区需要重绘时产生）。
// 		/*
// 			下面首先声明了一个PAINTSTRUCT的结构变量ps，并用BeginPaint()来填充（初始化）其中的字段。其中ps.rcPaint
// 			字段表示绘制窗口客户区的范围，ps.hdc字段为支持Window绘图的设备环境句柄，是绘图函数所必需的重要参数。
// 		*/
// 		PAINTSTRUCT ps;
// 		BeginPaint(hwnd, &ps);

// 		//用DrawText()在指定的矩形区域里（ps.rcPaint）写入正文"Hello Windows API!"。
// 		DrawText(
// 			ps.hdc, //设备环境句柄。
// 			"Hello Windows API!", //被输出的字符串。
// 			18, //被输出字符串的字符个数。
// 			&ps.rcPaint, //表示窗口客户区范围的RECT指针。
// 			/*
// 				下面的参数表示绘制选项的“|”运算组合。
// 				这里的DT_SINGLELINE | DT_CENTER | DT_VCENTER三项组合，表示将单行文本水平且垂直居中显示。
// 			*/
// 			DT_SINGLELINE | DT_CENTER | DT_VCENTER
// 		);

// 		EndPaint(hwnd, &ps); //最后通过EndPaint()释放设备环境句柄。
// 		return 0;
// 	case WM_DESTROY: //开始处理窗口销毁的消息（该消息在窗口被关闭时产生）。
// 		/*
// 			当用户从文件菜单中选择了“退出”命令，或从窗口系统菜单中选择了“关闭”命令，或鼠标单击了窗口的“关
// 			闭”按钮（窗口右上角带有×的按钮）时窗口将被关闭，此时系统向窗口发送一个WM_DESTROY消息，窗口接收到
// 			WM_DESTROY消息后即被销毁。
// 			当顶层窗口接收到一个WM_DESTROY消息时，必须调用PostQuitMessage()给消息队列发送一个WM_QUIT消息，只有
// 			当GetMessage()收到WM_QUIT消息后才能结束消息循环，终止应用程序的运行。这便是下面调用PostQuitMessage()
// 			的真正原因。
// 		*/
// 		PostQuitMessage(0); //该函数的唯一形参，为一个叫做程序退出码(ExitCode)的整数，用作WinMain()的返值。
// 		return 0;
// 	default: //所有其它消息进行缺省处理，即通过调用DefWindowProc()完成。
// 		return DefWindowProc(hwnd, message, wParam, lParam);
// 	}
// }