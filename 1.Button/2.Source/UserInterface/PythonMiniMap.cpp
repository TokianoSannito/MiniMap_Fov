//Add:
#ifdef ENABLE_FOV_OPTION
#include "PythonSystem.h"
#endif

//Search:

void CPythonMiniMap::Update(float fCenterX, float fCenterY)

//Add above:

#ifdef ENABLE_FOV_OPTION
void CPythonMiniMap::UpdateFieldOfView()
{
	const std::string strImageRoot = "D:/ymir work/ui/";

	std::string strImageCamera = strImageRoot + "minimap_camera.dds";

	if (CPythonSystem::instance().IsExtendedFOV())
		strImageCamera = strImageRoot + "minimap_camera_fov.dds";

	CGraphicImage* pImage = (CGraphicImage*)CResourceManager::Instance().GetResourcePointer(strImageCamera.c_str());
	m_MiniMapCameraraphicImageInstance.SetImagePointer(pImage);
}
#endif

//On bool CPythonMiniMap::Create() Search:

	const std::string strImageCamera = strImageRoot + "minimap_camera.dds";

//Replace with:

#ifdef ENABLE_FOV_OPTION
	std::string strImageCamera = strImageRoot + "minimap_camera.dds";

	if (CPythonSystem::instance().IsExtendedFOV())
		strImageCamera = strImageRoot + "minimap_camera_fov.dds";
#else
	const std::string strImageCamera = strImageRoot + "minimap_camera.dds";
#endif