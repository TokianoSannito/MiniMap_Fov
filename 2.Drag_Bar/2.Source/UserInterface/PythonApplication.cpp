//Search:

#ifdef ENABLE_FOV_OPTION
	float fFOV = m_pySystem.GetFOVLevel();
	m_pyGraphic.SetPerspective(fFOV, fAspect, 100.0, fFarClip);
#else
	m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);
#endif

//Replace with:

#ifdef ENABLE_FOV_OPTION
	float fFOV = m_pySystem.GetFOVLevel();
	m_pyGraphic.SetPerspective(fFOV, fAspect, 100.0, fFarClip);

	if (m_pyMiniMap.IsEven(fFOV))
		m_pyMiniMap.UpdateFieldOfView();
#else
	m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);
#endif