// File Line: 40
// RVA: 0x145AE90
__int64 UFG::_dynamic_initializer_for__UIBlipSymbol_caption__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("caption", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIBlipSymbol_caption, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__UIBlipSymbol_caption__);
}

// File Line: 58
// RVA: 0xCEFE0
UFG::UIMapBlipTypeManager *__fastcall UFG::UIMapBlipTypeManager::getInstance()
{
  UFG::UIMapBlipTypeManager *result; // rax
  UFG::UIMapBlipTypeManager *v1; // rax

  result = sUIMapBlipTypeManager;
  if ( !sUIMapBlipTypeManager )
  {
    v1 = (UFG::UIMapBlipTypeManager *)UFG::qMemoryPool::Allocate(
                                        &gScaleformMemoryPool,
                                        (unsigned int)((_DWORD)sUIMapBlipTypeManager + 32),
                                        "UIMapBlipTypeManager",
                                        0i64,
                                        1u);
    if ( v1 )
    {
      v1->mData.p = 0i64;
      *(_QWORD *)&v1->mData.size = 0i64;
      v1->mNumTypes = 0;
      v1->mPSSetData = 0i64;
    }
    else
    {
      v1 = 0i64;
    }
    sUIMapBlipTypeManager = v1;
    UFG::UIMapBlipTypeManager::Init(v1);
    result = sUIMapBlipTypeManager;
  }
  return result;
}

// File Line: 71
// RVA: 0xCEF00
bool __fastcall UFG::fnSortBlipTypeSets(UFG::qPropertySet *const *a, UFG::qPropertySet *const *b)
{
  UFG::qPropertySet **v2; // rdi
  char *v3; // rbx
  char *v4; // rdi

  v2 = (UFG::qPropertySet **)b;
  v3 = PropertyUtils::Get<char const *>(*a, (UFG::qSymbol *)&UIBlipSymbol_typeName.mUID, DEPTH_RECURSE);
  v4 = PropertyUtils::Get<char const *>(*v2, (UFG::qSymbol *)&UIBlipSymbol_typeName.mUID, DEPTH_RECURSE);
  LODWORD(v3) = UFG::qStringHashUpper32(v3, 0xFFFFFFFF);
  return (unsigned int)v3 < (unsigned int)UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
}

// File Line: 82
// RVA: 0xC5210
void __fastcall UFG::UIMapBlipTypeManager::Init(UFG::UIMapBlipTypeManager *this)
{
  UFG::UIMapBlipTypeManager *v1; // r14
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v3; // rax
  UFG::qPropertyList *v4; // rax
  unsigned int v5; // edi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  char *v10; // r15
  unsigned int v11; // esi
  unsigned int v12; // er12
  unsigned int v13; // er13
  UFG::qPropertyList *v14; // r14
  char *v15; // rax
  unsigned int v16; // ecx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  unsigned __int64 v19; // rax
  char *v20; // rax
  __int64 v21; // r12
  _QWORD *v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rsi
  UFG::qPropertySet *v25; // rbx
  bool *v26; // rax
  char *v27; // rcx
  bool *v28; // rax
  UFG::qSymbol *v29; // rcx
  bool *v30; // rax
  unsigned int *v31; // rcx
  bool *v32; // rax
  __int64 *v33; // rcx
  float *v34; // rax
  float *v35; // rcx
  float v36; // xmm7_4
  unsigned int *v37; // rax
  int *v38; // rcx
  unsigned int v39; // er12
  unsigned int *v40; // rax
  int *v41; // rcx
  unsigned int v42; // er13
  unsigned int *v43; // rax
  int *v44; // rcx
  __int64 v45; // rax
  bool *v46; // rax
  char *v47; // rcx
  bool *v48; // rax
  char *v49; // rcx
  bool *v50; // rax
  bool *v51; // rcx
  float *v52; // rax
  float *v53; // rcx
  float v54; // xmm8_4
  bool *v55; // rax
  char *v56; // rdx
  bool *v57; // rax
  char *v58; // rdx
  UFG::qSymbol *v59; // rax
  unsigned int v60; // ebx
  UFG::UIHKMinimapBlipType *v61; // rdi
  __int64 v62; // rdi
  UFG::UIHKMinimapBlipType *v63; // rcx
  UFG::UIHKMinimapBlipType *v64; // rcx
  char v65; // [rsp+1h] [rbp-80h]
  char v66; // [rsp+2h] [rbp-7Fh]
  char v67; // [rsp+3h] [rbp-7Eh]
  char v68; // [rsp+4h] [rbp-7Dh]
  char v69; // [rsp+5h] [rbp-7Ch]
  __int64 v70; // [rsp+8h] [rbp-79h]
  char *v71; // [rsp+10h] [rbp-71h]
  float v72; // [rsp+18h] [rbp-69h]
  float v73; // [rsp+1Ch] [rbp-65h]
  int v74; // [rsp+20h] [rbp-61h]
  unsigned int v75; // [rsp+24h] [rbp-5Dh]
  int v76; // [rsp+28h] [rbp-59h]
  int v77; // [rsp+2Ch] [rbp-55h]
  __int64 v78; // [rsp+30h] [rbp-51h]
  UFG::qSymbolUC v79; // [rsp+38h] [rbp-49h]
  char v80; // [rsp+3Ch] [rbp-45h]
  char v81; // [rsp+3Dh] [rbp-44h]
  char v82; // [rsp+3Eh] [rbp-43h]
  char v83; // [rsp+3Fh] [rbp-42h]
  __int64 v84; // [rsp+40h] [rbp-41h]
  UFG::qSymbol *v85; // [rsp+48h] [rbp-39h]
  char *pszSymbolString; // [rsp+50h] [rbp-31h]
  char *text; // [rsp+58h] [rbp-29h]
  __int64 v88; // [rsp+60h] [rbp-21h]
  UFG::UIMapBlipTypeManager *v89; // [rsp+E8h] [rbp+67h]
  UFG::qSymbol result[2]; // [rsp+F0h] [rbp+6Fh]
  unsigned int v91; // [rsp+F8h] [rbp+77h]
  char *v92; // [rsp+100h] [rbp+7Fh]
  __int64 v93; // [rsp+130h] [rbp+AFh]

  v88 = -2i64;
  v1 = this;
  v2 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v93, "UI-MinimapBlipTypes");
  v3 = UFG::PropertySetManager::GetPropertySet(v2);
  v1->mPSSetData = v3;
  if ( v3 )
  {
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&UIBlipSymbol_blipTypes.mUID, DEPTH_RECURSE);
    *(_QWORD *)&result[0].mUID = v4;
    if ( v4 )
    {
      v5 = v4->mNumElements;
      v91 = v5;
      v6 = v1->mData.size;
      if ( (signed int)(v5 - v1->mData.size) <= 0 )
      {
        v9 = v1->mData.size - v5;
        if ( v1->mData.size != v5 )
        {
          if ( v9 < v6 )
            v1->mData.size = v6 - v9;
          else
            v1->mData.size = 0;
        }
      }
      else
      {
        v7 = v1->mData.capacity;
        if ( v5 > v7 )
        {
          if ( v7 )
            v8 = 2 * v7;
          else
            v8 = 1;
          for ( ; v8 < v5; v8 *= 2 )
            ;
          if ( v8 - v5 > 0x10000 )
            v8 = v5 + 0x10000;
          UFG::qArray<UFG::UIHKMinimapBlipType,0>::Reallocate(&v1->mData, v8, "UIMapBlipTypeManager");
        }
        v1->mData.size = v5;
      }
      v1->mNumTypes = v5;
      v10 = 0i64;
      v71 = 0i64;
      v11 = 0;
      v70 = 0i64;
      v12 = 0;
      v13 = 0;
      if ( v5 )
      {
        v14 = *(UFG::qPropertyList **)&result[0].mUID;
        do
        {
          v15 = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v13);
          if ( v15 && *(_QWORD *)v15 )
            v92 = &v15[*(_QWORD *)v15];
          else
            v92 = 0i64;
          v16 = v11;
          v17 = v11 + 1;
          if ( v11 + 1 > v12 )
          {
            v18 = 1;
            if ( v12 )
              v18 = 2 * v12;
            for ( ; v18 < v17; v18 *= 2 )
              ;
            if ( v18 <= 2 )
              v18 = 2;
            if ( v18 - v17 > 0x10000 )
              v18 = v11 + 65537;
            if ( v18 != v11 )
            {
              v19 = 8i64 * v18;
              if ( !is_mul_ok(v18, 8ui64) )
                v19 = -1i64;
              v20 = UFG::qMalloc(v19, "qArray.Add", 0i64);
              v21 = (__int64)v20;
              if ( v10 )
              {
                if ( v11 )
                {
                  v22 = v20;
                  v23 = v11;
                  do
                  {
                    *v22 = *(_QWORD *)((char *)v22 + v10 - v20);
                    ++v22;
                    --v23;
                  }
                  while ( v23 );
                }
                operator delete[](v10);
              }
              v10 = (char *)v21;
              v71 = (char *)v21;
              v12 = v18;
              HIDWORD(v70) = v18;
              v16 = v11;
            }
          }
          ++v11;
          LODWORD(v70) = v17;
          *(_QWORD *)&v10[8 * v16] = v92;
          ++v13;
          v5 = v91;
        }
        while ( v13 < v91 );
        v1 = v89;
      }
      UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
        (UFG::qPropertySet **)v10,
        (UFG::qPropertySet **)&v10[8 * ((signed int)v11 - 1i64)],
        UFG::fnSortBlipTypeSets);
      if ( v5 )
      {
        LOBYTE(v89) = 0;
        LOBYTE(result[0].mUID) = 0;
        LOBYTE(v91) = 1;
        LOBYTE(v92) = 0;
        v72 = FLOAT_150_0;
        v74 = 0;
        v77 = 0;
        v76 = 0;
        v69 = 0;
        v68 = 1;
        HIBYTE(v79.mUID) = 0;
        v73 = FLOAT_0_80000001;
        v65 = 0;
        v81 = 0;
        v24 = 0i64;
        v78 = 0i64;
        v84 = v5;
        do
        {
          v25 = *(UFG::qPropertySet **)v10;
          pszSymbolString = PropertyUtils::Get<char const *>(
                              *(UFG::qPropertySet **)v10,
                              (UFG::qSymbol *)&UIBlipSymbol_typeName.mUID,
                              DEPTH_RECURSE);
          v85 = UFG::qPropertySet::Get<UFG::qSymbol>(v25, (UFG::qSymbol *)&UIBlipSymbol_icon.mUID, DEPTH_RECURSE);
          text = UFG::qPropertySet::Get<char const *>(v25, (UFG::qSymbol *)&UIBlipSymbol_caption.mUID, DEPTH_RECURSE);
          v26 = UFG::qPropertySet::Get<bool>(v25, (UFG::qSymbol *)&UIBlipSymbol_isWorldMapOnly.mUID, DEPTH_RECURSE);
          v27 = (char *)&v89;
          if ( v26 )
            v27 = (char *)v26;
          v67 = *v27;
          v28 = UFG::qPropertySet::Get<bool>(v25, (UFG::qSymbol *)&UIBlipSymbol_isObjective.mUID, DEPTH_RECURSE);
          v29 = result;
          if ( v28 )
            v29 = (UFG::qSymbol *)v28;
          v83 = v29->mUID;
          v30 = UFG::qPropertySet::Get<bool>(v25, (UFG::qSymbol *)&UIBlipSymbol_isDistanceFiltered.mUID, DEPTH_RECURSE);
          v31 = &v91;
          if ( v30 )
            v31 = (unsigned int *)v30;
          BYTE1(v79.mUID) = *(_BYTE *)v31;
          v32 = UFG::qPropertySet::Get<bool>(
                  v25,
                  (UFG::qSymbol *)&UIBlipSymbol_isDistanceFilteredOnWorldMap.mUID,
                  DEPTH_RECURSE);
          v33 = (__int64 *)&v92;
          if ( v32 )
            v33 = (__int64 *)v32;
          BYTE2(v79.mUID) = *(_BYTE *)v33;
          v34 = UFG::qPropertySet::Get<float>(v25, (UFG::qSymbol *)&UIBlipSymbol_filterDistance.mUID, DEPTH_RECURSE);
          v35 = &v72;
          if ( v34 )
            v35 = v34;
          v36 = *v35;
          v37 = UFG::qPropertySet::Get<unsigned long>(
                  v25,
                  (UFG::qSymbol *)&UIBlipSymbol_radiusColor.mUID,
                  DEPTH_RECURSE);
          v38 = &v74;
          if ( v37 )
            v38 = (int *)v37;
          v39 = *v38;
          v40 = UFG::qPropertySet::Get<unsigned long>(
                  v25,
                  (UFG::qSymbol *)&UIBlipSymbol_innerRadiusColor.mUID,
                  DEPTH_RECURSE);
          v41 = &v77;
          if ( v40 )
            v41 = (int *)v40;
          v42 = *v41;
          v43 = UFG::qPropertySet::Get<unsigned long>(v25, (UFG::qSymbol *)&UIBlipSymbol_drawDepth.mUID, DEPTH_RECURSE);
          v44 = &v76;
          if ( v43 )
            v44 = (int *)v43;
          v45 = (unsigned int)*v44;
          v46 = UFG::qPropertySet::Get<bool>(v25, (UFG::qSymbol *)&UIBlipSymbol_isHiddenIndoors.mUID, DEPTH_RECURSE);
          v47 = &v69;
          if ( v46 )
            v47 = (char *)v46;
          v80 = *v47;
          v48 = UFG::qPropertySet::Get<bool>(v25, (UFG::qSymbol *)&UIBlipSymbol_hasAltitude.mUID, DEPTH_RECURSE);
          v49 = &v68;
          if ( v48 )
            v49 = (char *)v48;
          v82 = *v49;
          v50 = UFG::qPropertySet::Get<bool>(
                  v25,
                  (UFG::qSymbol *)&UIBlipSymbol_isWorldMapZoomFiltered.mUID,
                  DEPTH_RECURSE);
          v51 = (bool *)&v79.mUID + 3;
          if ( v50 )
            v51 = v50;
          LOBYTE(v84) = *v51;
          v52 = UFG::qPropertySet::Get<float>(v25, (UFG::qSymbol *)&UIBlipSymbol_worldMapZoomFilter.mUID, DEPTH_RECURSE);
          v53 = &v73;
          if ( v52 )
            v53 = v52;
          v54 = *v53;
          v55 = UFG::qPropertySet::Get<bool>(
                  v25,
                  (UFG::qSymbol *)&UIBlipSymbol_isProximityUnlockable.mUID,
                  DEPTH_RECURSE);
          v56 = &v65;
          if ( v55 )
            v56 = (char *)v55;
          v66 = *v56;
          v57 = UFG::qPropertySet::Get<bool>(v25, (UFG::qSymbol *)&UIBlipSymbol_hideOnBorder.mUID, DEPTH_RECURSE);
          v58 = &v81;
          if ( v57 )
            v58 = (char *)v57;
          LOBYTE(v79.mUID) = *v58;
          v59 = UFG::qPropertySet::Get<UFG::qSymbol>(
                  v25,
                  (UFG::qSymbol *)&UIBlipSymbol_progressionFlow.mUID,
                  DEPTH_RECURSE);
          if ( v59 )
            v60 = v59->mUID;
          else
            v60 = qSymbol_none.mUID;
          v61 = v1->mData.p;
          v61[v24].TypeNameSymbol = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&v79, pszSymbolString)->mUID;
          v1->mData.p[v24].Icon = (UFG::qSymbol)v85->mUID;
          v62 = v78;
          UFG::qString::Set((UFG::qString *)((char *)&v1->mData.p->Caption + v78), text);
          v1->mData.p[v24].IsWorldMapOnly = v67;
          v1->mData.p[v24].IsObjective = v83;
          *(_WORD *)&v1->mData.p[v24].IsDistanceFiltered = *(_WORD *)((char *)&v79.mUID + 1);
          v1->mData.p[v24].FilterDistance = v36;
          v63 = v1->mData.p;
          v63[v24].RadiusColor.r = (float)(v39 >> 24) * 0.0039215689;
          v63[v24].RadiusColor.g = (float)BYTE2(v39) * 0.0039215689;
          v63[v24].RadiusColor.b = (float)BYTE1(v39) * 0.0039215689;
          v63[v24].RadiusColor.a = (float)(unsigned __int8)v39 * 0.0039215689;
          v64 = v1->mData.p;
          v64[v24].InnerRadiusColor.r = (float)(v42 >> 24) * 0.0039215689;
          v64[v24].InnerRadiusColor.g = (float)BYTE2(v42) * 0.0039215689;
          v64[v24].InnerRadiusColor.b = (float)BYTE1(v42) * 0.0039215689;
          v64[v24].InnerRadiusColor.a = (float)(unsigned __int8)v42 * 0.0039215689;
          v1->mData.p[v24].DrawDepth = v75;
          v1->mData.p[v24].IsHiddenIndoors = v80;
          v1->mData.p[v24].HasAltitude = v82;
          v1->mData.p[v24].IsWorldMapZoomFiltered = v84;
          v1->mData.p[v24].WorldMapZoomFilter = v54;
          v1->mData.p[v24].IsProximityUnlockable = v66;
          v1->mData.p[v24].HideOnBorder = v79.mUID;
          v1->mData.p[v24].ProgressionFlow.mUID = v60;
          v78 = v62 + 112;
          v10 += 8;
          ++v24;
          --v84;
        }
        while ( v84 );
        v10 = v71;
      }
      if ( v10 )
        operator delete[](v10);
    }
  }
}

// File Line: 197
// RVA: 0xC4A90
UFG::UIHKMinimapBlipType *__fastcall UFG::UIMapBlipTypeManager::GetType(UFG::UIMapBlipTypeManager *this, UFG::qSymbolUC *typeName)
{
  unsigned int v2; // er10
  unsigned int v4; // er8
  __int64 v5; // r11
  UFG::UIHKMinimapBlipType *v6; // rbx
  unsigned int v7; // edx
  unsigned int v8; // er8
  unsigned int v9; // eax
  unsigned int v10; // er9

  v2 = typeName->mUID;
  if ( typeName->mUID == -1 )
    return 0i64;
  v4 = this->mNumTypes;
  v5 = 0i64;
  if ( !v4 )
    return (UFG::UIHKMinimapBlipType *)v5;
  v6 = this->mData.p;
  v7 = 0;
  v8 = v4 - 1;
  while ( 1 )
  {
    v9 = v7 + ((v8 - v7) >> 1);
    v10 = v6[v7 + ((v8 - v7) >> 1)].TypeNameSymbol.mUID;
    if ( v10 >= v2 )
      break;
    v7 = v9 + 1;
LABEL_9:
    if ( v7 > v8 )
      return 0i64;
  }
  if ( v10 > v2 )
  {
    v8 = v9 - 1;
    goto LABEL_9;
  }
  return &v6[v9];
}

// File Line: 241
// RVA: 0xC5DB0
UFG::UIHKMinimapBlipType *__fastcall UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(UFG::qSymbolUC *iconType)
{
  UFG::qSymbolUC *v1; // rbx
  UFG::UIMapBlipTypeManager *v2; // rax
  UFG::UIHKMinimapBlipType *result; // rax
  UFG::UIHKMinimapBlipType *v4; // rbx
  UFG::ProgressionTracker *v5; // rax

  v1 = iconType;
  v2 = UFG::UIMapBlipTypeManager::getInstance();
  result = UFG::UIMapBlipTypeManager::GetType(v2, v1);
  v4 = result;
  if ( result )
    result = (UFG::UIHKMinimapBlipType *)(result->ProgressionFlow.mUID == qSymbol_none.mUID
                                       || (v5 = UFG::ProgressionTracker::Instance(),
                                           v4->ProgressionFlow.mUID == UFG::ProgressionTracker::GetActiveFlow(v5)->mUID));
  return result;
}

