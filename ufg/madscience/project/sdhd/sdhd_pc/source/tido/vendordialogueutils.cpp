// File Line: 25
// RVA: 0x1554EE0
__int64 dynamic_initializer_for__UFG::VendorDialogueUtils::sm_vendorVoiceStr__()
{
  UFG::qString::qString(&UFG::VendorDialogueUtils::sm_vendorVoiceStr, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::VendorDialogueUtils::sm_vendorVoiceStr__);
}

// File Line: 27
// RVA: 0x1554C10
__int64 dynamic_initializer_for__UFG::VendorDialogueUtils::sm_controller__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::VendorDialogueUtils::sm_controller__);
}

// File Line: 42
// RVA: 0x5ABC10
void __fastcall UFG::VendorDialogueUtils::Setup(UFG::StoreFront *store)
{
  UFG::StoreFront *v1; // rdi
  UFG::allocator::free_link *v2; // rax
  UFG::VendorDialogueUtils *v3; // rbx
  _BOOL8 v4; // rdx
  UFG::qWiseSymbol v5; // [rsp+50h] [rbp+8h]
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]
  UFG::allocator::free_link *v7; // [rsp+60h] [rbp+18h]

  v1 = store;
  if ( !UFG::VendorDialogueUtils::sm_instance )
  {
    v2 = UFG::qMalloc(0x140ui64, "VendorDialogueUtils", 0i64);
    v3 = (UFG::VendorDialogueUtils *)v2;
    v7 = v2;
    if ( v2 )
    {
      UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)v2);
      v3->vfptr = (UFG::AudioEntityVtbl *)&UFG::VendorDialogueUtils::`vftable';
    }
    else
    {
      v3 = 0i64;
    }
    UFG::VendorDialogueUtils::sm_instance = v3;
    UFG::qSymbol::create_from_string(&result, "VendorDialogue");
    (*(void (__fastcall **)(UFG::VendorDialogueUtils *, UFG::qSymbol *, UFG::qMatrix44 *))UFG::VendorDialogueUtils::sm_instance->vfptr->gap8)(
      UFG::VendorDialogueUtils::sm_instance,
      &result,
      &UFG::qMatrix44::msIdentity);
    LOBYTE(v4) = 1;
    UFG::VendorDialogueUtils::sm_instance->vfptr->SetShouldFollowListener(
      (UFG::AudioEntity *)UFG::VendorDialogueUtils::sm_instance,
      v4);
  }
  UFG::VendorDialogueUtils::sm_currentStore = v1;
  UFG::VendorDialogueUtils::GetVendorVoiceId();
  UFG::VendorDialogueUtils::sm_moneySpent = 0.0;
  UFG::VendorDialogueUtils::sm_idleTime = 0.0;
  UFG::VendorDialogueUtils::sm_playBrowse = 0;
  UFG::qWiseSymbol::create_from_string(&v5, "set_wardrobe_enter");
  UFG::AudioEntity::CreateAndPlayEvent(
    (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
    v5.mUID,
    0i64,
    0,
    0i64);
  _((AMD_HD3D *)v5.mUID);
}

// File Line: 68
// RVA: 0x598760
void UFG::VendorDialogueUtils::Cleanup(void)
{
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+8h]

  if ( UFG::VendorDialogueUtils::sm_instance )
  {
    UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&UFG::VendorDialogueUtils::sm_instance->vfptr);
    if ( UFG::VendorDialogueUtils::sm_instance )
      UFG::VendorDialogueUtils::sm_instance->vfptr->__vecDelDtor(
        (UFG::AudioEntity *)UFG::VendorDialogueUtils::sm_instance,
        1u);
    UFG::VendorDialogueUtils::sm_instance = 0i64;
    UFG::qWiseSymbol::create_from_string(&result, "set_wardrobe_exit");
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
      result.mUID,
      0i64,
      0,
      0i64);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::VendorDialogueUtils::sm_currentStore = 0i64;
}

// File Line: 102
// RVA: 0x5A7CC0
void __fastcall UFG::VendorDialogueUtils::PlayStoreClerkDialogue(UFG::VendorDialogueUtils::eVendorDialogueContext context, float frequencyOverride)
{
  float v2; // xmm7_4
  UFG::VendorDialogueUtils::eVendorDialogueContext v3; // edi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::VendorDialogueUtils *v5; // rcx
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm0
  UFG::VendorDialogueUtils *v9; // rax
  bool v10; // bl
  UFG::StoreFront *v11; // rdx
  UFG::GameStatTracker *v12; // rax
  bool v13; // r8
  const char *v14; // rcx
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  UFG::GameStatTracker *v18; // rax
  signed int v19; // eax
  const char *v20; // rcx
  UFG::qSymbol *v21; // rax
  unsigned int *v22; // rax
  UFG::GameStatTracker *v23; // rax
  signed int v24; // ebx
  const char *v25; // rcx
  UFG::qString v26; // [rsp+28h] [rbp-48h]
  UFG::qWiseSymbol eventId; // [rsp+90h] [rbp+20h]
  UFG::qSymbol result; // [rsp+98h] [rbp+28h]

  v2 = frequencyOverride;
  v3 = context;
  if ( UFG::VendorDialogueUtils::sm_currentStore )
  {
    if ( LocalPlayer )
    {
      v4 = LocalPlayer->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      v5 = UFG::VendorDialogueUtils::sm_instance;
      v6 = v4->mWorldTransform.v1;
      v7 = v4->mWorldTransform.v2;
      v8 = v4->mWorldTransform.v3;
      UFG::VendorDialogueUtils::sm_instance->m_WorldMatrix.v0 = v4->mWorldTransform.v0;
      v5->m_WorldMatrix.v1 = v6;
      v5->m_WorldMatrix.v2 = v7;
      v5->m_WorldMatrix.v3 = v8;
      UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v5->vfptr);
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v9 = UFG::VendorDialogueUtils::sm_instance;
      v7.x = v4->mWorldTransform.v3.y;
      v6.x = v4->mWorldTransform.v3.z;
      UFG::VendorDialogueUtils::sm_instance->m_WorldMatrix.v3.x = v4->mWorldTransform.v3.x;
      v9->m_WorldMatrix.v3.y = v7.x;
      v9->m_WorldMatrix.v3.z = v6.x;
      v9->m_WorldMatrix.v3.w = 1.0;
      UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&UFG::VendorDialogueUtils::sm_instance->vfptr);
    }
    v10 = strstr(UFG::VendorDialogueUtils::sm_vendorVoiceStr.mData, "Exotic") != 0i64;
    eventId.mUID = play_2d_22.mUID;
    _((AMD_HD3D *)play_2d_22.mUID);
    v11 = UFG::VendorDialogueUtils::sm_currentStore;
    if ( UFG::VendorDialogueUtils::sm_currentStore->mStoreType != 1 )
    {
      UFG::qWiseSymbol::operator=(&eventId, (UFG::qWiseSymbol *)&play_attendents_22.mUID);
      v11 = UFG::VendorDialogueUtils::sm_currentStore;
    }
    switch ( v3 )
    {
      case 0:
        if ( (unsigned int)(v11->mInventoryType - 62) > 1 )
          goto LABEL_53;
        v12 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::GetFaceLevel(v12);
        v13 = 0;
        v14 = "shop_sales_pitch_garage";
        goto LABEL_52;
      case 1:
        v15 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
        if ( v10 )
          v16 = UFG::VendorDialogueUtils::sm_vendorSpeakChance * 0.25;
        else
          v16 = UFG::VendorDialogueUtils::sm_vendorSpeakChance / v2;
        if ( v15 > v16 )
          goto LABEL_54;
        if ( (unsigned int)(UFG::VendorDialogueUtils::sm_currentStore->mInventoryType - 62) <= 1 )
        {
          if ( UFG::VendorDialogueUtils::PlayLineExternal("garage_clerk_comment", &eventId, 0) )
            goto LABEL_53;
          v13 = 0;
          v14 = "shop_clerk_comment_garage";
          goto LABEL_52;
        }
        if ( v10 )
        {
          v13 = 0;
          v14 = "shop_sales_comment_clothes";
          goto LABEL_52;
        }
        v17 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
        if ( v17 < 0.33000001 )
        {
          v13 = 0;
          v14 = "shop_sales_pitch_clothes";
          goto LABEL_52;
        }
        if ( v17 < 0.66000003 )
        {
          v13 = 0;
          v14 = "shop_clerk_comment_clothes";
          goto LABEL_52;
        }
        goto LABEL_53;
      case 2:
        if ( (unsigned int)(v11->mInventoryType - 62) <= 1 )
        {
          v18 = UFG::GameStatTracker::Instance();
          v19 = UFG::GameStatTracker::GetFaceLevel(v18);
          v20 = "garage_complete";
          if ( v19 >= 2 )
            v20 = "garage_complete_high_face";
          if ( !UFG::VendorDialogueUtils::PlayLineExternal(v20, &eventId, 0) )
          {
            UFG::VendorDialogueUtils::PlayLineExternal("shop_sale_complete_garage", &eventId, 0);
            UFG::VendorDialogueUtils::sm_moneySpent = UFG::VendorDialogueUtils::sm_moneySpent + 10000.0;
          }
          goto LABEL_53;
        }
        if ( UFG::VendorDialogueUtils::sm_lastItemPurchased )
        {
          v21 = UFG::qSymbol::create_from_string(&result, "DialogueOnPurchase");
          v22 = UFG::qPropertySet::Get<unsigned long>(
                  UFG::VendorDialogueUtils::sm_lastItemPurchased,
                  v21,
                  DEPTH_RECURSE);
          if ( v22 )
          {
            UFG::qString::FormatEx(&v26, "shop_sale_complete_clothes_specific.%03d", *v22);
            UFG::VendorDialogueUtils::PlayLineExternal(v26.mData, &eventId, 0);
            UFG::qString::~qString(&v26);
            goto LABEL_53;
          }
        }
        v13 = 0;
        v14 = "shop_sale_complete_clothes";
        goto LABEL_52;
      case 3:
        v13 = 0;
        if ( (unsigned int)(v11->mInventoryType - 62) > 1 )
          v14 = "shop_idle_clothes";
        else
          v14 = "shop_idle_garage";
        goto LABEL_52;
      case 4:
        v13 = 0;
        if ( v10 )
        {
          v14 = "shop_exit_no_money";
        }
        else if ( (unsigned int)(v11->mInventoryType - 62) > 1 )
        {
          v14 = "shop_no_money_clothes";
        }
        else
        {
          v14 = "shop_no_money";
        }
        goto LABEL_52;
      case 5:
        if ( (unsigned int)(v11->mInventoryType - 62) > 1 )
        {
          if ( UFG::VendorDialogueUtils::sm_moneySpent >= 1.0 )
          {
            v14 = "shop_exit_med_clothes";
            if ( UFG::VendorDialogueUtils::sm_moneySpent >= 4000.0 )
              v14 = "shop_exit_high_clothes";
          }
          else
          {
            v14 = "shop_exit_low_clothes";
          }
          v13 = 1;
          goto LABEL_52;
        }
        v23 = UFG::GameStatTracker::Instance();
        v24 = UFG::GameStatTracker::GetFaceLevel(v23);
        v25 = "shop_sale_complete_garage";
        if ( UFG::VendorDialogueUtils::sm_moneySpent <= 0.0 )
          v25 = "shop_exit_low_garage";
        if ( !UFG::VendorDialogueUtils::PlayLineExternal(v25, &eventId, 1)
          && UFG::VendorDialogueUtils::sm_moneySpent > 0.0 )
        {
          v13 = 1;
          if ( v24 >= 2 )
            v14 = "garage_complete_high_face";
          else
            v14 = "garage_complete";
LABEL_52:
          UFG::VendorDialogueUtils::PlayLineExternal(v14, &eventId, v13);
        }
LABEL_53:
        UFG::VendorDialogueUtils::sm_idleTime = 0.0;
LABEL_54:
        _((AMD_HD3D *)eventId.mUID);
        break;
      default:
        goto LABEL_53;
    }
  }
}

// File Line: 362
// RVA: 0x5AAEF0
void __fastcall UFG::VendorDialogueUtils::SetLastItemPurchased(UFG::qPropertySet *ps)
{
  UFG::VendorDialogueUtils::sm_lastItemPurchased = ps;
}

// File Line: 372
// RVA: 0x5986F0
void UFG::VendorDialogueUtils::ChooseTempClerkVoice(void)
{
  UFG::qSymbol *v0; // rax
  unsigned int v1; // eax
  char v2; // dl

  v0 = UFG::qPropertySet::Get<UFG::qSymbol>(
         UFG::VendorDialogueUtils::sm_currentStore->mpStoreParameters,
         (UFG::qSymbol *)&qSymbol_Gender.mUID,
         DEPTH_RECURSE);
  if ( v0 )
  {
    v1 = v0->mUID;
    v2 = 0;
    if ( v1 == qSymbol_Male.mUID )
      v2 = 1;
    if ( v1 != qSymbol_Female.mUID && v2 )
      UFG::qString::Set(&UFG::VendorDialogueUtils::sm_vendorVoiceStr, "MrFong");
  }
  UFG::qString::Set(&UFG::VendorDialogueUtils::sm_vendorVoiceStr, "Fan");
}

// File Line: 401
// RVA: 0x59D770
char __fastcall UFG::VendorDialogueUtils::GetVendorVoiceId()
{
  char result; // al
  UFG::SimObject *v1; // rcx
  __int64 v2; // rdx
  UFG::qPropertySet *v3; // rdi
  char *v4; // rbx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v5; // rdx

  result = (char)UFG::VendorDialogueUtils::sm_currentStore;
  if ( UFG::VendorDialogueUtils::sm_currentStore )
  {
    v1 = UFG::VendorDialogueUtils::sm_currentStore->mpStoreOwner;
    if ( v1 )
    {
      v2 = *(_QWORD *)&UFG::SimObject::GetComponentOfType(v1, UFG::ActorAudioComponent::_TypeUID)[6].m_Flags;
      if ( v2 )
        UFG::qString::Set(&UFG::VendorDialogueUtils::sm_vendorVoiceStr, *(const char **)(v2 + 72));
      else
        UFG::qString::Set(&UFG::VendorDialogueUtils::sm_vendorVoiceStr, &customWorldMapCaption);
      result = 1;
    }
    else
    {
      v3 = UFG::VendorDialogueUtils::sm_currentStore->mpStoreParameters;
      v4 = PropertyUtils::Get<char const *>(
             UFG::VendorDialogueUtils::sm_currentStore->mpStoreParameters,
             (UFG::qSymbol *)&qSymbol_Voice.mUID,
             DEPTH_RECURSE);
      if ( (unsigned int)UFG::qStringCompareInsensitive(v4, "NOTSET", -1) )
        v5 = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)v4;
      else
        v5 = UFG::VoiceProfileManager::AssignVoice(v3)[4].mNext;
      UFG::qString::Set(&UFG::VendorDialogueUtils::sm_vendorVoiceStr, (const char *)v5);
      if ( !v4 || !(unsigned int)UFG::qStringCompareInsensitive("NOTSET", v4, -1) )
        UFG::VendorDialogueUtils::ChooseTempClerkVoice();
      result = 1;
    }
  }
  return result;
}

// File Line: 446
// RVA: 0x5A6750
char __fastcall UFG::VendorDialogueUtils::PlayLineExternal(const char *context, UFG::qWiseSymbol *eventId, bool subtitle)
{
  bool v3; // si
  UFG::qWiseSymbol *v4; // r14
  const char *v5; // rdi
  __int64 v6; // rbx
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  unsigned int v9; // eax
  char v10; // bl
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rcx
  __int64 v15; // rbx
  UFG::AudioEvent *v16; // rcx
  UFG::AudioEventCallbackObject *v17; // rbx
  unsigned int v18; // eax
  UFG::qString v20; // [rsp+40h] [rbp-68h]
  UFG::qString result; // [rsp+68h] [rbp-40h]
  unsigned int final_hash; // [rsp+C8h] [rbp+20h]

  v3 = subtitle;
  v4 = eventId;
  v5 = context;
  if ( UFG::VendorDialogueUtils::sm_controller.m_pEvent )
    return 0;
  v6 = (signed int)UFG::qStringLength(context);
  final_hash = 0;
  UFG::qString::qString(&v20);
  if ( v5[v6 - 1] <= 57
    && v5[v6 - 1] >= 48
    && v5[v6 - 2] <= 57
    && v5[v6 - 2] >= 48
    && v5[v6 - 3] <= 57
    && v5[v6 - 3] >= 48 )
  {
    v7 = UFG::qString::FormatEx(&result, "%s.%s.", UFG::VendorDialogueUtils::sm_vendorVoiceStr.mData, v5);
    UFG::qString::Set(&v20, v7->mData, v7->mLength, 0i64, 0);
  }
  else
  {
    v8 = UFG::qString::FormatEx(&result, "%s.%s.%s.", UFG::VendorDialogueUtils::sm_vendorVoiceStr.mData, v5, "001");
    UFG::qString::Set(&v20, v8->mData, v8->mLength, 0i64, 0);
  }
  UFG::qString::~qString(&result);
  v9 = UFG::TiDo::CalcWwiseUid(v20.mData);
  if ( (signed int)UFG::ExternalSourceUtil::GetRandomVariation(v9, &final_hash, -1) < 0 )
  {
    v10 = 0;
LABEL_29:
    UFG::qString::~qString(&v20);
    return v10;
  }
  v11 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x20ui64, "ExternalSourceInfo.QueueSpeech", 0i64, 1u);
  if ( v11 )
  {
    UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo((UFG::AudioEventExternalSourceInfo *)v11, 1u);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  (*(UFG::qStaticWiseSymbol **)(v13 + 24))->mUID = slot_1_22.mUID;
  v14 = *(_QWORD *)(v13 + 24);
  *(_DWORD *)(v14 + 8) = final_hash;
  v15 = *(_QWORD *)(v13 + 24);
  *(_DWORD *)(v15 + 4) = Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)v14);
  UFG::AudioEntity::CreateEventA(
    (UFG::AudioEntity *)&UFG::VendorDialogueUtils::sm_instance->vfptr,
    v4->mUID,
    (UFG::AudioEventController *)&UFG::VendorDialogueUtils::sm_controller.m_pEvent,
    0i64,
    (UFG::AudioEventExternalSourceInfo *)v13);
  v16 = UFG::VendorDialogueUtils::sm_controller.m_pEvent;
  if ( UFG::VendorDialogueUtils::sm_controller.m_pEvent )
  {
    if ( !v3 )
      goto LABEL_23;
    v17 = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
    if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
    {
      UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
      v18 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
      UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v18;
      if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v18 )
        UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v18;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
    }
    if ( v17 )
    {
      v17->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
      v17->m_next = 0i64;
      v17->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SubtitleCallback::`vftable';
    }
    else
    {
      v17 = 0i64;
    }
    if ( UFG::VendorDialogueUtils::sm_controller.m_pEvent )
    {
      UFG::AudioEvent::AddCallback(UFG::VendorDialogueUtils::sm_controller.m_pEvent, v17);
      v16 = UFG::VendorDialogueUtils::sm_controller.m_pEvent;
LABEL_23:
      if ( v16 )
      {
        if ( v16->vfptr->Play(v16, 0) )
        {
          v10 = 1;
          goto LABEL_29;
        }
        *((_BYTE *)UFG::VendorDialogueUtils::sm_controller.m_pEvent + 144) |= 4u;
        if ( UFG::VendorDialogueUtils::sm_controller.m_pEvent )
          UFG::VendorDialogueUtils::sm_controller.m_pEvent->m_pController = 0i64;
        UFG::VendorDialogueUtils::sm_controller.m_pEvent = 0i64;
      }
      goto LABEL_30;
    }
  }
LABEL_30:
  UFG::qString::~qString(&v20);
  return 0;
}

