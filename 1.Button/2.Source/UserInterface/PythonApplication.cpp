//Search:

#ifdef ENABLE_FOV_OPTION
		if (CPythonSystem::instance().IsExtendedFOV())
		{
			m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE * 2.5, fAspect, 100.0, fFarClip);
		}
		else
		{
			m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
		}
#else
		m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
#endif

//Replace with:

#ifdef ENABLE_FOV_OPTION
		if (CPythonSystem::instance().IsExtendedFOV())
		{
			m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE * 2.5, fAspect, 100.0, fFarClip);
			m_pyMiniMap.UpdateFieldOfView();
		}
		else
		{
			m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
			m_pyMiniMap.UpdateFieldOfView();
		}
#else
		m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
#endif