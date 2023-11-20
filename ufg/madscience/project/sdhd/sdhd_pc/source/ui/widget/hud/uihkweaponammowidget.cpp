// File Line: 48
// RVA: 0x5C8C50
void __fastcall UFG::UIWeaponAmmoData::UIWeaponAmmoData(UFG::UIWeaponAmmoData *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::GunComponent> *v1; // [rsp+28h] [rbp+10h]

  *(_QWORD *)&this->ReserveAmmo = -1i64;
  *(_QWORD *)&this->ClipCapacity = -1i64;
  *(_QWORD *)&this->OldClips = -1i64;
  *(_WORD *)&this->IsCamera = 0;
  this->InventoryItem = 0;
  this->IconTexture = 0i64;
  this->TexturePack = 0i64;
  v1 = &this->mGunComponent;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  this->mGunComponent.m_pPointer = 0i64;
}

// File Line: 53
// RVA: 0x619BB0
void __fastcall UFG::UIWeaponAmmoData::Update(UFG::UIWeaponAmmoData *this, UFG::SimObject *weapon, bool *weaponChanged, bool *ammoChanged)
{
  UFG::SimObjectGame *v4; // rdi
  bool *v5; // r14
  bool *v6; // r12
  UFG::UIWeaponAmmoData *v7; // rbx
  UFG::SimObjectWeaponPropertiesComponent *v8; // rbp
  UFG::InventoryItemComponent *v9; // rsi
  UFG::SimComponent *v10; // r15
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // cx
  UFG::SimObjectWeaponPropertiesComponent *v14; // rax
  unsigned __int16 v15; // cx
  UFG::InventoryItemComponent *v16; // rax
  unsigned __int16 v17; // cx
  UFG::SimComponent *v18; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::GunComponent> *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::eInventoryItemEnum v23; // edi
  char v24; // al
  UFG::eInventoryItemEnum v25; // ecx
  bool v26; // cl
  bool v27; // al
  bool v28; // zf
  int v29; // edi
  UFG::GunComponent *v30; // rcx
  int v31; // eax
  UFG::GunComponent *v32; // rcx
  int v33; // eax
  UFG::GunComponent *v34; // rcx
  int v35; // eax
  UFG::GunComponent *v36; // rcx
  int v37; // eax
  bool v38; // sf

  v4 = (UFG::SimObjectGame *)weapon;
  v5 = ammoChanged;
  v6 = weaponChanged;
  v7 = this;
  if ( !weapon )
  {
    v8 = 0i64;
LABEL_3:
    v9 = 0i64;
    goto LABEL_4;
  }
  v13 = weapon->m_Flags;
  if ( (v13 >> 14) & 1 )
  {
    v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)weapon,
                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  else if ( (v13 & 0x8000u) == 0 )
  {
    if ( (v13 >> 13) & 1 )
    {
      v14 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>((UFG::SimObjectProp *)weapon);
    }
    else if ( (v13 >> 12) & 1 )
    {
      v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)weapon,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    else
    {
      v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                         weapon,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)weapon,
                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  v15 = v4->m_Flags;
  v8 = v14;
  if ( (v15 >> 14) & 1 || (v15 & 0x8000u) != 0 )
    goto LABEL_3;
  if ( (v15 >> 13) & 1 )
  {
    v9 = (UFG::InventoryItemComponent *)v4->m_Components.p[11].m_pComponent;
  }
  else
  {
    if ( (v15 >> 12) & 1 )
      v16 = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v4,
                                             UFG::InventoryItemComponent::_TypeUID);
    else
      v16 = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v4->vfptr,
                                             UFG::InventoryItemComponent::_TypeUID);
    v9 = v16;
  }
  if ( v9 )
  {
    v10 = v9->m_pOwnerInventoryComponent.m_pPointer;
    goto LABEL_5;
  }
LABEL_4:
  v10 = 0i64;
LABEL_5:
  *v6 = 0;
  *v5 = 0;
  v11 = v7->mGunComponent.m_pPointer;
  if ( !v11 || (UFG::SimObjectGame *)v11->m_pSimObject != v4 )
  {
    if ( v4 )
    {
      v17 = v4->m_Flags;
      if ( (v17 >> 14) & 1 )
      {
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v17 & 0x8000u) == 0 )
      {
        if ( (v17 >> 13) & 1 )
        {
          v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else if ( (v17 >> 12) & 1 )
        {
          v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else
        {
          v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::GunComponent::_TypeUID);
        }
      }
      else
      {
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      v12 = v18;
    }
    else
    {
      v12 = 0i64;
    }
    v19 = &v7->mGunComponent;
    if ( v7->mGunComponent.m_pPointer )
    {
      v20 = v19->mPrev;
      v21 = v7->mGunComponent.mNext;
      v20->mNext = v21;
      v21->mPrev = v20;
      v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
      v7->mGunComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mGunComponent.mPrev;
    }
    v7->mGunComponent.m_pPointer = v12;
    if ( v12 )
    {
      v22 = v12->m_SafePointerList.mNode.mPrev;
      v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
      v19->mPrev = v22;
      v7->mGunComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    }
  }
  if ( v8 && v9 )
  {
    v23 = v9->m_eInventoryItem;
    if ( !v8->mIsPhoneCamera || v7->IsCamera )
    {
      if ( v7->InventoryItem != v23 )
      {
        *v6 = 1;
        v7->IsCamera = 0;
        v24 = UFG::UIHKWeaponAmmoWidget::GetWeaponImageInfo(v23, &v7->TexturePack, &v7->IconTexture);
        v25 = 0;
        if ( v24 )
          v25 = v23;
        v7->InventoryItem = v25;
      }
    }
    else
    {
      *v6 = 1;
      v7->IsCamera = 1;
      v7->TexturePack = 0i64;
      v7->InventoryItem = 36;
      v7->IconTexture = "Icon_camera";
    }
  }
  v26 = v7->UnlimitedAmmo;
  v27 = v10 && BYTE1(v10[14].m_pSimObject);
  v7->UnlimitedAmmo = v27;
  *v5 |= v27 != v26;
  v28 = v7->IsCamera == 0;
  v29 = v7->ClipAmmo;
  v7->OldClips = v7->Clips;
  v7->OldReserveAmmo = v7->ReserveAmmo;
  if ( v28 )
  {
    v30 = (UFG::GunComponent *)v7->mGunComponent.m_pPointer;
    if ( v30 )
    {
      v31 = UFG::GunComponent::GetTotalAmmo(v30);
      v32 = (UFG::GunComponent *)v7->mGunComponent.m_pPointer;
      v7->ReserveAmmo = v31;
      v33 = UFG::GunComponent::GetClipAmmo(v32);
      v34 = (UFG::GunComponent *)v7->mGunComponent.m_pPointer;
      v7->ClipAmmo = v33;
      v35 = UFG::GunComponent::GetClipCapacity(v34);
      v36 = (UFG::GunComponent *)v7->mGunComponent.m_pPointer;
      v7->ClipCapacity = v35;
      v37 = UFG::GunComponent::GetClipsRemaining(v36);
      v38 = v7->ClipAmmo < 0;
      v7->Clips = v37;
      if ( v38 )
        v7->ClipAmmo = 0;
    }
    else
    {
      *(_QWORD *)&v7->ClipAmmo = -1i64;
      v7->Clips = -1;
    }
  }
  else
  {
    if ( UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Camera") )
    {
      v7->ReserveAmmo = 0;
      UFG::UIScreenManagerBase::getOverlay(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        "Camera");
      v7->ClipAmmo = 1;
      v7->ClipCapacity = -1;
    }
    *v5 |= v7->ClipAmmo != v29;
  }
  if ( v7->ClipAmmo != v29 || v7->Clips != v7->OldClips || v7->ReserveAmmo != v7->OldReserveAmmo || *v6 )
    *v5 |= 1u;
}
  }
  if ( v7->ClipAmmo != v29 || v7->Clips != v7->OldClips || v7->ReserveAmmo != v7->OldReserveAmmo || *v6 )
    *v5 |= 1u;
}

// File Line: 155
// RVA: 0x5C8380
void __fastcall UFG::UIHKWeaponAmmoWidget::UIHKWeaponAmmoWidget(UFG::UIHKWeaponAmmoWidget *this)
{
  UFG::UIHKWeaponAmmoWidget *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v2; // [rsp+58h] [rbp+10h]

  v1 = this;
  *(_WORD *)&this->mVisible = 1;
  `eh vector constructor iterator'(
    this->mDisplayedWeapons,
    0x48ui64,
    1,
    (void (__fastcall *)(void *))UFG::UIWeaponAmmoData::UIWeaponAmmoData);
  v1->mTextureRefeshFlag = 0;
  UFG::qString::qString(&v1->mTexturePack);
  v2 = &v1->mTargetingSystemBaseComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mTargetingSystemBaseComponent.m_pPointer = 0i64;
  UFG::qString::qString(&v1->mLastIconTexture, &customWorldMapCaption);
  v1->mLastClipAmmo = -1;
  *(_DWORD *)&v1->mLastHasLowAmmo = 0x1000000;
  v1->mVehicleReloadPromptActive = 0;
  v1->mEquipErrorTimer = 0.0;
}

// File Line: 160
// RVA: 0x5CDA30
void __fastcall UFG::UIHKWeaponAmmoWidget::~UIHKWeaponAmmoWidget(UFG::UIHKWeaponAmmoWidget *this)
{
  UFG::UIHKWeaponAmmoWidget *v1; // rdi
  char *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  v1 = this;
  v2 = this->mTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v2);
  UFG::qString::~qString(&v1->mLastIconTexture);
  v4 = &v1->mTargetingSystemBaseComponent;
  if ( v1->mTargetingSystemBaseComponent.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->mTargetingSystemBaseComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mTargetingSystemBaseComponent.mPrev;
  }
  v1->mTargetingSystemBaseComponent.m_pPointer = 0i64;
  v7 = v4->mPrev;
  v8 = v1->mTargetingSystemBaseComponent.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->mTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mTargetingSystemBaseComponent.mPrev;
  UFG::qString::~qString(&v1->mTexturePack);
  `eh vector destructor iterator'(
    v1->mDisplayedWeapons,
    0x48ui64,
    1,
    (void (__fastcall *)(void *))UFG::UIWeaponAmmoData::~UIWeaponAmmoData);
}

// File Line: 166
// RVA: 0x5E9F50
char __fastcall UFG::UIHKWeaponAmmoWidget::GetWeaponImageInfo(UFG::eInventoryItemEnum iType, const char **szTexturePack, const char **szImageName)
{
  char result; // al

  switch ( iType )
  {
    case 1:
      *szImageName = "Icons_Weapon_EMPTY_POP_CAN";
      *szTexturePack = "Data\\UI\\Icons_Weapon_EMPTY_POP_CAN_TP.perm.bin";
      result = 1;
      break;
    case 2:
    case 3:
      *szImageName = "Icons_Weapon_BOTTLED_SODA";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BOTTLED_SODA_TP.perm.bin";
      result = 1;
      break;
    case 4:
      *szImageName = "Icons_Weapon_BATON";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BATON_TP.perm.bin";
      result = 1;
      break;
    case 5:
      *szImageName = "Icons_Weapon_TelescopingBaton";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TelescopingBaton_TP.perm.bin";
      result = 1;
      break;
    case 6:
      *szImageName = "Icons_Weapon_PicketFence";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PicketFence_TP.perm.bin";
      result = 1;
      break;
    case 7:
    case 12:
      *szImageName = "Icons_Weapon_BROOM";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BROOM_TP.perm.bin";
      result = 1;
      break;
    case 8:
      *szImageName = "Icons_Weapon_CLEAVER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CLEAVER_TP.perm.bin";
      result = 1;
      break;
    case 9:
      *szImageName = "Icons_Weapon_KNIFE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_KNIFE_TP.perm.bin";
      result = 1;
      break;
    case 10:
      *szImageName = "Icons_Weapon_STORMSWORD";
      *szTexturePack = "Data\\UI\\Icons_Weapon_STORMSWORD_TP.perm.bin";
      result = 1;
      break;
    case 11:
      *szImageName = "Icons_Weapon_STRAIGHTSWORD";
      *szTexturePack = "Data\\UI\\Icons_Weapon_STRAIGHTSWORD_TP.perm.bin";
      result = 1;
      break;
    case 14:
      *szImageName = "Icons_Weapon_UMBRELLA";
      *szTexturePack = "Data\\UI\\Icons_Weapon_UMBRELLA_TP.perm.bin";
      result = 1;
      break;
    case 17:
      *szImageName = "Icons_Weapon_SHOPPINGBAG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SHOPPINGBAG.perm.bin";
      result = 1;
      break;
    case 32:
      *szImageName = "Icons_Weapon_9MM";
      *szTexturePack = "Data\\UI\\Icons_Weapon_9MM_TP.perm.bin";
      result = 1;
      break;
    case 34:
      *szImageName = "Icons_Weapon_QSZ92";
      *szTexturePack = "Data\\UI\\Icons_Weapon_QSZ92_TP.perm.bin";
      result = 1;
      break;
    case 36:
      *szImageName = "Icons_Weapon_45CAL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_45CAL_TP.perm.bin";
      result = 1;
      break;
    case 37:
      *szImageName = "Icons_Weapon_45CAL02";
      *szTexturePack = "Data\\UI\\Icons_Weapon_45CAL02_TP.perm.bin";
      result = 1;
      break;
    case 39:
      *szImageName = "Icons_Weapon_SILVERBALLER_PISTOL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SILVERBALLER_PISTOL_TP.perm.bin";
      result = 1;
      break;
    case 40:
      *szImageName = "Icons_Weapon_RICO_PISTOL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_RICO_PISTOL_TP.perm.bin";
      result = 1;
      break;
    case 41:
    case 43:
      *szImageName = "Icons_Weapon_ACT02";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ACT02_TP.perm.bin";
      result = 1;
      break;
    case 42:
      *szImageName = "Icons_Weapon_ACT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ACT_TP.perm.bin";
      result = 1;
      break;
    case 45:
      *szImageName = "Icons_Weapon_COMBAT_RIFLE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_COMBAT_RIFLE_TP.perm.bin";
      result = 1;
      break;
    case 46:
      *szImageName = "Icons_Weapon_ARGL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ARGL_TP.perm.bin";
      result = 1;
      break;
    case 49:
      *szImageName = "Icons_Weapon_TearGas";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TearGas_TP.perm.bin";
      result = 1;
      break;
    case 50:
      *szImageName = "Icons_Weapon_PUMPS";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PUMPS_TP.perm.bin";
      result = 1;
      break;
    case 52:
      *szImageName = "Icons_Weapon_ANTIRIOT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ANTIRIOT_TP.perm.bin";
      result = 1;
      break;
    case 53:
      *szImageName = "Icons_Weapon_ANTIRIOTNOLIGHT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ANTIRIOTNOLIGHT_TP.perm.bin";
      result = 1;
      break;
    case 55:
      *szImageName = "Icons_Weapon_MP";
      *szTexturePack = "Data\\UI\\Icons_Weapon_MP_TP.perm.bin";
      result = 1;
      break;
    case 57:
      *szImageName = "Icons_Weapon_SMG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SMG_TP.perm.bin";
      result = 1;
      break;
    case 58:
    case 59:
      *szImageName = "Icons_Weapon_SMG02";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SMG02_TP.perm.bin";
      result = 1;
      break;
    case 62:
      *szImageName = "Icons_Weapon_TT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TT_TP.perm.bin";
      result = 1;
      break;
    case 65:
      *szImageName = "Icons_Weapon_CROWBAR";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CROWBAR_TP.perm.bin";
      result = 1;
      break;
    case 66:
      *szImageName = "Icons_Weapon_TIREIRON";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TIREIRON_TP.perm.bin";
      result = 1;
      break;
    case 67:
    case 124:
    case 125:
    case 139:
      *szImageName = "Icons_Weapon_STICK";
      *szTexturePack = "Data\\UI\\Icons_Weapon_STICK_TP.perm.bin";
      result = 1;
      break;
    case 70:
      *szImageName = "Icons_Weapon_GROCERYBAG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_GROCERYBAG.perm.bin";
      result = 1;
      break;
    case 72:
      *szImageName = "Icons_Weapon_GAMEGUITAR";
      *szTexturePack = "Data\\UI\\Icons_Weapon_GAMEGUITAR_TP.perm.bin";
      result = 1;
      break;
    case 73:
      *szImageName = "Icons_Weapon_SHOVEL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SHOVEL_TP.perm.bin";
      result = 1;
      break;
    case 77:
      *szImageName = "Icons_Weapon_PURSE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PURSE_TP.perm.bin";
      result = 1;
      break;
    case 78:
      *szImageName = "Icons_Weapon_HANDPURSE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_HANDPURSE.perm.bin";
      result = 1;
      break;
    case 79:
      *szImageName = "Icons_Weapon_BRIEFCASE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BRIEFCASE_TP.perm.bin";
      result = 1;
      break;
    case 113:
      *szImageName = "Icons_Weapon_PAINTCAN";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PAINTCAN.perm.bin";
      result = 1;
      break;
    case 114:
      *szImageName = "Icons_Weapon_HAMMER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_HAMMER_TP.perm.bin";
      result = 1;
      break;
    case 121:
      *szImageName = "Icons_Weapon_CANEWALKING";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CANEWALKING_TP.perm.bin";
      result = 1;
      break;
    case 122:
      *szImageName = "Icons_Weapon_SCRUBBRUSH";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SCRUBBRUSH_TP.perm.bin";
      result = 1;
      break;
    case 123:
      *szImageName = "Icons_Weapon_SQUEEGEE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SQUEEGEE_TP.perm.bin";
      result = 1;
      break;
    case 133:
      *szImageName = "Icons_Weapon_COOKINGPAN";
      *szTexturePack = "Data\\UI\\Icons_Weapon_COOKINGPAN.perm.bin";
      result = 1;
      break;
    case 135:
      *szImageName = "Icons_Weapon_WRENCH";
      *szTexturePack = "Data\\UI\\Icons_Weapon_WRENCH_TP.perm.bin";
      result = 1;
      break;
    case 144:
      *szImageName = "Icons_Weapon_MACHETETONG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_MACHETETONG_TP.perm.bin";
      result = 1;
      break;
    case 145:
      *szImageName = "Icons_Weapon_CELLPHONE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CELLPHONE.perm.bin";
      result = 1;
      break;
    case 146:
      *szImageName = "Icons_Weapon_COOKINGSPOON";
      *szTexturePack = "Data\\UI\\Icons_Weapon_COOKINGSPOON.perm.bin";
      result = 1;
      break;
    case 147:
      *szImageName = "Icons_Weapon_WOK";
      *szTexturePack = "Data\\UI\\Icons_Weapon_WOK.perm.bin";
      result = 1;
      break;
    case 148:
      *szImageName = "Icons_Weapon_BULLPENIS";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BULLPENIS_TP.perm.bin";
      result = 1;
      break;
    case 149:
      *szImageName = "Icons_Weapon_HANDGRINDER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_HANDGRINDER_TP.perm.bin";
      result = 1;
      break;
    case 151:
      *szImageName = "Icons_Weapon_FISHWRAPPED";
      *szTexturePack = "Data\\UI\\Icons_Weapon_FISHWRAPPED_TP.perm.bin";
      result = 1;
      break;
    case 154:
      *szImageName = "Icons_Weapon_FIREEXTINGUISHER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_FIREEXTINGUISHER.perm.bin";
      result = 1;
      break;
    case 155:
    case 156:
      *szImageName = "Icons_Weapon_GOLD50";
      *szTexturePack = "Data\\UI\\Icons_Weapon_GOLD50_TP.perm.bin";
      result = 1;
      break;
    case 160:
      *szImageName = "Icons_Weapon_DUFFLEBAG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_DUFFLEBAG.perm.bin";
      result = 1;
      break;
    default:
      *szImageName = "Invalid";
      *szTexturePack = 0i64;
      result = 1;
      break;
  }
  return result;
}

// File Line: 469
// RVA: 0x618760
void __fastcall UFG::UIHKWeaponAmmoWidget::Update(UFG::UIHKWeaponAmmoWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rbp
  UFG::UIHKWeaponAmmoWidget *v4; // rbx
  Scaleform::GFx::Movie *v5; // rsi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm0_4
  bool v10; // di
  UFG::SimObject *v11; // rsi
  bool v12; // r14
  bool v13; // si
  bool v14; // cl
  UFG::UIHKScreenHud *v15; // rax
  int v16; // er9
  const char *v17; // r8
  UFG::SimObjectProp *v18; // rcx
  unsigned __int16 v19; // dx
  UFG::SimObjectWeaponPropertiesComponent *v20; // rax
  bool v21; // si
  UFG::SimComponent *v22; // rax
  UFG::InputActionData *v23; // rcx
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-60h]
  bool weaponChanged; // [rsp+A8h] [rbp+10h]
  bool ammoChanged; // [rsp+B8h] [rbp+20h]

  if ( !screen )
    return;
  v3 = screen;
  v4 = this;
  v5 = screen->mRenderable->m_movie.pObject;
  if ( !v5 )
    return;
  if ( !this->mTargetingSystemBaseComponent.m_pPointer )
  {
    if ( !LocalPlayer )
      return;
    v6 = LocalPlayer->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = LocalPlayer->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&LocalPlayer->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                 (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v7 = LocalPlayer->m_Components.p[20].m_pComponent;
    }
    UFG::qSafePointer<Creature,Creature>::operator=(
      (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v4->mTargetingSystemBaseComponent,
      v7);
    if ( !v4->mTargetingSystemBaseComponent.m_pPointer )
      return;
  }
  v8 = v4->mEquipErrorTimer;
  if ( v8 > 0.0 )
  {
    v9 = v8 - elapsed;
    v4->mEquipErrorTimer = v9;
    if ( v9 <= 0.0 )
      UFG::UIHKWeaponAmmoWidget::Flash_EquipError_SetVisible(v4, v3, 0);
  }
  v10 = v4->mVisible && !UFG::UIHKScreenHud::RacePosition->mVisible;
  if ( v4->mVisibleChanged )
  {
    v4->mVisibleChanged = 0;
LABEL_26:
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = v10;
    Scaleform::GFx::Movie::SetVariable(v5, "mc_WeaponSwitcher._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    goto LABEL_29;
  }
  if ( v10 != v4->mVisible )
    goto LABEL_26;
LABEL_29:
  if ( !v4->mVisible )
    return;
  v11 = *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(*(_QWORD *)&v4->mTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                                + 25i64)
                           + *(_QWORD *)&v4->mTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                           + 40);
  if ( !v11 )
  {
    v4->mDisplayedWeapons[0].InventoryItem = 0;
    v18 = *(UFG::SimObjectProp **)(56i64
                                 * *(unsigned __int8 *)(*(_QWORD *)&v4->mTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                                      + 50i64)
                                 + *(_QWORD *)&v4->mTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                                 + 40);
    if ( v18 )
    {
      v19 = v18->m_Flags;
      if ( (v19 >> 14) & 1 )
      {
        v20 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v18->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      else if ( (v19 & 0x8000u) == 0 )
      {
        if ( (v19 >> 13) & 1 )
        {
          v20 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v18);
        }
        else if ( (v19 >> 12) & 1 )
        {
          v20 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v18->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        else
        {
          v20 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v18->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        v20 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v18->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      if ( v20 )
        v21 = v20->mWeaponTypeInfo->mFireModes[v20->mFireMode]->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID;
      if ( LocalPlayer )
      {
        v22 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&LocalPlayer->vfptr,
                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        if ( !v22 || !(((unsigned __int64)LODWORD(v22[3].m_BoundComponentHandles.mNode.mPrev) >> 9) & 1) )
        {
          v23 = UFG::ActionDef_Inventory.mDataPerController[UFG::gActiveControllerNum];
          if ( v23 )
          {
            if ( v23->mActionTrue )
            {
              v4->mEquipErrorTimer = 2.0;
              UFG::UIHKWeaponAmmoWidget::Flash_EquipError_SetVisible(v4, v3, 1);
            }
          }
        }
      }
    }
    v16 = -1;
    v17 = &customWorldMapCaption;
    goto LABEL_59;
  }
  weaponChanged = 0;
  ammoChanged = 0;
  v12 = UFG::UI::IsPlayerInVehicle();
  UFG::UIWeaponAmmoData::Update(v4->mDisplayedWeapons, v11, &weaponChanged, &ammoChanged);
  v13 = v12 != v4->mVehicleReloadPromptActive || ammoChanged;
  if ( weaponChanged )
    UFG::UIHKWeaponAmmoWidget::LoadWeaponTexture(v4, v4->mDisplayedWeapons[0].TexturePack);
  if ( v13 )
  {
    v14 = v4->mDisplayedWeapons[0].ClipAmmo > 0;
    v15 = UFG::UIHKScreenHud::mInstance;
    if ( UFG::UIHKScreenHud::mInstance )
    {
      if ( UFG::UIHKScreenHud::mInstance->Reticle.mHasAmmo != v14 )
      {
        UFG::UIHKScreenHud::mInstance->Reticle.mHasAmmo = v14;
        *(_WORD *)&v15->Reticle.mChanged = 257;
      }
    }
    UFG::UIHKWeaponAmmoWidget::Flash_SetAmmo(v4, v3, v4->mDisplayedWeapons, weaponChanged);
  }
  if ( v4->mTextureRefeshFlag )
  {
    v4->mTextureRefeshFlag = 0;
    v16 = v4->mDisplayedWeapons[0].ClipAmmo;
    v17 = v4->mDisplayedWeapons[0].IconTexture;
LABEL_59:
    UFG::UIHKWeaponAmmoWidget::Flash_SetWeapon(v4, v3, v17, v16);
  }
}

// File Line: 572
// RVA: 0x612990
void __fastcall UFG::UIHKWeaponAmmoWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  if ( UFG::UIHKScreenHud::mInstance )
    UFG::UIHKScreenHud::mInstance->WeaponAmmo.mTextureRefeshFlag = 1;
}

// File Line: 580
// RVA: 0x5F1B80
void __fastcall UFG::UIHKWeaponAmmoWidget::LoadWeaponTexture(UFG::UIHKWeaponAmmoWidget *this, const char *texturePack)
{
  char *v2; // rbx
  const char *v3; // rsi
  UFG::UIHKWeaponAmmoWidget *v4; // rdi
  UFG::UIScreenTextureManager *v5; // rax
  const char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  v2 = this->mTexturePack.mData;
  v3 = texturePack;
  v4 = this;
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v5, v2);
  if ( v3 )
  {
    UFG::qString::Set(&v4->mTexturePack, v3);
    v6 = v4->mTexturePack.mData;
    v7 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v7,
      v6,
      DEFAULT_PRIORITY,
      UFG::UIHKWeaponAmmoWidget::TextureLoadedCallback,
      0i64);
  }
}

// File Line: 607
// RVA: 0x5DF200
void __fastcall UFG::UIHKWeaponAmmoWidget::Flash_SetAmmo(UFG::UIHKWeaponAmmoWidget *this, UFG::UIScreen *screen, UFG::UIWeaponAmmoData *data, bool weaponChanged)
{
  char v4; // r13
  UFG::UIWeaponAmmoData *v5; // rdi
  UFG::UIHKWeaponAmmoWidget *v6; // r14
  Scaleform::GFx::Movie *v7; // rsi
  bool v8; // bl
  bool v9; // r15
  bool v10; // r12
  bool v11; // bl
  char *v12; // rbx
  unsigned int v13; // eax
  UFG::UIGfxTranslator *v14; // rcx
  const char *v15; // rbx
  const char *v16; // r13
  double v17; // xmm6_8
  double v18; // xmm6_8
  char v19; // cl
  int v20; // ebx
  int v21; // eax
  int v22; // ebx
  double v23; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-A8h]
  char ptr; // [rsp+60h] [rbp-78h]
  __int64 v26; // [rsp+68h] [rbp-70h]
  __int64 v27; // [rsp+70h] [rbp-68h]
  char dest[4]; // [rsp+78h] [rbp-60h]
  char vars0; // [rsp+1D0h] [rbp+F8h]
  void *retaddr; // [rsp+1D8h] [rbp+100h]

  v26 = -2i64;
  v4 = weaponChanged;
  v5 = data;
  v6 = this;
  v7 = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 0;
  v8 = data->UnlimitedAmmo;
  value.Type = 2;
  value.mValue.BValue = v8;
  Scaleform::GFx::Movie::SetVariable(v7, "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_infinity._visible", &value, 1i64);
  v9 = !v5->UnlimitedAmmo && (float)((float)v5->ClipAmmo / (float)v5->ClipCapacity) <= 0.2;
  v10 = v5->Clips > 0;
  if ( v5->ClipAmmo != v6->mLastClipAmmo
    || v9 != v6->mLastHasLowAmmo
    || v10 != v6->mLastHasReserve
    || v5->ReserveAmmo != v5->OldReserveAmmo )
  {
    v11 = v9 && v10;
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 2;
    value.mValue.BValue = v11;
    Scaleform::GFx::Movie::SetVariable(v7, "mc_WeaponSwitcher.mc_equipped.mc_reload._visible", &value, 1i64);
    if ( v11 && (_BYTE)retaddr != v6->mVehicleReloadPromptActive )
    {
      v6->mVehicleReloadPromptActive = (char)retaddr;
      if ( (_BYTE)retaddr )
      {
        if ( UFG::UI::IsPlayerVehiclePassenger() )
          v12 = (char *)UFG::UI::LocalizeText("$HUD_HELP_COMBAT_RELOAD_ALT");
        else
          v12 = &customWorldMapCaption;
      }
      else
      {
        v13 = UFG::qStringHashUpper32("HUD_HELP_COMBAT_RELOAD", 0xFFFFFFFF);
        v14 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v14 || (v12 = (char *)v14->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, v13)) == 0i64 )
          v12 = "HUD_HELP_COMBAT_RELOAD";
      }
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 6;
      *(_QWORD *)&value.mValue.NValue = v12;
      Scaleform::GFx::Movie::SetVariable(
        v7,
        "mc_WeaponSwitcher.mc_equipped.mc_reload.mcClip.tf_text.htmlText",
        &value,
        1i64);
    }
    v15 = "0xCC4C40";
    v16 = "0xFFFFFF";
    if ( v9 )
      v16 = "0xCC4C40";
    if ( v10 )
      v15 = "0x959595";
    v17 = (double)v5->ClipAmmo;
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 5;
    value.mValue.NValue = v17;
    Scaleform::GFx::Movie::SetVariable(
      v7,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_currentAmmo.htmlText",
      &value,
      1i64);
    v18 = (double)v5->ReserveAmmo;
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 5;
    value.mValue.NValue = v18;
    Scaleform::GFx::Movie::SetVariable(
      v7,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_reserveAmmo.htmlText",
      &value,
      1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = v16;
    Scaleform::GFx::Movie::SetVariable(
      v7,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_currentAmmo.textColor",
      &value,
      1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = v15;
    Scaleform::GFx::Movie::SetVariable(
      v7,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_reserveAmmo.textColor",
      &value,
      1i64);
    v6->mLastHasLowAmmo = v9;
    v6->mLastHasReserve = v10;
    v4 = vars0;
  }
  v19 = 0;
  v20 = v5->ClipAmmo;
  if ( v20 < v6->mLastClipAmmo )
  {
    do
    {
      UFG::qSPrintf(
        dest,
        "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_ammoBullet.mc_bullet_%d._visible",
        (unsigned int)++v20);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 2;
      value.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(v7, dest, &value, 1i64);
    }
    while ( v20 < v6->mLastClipAmmo );
    v19 = 1;
  }
  v21 = v5->ClipAmmo;
  v22 = v6->mLastClipAmmo;
  if ( v21 > v22 )
  {
    if ( v22 < v21 )
    {
      do
      {
        UFG::qSPrintf(
          dest,
          "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_ammoBullet.mc_bullet_%d._visible",
          (unsigned int)++v22);
        if ( ((unsigned int)value.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = 2;
        value.mValue.BValue = 1;
        Scaleform::GFx::Movie::SetVariable(v7, dest, &value, 1i64);
      }
      while ( v22 < v5->ClipAmmo );
    }
    v19 = 1;
  }
  v6->mLastClipAmmo = v5->ClipAmmo;
  if ( v19 )
  {
    `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v23 = (double)(v5->ClipAmmo - 1);
    if ( (*(_DWORD *)dest >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v27 + 16i64))(v27, &ptr, value.DataAux);
      v27 = 0i64;
    }
    *(_DWORD *)dest = 5;
    *(double *)&value.DataAux = v23;
    Scaleform::GFx::Movie::Invoke(v7, "WeaponSwitcher_HighlightCurrentBullet", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  if ( !v4 && v5->ReserveAmmo > v5->OldReserveAmmo )
    Scaleform::GFx::Movie::Invoke(v7, "WeaponSwitcher_OnAmmoPickUp", 0i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 0;
}

// File Line: 713
// RVA: 0x5E1F90
void __fastcall UFG::UIHKWeaponAmmoWidget::Flash_SetWeapon(UFG::UIHKWeaponAmmoWidget *this, UFG::UIScreen *screen, const char *iconTexture, int clipAmmo)
{
  int v4; // er14
  const char *v5; // r15
  UFG::UIScreen *v6; // rdi
  UFG::UIHKWeaponAmmoWidget *v7; // rbx
  Scaleform::GFx::Movie *v8; // r13
  int v9; // edi
  int v10; // esi
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-A8h]
  char ptr; // [rsp+60h] [rbp-78h]
  char v13; // [rsp+68h] [rbp-70h]
  __int64 v14; // [rsp+70h] [rbp-68h]
  __int64 v15; // [rsp+78h] [rbp-60h]
  unsigned int v16; // [rsp+80h] [rbp-58h]
  double v17; // [rsp+88h] [rbp-50h]
  char v18; // [rsp+98h] [rbp-40h]
  __int64 v19; // [rsp+A8h] [rbp-30h]
  unsigned int v20; // [rsp+B0h] [rbp-28h]
  __int64 v21; // [rsp+B8h] [rbp-20h]
  __int64 v22; // [rsp+C8h] [rbp-10h]
  char dest; // [rsp+D8h] [rbp+0h]
  void *retaddr; // [rsp+228h] [rbp+150h]

  v22 = -2i64;
  v4 = clipAmmo;
  v5 = iconTexture;
  v6 = screen;
  v7 = this;
  if ( this->mForceUpdate
    || this->mLastClipAmmo != clipAmmo
    || this->mLastHasStowedWeapon != (_BYTE)retaddr
    || (unsigned int)UFG::qStringCompareInsensitive(iconTexture, this->mLastIconTexture.mData, -1) )
  {
    v8 = v6->mRenderable->m_movie.pObject;
    `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v9 = 0;
    if ( ((unsigned int)v15 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v14 + 16i64))(v14, &ptr, value.DataAux);
      v14 = 0i64;
    }
    LODWORD(v15) = 6;
    value.DataAux = (unsigned __int64)v5;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
        v15,
        &v13,
        COERCE_DOUBLE(*(_QWORD *)&v17));
      v15 = 0i64;
    }
    v16 = 5;
    v17 = (double)v4;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
      v19 = 0i64;
    }
    v20 = 2;
    LOBYTE(v21) = (_BYTE)retaddr;
    Scaleform::GFx::Movie::Invoke(v8, "WeaponSwitcher_SetIcon", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
    value.pObjectInterface = 0i64;
    value.Type = 0;
    do
    {
      v10 = v9 + 1;
      UFG::qSPrintf(
        &dest,
        "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_ammoBullet.mc_bullet_%d._visible",
        (unsigned int)(v9 + 1));
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 2;
      value.mValue.BValue = v9 < v4;
      Scaleform::GFx::Movie::SetVariable(v8, &dest, &value, 1i64);
      ++v9;
    }
    while ( v10 < 40 );
    v7->mForceUpdate = 0;
    v7->mLastClipAmmo = v4;
    UFG::qString::Set(&v7->mLastIconTexture, v5);
    v7->mLastHasStowedWeapon = (char)retaddr;
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 748
// RVA: 0x5DA8A0
void __fastcall UFG::UIHKWeaponAmmoWidget::Flash_EquipError_SetVisible(UFG::UIHKWeaponAmmoWidget *this, UFG::UIScreen *screen, bool visible)
{
  Scaleform::GFx::Movie *v3; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 2;
  value.mValue.BValue = visible;
  Scaleform::GFx::Movie::SetVariable(v3, "mc_WeaponSwitcher.mc_error._visible", &value, 1i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

