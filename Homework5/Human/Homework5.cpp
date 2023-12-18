#include "d3dUtility.h"
#include <iostream>
#include <Windows.h>
#include <string>


//
// Globals
//
//

IDirect3DDevice9* Device = 0;

const int Width = 640;
const int Height = 480;

ID3DXMesh* Objects[24] = { 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
D3DXMATRIX  Worlds[24];
D3DMATERIAL9 Mtrls[24];
//
// Framework Functions
//
bool Setup()
{
	//
	// Create objects.
	//
	D3DXCreateCylinder(Device, 0.2f, 0.0f,0.3, 20, 20, &Objects[0], 0);//hat
	D3DXCreateSphere(Device, 0.6f, 20, 20, &Objects[1], 0);//head
	D3DXCreateSphere(Device, 0.09f, 21, 20, &Objects[2], 0);//eye 1
	D3DXCreateSphere(Device, 0.09f, 22, 20, &Objects[3], 0);//eye 2
	D3DXCreateBox(Device, 0.1f, 0.1f, 0.1f, &Objects[4], 0);//nose
	D3DXCreateBox(Device, 0.5f, 0.5f, 0.5f, &Objects[5], 0);//neck
	D3DXCreateBox(Device, 1.7f, 0.6f, 1.2f, &Objects[6], 0);//upper_body
	D3DXCreateBox(Device, 1.3f, 1.2f, 1.2f, &Objects[7], 0);//middle_body
	D3DXCreateBox(Device, 1.6f, 0.6f, 1.2f, &Objects[8], 0);//lower_body
	D3DXCreateSphere(Device, 0.3f, 20, 20, &Objects[9], 0);//shoulder1
	D3DXCreateSphere(Device, 0.3f, 20, 20, &Objects[10], 0);//shoulder2
	D3DXCreateSphere(Device, 0.15f, 20, 20, &Objects[11], 0);//upper_hand1
	D3DXCreateSphere(Device, 0.15f, 20, 20, &Objects[12], 0);//opper_hand2
	D3DXCreateBox(Device, 0.2f, 1.6f, 0.2f,&Objects[13], 0);//hand1
	D3DXCreateBox(Device, 0.2f, 1.6f, 0.2f, &Objects[14], 0);//hand2
	D3DXCreateBox(Device, 0.3f, 3.0f, 0.3f, &Objects[15], 0);//leg1
	D3DXCreateBox(Device, 0.3f, 3.0f, 0.3f, &Objects[16], 0);//leg2
	D3DXCreateBox(Device, 0.32f, 0.2f, 0.4f, &Objects[17], 0);//foot1
	D3DXCreateBox(Device, 0.32f, 0.2f, 0.4f, &Objects[18], 0);//foot2
	D3DXCreateSphere(Device, 0.045f, 21, 20, &Objects[19], 0);//upperlip2
	D3DXCreateSphere(Device, 0.045f, 22, 20, &Objects[20], 0);//upperlip1
	D3DXCreateBox(Device, 0.25f, 0.05f, 0.1f, &Objects[21], 0);//mainlip
	D3DXCreateBox(Device, 1000.0f, 0.01f, 1000.0f, &Objects[22], 0);//sky
	D3DXCreateBox(Device, 1000.0f, 0.01f, 1000.0f, &Objects[23], 0);//ground

	//
	// Build world matrices - position the objects in world space.
	//

	D3DXMatrixTranslation(&Worlds[0], 0.0f, 2.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[1], 0.0f, 2.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[2], -0.18f, 2.05f, -0.55f);
	D3DXMatrixTranslation(&Worlds[3], 0.18f, 2.05f, -0.55f);
	D3DXMatrixTranslation(&Worlds[4], 0.0f, 1.93f, -0.55f);
	D3DXMatrixTranslation(&Worlds[5], 0.0f, 1.4f, 0.0f);
	D3DXMatrixTranslation(&Worlds[6], 0.0f, 0.9f, 0.0f);
	D3DXMatrixTranslation(&Worlds[7], 0.0f, 0.0f, 0.0f);//base
	D3DXMatrixTranslation(&Worlds[8], 0.0f, -0.9f, 0.0f);
	D3DXMatrixTranslation(&Worlds[9], -1.0f, 1.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[10], 1.0f, 1.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[11], 1.10f, -0.72f, 0.0f);
	D3DXMatrixTranslation(&Worlds[12], -1.10f, -0.72f, 0.0f);
	D3DXMatrixTranslation(&Worlds[13], 1.1f, 0.1f, 0.0f);
	D3DXMatrixTranslation(&Worlds[14], -1.1f, 0.1f, 0.0f);
	D3DXMatrixTranslation(&Worlds[15], -0.4f, -2.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[16], 0.4f, -2.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[17], -0.4f, -3.5f, -0.09f);
	D3DXMatrixTranslation(&Worlds[18], 0.4f, -3.50f, -0.09f);
	D3DXMatrixTranslation(&Worlds[19], 0.095f, 1.79f, -0.55f);
	D3DXMatrixTranslation(&Worlds[20], -0.095f, 1.79f, -0.55f);
	D3DXMatrixTranslation(&Worlds[21], 0.0f, 1.78f, -0.55f);
	D3DXMatrixTranslation(&Worlds[22], 0.0f, 20.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[23], 0.0f, -5.0f, 0.0f);

	//rotate
	//Worlds[0] = PositionFinder(3, 0, new float[] {-2.85f, -2.5f, 0.0f}, 3.14 / 2, 0, "x", "y");//hat
	//Worlds[5] = PositionFinder(3, 0, new float[] {+2.85f, -2.5f, 0.0f}, 3.14 / 2, 0, "x", "y");//hand2
	//Worlds[13] = PositionFinder(3, 0, new float[] {-1.2f, -5.8f, 0.0f}, 3.14 / 2, 0, "x", "x");
	//Worlds[14] = PositionFinder(3, 0, new float[] {1.2f, -5.8f, 0.0f}, 3.14 / 2, 0, "x", "x");
	//Worlds[15] = PositionFinder(3, 0, new float[] {-1.2f, -5.8f, 0.0f}, 3.14 / 2, 0, "x", "x");
	//Worlds[16] = PositionFinder(3, 0, new float[] {1.2f, -5.8f, 0.0f}, 3.14 / 2, 0, "x", "x");

	//
	// Setup the object's materials.
	//

	Mtrls[0] = d3d::BLUE_MTRL;
	Mtrls[1] = d3d::YELLOW_MTRL;
	Mtrls[2] = d3d::BLACK_MTRL;
	Mtrls[3] = d3d::BLACK_MTRL;
	Mtrls[4] = d3d::BLACK_MTRL;
	Mtrls[5] = d3d::YELLOW_MTRL;
	Mtrls[6] = d3d::RED_MTRL;
	Mtrls[7] = d3d::YELLOW_MTRL;
	Mtrls[8] = d3d::BLUE_MTRL;
	Mtrls[9] = d3d::RED_MTRL;
	Mtrls[10] = d3d::RED_MTRL;
	Mtrls[11] = d3d::YELLOW_MTRL;
	Mtrls[12] = d3d::YELLOW_MTRL;
	Mtrls[13] = d3d::YELLOW_MTRL;
	Mtrls[14] = d3d::YELLOW_MTRL;
	Mtrls[15] = d3d::YELLOW_MTRL;
	Mtrls[16] = d3d::YELLOW_MTRL;
	Mtrls[17] = d3d::BLUE_MTRL;
	Mtrls[18] = d3d::BLUE_MTRL;
	Mtrls[19] = d3d::BLACK_MTRL;
	Mtrls[20] = d3d::BLACK_MTRL;
	Mtrls[21] = d3d::BLACK_MTRL;
	Mtrls[22] = d3d::BLUE_MTRL;
	Mtrls[23] = d3d::GREEN_MTRL;

	//
	// Setup a point light.  Note that the point light
	// is positioned at the origin.
	//

	D3DXVECTOR3 pos(40.0f, 0.0f, 0.0f);
	D3DXCOLOR   c = d3d::WHITE;
	D3DLIGHT9 point = d3d::InitPointLight(&pos, &c);

	//
	// Set and Enable the light.
	//

	Device->SetLight(0, &point);
	Device->LightEnable(0, true);

	//
	// Set lighting related render states.
	//

	Device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	Device->SetRenderState(D3DRS_SPECULARENABLE, false);

	//
	// Set the projection matrix.
	//

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DX_PI * 0.25f, // 45 - degree
		(float)Width / (float)Height,
		1.0f,
		1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	return true;
}

void Cleanup()
{
	for (int i = 0; i < 24; i++)
		d3d::Release<ID3DXMesh*>(Objects[i]);
}

bool Display(float timeDelta)
{
	if (Device)
	{
		// 
		// Update the scene: update camera position.
		//

		static float angle = (3.0f * D3DX_PI) / 2.0f;
		static float height = 5.0f;

		if (::GetAsyncKeyState(VK_LEFT) & 0x8000f)
			angle -= 0.5f * timeDelta;

		if (::GetAsyncKeyState(VK_RIGHT) & 0x8000f)
			angle += 0.5f * timeDelta;

		if (::GetAsyncKeyState(VK_UP) & 0x8000f)
			height += 5.0f * timeDelta;

		if (::GetAsyncKeyState(VK_DOWN) & 0x8000f)
			height -= 5.0f * timeDelta;

		D3DXVECTOR3 position(cosf(angle) * 7.0f, height, sinf(angle) * 7.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXMATRIX V;
		D3DXMatrixLookAtLH(&V, &position, &target, &up);

		Device->SetTransform(D3DTS_VIEW, &V);

		//
		// Draw the scene:
		//
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		Device->BeginScene();

		for (int i = 0; i < 24; i++)
		{
			// set material and world matrix for ith object, then render
			// the ith object.
			Device->SetMaterial(&Mtrls[i]);
			Device->SetTransform(D3DTS_WORLD, &Worlds[i]);
			Objects[i]->DrawSubset(0);
		}

		Device->EndScene();
		Device->Present(0, 0, 0, 0);
	}
	return true;
}
//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
	HINSTANCE prevInstance,
	PSTR cmdLine,
	int showCmd)
{
	if (!d3d::InitD3D(hinstance,
		Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, (LPCWSTR)"InitD3D() - FAILED", 0, 0);
		return 0;
	}

	if (!Setup())
	{
		::MessageBox(0, (LPCWSTR)"Setup() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop(Display);

	Cleanup();

	Device->Release();

	return 0;
}