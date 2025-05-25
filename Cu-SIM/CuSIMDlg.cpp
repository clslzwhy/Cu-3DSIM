
// CuSIMDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CuSIM.h"
#include "CuSIMDlg.h"
#include "afxdialogex.h"
#include "kernel.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCuSIMDlg 对话框



CCuSIMDlg::CCuSIMDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUSIM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCuSIMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCuSIMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCuSIMDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCuSIMDlg 消息处理程序

BOOL CCuSIMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
#if 1
	AllocConsole();
	SetConsoleTitle(_T("Debug Output"));
	freopen("CONOUT$", "w", stdout);
#endif
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCuSIMDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCuSIMDlg::OnPaint()
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
HCURSOR CCuSIMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCuSIMDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CalFuntion CalFuntionCall;
	sCudaPara para;
	string Dstpath;
	clock_t start, end;
	start = clock();

	//CalFuntionCall.MainPath = argv[1];

	//para.dataparamsCpu.Nz = atoi(argv[2]);// 深度 Z
	//para.dataparamsCpu.exwavelength = atoi(argv[3]);
	//para.dataparamsCpu.lambda = atoi(argv[4]);
	//Dstpath = argv[5];
	//CalFuntionCall.ImgSizeBefore = atoi(argv[6]);





	CalFuntionCall.MainPath = "20220929-Actin-1518-488_HSNR_004.tif";
	para.dataparamsCpu.Nz = 13;// 深度 Z
	para.dataparamsCpu.exwavelength = 488;
	para.dataparamsCpu.lambda = 561;
	Dstpath = "output/result";


	int readtype = 1;
	CalFuntionCall.ImgSizeBefore = 512;
	para.dataparamsCpu.ImageCut = 32;

	para.dataparamsCpu.ImageCutThread = 32;


	para.dataparamsCpu.ImageCutBlock = CalFuntionCall.ImgSizeBefore / para.dataparamsCpu.ImageCutThread;







	cout << Dstpath << endl;

	cout << CalFuntionCall.MainPath << endl;



	printf("Nz  %f\n", para.dataparamsCpu.Nz);


	printf("lambda  %f\n", para.dataparamsCpu.lambda);
	printf("exwavelength  %f\n", para.dataparamsCpu.exwavelength);











	CalFuntionCall.Npola = int(para.dataparamsCpu.Nz) * 4 + 1;
	CalFuntionCall.Nazim = 3 * 32;//3不是Nz,就是32


	para.dataparamsCpu.emwavelength = para.dataparamsCpu.lambda;
	CalFuntionCall.ImageSizeCut = para.dataparamsCpu.ImageCut;

	CalFuntionCall.ImgSizeAfter = CalFuntionCall.ImgSizeBefore * 2;
	para.dataparamsCpu.numpixelsx = CalFuntionCall.ImgSizeBefore;
	para.dataparamsCpu.numpixelsy = CalFuntionCall.ImgSizeBefore;
	para.dataparamsCpu.Nx = para.dataparamsCpu.numpixelsx * 2;
	para.dataparamsCpu.Ny = para.dataparamsCpu.numpixelsy * 2;

	para.dataparamsCpu.allftorderims = new cv::Mat[para.dataparamsCpu.Nz * 5];
	para.dataparamsCpu.OTFshift0 = new cv::Mat[para.dataparamsCpu.Nz * 5];


	para.dataparamsCpu.notchwidthxy1 = 0.4 * para.dataparamsCpu.Nx / 1024;//就是1024
	para.dataparamsCpu.notchwidthxy2 = 0.5 * para.dataparamsCpu.Ny / 1024;//就是1024

	cv::imreadmulti(CalFuntionCall.MainPath, para.dataparamsCpu.images, cv::IMREAD_ANYDEPTH);

	for (int i = 0; i < para.dataparamsCpu.Nz * 15; i++)
	{
		para.dataparamsCpu.images[i].convertTo(para.dataparamsCpu.images[i], CV_64FC1);
	}

	printf("Out Info 1:图片数量：%f\n", para.dataparamsCpu.Nz);
	
	switch (readtype)
	{
	case 1:
		for (int j = 0; j < para.dataparamsCpu.Nz; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int i = 0; i < 5; i++)
				{
					para.dataparamsCpu.Snoisy.push_back(para.dataparamsCpu.images.at(k * 5 * para.dataparamsCpu.Nz + 5 * j + i));
				}

			}
		}


		break;

	case 2:
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < para.dataparamsCpu.Nz; j++)
			{
				para.dataparamsCpu.Snoisy.push_back(para.dataparamsCpu.images.at(j + i * para.dataparamsCpu.Nz));
			}

		}
		break;
	case 3:
		for (int i = 0; i < 15 * para.dataparamsCpu.Nz; i++)
		{
			para.dataparamsCpu.Snoisy.push_back(para.dataparamsCpu.images.at(i));
		}
		break;
	}
	

	cv::Mat* Result = new cv::Mat[para.dataparamsCpu.Nz];
	CalFuntionCall.Recon3DSIM(Result, para, CalFuntionCall.ImgSizeBefore, CalFuntionCall.ImgSizeBefore);
	for (int ti = 0; ti < para.dataparamsCpu.Nz; ti++)
	{
		string Pathresult;
		if (ti < 10)
		{
			Pathresult = Dstpath + "0" + to_string(ti) + ".tif";

		}
		else
		{
			Pathresult = Dstpath + "" + to_string(ti) + ".tif";
		}


		cv::Mat res;
		normalize(Result[ti], res, 0, 1, cv::NORM_MINMAX);
		cv::Mat res2(para.dataparamsCpu.images.at(0).cols * 2, para.dataparamsCpu.images.at(0).rows * 2, CV_16UC1);

		res2 = CalFuntionCall.double2Mat16(res, para.dataparamsCpu.images.at(0).cols * 2, para.dataparamsCpu.images.at(0).rows * 2);


		imwrite(Pathresult, res2);

	}

	std::cout << "Hello World!\n";
	end = clock();        //程序结束用时
	double endtime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Total time:" << endtime << "s" << endl;        //s为单位
	cout << "Total time:" << endtime * 1000 << "ms" << endl;    //ms为单位

}
