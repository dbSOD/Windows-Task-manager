
// MFC���������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���������.h"
#include "MFC���������Dlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <tchar.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  WCHAR_TO_CHAR(lpW_Char, lpChar) \
    WideCharToMultiByte(CP_ACP, NULL, lpW_Char, -1, \
lpChar, _countof(lpChar), NULL, FALSE);

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC���������Dlg �Ի���



CMFC���������Dlg::CMFC���������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
	, m_foldload(_T(""))
	, m_wenJianXinXi(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC���������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_SheelTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_ShellList);
	DDX_Text(pDX, IDC_EDIT1, m_foldload);
	DDX_Text(pDX, IDC_EDIT2, m_wenJianXinXi);
}

BEGIN_MESSAGE_MAP(CMFC���������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLTREE1, &CMFC���������Dlg::OnNMClickMfcshelltree1)
	ON_NOTIFY(NM_DBLCLK, IDC_MFCSHELLTREE1, &CMFC���������Dlg::OnNMDblclkMfcshelltree1)
	ON_NOTIFY(TVN_SELCHANGING, IDC_MFCSHELLTREE1, &CMFC���������Dlg::OnTvnSelchangingMfcshelltree1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC���������Dlg::OnBnClickedClean)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC���������Dlg::OnBnClickedHuoquWenjian)
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLLIST1, &CMFC���������Dlg::OnNMClickMfcshelllist1)
END_MESSAGE_MAP()


// CMFC���������Dlg ��Ϣ�������

BOOL CMFC���������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(true);

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_SheelTree.SetRelatedList(&m_ShellList);
	m_ShellList.EnableShellContextMenu(true);
	//CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	m_wenJianXinXi = L"�˴���ʾ�ļ���Ϣ";
	UpdateData(false);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC���������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC���������Dlg::OnPaint()
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
HCURSOR CMFC���������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC���������Dlg::OnNMClickMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
}


void CMFC���������Dlg::OnNMDblclkMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
}


void CMFC���������Dlg::OnTvnSelchangingMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
}


void CMFC���������Dlg::OnBnClickedClean()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	TCHAR* p = (TCHAR*)m_foldload.GetBuffer();//L"D:\\project\\24_MFC_day007_3.2";// 
		
	EnumLoad(p);
	MessageBox(TEXT("�������"), TEXT("֪ͨ"), 0);
}

void CMFC���������Dlg::EnumLoad(TCHAR * load)
{
	BOOL Flag = FALSE;
	TCHAR szSearchPath[MAX_PATH] = {};
	_stprintf_s(szSearchPath, MAX_PATH, L"%s\\*.*", load);
	WIN32_FIND_DATA wsd = {};
	HANDLE hFile = FindFirstFile(szSearchPath, &wsd);
	if (hFile == INVALID_HANDLE_VALUE) {
		return;
	}
	do {
		if (wsd.cFileName[0] == '.') {
			continue;
		}
		if (wsd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) {
			TCHAR oppo[MAX_PATH];
			_stprintf_s(oppo, MAX_PATH, L"%s\\%s", load, wsd.cFileName);
			if (_tcscmp(L"Debug", wsd.cFileName) == 0 || _tcscmp(L"Release", wsd.cFileName) == 0
				|| _tcscmp(L"ipch",wsd.cFileName) == 0) {
				//_stprintf_s(oppo, MAX_PATH, L"%s%s", oppo, "\0");
				deleteFolder(oppo);
				continue;
			}
			EnumLoad(oppo);
		}
		else {
			int Size = _tcslen(wsd.cFileName);
			if (NULL != StrStr(wsd.cFileName, L".db")) {
				TCHAR oppoStr[MAX_PATH];
				_stprintf_s(oppoStr, MAX_PATH, L"%s\\%s", load, wsd.cFileName);
				//deleteFolder(oppoStr);
				DeleteFile(oppoStr);
			}

		}
	} while (FindNextFile(hFile, &wsd));
}

void CMFC���������Dlg::deleteFolder(TCHAR * load)
{
	

	/*char c[100] = {};
	CString temp1;
	temp1.Format(L"rd /s/q  %s", load);

	WCHAR_TO_CHAR(temp1.GetBuffer(), c);
	system(c);*/
	SHFILEOPSTRUCT FileOp = {};
	FileOp.fFlags = FOF_NOCONFIRMATION;
//	FileOp.hNameMappings = NULL;
//	FileOp.hwnd = NULL;
//	FileOp.lpszProgressTitle = NULL;
	CString temp = load;
	temp += '\0';
	FileOp.pFrom = temp;
//	FileOp.pTo = NULL;
	FileOp.wFunc = FO_DELETE;
	SHFileOperation(&FileOp);

}


void CMFC���������Dlg::OnBnClickedHuoquWenjian()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString wenJianSum = m_foldload + L"\\"+wenJianMing;
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	GetFileAttributesEx(wenJianSum, GetFileExInfoStandard, &wfad);
	FILETIME ftLocal;
	FileTimeToLocalFileTime(&wfad.ftCreationTime, &ftLocal);
	SYSTEMTIME stcCreatTime;
	FileTimeToSystemTime(&ftLocal, &stcCreatTime);
	
	
	m_wenJianXinXi = wenJianSum;
		//L"����ʱ�䣺";
	UpdateData(false);	
}


void CMFC���������Dlg::OnNMClickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	//m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
	int temp = pNMItemActivate->iItem;
	wenJianMing = m_ShellList.GetItemText(temp, 0);
}
