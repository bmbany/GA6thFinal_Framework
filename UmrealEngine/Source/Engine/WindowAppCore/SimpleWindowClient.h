#pragma once
#define WIN32_LEAN_AND_MEAN

#pragma comment(lib, "Dbghelp.lib")

struct ClientHelper
{
	/**Ŭ���̾�Ʈ�� ȭ�� ����� ��ġ ��Ų��.*/
	static void WinToScreenCenter(HWND hwnd);

	/**Ŭ���̾�Ʈ ũ�⸦ ���� ȭ�� �ػ� �������� Clamp �ϴ� �Լ�.*/
	static void ClampScreenMaxSize(SIZE& size);
};

class SimpleWindowClient
{
	friend LRESULT CALLBACK DefaultWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
public:
	SimpleWindowClient() = default;
	virtual ~SimpleWindowClient() = default;

	void Initialize(HINSTANCE hinstance);
	void Run();
	void Uninitialize();

	/** ���� �������� ���ӷ����� �����ŵ�ϴ�.*/
	void RunEnd();

	HINSTANCE GetHInstance() const { return hInstance; }
	HWND	  GetHWND() const { return hwnd; }
protected:
	/*1��° ȣ��Ǵ� �ʱ�ȭ �Լ�*/
	virtual void PreInitialize()	= 0;
	/*2��° ȣ��Ǵ� �ʱ�ȭ �Լ�*/
	virtual void ModuleInitialize() = 0;

	/*1��° ȣ��Ǵ� ���� �Լ�*/
	virtual void ModuleUnitialize() = 0; 
	/*2��° ȣ��Ǵ� ���� �Լ�*/
	virtual void PreUnitialize()	= 0;

	virtual void ClientUpdate()		= 0;
	virtual void ClientRender()		= 0;

protected:
	/** Ŭ���� ��Ÿ��. Initialize() ���������� ����˴ϴ�.*/
	UINT winClassStyle = CS_HREDRAW | CS_VREDRAW;

	/** Ŭ���̾�Ʈ ������ ��Ÿ��. Initialize() ���������� ����˴ϴ�. �⺻�� : �׵θ� ���� â���*/
	DWORD windowStyleEX = WS_POPUP;

	/** ������ Ŭ���� ����ü �̸�. Initialize() ���������� ����˴ϴ�.*/
	LPCWSTR winClassName = L"UmrealEngineClass";

	/** ������ Ŭ���̾�Ʈ �̸�. Initialize() ���������� ����˴ϴ�.*/
	LPCWSTR windowName = L"DemoApp";

	/** ����� ������ ���ν��� (nullptr�̸� �⺻ ���ν����� ����մϴ�.) Initialize() ���������� ����˴ϴ�.*/
	WNDPROC customWndProc = nullptr;

	/** Ŭ���̾�Ʈ ������. Initialize() ���������� ����˴ϴ�. �⺻ �� : ȭ�� �ػ�*/
	SIZE clientSize = { 0, 0 };

protected:
	/*������ ��Ÿ���� â����*/
	void SetStyleToWindowed();
	/*������ ��Ÿ���� �׵θ� ���� â����*/
	void SetStyleToBorderlessWindowed();

	/*Ŭ���̾�Ʈ ũ�⸦ ����� �ػ󵵷�*/
	void SetOptimalScreenSize();

protected:
	bool isRunEnd = false;
private:
	MSG msg{};

private:
	inline static HINSTANCE hInstance{};
	HWND hwnd{};
	void WindowInit(HINSTANCE _hinstance);
	void WindowUninit();
};