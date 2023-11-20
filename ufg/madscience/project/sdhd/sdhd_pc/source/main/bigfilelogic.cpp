// File Line: 47
// RVA: 0x1501E30
const char *UFG::_dynamic_initializer_for__SYSTEM_NAMES__()
{
  const char *result; // rax

  SYSTEM_NAMES[0] = UFG::BigFileLogic::SYSTEM_BOOT;
  SYSTEM_NAMES[1] = (const char *)&UFG::BigFileLogic::SYSTEM_GLOBAL->mEnableStereo;
  SYSTEM_NAMES[2] = UFG::BigFileLogic::SYSTEM_UI;
  SYSTEM_NAMES[3] = UFG::BigFileLogic::SYSTEM_CHARACTERS;
  SYSTEM_NAMES[4] = UFG::BigFileLogic::SYSTEM_VEHICLES;
  SYSTEM_NAMES[5] = UFG::BigFileLogic::SYSTEM_ANIMATION;
  SYSTEM_NAMES[6] = UFG::BigFileLogic::SYSTEM_NISANIMATION;
  SYSTEM_NAMES[7] = UFG::BigFileLogic::SYSTEM_WORLD;
  SYSTEM_NAMES[8] = UFG::BigFileLogic::SYSTEM_GAMEPLAY;
  SYSTEM_NAMES[9] = UFG::BigFileLogic::SYSTEM_AUDIO;
  SYSTEM_NAMES[10] = UFG::BigFileLogic::SYSTEM_PARTS;
  SYSTEM_NAMES[11] = UFG::BigFileLogic::SYSTEM_PREFAB_DATA;
  result = UFG::BigFileLogic::SYSTEM_STREAMING_INSTALLER_PART_01;
  SYSTEM_NAMES[12] = UFG::BigFileLogic::SYSTEM_STREAMING_INSTALLER_PART_01;
  return result;
}

// File Line: 76
// RVA: 0x1501EF0
__int64 UFG::_dynamic_initializer_for__gBigFileSystemUsage__()
{
  return atexit(UFG::_dynamic_atexit_destructor_for__gBigFileSystemUsage__);
}

// File Line: 79
// RVA: 0x426AA0
__int64 __fastcall UFG::BigFileLogic::GetBigFileMode(const char *systemName, const char *subSystemName)
{
  const char *v2; // rdi
  int v3; // ebx
  UFG::qNode<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage> *v4; // rax

  v2 = subSystemName;
  v3 = UFG::qStringHashUpper32(systemName, 0xFFFFFFFF);
  if ( v2 )
    UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
  v4 = UFG::gBigFileSystemUsage.mNode.mNext;
  if ( (UFG::qList<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage,1,0> *)UFG::gBigFileSystemUsage.mNode.mNext == &UFG::gBigFileSystemUsage )
    return 0i64;
  while ( v3 != HIDWORD(v4[1].mPrev) )
  {
    v4 = v4->mNext;
    if ( v4 == (UFG::qNode<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage> *)&UFG::gBigFileSystemUsage )
      return 0i64;
  }
  return LODWORD(v4[1].mPrev);
}

// File Line: 98
// RVA: 0x426B10
char __fastcall UFG::BigFileLogic::IsBigFileEnabled(const char *systemName, const char *subSystemName)
{
  const char *v2; // rdi
  int v3; // ebx
  UFG::qNode<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage> *v4; // rcx
  char result; // al

  v2 = subSystemName;
  v3 = UFG::qStringHashUpper32(systemName, 0xFFFFFFFF);
  if ( v2 )
    UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
  v4 = UFG::gBigFileSystemUsage.mNode.mNext;
  if ( (UFG::qList<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage,1,0> *)UFG::gBigFileSystemUsage.mNode.mNext == &UFG::gBigFileSystemUsage )
    goto LABEL_6;
  while ( v3 != HIDWORD(v4[1].mPrev) )
  {
    v4 = v4->mNext;
    if ( v4 == (UFG::qNode<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage> *)&UFG::gBigFileSystemUsage )
      goto LABEL_6;
  }
  if ( (unsigned int)(LODWORD(v4[1].mPrev) - 1) > 1 )
LABEL_6:
    result = 0;
  else
    result = 1;
  return result;
}

// File Line: 107
// RVA: 0x426C10
void __fastcall UFG::BigFileLogic::ProcessBuildOptions(UFG::BuildLabOptions *buildlab_options)
{
  UFG::BuildLabOptions *v1; // r14
  const char **v2; // rdi
  signed __int64 v3; // rbp
  const char *v4; // rsi
  char *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage> *v9; // rax

  v1 = buildlab_options;
  v2 = SYSTEM_NAMES;
  v3 = 13i64;
  do
  {
    v4 = *v2;
    v5 = UFG::BuildLabOptions::GetValue(v1, *v2, 0i64);
    if ( (unsigned int)UFG::qStringCompareInsensitive(v5, UFG::BigFileLogic::BUILD_OPTION_BIG, -1) )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(v5, UFG::BigFileLogic::BUILD_OPTION_CREATE_BIG, -1) )
        goto LABEL_13;
      v8 = UFG::qMalloc(0x20ui64, "BigFileLogic", 0i64);
      v7 = v8;
      if ( v8 )
      {
        v8->mNext = v8;
        v8[1].mNext = v8;
        LODWORD(v8[2].mNext) = 2;
        HIDWORD(v8[2].mNext) = UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
        LODWORD(v7[3].mNext) = -1;
      }
      else
      {
        v7 = 0i64;
      }
      LODWORD(v7[2].mNext) = 1;
    }
    else
    {
      v6 = UFG::qMalloc(0x20ui64, "BigFileLogic", 0i64);
      v7 = v6;
      if ( v6 )
      {
        v6->mNext = v6;
        v6[1].mNext = v6;
        LODWORD(v6[2].mNext) = 2;
        HIDWORD(v6[2].mNext) = UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
        LODWORD(v7[3].mNext) = -1;
      }
      else
      {
        v7 = 0i64;
      }
      LODWORD(v7[2].mNext) = 2;
    }
    v9 = UFG::gBigFileSystemUsage.mNode.mPrev;
    UFG::gBigFileSystemUsage.mNode.mPrev->mNext = (UFG::qNode<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage> *)v7;
    v7->mNext = (UFG::allocator::free_link *)v9;
    v7[1].mNext = (UFG::allocator::free_link *)&UFG::gBigFileSystemUsage;
    UFG::gBigFileSystemUsage.mNode.mPrev = (UFG::qNode<UFG::BigFileSystemUsage,UFG::BigFileSystemUsage> *)v7;
LABEL_13:
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 129
// RVA: 0x426A30
UFG::qString *__fastcall UFG::BigFileLogic::GetBigFileIndexName(UFG::qString *result, const char *systemName, const char *subsystemName, const char *systemSuffix)
{
  const char *v4; // rax
  UFG::qString *v5; // rbx
  char *v6; // r9
  __int64 v8; // [rsp+20h] [rbp-18h]

  v4 = systemSuffix;
  v5 = result;
  LODWORD(v8) = 0;
  v6 = &customWorldMapCaption;
  if ( subsystemName )
  {
    if ( v4 )
      v6 = (char *)v4;
    UFG::qString::qString(result, "%s%s.bix", subsystemName, v6, v8, -2i64);
  }
  else
  {
    if ( v4 )
      v6 = (char *)v4;
    UFG::qString::qString(result, "%s%s.bix", systemName, v6, v8, -2i64);
  }
  return v5;
}

// File Line: 141
// RVA: 0x426B90
char __fastcall UFG::BigFileLogic::MountSystemBigFile(const char *systemName, const char *subSystemName, const char *systemSuffix)
{
  const char *v3; // rsi
  const char *v4; // rbx
  const char *v5; // rdi
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  hkgpIndexedMesh::EdgeBarrier *v7; // rcx
  bool v8; // al
  char v9; // bl
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v3 = systemSuffix;
  v4 = subSystemName;
  v5 = systemName;
  if ( !UFG::BigFileLogic::IsBigFileEnabled(systemName, subSystemName) )
    return 0;
  UFG::BigFileLogic::GetBigFileIndexName(&result, v5, v4, v3);
  v8 = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6);
  v9 = UFG::BigFileSystem::LoadBigFileIndex(result.mData, v8);
  UFG::qString::~qString(&result);
  return v9;
}

// File Line: 157
// RVA: 0x426D70
void __fastcall UFG::BigFileLogic::SetSystemBigFileEnabled(const char *systemName, const char *subSystemName, bool enabled)
{
  bool v3; // bl
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v3 = enabled;
  UFG::BigFileLogic::GetBigFileIndexName(&result, systemName, subSystemName, 0i64);
  UFG::BigFileSystem::SetBigFileState(result.mData, (UFG::BIGFileIndex::State)(v3 != 0));
  UFG::qString::~qString(&result);
}

// File Line: 164
// RVA: 0x426DC0
void __fastcall UFG::BigFileLogic::UnmountSystemBigFile(const char *systemName, const char *subSystemName)
{
  const char *v2; // rbx
  const char *v3; // rdi
  UFG *v4; // rcx
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = subSystemName;
  v3 = systemName;
  if ( UFG::BigFileLogic::IsBigFileEnabled(systemName, subSystemName) )
  {
    UFG::BigFileLogic::GetBigFileIndexName(&result, v3, v2, 0i64);
    UFG::qFileWaitForCompletion(v4);
    UFG::BigFileSystem::UnloadBigFileIndex(result.mData);
    UFG::qString::~qString(&result);
  }
}

