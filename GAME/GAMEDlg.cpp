
// GAMEDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GAME.h"
#include "GAMEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGAMEDlg 对话框




CGAMEDlg::CGAMEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGAMEDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGAMEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGAMEDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGAMEDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CGAMEDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGAMEDlg 消息处理程序

BOOL CGAMEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGAMEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGAMEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGAMEDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();   默认确认对话框
	//::MessageBox(0,"sb", "刘聪是",MB_OK);   弹出消息框
	
	//画三角形
	CClientDC dc(this);//获取当前客户端dc
	HDC hdc=dc.m_hDC;
	HPEN penRed=::CreatePen(PS_SOLID,10,RGB(235,0,0)); //创造一个新画笔
	HPEN penOld=(HPEN)SelectObject(hdc,penRed);//放入画室
	//绘图操作
	MoveToEx(hdc,150,100,NULL);//距左上角横坐标150 纵坐标100
	LineTo(hdc,200,150);
	LineTo(hdc,300,150);
	LineTo(hdc,150,100);
	SelectObject(hdc,penOld);
	DeleteObject(penRed);
}


void CGAMEDlg::OnBnClickedButton1()
{	
	//图片和代码放到一个文件夹
	// TODO: 在此添加控件通知处理程序代码
	CClientDC dc(this);//获取当前客户区dc
	HBITMAP hBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),"图片/地面A.BMP",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);//加载一张图片
	HDC hDCBitmap=CreateCompatibleDC(dc);//创造一个和客户区dc兼容的dc
	SelectObject(hDCBitmap,hBitmap);//为这个dc选择位图
	DIBSECTION ds;
	BITMAPINFOHEADER &bm=ds.dsBmih;//位图的头文件
	GetObject(hBitmap,sizeof(ds),&ds);//获取位图的描述
	int iWidth=bm.biWidth;//位图的宽
	int iHeight=bm.biHeight;//位图的高
	BitBlt(dc.m_hDC,0,0,iWidth,iHeight,hDCBitmap,0,0,SRCCOPY);

}
