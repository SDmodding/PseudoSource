// File Line: 15
// RVA: 0xD09230
hkpMoppCode *__fastcall hkpMoppUtility::buildCode(
        hkpShapeContainer *shapeContainer,
        hkpMoppCompilerInput *moppInput,
        hkArray<hkpMoppCodeReindexedTerminal,hkContainerHeapAllocator> *reindexInfo)
{
  hkpMoppCode *v6; // rbx
  hkpMoppShapeMediator v8; // [rsp+20h] [rbp-58h] BYREF
  hkpMoppCachedShapeMediator v9; // [rsp+40h] [rbp-38h] BYREF

  if ( moppInput->m_cachePrimitiveExtents.m_bool )
  {
    hkpMoppCachedShapeMediator::hkpMoppCachedShapeMediator(&v9, shapeContainer);
    v6 = hkpMoppUtility::buildCodeInternal(&v9, shapeContainer, moppInput, reindexInfo);
    hkpMoppCachedShapeMediator::~hkpMoppCachedShapeMediator(&v9);
  }
  else
  {
    hkpMoppShapeMediator::hkpMoppShapeMediator(&v8, shapeContainer);
    v6 = hkpMoppUtility::buildCodeInternal(&v8, shapeContainer, moppInput, reindexInfo);
    hkpMoppShapeMediator::~hkpMoppShapeMediator(&v8);
  }
  if ( v6 )
    v6->m_buildType.m_storage = moppInput->m_enableChunkSubdivision.m_bool == 0;
  return v6;
}

// File Line: 44
// RVA: 0xD092E0
hkpMoppCode *__fastcall hkpMoppUtility::buildCodeInternal(
        hkpMoppMediator *mediator,
        hkpShapeContainer *shapeContainer,
        hkpMoppCompilerInput *moppInput,
        hkArray<hkpMoppCodeReindexedTerminal,hkContainerHeapAllocator> *reindexInfo)
{
  bool v7; // zf
  bool v8; // al
  char v9; // si
  __m128 m_quad; // xmm0
  unsigned int v11; // esi
  _QWORD **Value; // rax
  char *v13; // rax
  hkpMoppCompilerChunkInfo *m_chunkInfo; // rcx
  char *v15; // r15
  hkpMoppCode *v16; // rbx
  _QWORD **v17; // rax
  hkpMoppCostFunction::hkpMoppSplitCostParams v19; // [rsp+30h] [rbp-D0h] BYREF
  int v20; // [rsp+50h] [rbp-B0h] BYREF
  hkpMoppCodeReindexedTerminal *p; // [rsp+58h] [rbp-A8h]
  int numtoinsert; // [rsp+60h] [rbp-A0h]
  int v23; // [rsp+64h] [rbp-9Ch]
  void *v24; // [rsp+68h] [rbp-98h]
  int v25; // [rsp+70h] [rbp-90h]
  int v26; // [rsp+74h] [rbp-8Ch]
  __int64 v27; // [rsp+78h] [rbp-88h]
  int v28; // [rsp+80h] [rbp-80h]
  hkpMoppAssembler::hkpMoppAssemblerParams ap; // [rsp+90h] [rbp-70h] BYREF
  hkpMoppCompiler v30; // [rsp+C0h] [rbp-40h] BYREF

  hkpMoppCompiler::hkpMoppCompiler(&v30, HK_MOPP_MT_LANDSCAPE);
  hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams(&v19, HK_MOPP_MT_LANDSCAPE);
  v7 = moppInput->m_useShapeKeys.m_bool == 0;
  v19.m_weightPrimitiveSplit = 1.0;
  if ( v7 || moppInput->m_enableChunkSubdivision.m_bool )
    v19.m_weightPrimitiveIdSpread = 0.0;
  hkpMoppCompiler::setCostParams(&v30, &v19);
  v8 = moppInput->m_enableInterleavedBuilding.m_bool != 0;
  ap.m_absoluteFitToleranceOfTriangles = 1.0;
  ap.m_relativeFitToleranceOfInternalNodes = FLOAT_0_5;
  ap.m_absoluteFitToleranceOfInternalNodes = FLOAT_0_2;
  ap.m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f)_xmm;
  v7 = moppInput->m_enableChunkSubdivision.m_bool == 0;
  v9 = v8;
  ap.m_groupLevels = 5;
  if ( !v7 )
    v9 = 0;
  ap.m_interleavedBuildingEnabled.m_bool = 1;
  ap.m_relativeFitToleranceOfInternalNodes = hkpMoppCompilerInput::getRelativeFitToleranceOfInternalNodes(moppInput);
  ap.m_absoluteFitToleranceOfInternalNodes = hkpMoppCompilerInput::getAbsoluteFitToleranceOfInternalNodes(moppInput);
  ap.m_absoluteFitToleranceOfTriangles = hkpMoppCompilerInput::getAbsoluteFitToleranceOfTriangles(moppInput);
  m_quad = hkpMoppCompilerInput::getAbsoluteFitToleranceOfAxisAlignedTriangles(moppInput, (hkVector4f *)&v19)->m_quad;
  ap.m_interleavedBuildingEnabled.m_bool = v9;
  ap.m_absoluteFitToleranceOfAxisAlignedTriangles.m_quad = m_quad;
  hkpMoppCompiler::setAssemblerParams(&v30, &ap);
  hkpMoppSplitter::hkpMoppSplitParams::hkpMoppSplitParams(
    (hkpMoppSplitter::hkpMoppSplitParams *)&v19,
    HK_MOPP_MT_LANDSCAPE);
  if ( moppInput->m_enablePrimitiveSplitting.m_bool )
    LODWORD(v19.m_weightNumUnbalancedTriangles) = 50;
  else
    *(_QWORD *)&v19.m_weightPlaneDistance = 0i64;
  LODWORD(v19.m_weightPlanePosition) = 5;
  LOBYTE(v19.m_queryErrorTolerance) = v9;
  hkpMoppCompiler::setSplitParams(&v30, (hkpMoppSplitter::hkpMoppSplitParams *)&v19);
  v11 = hkpMoppCompiler::calculateRequiredBufferSize(&v30, mediator);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[10] + 8i64))(Value[10], v11);
  m_chunkInfo = (hkpMoppCompilerChunkInfo *)&v20;
  if ( !moppInput->m_enableChunkSubdivision.m_bool )
    m_chunkInfo = v30.m_chunkInfo;
  v30.m_chunkInfo = m_chunkInfo;
  v15 = v13;
  v20 = 512;
  p = 0i64;
  numtoinsert = 0;
  v23 = 0x80000000;
  v24 = 0i64;
  v25 = 0;
  v26 = 0x80000000;
  v27 = 0i64;
  v28 = 20;
  v16 = hkpMoppCompiler::compile(&v30, mediator, v13, v11);
  if ( reindexInfo )
    hkArrayBase<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost>::_insertAt(
      reindexInfo,
      &hkContainerHeapAllocator::s_alloc,
      0,
      p,
      numtoinsert);
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v17[10] + 16i64))(v17[10], v15, v11);
  v25 = 0;
  if ( v26 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v24, 16 * v26);
  v24 = 0i64;
  v26 = 0x80000000;
  numtoinsert = 0;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, p, 8 * v23);
  p = 0i64;
  v23 = 0x80000000;
  hkpMoppCompiler::~hkpMoppCompiler(&v30);
  return v16;
}

