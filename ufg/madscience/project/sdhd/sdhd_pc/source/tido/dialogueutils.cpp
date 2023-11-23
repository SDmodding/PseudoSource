// File Line: 37
// RVA: 0x1554F40
__int64 dynamic_initializer_for__UFG::VoiceProfileManager::sm_voiceProfiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VoiceProfileManager::sm_voiceProfiles__);
}

// File Line: 38
// RVA: 0x1554F70
__int64 dynamic_initializer_for__UFG::VoiceProfileManager::sm_voiceTags__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VoiceProfileManager::sm_voiceTags.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VoiceProfileManager::sm_voiceTags__);
}

// File Line: 46
// RVA: 0x5A29A0
void UFG::VoiceProfileManager::LoadVoiceProfiles(void)
{
  UFG::qPropertyList *v0; // rcx
  unsigned int v1; // r12d
  char *ValuePtr; // rax
  UFG::qPropertySet *v3; // rbx
  char *v4; // rsi
  UFG::qPropertySet *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int v7; // r15d
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r14
  unsigned int v10; // edi
  UFG::qSymbol *v11; // rsi
  UFG::qBaseTreeRB *v12; // rax
  UFG::allocator::free_link *p_mCount; // rbx
  unsigned int v14; // ecx
  UFG::qBaseNodeRB *v15; // rdx
  unsigned int v16; // eax
  unsigned int mNext_high; // edx
  UFG::allocator::free_link *v18; // rdi
  unsigned int v19; // ecx
  unsigned int *p; // rdx
  UFG::qSymbol result; // [rsp+30h] [rbp-78h] BYREF
  unsigned int mNumElements; // [rsp+34h] [rbp-74h]
  char *v23; // [rsp+38h] [rbp-70h]
  UFG::qPropertyList *v24; // [rsp+40h] [rbp-68h]
  __int64 v25; // [rsp+48h] [rbp-60h]
  UFG::allocator::free_link *v26; // [rsp+50h] [rbp-58h]
  AMD_HD3D **v27; // [rsp+58h] [rbp-50h]
  AMD_HD3D *v28; // [rsp+B0h] [rbp+8h] BYREF
  UFG::qWiseSymbol v29; // [rsp+B8h] [rbp+10h] BYREF
  unsigned int mUID; // [rsp+C0h] [rbp+18h] BYREF
  UFG::allocator::free_link *v31; // [rsp+C8h] [rbp+20h]

  v25 = -2i64;
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&UFG::VoiceProfileManager::sm_voiceProfiles);
  UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[1] = 0i64;
  UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[0] = 0i64;
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&UFG::VoiceProfileManager::sm_voiceTags);
  UFG::qSymbol::create_from_string(&result, "Audio-Voices");
  UFG::VoiceProfileManager::sm_propertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v0 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         UFG::VoiceProfileManager::sm_propertySet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_VoiceProfiles,
         DEPTH_RECURSE);
  v24 = v0;
  mNumElements = v0->mNumElements;
  v1 = 0;
  for ( LODWORD(v31) = 0; v1 < mNumElements; v0 = v24 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v0, 0x1Au, v1);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v3 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v3 = 0i64;
    v4 = PropertyUtils::Get<char const *>(v3, (UFG::qArray<unsigned long,0> *)&TiDoSym_WwiseVoiceId, DEPTH_RECURSE);
    v23 = v4;
    UFG::qWiseSymbol::create_from_string(&v29, v4);
    v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(v3, (UFG::qArray<unsigned long,0> *)&TiDoSym_Tags, DEPTH_RECURSE);
    if ( v5 )
    {
      v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v5, (UFG::qArray<unsigned long,0> *)&TiDoSym_Tags, DEPTH_RECURSE);
      v7 = v6->mNumElements;
      v8 = 0i64;
      v9 = 0i64;
      v10 = 0;
      if ( v7 )
      {
        do
        {
          v11 = UFG::qPropertyList::Get<UFG::qSymbol>(v6, v10);
          if ( !v11->mUID
            || (v12 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v11->mUID)) == 0i64
            || (p_mCount = (UFG::allocator::free_link *)&v12[-1].mCount, v12 == (UFG::qBaseTreeRB *)8) )
          {
            p_mCount = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "VoiceTag", 0i64, 1u);
            v26 = p_mCount;
            if ( p_mCount )
            {
              v27 = (AMD_HD3D **)&mUID;
              ++UFG::VoiceTag::sm_idxCnt;
              mUID = v11->mUID;
              v14 = UFG::VoiceTag::sm_idxCnt;
              v15 = 0i64;
              p_mCount[1].mNext = 0i64;
              p_mCount[2].mNext = 0i64;
              p_mCount[3].mNext = 0i64;
              p_mCount->mNext = (UFG::allocator::free_link *)&UFG::VoiceTag::`vftable;
              v16 = mUID;
              LODWORD(p_mCount[5].mNext) = mUID;
              HIDWORD(p_mCount[5].mNext) = v14;
              LODWORD(p_mCount[4].mNext) = v16;
            }
            else
            {
              v15 = 0i64;
              p_mCount = 0i64;
            }
            if ( p_mCount )
              v15 = (UFG::qBaseNodeRB *)&p_mCount[1];
            UFG::qBaseTreeRB::Add(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v15);
          }
          mNext_high = HIDWORD(p_mCount[5].mNext);
          if ( mNext_high >= 0x40 )
            v8 |= 1i64 << ((unsigned __int8)mNext_high - 64);
          else
            v9 |= 1i64 << mNext_high;
          if ( mNext_high >= 0x40 )
            UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[1] |= 1i64 << ((unsigned __int8)mNext_high - 64);
          else
            UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[0] |= 1i64 << mNext_high;
          ++v10;
        }
        while ( v10 < v7 );
        v1 = (unsigned int)v31;
        v4 = v23;
      }
      v18 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x78ui64, "VoiceProfile", 0i64, 1u);
      v31 = v18;
      if ( v18 )
      {
        LODWORD(v28) = v29;
        _((AMD_HD3D *)v29.mUID);
        v27 = &v28;
        v18[1].mNext = 0i64;
        v18[2].mNext = 0i64;
        v18[3].mNext = 0i64;
        v18->mNext = (UFG::allocator::free_link *)&UFG::VoiceProfile::`vftable;
        LODWORD(v18[5].mNext) = (_DWORD)v28;
        _((AMD_HD3D *)(unsigned int)v28);
        HIDWORD(v18[5].mNext) = -1;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        UFG::qString::qString((UFG::qString *)&v18[6]);
        LODWORD(v18[11].mNext) = 50;
        v18[12].mNext = (UFG::allocator::free_link *)v9;
        v18[13].mNext = (UFG::allocator::free_link *)v8;
        LODWORD(v18[4].mNext) = (_DWORD)v28;
        UFG::qString::Set((UFG::qString *)&v18[6], &customCaption);
        LOBYTE(v18[14].mNext) |= 1u;
        _((AMD_HD3D *)(unsigned int)v28);
      }
      else
      {
        v18 = 0i64;
      }
      UFG::qString::Set((UFG::qString *)&v18[6], v4);
      UFG::VoiceProfileManager::SetTagVoice((UFG::VoiceProfile *)v18);
      v19 = 0;
      if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size )
      {
        p = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p;
        while ( v29.mUID != *p )
        {
          ++v19;
          ++p;
          if ( v19 >= UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size )
            goto LABEL_32;
        }
      }
      else
      {
LABEL_32:
        v19 = -1;
      }
      LOBYTE(v18[14].mNext) &= ~2u;
      LOBYTE(v18[14].mNext) |= 2 * (v19 != -1);
      UFG::qBaseTreeRB::Add(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, (UFG::qBaseNodeRB *)&v18[1]);
    }
    _((AMD_HD3D *)v29.mUID);
    LODWORD(v31) = ++v1;
  }
}

// File Line: 123
// RVA: 0x5AB370
void __fastcall UFG::VoiceProfileManager::SetTagVoice(UFG::VoiceProfile *profile)
{
  unsigned int v2; // eax
  int *v3; // rdi
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // r14
  UFG::qBaseTreeRB *v6; // rax
  int *v7; // rbp
  UFG::qBaseTreeRB *v8; // rax
  int *v9; // rsi
  UFG::qBaseTreeRB *v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int8 v12; // r10
  unsigned __int64 v13; // rax
  bool v14; // r9
  unsigned __int64 v15; // rax
  bool v16; // r8
  unsigned __int64 v17; // rax
  UFG::qWiseSymbol *v18; // rdx
  int v19; // eax
  UFG::qWiseSymbol *p_m_wwiseTagsUid; // rcx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax

  v2 = _S36_1;
  if ( (_S36_1 & 1) == 0 )
  {
    _S36_1 |= 1u;
    UFG::qWiseSymbol::create_from_string(&girl_1, "girl_1");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__girl_1__);
    v2 = _S36_1;
  }
  if ( (v2 & 2) == 0 )
  {
    _S36_1 = v2 | 2;
    UFG::qWiseSymbol::create_from_string(&girl_2, "girl_2");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__girl_2__);
    v2 = _S36_1;
  }
  if ( (v2 & 4) == 0 )
  {
    _S36_1 = v2 | 4;
    UFG::qWiseSymbol::create_from_string(&man_1, "man_1");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__man_1__);
    v2 = _S36_1;
  }
  if ( (v2 & 8) == 0 )
  {
    _S36_1 = v2 | 8;
    UFG::qWiseSymbol::create_from_string(&man_2, "man_2");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__man_2__);
    v2 = _S36_1;
  }
  if ( (v2 & 0x10) == 0 )
  {
    _S36_1 = v2 | 0x10;
    UFG::qWiseSymbol::create_from_string(&old_man, "old_man");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__old_man__);
    v2 = _S36_1;
  }
  if ( (v2 & 0x20) == 0 )
  {
    _S36_1 = v2 | 0x20;
    UFG::qWiseSymbol::create_from_string(&old_lady, "old_lady");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__old_lady__);
    v2 = _S36_1;
  }
  if ( (v2 & 0x40) == 0 )
  {
    _S36_1 = v2 | 0x40;
    UFG::qWiseSymbol::create_from_string(&thug_3, "thug_3");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__thug_3__);
    v2 = _S36_1;
  }
  if ( (v2 & 0x80u) == 0 )
  {
    _S36_1 = v2 | 0x80;
    UFG::qWiseSymbol::create_from_string(&thug_1, "thug_1");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__thug_1__);
    v2 = _S36_1;
  }
  if ( (v2 & 0x100) == 0 )
  {
    _S36_1 = v2 | 0x100;
    UFG::qWiseSymbol::create_from_string(&thug_4, "thug_4");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__thug_4__);
    v2 = _S36_1;
  }
  if ( (v2 & 0x200) == 0 )
  {
    _S36_1 = v2 | 0x200;
    UFG::qWiseSymbol::create_from_string(&thug_2, "thug_2");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__thug_2__);
  }
  v3 = 0i64;
  if ( !qSymbol_Male.mUID
    || (v4 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Male.mUID),
        p_mCount = &v4[-1].mCount,
        !v4) )
  {
    p_mCount = 0i64;
  }
  if ( !qSymbol_Female.mUID
    || (v6 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Female.mUID),
        v7 = &v6[-1].mCount,
        !v6) )
  {
    v7 = 0i64;
  }
  if ( !qSymbol_Thug.mUID
    || (v8 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Thug.mUID),
        v9 = &v8[-1].mCount,
        !v8) )
  {
    v9 = 0i64;
  }
  if ( qSymbol_Elderly.mUID )
  {
    v10 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Elderly.mUID);
    if ( v10 )
      v3 = &v10[-1].mCount;
  }
  v11 = profile->m_bitFlags.mFlags[(unsigned __int64)(unsigned int)p_mCount[11] >> 6];
  v12 = _bittest64((const __int64 *)&v11, p_mCount[11] & 0x3F);
  v14 = 0;
  if ( v7 )
  {
    v13 = profile->m_bitFlags.mFlags[(unsigned __int64)(unsigned int)v7[11] >> 6];
    if ( _bittest64((const __int64 *)&v13, v7[11] & 0x3F) )
      v14 = 1;
  }
  v16 = 0;
  if ( v9 )
  {
    v15 = profile->m_bitFlags.mFlags[(unsigned __int64)(unsigned int)v9[11] >> 6];
    if ( _bittest64((const __int64 *)&v15, v9[11] & 0x3F) )
      v16 = 1;
  }
  if ( v3 )
  {
    v17 = profile->m_bitFlags.mFlags[(unsigned __int64)(unsigned int)v3[11] >> 6];
    if ( _bittest64((const __int64 *)&v17, v3[11] & 0x3F) )
    {
      if ( v12 )
      {
        v18 = &old_man;
LABEL_62:
        p_m_wwiseTagsUid = &profile->m_wwiseTagsUid;
        goto LABEL_63;
      }
      if ( v14 )
      {
        v18 = &old_lady;
        goto LABEL_62;
      }
    }
  }
  if ( v16 )
  {
    v19 = UFG::qRandom(4u, (unsigned int *)&UFG::qDefaultSeed);
    p_m_wwiseTagsUid = &profile->m_wwiseTagsUid;
    if ( !v19 )
      goto LABEL_52;
    v21 = v19 - 1;
    if ( !v21 )
    {
      v18 = &thug_2;
      goto LABEL_63;
    }
    v22 = v21 - 1;
    if ( !v22 )
    {
      v18 = &thug_3;
      goto LABEL_63;
    }
    if ( v22 == 1 )
      v18 = &thug_4;
    else
LABEL_52:
      v18 = &thug_1;
  }
  else
  {
    if ( !v12 )
    {
      v24 = UFG::qRandom(2u, (unsigned int *)&UFG::qDefaultSeed);
      v18 = &girl_1;
      if ( !v24 )
        v18 = &girl_2;
      goto LABEL_62;
    }
    v23 = UFG::qRandom(2u, (unsigned int *)&UFG::qDefaultSeed);
    p_m_wwiseTagsUid = &profile->m_wwiseTagsUid;
    if ( v23 )
      v18 = &man_1;
    else
      v18 = &man_2;
  }
LABEL_63:
  UFG::qWiseSymbol::operator=(p_m_wwiseTagsUid, v18);
}

// File Line: 207
// RVA: 0x596590
UFG::VoiceProfile *__fastcall UFG::VoiceProfileManager::AddOrGetVoiceProfile(
        const char *voiceStr,
        UFG::qWiseSymbol *tag_voice)
{
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // rbx
  UFG::qBaseNodeRB *v6; // rdi
  UFG::allocator::free_link *v7; // rbx
  int *v8; // rax
  unsigned __int128 v10; // [rsp+50h] [rbp-28h] BYREF
  unsigned int uid; // [rsp+90h] [rbp+18h] BYREF
  unsigned int v12; // [rsp+98h] [rbp+20h] BYREF

  UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&uid, voiceStr);
  if ( !uid
    || (v4 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, uid)) == 0i64
    || (p_mCount = &v4[-1].mCount, v4 == (UFG::qBaseTreeRB *)8) )
  {
    v6 = 0i64;
    v10 = 0ui64;
    v7 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x78ui64, "VoiceProfile", 0i64, 1u);
    if ( v7 )
    {
      v12 = uid;
      _((AMD_HD3D *)uid);
      UFG::VoiceProfile::VoiceProfile((UFG::VoiceProfile *)v7, &v12, (UFG::BitFlags128 *)&v10, 0);
      p_mCount = v8;
    }
    else
    {
      p_mCount = 0i64;
    }
    UFG::qString::Set((UFG::qString *)(p_mCount + 12), voiceStr);
    UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)p_mCount + 11, tag_voice);
    if ( p_mCount )
      v6 = (UFG::qBaseNodeRB *)(p_mCount + 2);
    UFG::qBaseTreeRB::Add(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, v6);
  }
  _((AMD_HD3D *)uid);
  return (UFG::VoiceProfile *)p_mCount;
}

// File Line: 230
// RVA: 0x5B1720
bool __fastcall UFG::VoiceSortFn(UFG::qPointerNode<UFG::VoiceProfile> *a, UFG::qPointerNode<UFG::VoiceProfile> *b)
{
  return a->mNode->m_weight >= b->mNode->m_weight;
}

// File Line: 239
// RVA: 0x596CE0
UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *__fastcall UFG::VoiceProfileManager::AssignVoice(
        UFG::qPropertySet *pSet)
{
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v1; // rdi
  unsigned int v2; // r15d
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // r14
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v10; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *mPrev; // rax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  UFG::qBaseTreeRB *Next; // rax
  int v15; // edx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *mNext; // rax
  int v17; // eax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v18; // r8
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v19; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v20; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v21; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v22; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v23; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *i; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v25; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v26; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v27; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v28; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v29; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v30; // rcx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> v32; // [rsp+28h] [rbp-28h] BYREF
  UFG::BitFlags128 result; // [rsp+38h] [rbp-18h] BYREF

  UFG::VoiceProfileManager::BuildBitFlags(&result, pSet);
  v32.mNode.mPrev = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v32;
  v32.mNode.mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v32;
  v1 = 0i64;
  v2 = 0;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::VoiceProfileManager::sm_voiceProfiles);
  p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
  if ( !Head )
    p_mCachedBufferPtr = 0i64;
  v5 = result.mFlags[1];
  v6 = result.mFlags[0];
  while ( p_mCachedBufferPtr )
  {
    v7 = v6 & *((_QWORD *)p_mCachedBufferPtr + 12);
    v8 = v5 & *((_QWORD *)p_mCachedBufferPtr + 13);
    if ( (p_mCachedBufferPtr[112] & 1) != 0 && v7 == v6 && v8 == v5 && v7 | v8 )
    {
      v9 = UFG::qMalloc(0x18ui64, "VoiceManager.PossibleVoiceMatch", 0i64);
      v10 = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)v9;
      if ( v9 )
      {
        v9->mNext = v9;
        v9[1].mNext = v9;
        v9[2].mNext = (UFG::allocator::free_link *)p_mCachedBufferPtr;
      }
      else
      {
        v10 = 0i64;
      }
      mPrev = v32.mNode.mPrev;
      v32.mNode.mPrev->mNext = v10;
      v10->mPrev = mPrev;
      v10->mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v32;
      v32.mNode.mPrev = v10;
      v2 += *((_DWORD *)p_mCachedBufferPtr + 22);
      v12 = 0;
      if ( *((_DWORD *)p_mCachedBufferPtr + 22) + UFG::TidoGame::sm_voiceAssignerWeightIncrement )
        v12 = *((_DWORD *)p_mCachedBufferPtr + 22) + UFG::TidoGame::sm_voiceAssignerWeightIncrement;
      v13 = UFG::TidoGame::sm_voiceAssignerWeightLimit;
      if ( v12 < UFG::TidoGame::sm_voiceAssignerWeightLimit )
        v13 = v12;
      *((_DWORD *)p_mCachedBufferPtr + 22) = v13;
    }
    Next = UFG::qBaseTreeRB::GetNext(
             &UFG::VoiceProfileManager::sm_voiceProfiles.mTree,
             (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
    if ( Next )
      p_mCachedBufferPtr = (char *)&Next[-1].mCount;
    else
      p_mCachedBufferPtr = 0i64;
  }
  UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
    &v32,
    (bool (__fastcall *)(Render::DebugTriStrip *, Render::DebugTriStrip *))UFG::VoiceSortFn);
  v15 = 0;
  mNext = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext;
  if ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext != &v32 )
  {
    do
    {
      ++v15;
      mNext = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)mNext->mNode.mNext;
    }
    while ( mNext != &v32 );
    if ( v15 )
    {
      v17 = UFG::qRandom(v2, (unsigned int *)&UFG::qDefaultSeed);
      v18 = v32.mNode.mNext;
      v19 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext;
      if ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext != &v32 )
      {
        while ( 1 )
        {
          v17 -= LODWORD(v19[1].mNode.mPrev[5].mNext);
          if ( v17 <= 0 )
            break;
          v19 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v19->mNode.mNext;
          if ( v19 == &v32 )
            goto LABEL_28;
        }
        v1 = v19[1].mNode.mPrev;
        do
        {
LABEL_28:
          v20 = v18->mPrev;
          v21 = v18->mNext;
          v20->mNext = v21;
          v21->mPrev = v20;
          v18->mPrev = v18;
          v18->mNext = v18;
          v22 = v18->mPrev;
          v23 = v18->mNext;
          v22->mNext = v23;
          v23->mPrev = v22;
          v18->mPrev = v18;
          v18->mNext = v18;
          operator delete[](v18);
          v18 = v32.mNode.mNext;
        }
        while ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext != &v32 );
      }
      LODWORD(v1[5].mNext) = UFG::TidoGame::sm_voiceAssignerWeightReset;
    }
  }
  for ( i = v32.mNode.mNext;
        (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext != &v32;
        i = v32.mNode.mNext )
  {
    v25 = i->mPrev;
    v26 = i->mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    i->mPrev = i;
    i->mNext = i;
    v27 = i->mPrev;
    v28 = i->mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    i->mPrev = i;
    i->mNext = i;
    operator delete[](i);
  }
  v29 = v32.mNode.mPrev;
  v30 = v32.mNode.mNext;
  v32.mNode.mPrev->mNext = v32.mNode.mNext;
  v30->mPrev = v29;
  return v1;
}

// File Line: 292
// RVA: 0x596970
UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *__fastcall UFG::VoiceProfileManager::AssignVoice(
        UFG::SimObject *simObject)
{
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v2; // rdi
  unsigned int v3; // r15d
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rbx
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v11; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *mPrev; // rax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  UFG::qBaseTreeRB *Next; // rax
  int v16; // edx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *mNext; // rax
  int v18; // eax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v19; // r8
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v20; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v21; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v22; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v23; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v24; // rax
  char v25; // r15
  unsigned int v26; // ebx
  __int64 v27; // rsi
  unsigned __int64 v28; // r14
  Render::SkinningCacheNode *v29; // rax
  char *p_mCount; // rcx
  UFG::qBaseTreeRB *v31; // rax
  char *v32; // rax
  char *v33; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *i; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v35; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v36; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v37; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v38; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v39; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v40; // rcx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> v42; // [rsp+28h] [rbp-58h] BYREF
  UFG::BitFlags128 result; // [rsp+40h] [rbp-40h] BYREF
  UFG::qString v44; // [rsp+50h] [rbp-30h] BYREF

  UFG::VoiceProfileManager::BuildBitFlags(&result, simObject);
  v42.mNode.mPrev = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v42;
  v42.mNode.mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v42;
  v2 = 0i64;
  v3 = 0;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::VoiceProfileManager::sm_voiceProfiles);
  p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
  if ( !Head )
    p_mCachedBufferPtr = 0i64;
  v6 = result.mFlags[1];
  v7 = result.mFlags[0];
  while ( p_mCachedBufferPtr )
  {
    v8 = v7 & *((_QWORD *)p_mCachedBufferPtr + 12);
    v9 = v6 & *((_QWORD *)p_mCachedBufferPtr + 13);
    if ( (p_mCachedBufferPtr[112] & 1) != 0 && v8 == v7 && v9 == v6 && v8 | v9 )
    {
      v10 = UFG::qMalloc(0x18ui64, "VoiceManager.PossibleVoiceMatch", 0i64);
      v11 = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)v10;
      if ( v10 )
      {
        v10->mNext = v10;
        v10[1].mNext = v10;
        v10[2].mNext = (UFG::allocator::free_link *)p_mCachedBufferPtr;
      }
      else
      {
        v11 = 0i64;
      }
      mPrev = v42.mNode.mPrev;
      v42.mNode.mPrev->mNext = v11;
      v11->mPrev = mPrev;
      v11->mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v42;
      v42.mNode.mPrev = v11;
      v3 += *((_DWORD *)p_mCachedBufferPtr + 22);
      v13 = 0;
      if ( *((_DWORD *)p_mCachedBufferPtr + 22) + UFG::TidoGame::sm_voiceAssignerWeightIncrement )
        v13 = *((_DWORD *)p_mCachedBufferPtr + 22) + UFG::TidoGame::sm_voiceAssignerWeightIncrement;
      v14 = UFG::TidoGame::sm_voiceAssignerWeightLimit;
      if ( v13 < UFG::TidoGame::sm_voiceAssignerWeightLimit )
        v14 = v13;
      *((_DWORD *)p_mCachedBufferPtr + 22) = v14;
    }
    Next = UFG::qBaseTreeRB::GetNext(
             &UFG::VoiceProfileManager::sm_voiceProfiles.mTree,
             (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
    if ( Next )
      p_mCachedBufferPtr = (char *)&Next[-1].mCount;
    else
      p_mCachedBufferPtr = 0i64;
  }
  UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
    &v42,
    (bool (__fastcall *)(Render::DebugTriStrip *, Render::DebugTriStrip *))UFG::VoiceSortFn);
  v16 = 0;
  mNext = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext;
  if ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext == &v42 )
    goto LABEL_30;
  do
  {
    ++v16;
    mNext = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)mNext->mNode.mNext;
  }
  while ( mNext != &v42 );
  if ( !v16 )
  {
LABEL_30:
    UFG::qString::qString(&v44);
    v25 = 1;
    v26 = 0;
    v27 = 1i64;
    v28 = 0i64;
    do
    {
      if ( (v27 & result.mFlags[v28 >> 6]) != 0 )
      {
        if ( !v25 )
          UFG::qString::operator+=(&v44, ", ");
        v29 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::VoiceProfileManager::sm_voiceTags);
        p_mCount = (char *)&v29[-1].mCachedBufferPtr;
        if ( !v29 )
LABEL_35:
          p_mCount = 0i64;
        while ( p_mCount )
        {
          if ( *((_DWORD *)p_mCount + 11) == v26 )
          {
            v32 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mCount + 10);
            UFG::qString::operator+=(&v44, v32);
            v25 = 0;
            break;
          }
          v31 = UFG::qBaseTreeRB::GetNext(
                  &UFG::VoiceProfileManager::sm_voiceTags.mTree,
                  (UFG::qBaseNodeRB *)(p_mCount + 8));
          if ( !v31 )
            goto LABEL_35;
          p_mCount = (char *)&v31[-1].mCount;
        }
      }
      ++v26;
      ++v28;
      v27 = __ROL8__(v27, 1);
    }
    while ( v26 < 0x80 );
    v33 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&simObject->m_Name);
    UFG::qPrintf("TC_VOICE_DBG: Could not find voice for profile: %s --> %s \n", v33, v44.mData);
    UFG::qString::~qString(&v44);
  }
  else
  {
    v18 = UFG::qRandom(v3, (unsigned int *)&UFG::qDefaultSeed);
    v19 = v42.mNode.mNext;
    v20 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext;
    if ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext != &v42 )
    {
      while ( 1 )
      {
        v18 -= LODWORD(v20[1].mNode.mPrev[5].mNext);
        if ( v18 <= 0 )
          break;
        v20 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v20->mNode.mNext;
        if ( v20 == &v42 )
          goto LABEL_28;
      }
      v2 = v20[1].mNode.mPrev;
      do
      {
LABEL_28:
        v21 = v19->mPrev;
        v22 = v19->mNext;
        v21->mNext = v22;
        v22->mPrev = v21;
        v19->mPrev = v19;
        v19->mNext = v19;
        v23 = v19->mPrev;
        v24 = v19->mNext;
        v23->mNext = v24;
        v24->mPrev = v23;
        v19->mPrev = v19;
        v19->mNext = v19;
        operator delete[](v19);
        v19 = v42.mNode.mNext;
      }
      while ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext != &v42 );
    }
    LODWORD(v2[5].mNext) = UFG::TidoGame::sm_voiceAssignerWeightReset;
  }
  for ( i = v42.mNode.mNext;
        (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext != &v42;
        i = v42.mNode.mNext )
  {
    v35 = i->mPrev;
    v36 = i->mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    i->mPrev = i;
    i->mNext = i;
    v37 = i->mPrev;
    v38 = i->mNext;
    v37->mNext = v38;
    v38->mPrev = v37;
    i->mPrev = i;
    i->mNext = i;
    operator delete[](i);
  }
  v39 = v42.mNode.mPrev;
  v40 = v42.mNode.mNext;
  v42.mNode.mPrev->mNext = v42.mNode.mNext;
  v40->mPrev = v39;
  return v2;
}mPrev = v37;
    i->mPrev = i;
    i->mNext = i;
    operator delete[](i);
  }
  v39 = v42.mNode.mPrev;
  v40 = v42.mNode.mNext;
  v42.mNode.mPrev->

// File Line: 385
// RVA: 0x597290
UFG::BitFlags128 *__fastcall UFG::VoiceProfileManager::BuildBitFlags(
        UFG::BitFlags128 *result,
        UFG::SimObjectCVBase *simObject)
{
  UFG::qPropertyList *v4; // rbp
  bool IsFemale; // al
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v7; // rax
  int *p_mCount; // rax
  unsigned int v9; // ecx
  unsigned int mNumElements; // esi
  unsigned int i; // edi
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  int *v14; // rax
  unsigned int v15; // ecx

  result->mFlags[1] = 0i64;
  result->mFlags[0] = 0i64;
  v4 = PropertyUtils::Get<UFG::qPropertyList>(
         simObject->m_pSceneObj,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_VoiceTagList);
  if ( qSymbol_Male.mUID )
    UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Male.mUID);
  IsFemale = UFG::IsFemale(simObject);
  mUID = qSymbol_Female.mUID;
  if ( !IsFemale )
    mUID = qSymbol_Male.mUID;
  if ( mUID && (v7 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, mUID)) != 0i64 )
    p_mCount = &v7[-1].mCount;
  else
    p_mCount = 0i64;
  v9 = p_mCount[11];
  if ( v9 >= 0x40 )
    result->mFlags[1] |= 1i64 << ((unsigned __int8)v9 - 64);
  else
    result->mFlags[0] |= 1i64 << v9;
  mNumElements = v4->mNumElements;
  for ( i = 0; i < mNumElements; ++i )
  {
    v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v4, i)->mUID;
    if ( v12 && (v13 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v12)) != 0i64 )
      v14 = &v13[-1].mCount;
    else
      v14 = 0i64;
    v15 = v14[11];
    if ( v15 >= 0x40 )
      result->mFlags[1] |= 1i64 << ((unsigned __int8)v15 - 64);
    else
      result->mFlags[0] |= 1i64 << v15;
  }
  return result;
}

// File Line: 424
// RVA: 0x5973B0
UFG::BitFlags128 *__fastcall UFG::VoiceProfileManager::BuildBitFlags(UFG::BitFlags128 *result, UFG::qPropertySet *pSet)
{
  UFG::qPropertyList *v4; // rbp
  UFG::qBaseTreeRB *v5; // rax
  int *p_mCount; // rdi
  UFG::qSymbol *v7; // rax
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v9; // rax
  unsigned int v10; // ecx
  unsigned int mNumElements; // esi
  unsigned int i; // edi
  unsigned int v13; // edx
  UFG::qBaseTreeRB *v14; // rax
  int *v15; // rax
  unsigned int v16; // ecx

  result->mFlags[1] = 0i64;
  result->mFlags[0] = 0i64;
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         pSet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_VoiceTagList,
         DEPTH_RECURSE);
  if ( qSymbol_Male.mUID
    && (v5 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Male.mUID)) != 0i64 )
  {
    p_mCount = &v5[-1].mCount;
  }
  else
  {
    p_mCount = 0i64;
  }
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(pSet, (UFG::qArray<unsigned long,0> *)&qSymbol_Gender, DEPTH_RECURSE);
  if ( v7 )
  {
    mUID = qSymbol_Female.mUID;
    if ( v7->mUID != qSymbol_Female.mUID )
      mUID = qSymbol_Male.mUID;
    if ( mUID && (v9 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, mUID)) != 0i64 )
      p_mCount = &v9[-1].mCount;
    else
      p_mCount = 0i64;
  }
  v10 = p_mCount[11];
  if ( v10 >= 0x40 )
    result->mFlags[1] |= 1i64 << ((unsigned __int8)v10 - 64);
  else
    result->mFlags[0] |= 1i64 << v10;
  mNumElements = v4->mNumElements;
  for ( i = 0; i < mNumElements; ++i )
  {
    v13 = UFG::qPropertyList::Get<UFG::qSymbol>(v4, i)->mUID;
    if ( v13 && (v14 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v13)) != 0i64 )
      v15 = &v14[-1].mCount;
    else
      v15 = 0i64;
    v16 = v15[11];
    if ( v16 >= 0x40 )
      result->mFlags[1] |= 1i64 << ((unsigned __int8)v16 - 64);
    else
      result->mFlags[0] |= 1i64 << v16;
  }
  return result;
}

// File Line: 550
// RVA: 0x593830
void __fastcall UFG::VoiceProfile::VoiceProfile(
        UFG::VoiceProfile *this,
        unsigned int *wwiseId,
        UFG::BitFlags128 *flags,
        bool isTC)
{
  AMD_HD3D *v8; // rcx

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->vfptr = (UFG::VoiceProfileVtbl *)&UFG::VoiceProfile::`vftable;
  v8 = (AMD_HD3D *)*wwiseId;
  this->m_wwiseVoiceUid.mUID = (unsigned int)v8;
  _(v8);
  this->m_wwiseTagsUid.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  UFG::qString::qString(&this->m_subtitleSet);
  this->m_weight = 50;
  this->m_bitFlags = *flags;
  this->mNode.mUID = *wwiseId;
  UFG::qString::Set(&this->m_subtitleSet, &customCaption);
  *((_BYTE *)this + 112) &= ~1u;
  *((_BYTE *)this + 112) |= isTC;
  _((AMD_HD3D *)*wwiseId);
}

// File Line: 570
// RVA: 0x596FF0
bool __fastcall UFG::VoiceProfile::BankRequiredForExertions(UFG::VoiceProfile *this)
{
  unsigned int v2; // eax
  unsigned int mUID; // eax

  v2 = _S37_1;
  if ( (_S37_1 & 1) == 0 )
  {
    _S37_1 |= 1u;
    UFG::qWiseSymbol::create_from_string(&girl_1_0, "girl_1");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__girl_1__);
    v2 = _S37_1;
  }
  if ( (v2 & 2) == 0 )
  {
    _S37_1 = v2 | 2;
    UFG::qWiseSymbol::create_from_string(&girl_2_0, "girl_2");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__girl_2__);
    v2 = _S37_1;
  }
  if ( (v2 & 4) == 0 )
  {
    _S37_1 = v2 | 4;
    UFG::qWiseSymbol::create_from_string(&man_1_0, "man_1");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__man_1__);
    v2 = _S37_1;
  }
  if ( (v2 & 8) == 0 )
  {
    _S37_1 = v2 | 8;
    UFG::qWiseSymbol::create_from_string(&man_2_0, "man_2");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__man_2__);
    v2 = _S37_1;
  }
  if ( (v2 & 0x10) == 0 )
  {
    _S37_1 = v2 | 0x10;
    UFG::qWiseSymbol::create_from_string(&old_man_0, "old_man");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__old_man__);
    v2 = _S37_1;
  }
  if ( (v2 & 0x20) == 0 )
  {
    _S37_1 = v2 | 0x20;
    UFG::qWiseSymbol::create_from_string(&old_lady_0, "old_lady");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__old_lady__);
    v2 = _S37_1;
  }
  if ( (v2 & 0x40) == 0 )
  {
    _S37_1 = v2 | 0x40;
    UFG::qWiseSymbol::create_from_string(&thug_3_0, "thug_3");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__thug_3__);
    v2 = _S37_1;
  }
  if ( (v2 & 0x80u) == 0 )
  {
    _S37_1 = v2 | 0x80;
    UFG::qWiseSymbol::create_from_string(&thug_1_0, "thug_1");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__thug_1__);
    v2 = _S37_1;
  }
  if ( (v2 & 0x100) == 0 )
  {
    _S37_1 = v2 | 0x100;
    UFG::qWiseSymbol::create_from_string(&thug_4_0, "thug_4");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__thug_4__);
    v2 = _S37_1;
  }
  if ( (v2 & 0x200) == 0 )
  {
    _S37_1 = v2 | 0x200;
    UFG::qWiseSymbol::create_from_string(&thug_2_0, "thug_2");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__thug_2__);
  }
  mUID = this->m_wwiseTagsUid.mUID;
  return mUID != girl_1_0.mUID
      && mUID != girl_2_0.mUID
      && mUID != man_1_0.mUID
      && mUID != man_2_0.mUID
      && mUID != old_man_0.mUID
      && mUID != old_lady_0.mUID
      && mUID != thug_1_0.mUID
      && mUID != thug_2_0.mUID
      && mUID != thug_3_0.mUID
      && mUID != thug_4_0.mUID;
}

