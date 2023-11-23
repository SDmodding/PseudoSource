// File Line: 14
// RVA: 0xCC1C60
void __fastcall hkgpCgo::optimize(
        hkgpCgo::Config *config,
        hkGeometry *geometry,
        hkgpCgo::IProgress *progress,
        hkArray<hkgpCgo::ClusterData,hkContainerHeapAllocator> *clusters)
{
  char v8; // r13
  int m_size; // ebx
  __int128 v10; // xmm1
  __int128 v11; // xmm1
  bool v12; // r14
  float m_error; // xmm6_4
  hkgpCgo::IProgressVtbl *vfptr; // rbx
  __int64 v15; // r8
  hkgpCgoInternal::EdgeInfo *BestEdge; // rax
  hkgpCgoInternal::EdgeInfo *v17; // rax
  float m_updateThreshold; // xmm2_4
  int v19; // [rsp+30h] [rbp-A8h]
  hkgpCgoInternal v20; // [rsp+40h] [rbp-98h] BYREF

  v8 = 1;
  do
  {
    m_size = geometry->m_triangles.m_size;
    v19 = m_size;
    hkgpCgoInternal::hkgpCgoInternal(&v20);
    v10 = *(_OWORD *)&config->m_maxAngle;
    *(_OWORD *)&v20.m_config.m_semantic = *(_OWORD *)&config->m_semantic;
    *(_OWORD *)&v20.m_config.m_maxAngle = v10;
    v11 = *(_OWORD *)&config->m_tracker;
    *(_OWORD *)&v20.m_config.m_updateThreshold = *(_OWORD *)&config->m_updateThreshold;
    *(_OWORD *)&v20.m_config.m_tracker = v11;
    *(_QWORD *)&v20.m_config.m_maxAngleDrift = *(_QWORD *)&config->m_minConvergence;
    hkgpCgoInternal::load(&v20, geometry);
    if ( v8 && clusters )
      hkgpCgoInternal::analyze(&v20, clusters);
    v12 = 0;
    v8 = 0;
    if ( hkgpCgoInternal::getBestEdge(&v20) )
    {
      do
      {
        if ( config->m_maxDistance <= hkgpCgoInternal::getBestEdge(&v20)->m_error
          || SLODWORD(v20.m_geometry) <= config->m_maxVertices )
        {
          break;
        }
        m_error = hkgpCgoInternal::getBestEdge(&v20)->m_error;
        while ( hkgpCgoInternal::getBestEdge(&v20) )
        {
          if ( config->m_maxDistance <= hkgpCgoInternal::getBestEdge(&v20)->m_error )
            break;
          if ( SLODWORD(v20.m_geometry) <= config->m_maxVertices )
            break;
          if ( progress )
          {
            vfptr = progress->vfptr;
            hkgpCgoInternal::getBestEdge(&v20);
            if ( !((unsigned __int8 (__fastcall *)(hkgpCgo::IProgress *, hkgpCgoInternal *, __int64, _QWORD, _DWORD))vfptr->step)(
                    progress,
                    &v20,
                    v15,
                    LODWORD(v20.m_geometry),
                    v20.m_topology.m_sets.m_data) )
              break;
          }
          BestEdge = hkgpCgoInternal::getBestEdge(&v20);
          hkgpCgoInternal::collapseEdge(&v20, BestEdge);
          if ( hkgpCgoInternal::getBestEdge(&v20) )
          {
            v17 = hkgpCgoInternal::getBestEdge(&v20);
            m_updateThreshold = config->m_updateThreshold;
            if ( m_updateThreshold > 0.0 && (float)(v17->m_error - m_error) > m_updateThreshold )
              break;
            m_error = v17->m_error;
          }
        }
        hkgpCgoInternal::update(&v20);
      }
      while ( hkgpCgoInternal::getBestEdge(&v20) );
      m_size = v19;
    }
    hkgpCgoInternal::bake(&v20);
    if ( geometry->m_triangles.m_size < m_size )
      v12 = config->m_multiPass.m_bool != 0;
    hkgpCgoInternal::~hkgpCgoInternal(&v20);
  }
  while ( v12 );
}

