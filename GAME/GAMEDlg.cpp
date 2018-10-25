
// GAMEDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GAME.h"
#include "GAMEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGAMEDlg �Ի���




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


// CGAMEDlg ��Ϣ�������

BOOL CGAMEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGAMEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGAMEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGAMEDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();   Ĭ��ȷ�϶Ի���
	//::MessageBox(0,"sb", "������",MB_OK);   ������Ϣ��
	
	//��������
	CClientDC dc(this);//��ȡ��ǰ�ͻ���dc
	HDC hdc=dc.m_hDC;
	HPEN penRed=::CreatePen(PS_SOLID,10,RGB(235,0,0)); //����һ���»���
	HPEN penOld=(HPEN)SelectObject(hdc,penRed);//���뻭��
	//��ͼ����
	MoveToEx(hdc,150,100,NULL);//�����ϽǺ�����150 ������100
	LineTo(hdc,200,150);
	LineTo(hdc,300,150);
	LineTo(hdc,150,100);
	SelectObject(hdc,penOld);
	DeleteObject(penRed);
}


void CGAMEDlg::OnBnClickedButton1()
{	
	//ͼƬ�ʹ���ŵ�һ���ļ���
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDC dc(this);//��ȡ��ǰ�ͻ���dc
	HBITMAP hBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),"ͼƬ/����A.BMP",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);//����һ��ͼƬ
	HDC hDCBitmap=CreateCompatibleDC(dc);//����һ���Ϳͻ���dc���ݵ�dc
	SelectObject(hDCBitmap,hBitmap);//Ϊ���dcѡ��λͼ
	DIBSECTION ds;
	BITMAPINFOHEADER &bm=ds.dsBmih;//λͼ��ͷ�ļ�
	GetObject(hBitmap,sizeof(ds),&ds);//��ȡλͼ������
	int iWidth=bm.biWidth;//λͼ�Ŀ�
	int iHeight=bm.biHeight;//λͼ�ĸ�
	BitBlt(dc.m_hDC,0,0,iWidth,iHeight,hDCBitmap,0,0,SRCCOPY);

}
