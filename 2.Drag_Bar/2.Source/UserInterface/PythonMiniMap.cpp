//Search:

void CPythonMiniMap::Update(float fCenterX, float fCenterY)

//Add above:

#ifdef ENABLE_FOV_OPTION
bool CPythonMiniMap::IsEven(int number)
{
	if (number % 2 == 0)
		return true;

	return false;
}

void CPythonMiniMap::UpdateFieldOfView()
{
	const std::string strImageRootCamera = "D:/ymir work/ui/camera/";

	std::string strImageCamera = strImageRootCamera + "minimap_camera_30.dds";

	char minimapname[256];
	int fFOV = CPythonSystem::instance().GetFOVLevel();
	if (fFOV > 30)
	{
		sprintf(minimapname, ("minimap_camera_%d.dds"), fFOV);
		strImageCamera = strImageRootCamera + minimapname;
	}
	CGraphicImage* pImage = (CGraphicImage*)CResourceManager::Instance().GetResourcePointer(strImageCamera.c_str());
	m_MiniMapCameraraphicImageInstance.SetImagePointer(pImage);
	TraceError("strImageCamera: %s", strImageCamera);
}
#endif

//On bool CPythonMiniMap::Create() Search:

	const std::string strImageCamera = strImageRoot + "minimap_camera.dds";

//Replace with:

#ifdef ENABLE_FOV_OPTION
	std::string strImageCamera = strImageRoot + "minimap_camera.dds";
#else
	const std::string strImageCamera = strImageRoot + "minimap_camera.dds";
#endif

//Search:

	pImage = (CGraphicImage*) CResourceManager::Instance().GetResourcePointer(strImageCamera.c_str());

//Add above:

#ifdef ENABLE_FOV_OPTION
	const std::string strImageRootCamera = "D:/ymir work/ui/camera/";

	char minimapname[256];
	int fFOV = CPythonSystem::instance().GetFOVLevel();
	if (fFOV > 30)
	{
		if (IsEven(fFOV))
		{
		sprintf(minimapname, ("minimap_camera_%d.dds"), fFOV);
		strImageCamera = strImageRootCamera + minimapname;
		}
		else
		{
			sprintf(minimapname, ("minimap_camera_%d.dds"), fFOV-1);
			strImageCamera = strImageRootCamera + minimapname;
		}
	}
#endif