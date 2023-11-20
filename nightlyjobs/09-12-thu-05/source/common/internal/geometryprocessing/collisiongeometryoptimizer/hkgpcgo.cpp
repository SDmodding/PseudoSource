// File Line: 14
// RVA: 0xCC1C60
void __fastcall hkgpCgo::optimize(hkgpCgo::Config *config, hkGeometry *geometry, hkgpCgo::IProgress *progress, hkArray<hkgpCgo::ClusterData,hkContainerHeapAllocator> *clusters)
{
  hkArray<hkgpCgo::ClusterData,hkContainerHeapAllocator> *v4; // r12
  hkgpCgo::IProgress *v5; // rsi
  hkGeometry *v6; // r15
  hkgpCgo::Config *v7; // rdi
  char v8; // r13
  int v9; // ebx
  __int128 v10; // xmm1
  __int128 v11; // xmm1
  char v12; // r14
  __int128 v13; // xmm6
  hkgpCgo::IProgressVtbl *v14; // rbx
  __int128 v15; // xmm2
  __int64 v16; // r8
  hkgpCgoInternal::EdgeInfo *v17; // rax
  hkgpCgoInternal::EdgeInfo *v18; // rax
  float v19; // xmm2_4
  _QWORD v20[2]; // [rsp+20h] [rbp-B8h]
  int v21; // [rsp+30h] [rbp-A8h]
  hkgpCgoInternal v22; // [rsp+40h] [rbp-98h]

  v4 = clusters;
  v5 = progress;
  v6 = geometry;
  v7 = config;
  v8 = 1;
  do
  {
    v9 = v6->m_triangles.m_size;
    v21 = v6->m_triangles.m_size;
    hkgpCgoInternal::hkgpCgoInternal(&v22);
    v10 = *(_OWORD *)&v7->m_maxAngle;
    *(_OWORD *)&v22.m_config.m_semantic = *(_OWORD *)&v7->m_semantic;
    *(_OWORD *)&v22.m_config.m_maxAngle = v10;
    v11 = *(_OWORD *)&v7->m_tracker;
    *(_OWORD *)&v22.m_config.m_updateThreshold = *(_OWORD *)&v7->m_updateThreshold;
    *(_OWORD *)&v22.m_config.m_tracker = v11;
    *(_QWORD *)&v22.m_config.m_maxAngleDrift = *(_QWORD *)&v7->m_minConvergence;
    hkgpCgoInternal::load(&v22, v6);
    if ( v8 && v4 )
      hkgpCgoInternal::analyze(&v22, v4);
    v12 = 0;
    v8 = 0;
    if ( hkgpCgoInternal::getBestEdge(&v22) )
    {
      do
      {
        if ( v7->m_maxDistance <= hkgpCgoInternal::getBestEdge(&v22)->m_error
          || SLODWORD(v22.m_geometry) <= v7->m_maxVertices )
        {
          break;
        }
        v13 = LODWORD(hkgpCgoInternal::getBestEdge(&v22)->m_error);
        while ( hkgpCgoInternal::getBestEdge(&v22) )
        {
          if ( v7->m_maxDistance <= hkgpCgoInternal::getBestEdge(&v22)->m_error )
            break;
          if ( SLODWORD(v22.m_geometry) <= v7->m_maxVertices )
            break;
          if ( v5 )
          {
            v14 = v5->vfptr;
            v15 = LODWORD(hkgpCgoInternal::getBestEdge(&v22)->m_error);
            LODWORD(v20[0]) = v22.m_topology.m_sets.m_data;
            if ( !((unsigned __int8 (__fastcall *)(hkgpCgo::IProgress *, hkgpCgoInternal *, __int64, _QWORD, _QWORD))v14->step)(
                    v5,
                    &v22,
                    v16,
                    LODWORD(v22.m_geometry),
                    v20[0]) )
              break;
          }
          v17 = hkgpCgoInternal::getBestEdge(&v22);
          hkgpCgoInternal::collapseEdge(&v22, v17);
          if ( hkgpCgoInternal::getBestEdge(&v22) )
          {
            v18 = hkgpCgoInternal::getBestEdge(&v22);
            v19 = v7->m_updateThreshold;
            if ( v19 > 0.0 && (float)(v18->m_error - *(float *)&v13) > v19 )
              break;
            *(float *)&v13 = v18->m_error;
          }
        }
        hkgpCgoInternal::update(&v22);
      }
      while ( hkgpCgoInternal::getBestEdge(&v22) );
      v9 = v21;
    }
    hkgpCgoInternal::bake(&v22);
    if ( v6->m_triangles.m_size < v9 )
    {
      v12 = 0;
      if ( v7->m_multiPass.m_bool )
        v12 = 1;
    }
    hkgpCgoInternal::~hkgpCgoInternal(&v22);
  }
  while ( v12 );
}

