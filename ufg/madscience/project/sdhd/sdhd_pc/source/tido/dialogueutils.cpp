// File Line: 37
// RVA: 0x1554F40
__int64 dynamic_initializer_for__UFG::VoiceProfileManager::sm_voiceProfiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::VoiceProfileManager::sm_voiceProfiles__);
}

// File Line: 38
// RVA: 0x1554F70
__int64 dynamic_initializer_for__UFG::VoiceProfileManager::sm_voiceTags__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VoiceProfileManager::sm_voiceTags.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::VoiceProfileManager::sm_voiceTags__);
}

// File Line: 46
// RVA: 0x5A29A0
void UFG::VoiceProfileManager::LoadVoiceProfiles(void)
{
  UFG::qPropertyList *v0; // rcx
  unsigned int v1; // er12
  char *v2; // rax
  UFG::qPropertySet *v3; // rbx
  char *v4; // rax
  const char *v5; // rsi
  UFG::qPropertySet *v6; // rax
  UFG::qPropertyList *v7; // r13
  unsigned int v8; // er15
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // r14
  unsigned int v11; // edi
  UFG::qSymbol *v12; // rsi
  UFG::qBaseTreeRB *v13; // rax
  UFG::allocator::free_link *v14; // rbx
  unsigned int v15; // ecx
  UFG::qBaseNodeRB *v16; // rdx
  unsigned int v17; // eax
  unsigned int v18; // edx
  UFG::allocator::free_link *v19; // rdi
  unsigned int v20; // ecx
  unsigned int *v21; // rdx
  UFG::qSymbol result; // [rsp+30h] [rbp-78h]
  unsigned int v23; // [rsp+34h] [rbp-74h]
  char *v24; // [rsp+38h] [rbp-70h]
  UFG::qPropertyList *v25; // [rsp+40h] [rbp-68h]
  __int64 v26; // [rsp+48h] [rbp-60h]
  UFG::allocator::free_link *v27; // [rsp+50h] [rbp-58h]
  AMD_HD3D **v28; // [rsp+58h] [rbp-50h]
  AMD_HD3D *v29; // [rsp+B0h] [rbp+8h]
  UFG::qWiseSymbol v30; // [rsp+B8h] [rbp+10h]
  unsigned int v31; // [rsp+C0h] [rbp+18h]
  UFG::allocator::free_link *v32; // [rsp+C8h] [rbp+20h]

  v26 = -2i64;
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&UFG::VoiceProfileManager::sm_voiceProfiles);
  UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[1] = 0i64;
  UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[0] = 0i64;
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&UFG::VoiceProfileManager::sm_voiceTags);
  UFG::qSymbol::create_from_string(&result, "Audio-Voices");
  UFG::VoiceProfileManager::sm_propertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v0 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         UFG::VoiceProfileManager::sm_propertySet,
         (UFG::qSymbol *)&TiDoSym_VoiceProfiles.mUID,
         DEPTH_RECURSE);
  v25 = v0;
  v23 = v0->mNumElements;
  v1 = 0;
  LODWORD(v32) = 0;
  if ( v23 )
  {
    do
    {
      v2 = UFG::qPropertyList::GetValuePtr(v0, 0x1Au, v1);
      if ( v2 && *(_QWORD *)v2 )
        v3 = (UFG::qPropertySet *)&v2[*(_QWORD *)v2];
      else
        v3 = 0i64;
      v4 = PropertyUtils::Get<char const *>(v3, (UFG::qSymbol *)&TiDoSym_WwiseVoiceId.mUID, DEPTH_RECURSE);
      v5 = v4;
      v24 = v4;
      UFG::qWiseSymbol::create_from_string(&v30, v4);
      v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(v3, (UFG::qSymbol *)&TiDoSym_Tags.mUID, DEPTH_RECURSE);
      if ( v6 )
      {
        v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qSymbol *)&TiDoSym_Tags.mUID, DEPTH_RECURSE);
        v8 = v7->mNumElements;
        v9 = 0i64;
        v10 = 0i64;
        v11 = 0;
        if ( v8 )
        {
          do
          {
            v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v7, v11);
            if ( !v12->mUID
              || (v13 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v12->mUID)) == 0i64
              || (v14 = (UFG::allocator::free_link *)&v13[-1].mCount, v13 == (UFG::qBaseTreeRB *)8) )
            {
              v14 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "VoiceTag", 0i64, 1u);
              v27 = v14;
              if ( v14 )
              {
                v28 = (AMD_HD3D **)&v31;
                ++UFG::VoiceTag::sm_idxCnt;
                v31 = v12->mUID;
                v15 = UFG::VoiceTag::sm_idxCnt;
                v16 = 0i64;
                v14[1].mNext = 0i64;
                v14[2].mNext = 0i64;
                v14[3].mNext = 0i64;
                v14->mNext = (UFG::allocator::free_link *)&UFG::VoiceTag::`vftable;
                v17 = v31;
                LODWORD(v14[5].mNext) = v31;
                HIDWORD(v14[5].mNext) = v15;
                LODWORD(v14[4].mNext) = v17;
              }
              else
              {
                v16 = 0i64;
                v14 = 0i64;
              }
              if ( v14 )
                v16 = (UFG::qBaseNodeRB *)&v14[1];
              UFG::qBaseTreeRB::Add(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v16);
            }
            v18 = HIDWORD(v14[5].mNext);
            if ( v18 >= 0x40 )
              v9 |= 1i64 << ((unsigned __int8)v18 - 64);
            else
              v10 |= 1i64 << v18;
            if ( v18 >= 0x40 )
              UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[1] |= 1i64 << ((unsigned __int8)v18 - 64);
            else
              UFG::VoiceProfileManager::sm_MasterFlagSet.mFlags[0] |= 1i64 << v18;
            ++v11;
          }
          while ( v11 < v8 );
          v1 = (unsigned int)v32;
          v5 = v24;
        }
        v19 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x78ui64, "VoiceProfile", 0i64, 1u);
        v32 = v19;
        if ( v19 )
        {
          LODWORD(v29) = v30;
          _((AMD_HD3D *)v30.mUID);
          v28 = &v29;
          v19[1].mNext = 0i64;
          v19[2].mNext = 0i64;
          v19[3].mNext = 0i64;
          v19->mNext = (UFG::allocator::free_link *)&UFG::VoiceProfile::`vftable;
          LODWORD(v19[5].mNext) = (_DWORD)v29;
          _((AMD_HD3D *)(unsigned int)v29);
          HIDWORD(v19[5].mNext) = -1;
          _((AMD_HD3D *)0xFFFFFFFFi64);
          UFG::qString::qString((UFG::qString *)&v19[6]);
          LODWORD(v19[11].mNext) = 50;
          v19[12].mNext = (UFG::allocator::free_link *)v10;
          v19[13].mNext = (UFG::allocator::free_link *)v9;
          LODWORD(v19[4].mNext) = (_DWORD)v29;
          UFG::qString::Set((UFG::qString *)&v19[6], &customWorldMapCaption);
          LOBYTE(v19[14].mNext) |= 1u;
          _((AMD_HD3D *)(unsigned int)v29);
        }
        else
        {
          v19 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v19[6], v5);
        UFG::VoiceProfileManager::SetTagVoice((UFG::VoiceProfile *)v19);
        v20 = 0;
        if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size )
        {
          v21 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p;
          while ( v30.mUID != *v21 )
          {
            ++v20;
            ++v21;
            if ( v20 >= UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size )
              goto LABEL_32;
          }
        }
        else
        {
LABEL_32:
          v20 = -1;
        }
        LOBYTE(v19[14].mNext) &= 0xFDu;
        LOBYTE(v19[14].mNext) |= 2 * (v20 != -1);
        UFG::qBaseTreeRB::Add(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, (UFG::qBaseNodeRB *)&v19[1]);
      }
      _((AMD_HD3D *)v30.mUID);
      LODWORD(v32) = ++v1;
      v0 = v25;
    }
    while ( v1 < v23 );
  }
}

// File Line: 123
// RVA: 0x5AB370
void __fastcall UFG::VoiceProfileManager::SetTagVoice(UFG::VoiceProfile *profile)
{
  UFG::VoiceProfile *v1; // rbx
  unsigned int v2; // eax
  signed __int64 v3; // rdi
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // r14
  UFG::qBaseTreeRB *v6; // rax
  signed __int64 v7; // rbp
  UFG::qBaseTreeRB *v8; // rax
  signed __int64 v9; // rsi
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
  UFG::qWiseSymbol *v20; // rcx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax

  v1 = profile;
  v2 = _S36_1;
  if ( !(_S36_1 & 1) )
  {
    _S36_1 |= 1u;
    UFG::qWiseSymbol::create_from_string(&girl_1, "girl_1");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__girl_1__);
    v2 = _S36_1;
  }
  if ( !(v2 & 2) )
  {
    _S36_1 = v2 | 2;
    UFG::qWiseSymbol::create_from_string(&girl_2, "girl_2");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__girl_2__);
    v2 = _S36_1;
  }
  if ( !(v2 & 4) )
  {
    _S36_1 = v2 | 4;
    UFG::qWiseSymbol::create_from_string(&man_1, "man_1");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__man_1__);
    v2 = _S36_1;
  }
  if ( !(v2 & 8) )
  {
    _S36_1 = v2 | 8;
    UFG::qWiseSymbol::create_from_string(&man_2, "man_2");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__man_2__);
    v2 = _S36_1;
  }
  if ( !(v2 & 0x10) )
  {
    _S36_1 = v2 | 0x10;
    UFG::qWiseSymbol::create_from_string(&old_man, "old_man");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__old_man__);
    v2 = _S36_1;
  }
  if ( !(v2 & 0x20) )
  {
    _S36_1 = v2 | 0x20;
    UFG::qWiseSymbol::create_from_string(&old_lady, "old_lady");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__old_lady__);
    v2 = _S36_1;
  }
  if ( !(v2 & 0x40) )
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
  if ( !_bittest((const signed int *)&v2, 8u) )
  {
    _S36_1 = v2 | 0x100;
    UFG::qWiseSymbol::create_from_string(&thug_4, "thug_4");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__thug_4__);
    v2 = _S36_1;
  }
  if ( !_bittest((const signed int *)&v2, 9u) )
  {
    _S36_1 = v2 | 0x200;
    UFG::qWiseSymbol::create_from_string(&thug_2, "thug_2");
    atexit(UFG::VoiceProfileManager::SetTagVoice_::_2_::_dynamic_atexit_destructor_for__thug_2__);
  }
  v3 = 0i64;
  if ( !qSymbol_Male.mUID
    || (v4 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Male.mUID),
        v5 = (signed __int64)&v4[-1].mCount,
        !v4) )
  {
    v5 = 0i64;
  }
  if ( !qSymbol_Female.mUID
    || (v6 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Female.mUID),
        v7 = (signed __int64)&v6[-1].mCount,
        !v6) )
  {
    v7 = 0i64;
  }
  if ( !qSymbol_Thug.mUID
    || (v8 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Thug.mUID),
        v9 = (signed __int64)&v8[-1].mCount,
        !v8) )
  {
    v9 = 0i64;
  }
  if ( qSymbol_Elderly.mUID )
  {
    v10 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Elderly.mUID);
    if ( v10 )
      v3 = (signed __int64)&v10[-1].mCount;
  }
  v11 = v1->m_bitFlags.mFlags[(unsigned __int64)*(unsigned int *)(v5 + 44) >> 6];
  v12 = _bittest64((const signed __int64 *)&v11, *(_DWORD *)(v5 + 44) & 0x3F);
  v14 = 0;
  if ( v7 )
  {
    v13 = v1->m_bitFlags.mFlags[(unsigned __int64)*(unsigned int *)(v7 + 44) >> 6];
    if ( _bittest64((const signed __int64 *)&v13, *(_DWORD *)(v7 + 44) & 0x3F) )
      v14 = 1;
  }
  v16 = 0;
  if ( v9 )
  {
    v15 = v1->m_bitFlags.mFlags[(unsigned __int64)*(unsigned int *)(v9 + 44) >> 6];
    if ( _bittest64((const signed __int64 *)&v15, *(_DWORD *)(v9 + 44) & 0x3F) )
      v16 = 1;
  }
  if ( v3 )
  {
    v17 = v1->m_bitFlags.mFlags[(unsigned __int64)*(unsigned int *)(v3 + 44) >> 6];
    if ( _bittest64((const signed __int64 *)&v17, *(_DWORD *)(v3 + 44) & 0x3F) )
    {
      if ( v12 )
      {
        v18 = &old_man;
LABEL_62:
        v20 = &v1->m_wwiseTagsUid;
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
    v19 = UFG::qRandom(4, &UFG::qDefaultSeed);
    v20 = &v1->m_wwiseTagsUid;
    if ( !v19 )
      goto LABEL_66;
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
LABEL_66:
      v18 = &thug_1;
  }
  else
  {
    if ( !v12 )
    {
      v24 = UFG::qRandom(2, &UFG::qDefaultSeed);
      v18 = &girl_1;
      if ( !v24 )
        v18 = &girl_2;
      goto LABEL_62;
    }
    v23 = UFG::qRandom(2, &UFG::qDefaultSeed);
    v20 = &v1->m_wwiseTagsUid;
    if ( v23 )
      v18 = &man_1;
    else
      v18 = &man_2;
  }
LABEL_63:
  UFG::qWiseSymbol::operator=(v20, v18);
}

// File Line: 207
// RVA: 0x596590
UFG::VoiceProfile *__fastcall UFG::VoiceProfileManager::AddOrGetVoiceProfile(const char *voiceStr, UFG::qWiseSymbol *tag_voice)
{
  UFG::qWiseSymbol *v2; // rbp
  const char *v3; // rsi
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rbx
  UFG::qBaseNodeRB *v6; // rdi
  UFG::allocator::free_link *v7; // rbx
  signed __int64 v8; // rax
  __m128i v10; // [rsp+50h] [rbp-28h]
  unsigned int uid; // [rsp+90h] [rbp+18h]
  unsigned int v12; // [rsp+98h] [rbp+20h]

  v2 = tag_voice;
  v3 = voiceStr;
  UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&uid, voiceStr);
  if ( !uid
    || (v4 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, uid)) == 0i64
    || (v5 = (signed __int64)&v4[-1].mCount, v4 == (UFG::qBaseTreeRB *)8) )
  {
    v6 = 0i64;
    v10 = 0ui64;
    v7 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x78ui64, "VoiceProfile", 0i64, 1u);
    if ( v7 )
    {
      _mm_store_si128(&v10, v10);
      v12 = uid;
      _((AMD_HD3D *)uid);
      UFG::VoiceProfile::VoiceProfile((UFG::VoiceProfile *)v7, (__int64)&v12, (UFG::BitFlags128 *)&v10, 0);
      v5 = v8;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qString::Set((UFG::qString *)(v5 + 48), v3);
    UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v5 + 44), v2);
    if ( v5 )
      v6 = (UFG::qBaseNodeRB *)(v5 + 8);
    UFG::qBaseTreeRB::Add(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, v6);
  }
  _((AMD_HD3D *)uid);
  return (UFG::VoiceProfile *)v5;
}

// File Line: 230
// RVA: 0x5B1720
bool __fastcall UFG::VoiceSortFn(UFG::qPointerNode<UFG::VoiceProfile> *a, UFG::qPointerNode<UFG::VoiceProfile> *b)
{
  return a->mNode->m_weight >= b->mNode->m_weight;
}

// File Line: 239
// RVA: 0x596CE0
UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *__fastcall UFG::VoiceProfileManager::AssignVoice(UFG::qPropertySet *pSet)
{
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v1; // rdi
  int v2; // er15
  Render::SkinningCacheNode *v3; // rax
  signed __int64 v4; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // r14
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v10; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v11; // rax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  UFG::qBaseTreeRB *v14; // rax
  int v15; // edx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v16; // rax
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
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> v32; // [rsp+28h] [rbp-28h]
  UFG::BitFlags128 result; // [rsp+38h] [rbp-18h]

  UFG::VoiceProfileManager::BuildBitFlags(&result, pSet);
  v32.mNode.mPrev = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v32;
  v32.mNode.mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v32;
  v1 = 0i64;
  v2 = 0;
  v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::VoiceProfileManager::sm_voiceProfiles);
  v4 = (signed __int64)&v3[-1].mCachedBufferPtr;
  if ( !v3 )
    v4 = 0i64;
  v5 = result.mFlags[1];
  v6 = result.mFlags[0];
  while ( v4 )
  {
    v7 = v6 & *(_QWORD *)(v4 + 96);
    v8 = v5 & *(_QWORD *)(v4 + 104);
    if ( *(_BYTE *)(v4 + 112) & 1 && v7 == v6 && v8 == v5 && v7 | v8 )
    {
      v9 = UFG::qMalloc(0x18ui64, "VoiceManager.PossibleVoiceMatch", 0i64);
      v10 = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)v9;
      if ( v9 )
      {
        v9->mNext = v9;
        v9[1].mNext = v9;
        v9[2].mNext = (UFG::allocator::free_link *)v4;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = v32.mNode.mPrev;
      v32.mNode.mPrev->mNext = v10;
      v10->mPrev = v11;
      v10->mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v32;
      v32.mNode.mPrev = v10;
      v2 += *(_DWORD *)(v4 + 88);
      v12 = 0;
      if ( *(_DWORD *)(v4 + 88) + UFG::TidoGame::sm_voiceAssignerWeightIncrement )
        v12 = *(_DWORD *)(v4 + 88) + UFG::TidoGame::sm_voiceAssignerWeightIncrement;
      v13 = UFG::TidoGame::sm_voiceAssignerWeightLimit;
      if ( v12 < UFG::TidoGame::sm_voiceAssignerWeightLimit )
        v13 = v12;
      *(_DWORD *)(v4 + 88) = v13;
    }
    v14 = UFG::qBaseTreeRB::GetNext(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, (UFG::qBaseNodeRB *)(v4 + 8));
    if ( v14 )
      v4 = (signed __int64)&v14[-1].mCount;
    else
      v4 = 0i64;
  }
  UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
    &v32,
    (bool (__fastcall *)(Render::DebugTriStrip *, Render::DebugTriStrip *))UFG::VoiceSortFn);
  v15 = 0;
  v16 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext;
  if ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v32.mNode.mNext != &v32 )
  {
    do
    {
      ++v15;
      v16 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v16->mNode.mNext;
    }
    while ( v16 != &v32 );
    if ( v15 )
    {
      v17 = UFG::qRandom(v2, &UFG::qDefaultSeed);
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
UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *__fastcall UFG::VoiceProfileManager::AssignVoice(UFG::SimObject *simObject)
{
  UFG::SimObject *v1; // r13
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v2; // rdi
  int v3; // er15
  Render::SkinningCacheNode *v4; // rax
  signed __int64 v5; // rbx
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v11; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v12; // rax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  UFG::qBaseTreeRB *v15; // rax
  int v16; // edx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v17; // rax
  int v18; // eax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v19; // r8
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v20; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v21; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v22; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v23; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v24; // rax
  char v25; // r15
  unsigned int v26; // ebx
  signed __int64 v27; // rsi
  unsigned __int64 v28; // r14
  Render::SkinningCacheNode *v29; // rax
  signed __int64 v30; // rcx
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
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> v42; // [rsp+28h] [rbp-58h]
  UFG::BitFlags128 result; // [rsp+40h] [rbp-40h]
  UFG::qString v44; // [rsp+50h] [rbp-30h]

  v1 = simObject;
  UFG::VoiceProfileManager::BuildBitFlags(&result, simObject);
  v42.mNode.mPrev = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v42;
  v42.mNode.mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v42;
  v2 = 0i64;
  v3 = 0;
  v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::VoiceProfileManager::sm_voiceProfiles);
  v5 = (signed __int64)&v4[-1].mCachedBufferPtr;
  if ( !v4 )
    v5 = 0i64;
  v6 = result.mFlags[1];
  v7 = result.mFlags[0];
  while ( v5 )
  {
    v8 = v7 & *(_QWORD *)(v5 + 96);
    v9 = v6 & *(_QWORD *)(v5 + 104);
    if ( *(_BYTE *)(v5 + 112) & 1 && v8 == v7 && v9 == v6 && v8 | v9 )
    {
      v10 = UFG::qMalloc(0x18ui64, "VoiceManager.PossibleVoiceMatch", 0i64);
      v11 = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)v10;
      if ( v10 )
      {
        v10->mNext = v10;
        v10[1].mNext = v10;
        v10[2].mNext = (UFG::allocator::free_link *)v5;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = v42.mNode.mPrev;
      v42.mNode.mPrev->mNext = v11;
      v11->mPrev = v12;
      v11->mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v42;
      v42.mNode.mPrev = v11;
      v3 += *(_DWORD *)(v5 + 88);
      v13 = 0;
      if ( *(_DWORD *)(v5 + 88) + UFG::TidoGame::sm_voiceAssignerWeightIncrement )
        v13 = *(_DWORD *)(v5 + 88) + UFG::TidoGame::sm_voiceAssignerWeightIncrement;
      v14 = UFG::TidoGame::sm_voiceAssignerWeightLimit;
      if ( v13 < UFG::TidoGame::sm_voiceAssignerWeightLimit )
        v14 = v13;
      *(_DWORD *)(v5 + 88) = v14;
    }
    v15 = UFG::qBaseTreeRB::GetNext(&UFG::VoiceProfileManager::sm_voiceProfiles.mTree, (UFG::qBaseNodeRB *)(v5 + 8));
    if ( v15 )
      v5 = (signed __int64)&v15[-1].mCount;
    else
      v5 = 0i64;
  }
  UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
    &v42,
    (bool (__fastcall *)(Render::DebugTriStrip *, Render::DebugTriStrip *))UFG::VoiceSortFn);
  v16 = 0;
  v17 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext;
  if ( (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v42.mNode.mNext == &v42 )
    goto LABEL_48;
  do
  {
    ++v16;
    v17 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v17->mNode.mNext;
  }
  while ( v17 != &v42 );
  if ( v16 )
  {
    v18 = UFG::qRandom(v3, &UFG::qDefaultSeed);
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
  else
  {
LABEL_48:
    UFG::qString::qString(&v44);
    _mm_store_si128((__m128i *)&result, (__m128i)result);
    v25 = 1;
    v26 = 0;
    v27 = 1i64;
    v28 = 0i64;
    do
    {
      if ( v27 & result.mFlags[v28 >> 6] )
      {
        if ( !v25 )
          UFG::qString::operator+=(&v44, ", ");
        v29 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::VoiceProfileManager::sm_voiceTags);
        v30 = (signed __int64)&v29[-1].mCachedBufferPtr;
        if ( !v29 )
LABEL_35:
          v30 = 0i64;
        while ( v30 )
        {
          if ( *(_DWORD *)(v30 + 44) == v26 )
          {
            v32 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v30 + 40));
            UFG::qString::operator+=(&v44, v32);
            v25 = 0;
            break;
          }
          v31 = UFG::qBaseTreeRB::GetNext(&UFG::VoiceProfileManager::sm_voiceTags.mTree, (UFG::qBaseNodeRB *)(v30 + 8));
          if ( !v31 )
            goto LABEL_35;
          v30 = (signed __int64)&v31[-1].mCount;
        }
      }
      ++v26;
      ++v28;
      v27 = __ROL8__(v27, 1);
    }
    while ( v26 < 0x80 );
    v33 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_Name);
    UFG::qPrintf("TC_VOICE_DBG: Could not find voice for profile: %s --> %s \n", v33, v44.mData);
    UFG::qString::~qString(&v44);
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
}

// File Line: 385
// RVA: 0x597290
UFG::BitFlags128 *__fastcall UFG::VoiceProfileManager::BuildBitFlags(UFG::BitFlags128 *result, UFG::SimObject *simObject)
{
  UFG::SimObject *v2; // rdi
  UFG::BitFlags128 *v3; // rbx
  UFG::qPropertyList *v4; // rbp
  bool v5; // al
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  signed __int64 v8; // rax
  unsigned int v9; // ecx
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  signed __int64 v14; // rax
  unsigned int v15; // ecx

  v2 = simObject;
  v3 = result;
  result->mFlags[1] = 0i64;
  result->mFlags[0] = 0i64;
  v4 = (UFG::qPropertyList *)PropertyUtils::Get<UFG::qPropertyList>(
                               simObject->m_pSceneObj,
                               (UFG::qSymbol *)&TiDoSym_VoiceTagList.mUID);
  if ( qSymbol_Male.mUID )
    UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Male.mUID);
  v5 = UFG::IsFemale(v2);
  v6 = qSymbol_Female.mUID;
  if ( !v5 )
    v6 = qSymbol_Male.mUID;
  if ( v6 && (v7 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v6)) != 0i64 )
    v8 = (signed __int64)&v7[-1].mCount;
  else
    v8 = 0i64;
  v9 = *(_DWORD *)(v8 + 44);
  if ( v9 >= 0x40 )
    v3->mFlags[1] |= 1i64 << ((unsigned __int8)v9 - 64);
  else
    v3->mFlags[0] |= 1i64 << v9;
  v10 = v4->mNumElements;
  v11 = 0;
  if ( v10 )
  {
    do
    {
      v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v4, v11)->mUID;
      if ( v12 && (v13 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v12)) != 0i64 )
        v14 = (signed __int64)&v13[-1].mCount;
      else
        v14 = 0i64;
      v15 = *(_DWORD *)(v14 + 44);
      if ( v15 >= 0x40 )
        v3->mFlags[1] |= 1i64 << ((unsigned __int8)v15 - 64);
      else
        v3->mFlags[0] |= 1i64 << v15;
      ++v11;
    }
    while ( v11 < v10 );
  }
  return v3;
}

// File Line: 424
// RVA: 0x5973B0
UFG::BitFlags128 *__fastcall UFG::VoiceProfileManager::BuildBitFlags(UFG::BitFlags128 *result, UFG::qPropertySet *pSet)
{
  UFG::qPropertySet *v2; // rsi
  UFG::BitFlags128 *v3; // rbx
  UFG::qPropertyList *v4; // rbp
  UFG::qBaseTreeRB *v5; // rax
  signed __int64 v6; // rdi
  UFG::qSymbol *v7; // rax
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // edx
  UFG::qBaseTreeRB *v14; // rax
  signed __int64 v15; // rax
  unsigned int v16; // ecx

  v2 = pSet;
  v3 = result;
  result->mFlags[1] = 0i64;
  result->mFlags[0] = 0i64;
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(pSet, (UFG::qSymbol *)&TiDoSym_VoiceTagList.mUID, DEPTH_RECURSE);
  if ( qSymbol_Male.mUID
    && (v5 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, qSymbol_Male.mUID)) != 0i64 )
  {
    v6 = (signed __int64)&v5[-1].mCount;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_Gender.mUID, DEPTH_RECURSE);
  if ( v7 )
  {
    v8 = qSymbol_Female.mUID;
    if ( v7->mUID != qSymbol_Female.mUID )
      v8 = qSymbol_Male.mUID;
    if ( v8 && (v9 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v8)) != 0i64 )
      v6 = (signed __int64)&v9[-1].mCount;
    else
      v6 = 0i64;
  }
  v10 = *(_DWORD *)(v6 + 44);
  if ( v10 >= 0x40 )
    v3->mFlags[1] |= 1i64 << ((unsigned __int8)v10 - 64);
  else
    v3->mFlags[0] |= 1i64 << v10;
  v11 = v4->mNumElements;
  v12 = 0;
  if ( v11 )
  {
    do
    {
      v13 = UFG::qPropertyList::Get<UFG::qSymbol>(v4, v12)->mUID;
      if ( v13 && (v14 = UFG::qBaseTreeRB::Get(&UFG::VoiceProfileManager::sm_voiceTags.mTree, v13)) != 0i64 )
        v15 = (signed __int64)&v14[-1].mCount;
      else
        v15 = 0i64;
      v16 = *(_DWORD *)(v15 + 44);
      if ( v16 >= 0x40 )
        v3->mFlags[1] |= 1i64 << ((unsigned __int8)v16 - 64);
      else
        v3->mFlags[0] |= 1i64 << v16;
      ++v12;
    }
    while ( v12 < v11 );
  }
  return v3;
}

// File Line: 550
// RVA: 0x593830
void __fastcall UFG::VoiceProfile::VoiceProfile(UFG::VoiceProfile *this, __int64 wwiseId, UFG::BitFlags128 *flags, bool isTC)
{
  bool v4; // si
  UFG::BitFlags128 *v5; // rdi
  unsigned int *v6; // r14
  UFG::VoiceProfile *v7; // r15
  AMD_HD3D *v8; // rcx

  v4 = isTC;
  v5 = flags;
  v6 = (unsigned int *)wwiseId;
  v7 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->vfptr = (UFG::VoiceProfileVtbl *)&UFG::VoiceProfile::`vftable;
  v8 = (AMD_HD3D *)*(unsigned int *)wwiseId;
  v7->m_wwiseVoiceUid.mUID = (unsigned int)v8;
  _(v8);
  v7->m_wwiseTagsUid.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  UFG::qString::qString(&v7->m_subtitleSet);
  v7->m_weight = 50;
  v7->m_bitFlags.mFlags[0] = v5->mFlags[0];
  v7->m_bitFlags.mFlags[1] = v5->mFlags[1];
  v7->mNode.mUID = *v6;
  UFG::qString::Set(&v7->m_subtitleSet, &customWorldMapCaption);
  *((_BYTE *)v7 + 112) &= 0xFEu;
  *((_BYTE *)v7 + 112) |= v4;
  _((AMD_HD3D *)*v6);
}

// File Line: 570
// RVA: 0x596FF0
bool __fastcall UFG::VoiceProfile::BankRequiredForExertions(UFG::VoiceProfile *this)
{
  UFG::VoiceProfile *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax

  v1 = this;
  v2 = _S37_1;
  if ( !(_S37_1 & 1) )
  {
    _S37_1 |= 1u;
    UFG::qWiseSymbol::create_from_string(&girl_1_0, "girl_1");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__girl_1__);
    v2 = _S37_1;
  }
  if ( !(v2 & 2) )
  {
    _S37_1 = v2 | 2;
    UFG::qWiseSymbol::create_from_string(&girl_2_0, "girl_2");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__girl_2__);
    v2 = _S37_1;
  }
  if ( !(v2 & 4) )
  {
    _S37_1 = v2 | 4;
    UFG::qWiseSymbol::create_from_string(&man_1_0, "man_1");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__man_1__);
    v2 = _S37_1;
  }
  if ( !(v2 & 8) )
  {
    _S37_1 = v2 | 8;
    UFG::qWiseSymbol::create_from_string(&man_2_0, "man_2");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__man_2__);
    v2 = _S37_1;
  }
  if ( !(v2 & 0x10) )
  {
    _S37_1 = v2 | 0x10;
    UFG::qWiseSymbol::create_from_string(&old_man_0, "old_man");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__old_man__);
    v2 = _S37_1;
  }
  if ( !(v2 & 0x20) )
  {
    _S37_1 = v2 | 0x20;
    UFG::qWiseSymbol::create_from_string(&old_lady_0, "old_lady");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__old_lady__);
    v2 = _S37_1;
  }
  if ( !(v2 & 0x40) )
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
  if ( !_bittest((const signed int *)&v2, 8u) )
  {
    _S37_1 = v2 | 0x100;
    UFG::qWiseSymbol::create_from_string(&thug_4_0, "thug_4");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__thug_4__);
    v2 = _S37_1;
  }
  if ( !_bittest((const signed int *)&v2, 9u) )
  {
    _S37_1 = v2 | 0x200;
    UFG::qWiseSymbol::create_from_string(&thug_2_0, "thug_2");
    atexit(UFG::VoiceProfile::BankRequiredForExertions_::_2_::_dynamic_atexit_destructor_for__thug_2__);
  }
  v3 = v1->m_wwiseTagsUid.mUID;
  return v3 != girl_1_0.mUID
      && v3 != girl_2_0.mUID
      && v3 != man_1_0.mUID
      && v3 != man_2_0.mUID
      && v3 != old_man_0.mUID
      && v3 != old_lady_0.mUID
      && v3 != thug_1_0.mUID
      && v3 != thug_2_0.mUID
      && v3 != thug_3_0.mUID
      && v3 != thug_4_0.mUID;
}

