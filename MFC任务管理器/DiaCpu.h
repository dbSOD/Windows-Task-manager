#pragma once


// CDiaCpu �Ի���

class CDiaCpu : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCpu)

public:
	CDiaCpu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaCpu();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGCPU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
