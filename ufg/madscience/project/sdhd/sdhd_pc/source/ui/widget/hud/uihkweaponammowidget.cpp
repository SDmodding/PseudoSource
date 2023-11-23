// File Line: 48
// RVA: 0x5C8C50
void __fastcall UFG::UIWeaponAmmoData::UIWeaponAmmoData(UFG::UIWeaponAmmoData *this)
{
  *(_QWORD *)&this->ReserveAmmo = -1i64;
  *(_QWORD *)&this->ClipCapacity = -1i64;
  *(_QWORD *)&this->OldClips = -1i64;
  *(_WORD *)&this->IsCamera = 0;
  this->InventoryItem = eINVENTORY_ITEM_INVALID;
  this->IconTexture = 0i64;
  this->TexturePack = 0i64;
  this->mGunComponent.mPrev = &this->mGunComponent;
  this->mGunComponent.mNext = &this->mGunComponent;
  this->mGunComponent.m_pPointer = 0i64;
}

// File Line: 53
// RVA: 0x619BB0
void __fastcall UFG::UIWeaponAmmoData::Update(
        UFG::UIWeaponAmmoData *this,
        UFG::SimObjectProp *weapon,
        bool *weaponChanged,
        bool *ammoChanged)
{
  UFG::SimObjectWeaponPropertiesComponent *v8; // rbp
  UFG::InventoryItemComponent *m_pComponent; // rsi
  UFG::SimComponent *m_pPointer; // r15
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // r8
  signed __int16 m_Flags; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  signed __int16 v15; // cx
  UFG::InventoryItemComponent *ComponentOfType; // rax
  signed __int16 v17; // cx
  UFG::SimComponent *v18; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::GunComponent> *p_mGunComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::eInventoryItemEnum m_eInventoryItem; // edi
  char WeaponImageInfo; // al
  UFG::eInventoryItemEnum v25; // ecx
  char UnlimitedAmmo; // cl
  char v27; // al
  bool v28; // zf
  int ClipAmmo; // edi
  UFG::GunComponent *v30; // rcx
  int TotalAmmo; // eax
  UFG::GunComponent *v32; // rcx
  int v33; // eax
  UFG::GunComponent *v34; // rcx
  int ClipCapacity; // eax
  UFG::GunComponent *v36; // rcx
  int ClipsRemaining; // eax
  bool v38; // sf

  if ( !weapon )
  {
    v8 = 0i64;
LABEL_3:
    m_pComponent = 0i64;
    goto LABEL_4;
  }
  m_Flags = weapon->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
LABEL_15:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     weapon,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    goto LABEL_17;
  }
  if ( (m_Flags & 0x2000) == 0 )
  {
    if ( (m_Flags & 0x1000) == 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       weapon,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_17;
    }
    goto LABEL_15;
  }
  ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(weapon);
LABEL_17:
  v15 = weapon->m_Flags;
  v8 = ComponentOfTypeHK;
  if ( (v15 & 0x4000) != 0 || v15 < 0 )
    goto LABEL_3;
  if ( (v15 & 0x2000) != 0 )
  {
    m_pComponent = (UFG::InventoryItemComponent *)weapon->m_Components.p[11].m_pComponent;
  }
  else
  {
    if ( (v15 & 0x1000) != 0 )
      ComponentOfType = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         weapon,
                                                         UFG::InventoryItemComponent::_TypeUID);
    else
      ComponentOfType = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                                         weapon,
                                                         UFG::InventoryItemComponent::_TypeUID);
    m_pComponent = ComponentOfType;
  }
  if ( m_pComponent )
  {
    m_pPointer = m_pComponent->m_pOwnerInventoryComponent.m_pPointer;
    goto LABEL_5;
  }
LABEL_4:
  m_pPointer = 0i64;
LABEL_5:
  *weaponChanged = 0;
  *ammoChanged = 0;
  v11 = this->mGunComponent.m_pPointer;
  if ( !v11 || v11->m_pSimObject != weapon )
  {
    if ( weapon )
    {
      v17 = weapon->m_Flags;
      if ( (v17 & 0x4000) != 0 || v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(weapon, UFG::GunComponent::_TypeUID);
      else
        v18 = UFG::SimObject::GetComponentOfType(weapon, UFG::GunComponent::_TypeUID);
      v12 = v18;
    }
    else
    {
      v12 = 0i64;
    }
    p_mGunComponent = &this->mGunComponent;
    if ( this->mGunComponent.m_pPointer )
    {
      mPrev = p_mGunComponent->mPrev;
      mNext = this->mGunComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mGunComponent->mPrev = p_mGunComponent;
      this->mGunComponent.mNext = &this->mGunComponent;
    }
    this->mGunComponent.m_pPointer = v12;
    if ( v12 )
    {
      v22 = v12->m_SafePointerList.mNode.mPrev;
      v22->mNext = p_mGunComponent;
      p_mGunComponent->mPrev = v22;
      this->mGunComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = p_mGunComponent;
    }
  }
  if ( v8 && m_pComponent )
  {
    m_eInventoryItem = m_pComponent->m_eInventoryItem;
    if ( !v8->mIsPhoneCamera || this->IsCamera )
    {
      if ( this->InventoryItem != m_eInventoryItem )
      {
        *weaponChanged = 1;
        this->IsCamera = 0;
        WeaponImageInfo = UFG::UIHKWeaponAmmoWidget::GetWeaponImageInfo(
                            m_eInventoryItem,
                            &this->TexturePack,
                            &this->IconTexture);
        v25 = eINVENTORY_ITEM_INVALID;
        if ( WeaponImageInfo )
          v25 = m_eInventoryItem;
        this->InventoryItem = v25;
      }
    }
    else
    {
      *weaponChanged = 1;
      this->IsCamera = 1;
      this->TexturePack = 0i64;
      this->InventoryItem = eINVENTORY_ITEM_PISTOL_45CAL;
      this->IconTexture = "Icon_camera";
    }
  }
  UnlimitedAmmo = this->UnlimitedAmmo;
  v27 = m_pPointer && BYTE1(m_pPointer[14].m_pSimObject);
  this->UnlimitedAmmo = v27;
  *ammoChanged |= v27 != UnlimitedAmmo;
  v28 = !this->IsCamera;
  ClipAmmo = this->ClipAmmo;
  this->OldClips = this->Clips;
  this->OldReserveAmmo = this->ReserveAmmo;
  if ( v28 )
  {
    v30 = (UFG::GunComponent *)this->mGunComponent.m_pPointer;
    if ( v30 )
    {
      TotalAmmo = UFG::GunComponent::GetTotalAmmo(v30);
      v32 = (UFG::GunComponent *)this->mGunComponent.m_pPointer;
      this->ReserveAmmo = TotalAmmo;
      v33 = UFG::GunComponent::GetClipAmmo(v32);
      v34 = (UFG::GunComponent *)this->mGunComponent.m_pPointer;
      this->ClipAmmo = v33;
      ClipCapacity = UFG::GunComponent::GetClipCapacity(v34);
      v36 = (UFG::GunComponent *)this->mGunComponent.m_pPointer;
      this->ClipCapacity = ClipCapacity;
      ClipsRemaining = UFG::GunComponent::GetClipsRemaining(v36);
      v38 = this->ClipAmmo < 0;
      this->Clips = ClipsRemaining;
      if ( v38 )
        this->ClipAmmo = 0;
    }
    else
    {
      *(_QWORD *)&this->ClipAmmo = -1i64;
      this->Clips = -1;
    }
  }
  else
  {
    if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Camera") )
    {
      this->ReserveAmmo = 0;
      UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Camera");
      this->ClipAmmo = 1;
      this->ClipCapacity = -1;
    }
    *ammoChanged |= this->ClipAmmo != ClipAmmo;
  }
  if ( this->ClipAmmo != ClipAmmo
    || this->Clips != this->OldClips
    || this->ReserveAmmo != this->OldReserveAmmo
    || *weaponChanged )
  {
    *ammoChanged |= 1u;
  }
}

// File Line: 155
// RVA: 0x5C8380
void __fastcall UFG::UIHKWeaponAmmoWidget::UIHKWeaponAmmoWidget(UFG::UIHKWeaponAmmoWidget *this)
{
  *(_WORD *)&this->mVisible = 1;
  `eh vector constructor iterator(
    this->mDisplayedWeapons,
    0x48ui64,
    1,
    (void (__fastcall *)(void *))UFG::UIWeaponAmmoData::UIWeaponAmmoData);
  this->mTextureRefeshFlag = 0;
  UFG::qString::qString(&this->mTexturePack);
  this->mTargetingSystemBaseComponent.mPrev = &this->mTargetingSystemBaseComponent;
  this->mTargetingSystemBaseComponent.mNext = &this->mTargetingSystemBaseComponent;
  this->mTargetingSystemBaseComponent.m_pPointer = 0i64;
  UFG::qString::qString(&this->mLastIconTexture, &customCaption);
  this->mLastClipAmmo = -1;
  *(_DWORD *)&this->mLastHasLowAmmo = 0x1000000;
  this->mVehicleReloadPromptActive = 0;
  this->mEquipErrorTimer = 0.0;
}

// File Line: 160
// RVA: 0x5CDA30
void __fastcall UFG::UIHKWeaponAmmoWidget::~UIHKWeaponAmmoWidget(UFG::UIHKWeaponAmmoWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_mTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  mData = this->mTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::qString::~qString(&this->mLastIconTexture);
  p_mTargetingSystemBaseComponent = &this->mTargetingSystemBaseComponent;
  if ( this->mTargetingSystemBaseComponent.m_pPointer )
  {
    mPrev = p_mTargetingSystemBaseComponent->mPrev;
    mNext = this->mTargetingSystemBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTargetingSystemBaseComponent->mPrev = p_mTargetingSystemBaseComponent;
    this->mTargetingSystemBaseComponent.mNext = &this->mTargetingSystemBaseComponent;
  }
  this->mTargetingSystemBaseComponent.m_pPointer = 0i64;
  v7 = p_mTargetingSystemBaseComponent->mPrev;
  v8 = this->mTargetingSystemBaseComponent.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_mTargetingSystemBaseComponent->mPrev = p_mTargetingSystemBaseComponent;
  this->mTargetingSystemBaseComponent.mNext = &this->mTargetingSystemBaseComponent;
  UFG::qString::~qString(&this->mTexturePack);
  `eh vector destructor iterator(
    this->mDisplayedWeapons,
    0x48ui64,
    1,
    (void (__fastcall *)(void *))UFG::UIWeaponAmmoData::~UIWeaponAmmoData);
}

// File Line: 166
// RVA: 0x5E9F50
char __fastcall UFG::UIHKWeaponAmmoWidget::GetWeaponImageInfo(
        UFG::eInventoryItemEnum iType,
        const char **szTexturePack,
        const char **szImageName)
{
  char result; // al

  switch ( iType )
  {
    case eINVENTORY_ITEM_EMPTY_POP_CAN:
      *szImageName = "Icons_Weapon_EMPTY_POP_CAN";
      *szTexturePack = "Data\\UI\\Icons_Weapon_EMPTY_POP_CAN_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_BOTTLED_SODA:
    case eINVENTORY_ITEM_EMPTY_BEER_BOTTLE:
      *szImageName = "Icons_Weapon_BOTTLED_SODA";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BOTTLED_SODA_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_BATON:
      *szImageName = "Icons_Weapon_BATON";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BATON_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_POLICE_BATON:
      *szImageName = "Icons_Weapon_TelescopingBaton";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TelescopingBaton_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PICKET_SIGN:
      *szImageName = "Icons_Weapon_PicketFence";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PicketFence_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_BROOM_FULL:
    case eINVENTORY_ITEM_BROOM_PUSH:
      *szImageName = "Icons_Weapon_BROOM";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BROOM_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_CLEAVER:
      *szImageName = "Icons_Weapon_CLEAVER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CLEAVER_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_KNIFE:
      *szImageName = "Icons_Weapon_KNIFE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_KNIFE_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_STORM_SWORD:
      *szImageName = "Icons_Weapon_STORMSWORD";
      *szTexturePack = "Data\\UI\\Icons_Weapon_STORMSWORD_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PEACHWOOD_SWORD:
      *szImageName = "Icons_Weapon_STRAIGHTSWORD";
      *szTexturePack = "Data\\UI\\Icons_Weapon_STRAIGHTSWORD_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_UMBRELLA:
      *szImageName = "Icons_Weapon_UMBRELLA";
      *szTexturePack = "Data\\UI\\Icons_Weapon_UMBRELLA_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SHOPPING_BAG:
      *szImageName = "Icons_Weapon_SHOPPINGBAG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SHOPPINGBAG.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PISTOL_9MM:
      *szImageName = "Icons_Weapon_9MM";
      *szTexturePack = "Data\\UI\\Icons_Weapon_9MM_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PISTOL_SERVICE:
      *szImageName = "Icons_Weapon_QSZ92";
      *szTexturePack = "Data\\UI\\Icons_Weapon_QSZ92_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PISTOL_45CAL:
      *szImageName = "Icons_Weapon_45CAL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_45CAL_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PISTOL_45CAL_TAC:
      *szImageName = "Icons_Weapon_45CAL02";
      *szTexturePack = "Data\\UI\\Icons_Weapon_45CAL02_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PISTOL_HITMAN:
      *szImageName = "Icons_Weapon_SILVERBALLER_PISTOL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SILVERBALLER_PISTOL_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PISTOL_JUST_CAUSE:
      *szImageName = "Icons_Weapon_RICO_PISTOL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_RICO_PISTOL_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_RIFLE_ASSAUL_TAC:
    case eINVENTORY_ITEM_RIFLE_ASSAULT_DLC:
      *szImageName = "Icons_Weapon_ACT02";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ACT02_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_RIFLE_ASSAULT:
      *szImageName = "Icons_Weapon_ACT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ACT_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_RIFLE_DEUS_EX:
      *szImageName = "Icons_Weapon_COMBAT_RIFLE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_COMBAT_RIFLE_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_RIFLE_GRENADE:
      *szImageName = "Icons_Weapon_ARGL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ARGL_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_RIFLE_TEAR_GAS:
      *szImageName = "Icons_Weapon_TearGas";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TearGas_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SHOTGUN_PUMP:
      *szImageName = "Icons_Weapon_PUMPS";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PUMPS_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SHOTGUN_ANTI_TAC:
      *szImageName = "Icons_Weapon_ANTIRIOT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ANTIRIOT_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SHOTGUN_ANTIRIOT:
      *szImageName = "Icons_Weapon_ANTIRIOTNOLIGHT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_ANTIRIOTNOLIGHT_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SMG_MACHINE_PISTOL:
      *szImageName = "Icons_Weapon_MP";
      *szTexturePack = "Data\\UI\\Icons_Weapon_MP_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SMG_45CAL_TACLIG:
      *szImageName = "Icons_Weapon_SMG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SMG_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SMG_45CAL_GOLD:
    case eINVENTORY_ITEM_SMG_45CAL:
      *szImageName = "Icons_Weapon_SMG02";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SMG02_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_CAR_TURRET:
      *szImageName = "Icons_Weapon_TT";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TT_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_CROWBAR:
      *szImageName = "Icons_Weapon_CROWBAR";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CROWBAR_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_TIREIRON:
      *szImageName = "Icons_Weapon_TIREIRON";
      *szTexturePack = "Data\\UI\\Icons_Weapon_TIREIRON_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_WOODENCLUB:
    case eINVENTORY_ITEM_STICKTREE:
    case eINVENTORY_ITEM_STICKBAMBOO:
    case eINVENTORY_ITEM_BROOMWEAPON:
      *szImageName = "Icons_Weapon_STICK";
      *szTexturePack = "Data\\UI\\Icons_Weapon_STICK_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_GROCERYBAG:
      *szImageName = "Icons_Weapon_GROCERYBAG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_GROCERYBAG.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_GAMEGUITAR:
      *szImageName = "Icons_Weapon_GAMEGUITAR";
      *szTexturePack = "Data\\UI\\Icons_Weapon_GAMEGUITAR_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SHOVEL:
      *szImageName = "Icons_Weapon_SHOVEL";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SHOVEL_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PURSE:
      *szImageName = "Icons_Weapon_PURSE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PURSE_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PURSEHAND:
      *szImageName = "Icons_Weapon_HANDPURSE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_HANDPURSE.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_BRIEFCASE:
      *szImageName = "Icons_Weapon_BRIEFCASE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BRIEFCASE_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PAINTCAN:
      *szImageName = "Icons_Weapon_PAINTCAN";
      *szTexturePack = "Data\\UI\\Icons_Weapon_PAINTCAN.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_HAMMER:
      *szImageName = "Icons_Weapon_HAMMER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_HAMMER_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_CANEWALKING:
      *szImageName = "Icons_Weapon_CANEWALKING";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CANEWALKING_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SCRUBBRUSH:
      *szImageName = "Icons_Weapon_SCRUBBRUSH";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SCRUBBRUSH_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_SQUEEGEE:
      *szImageName = "Icons_Weapon_SQUEEGEE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_SQUEEGEE_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_COOKINGPAN:
      *szImageName = "Icons_Weapon_COOKINGPAN";
      *szTexturePack = "Data\\UI\\Icons_Weapon_COOKINGPAN.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_WRENCH:
      *szImageName = "Icons_Weapon_WRENCH";
      *szTexturePack = "Data\\UI\\Icons_Weapon_WRENCH_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_MACHETETONG:
      *szImageName = "Icons_Weapon_MACHETETONG";
      *szTexturePack = "Data\\UI\\Icons_Weapon_MACHETETONG_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_CELLPHONE:
      *szImageName = "Icons_Weapon_CELLPHONE";
      *szTexturePack = "Data\\UI\\Icons_Weapon_CELLPHONE.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_COOKINGSPOON:
      *szImageName = "Icons_Weapon_COOKINGSPOON";
      *szTexturePack = "Data\\UI\\Icons_Weapon_COOKINGSPOON.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_COOKINGWOK:
      *szImageName = "Icons_Weapon_WOK";
      *szTexturePack = "Data\\UI\\Icons_Weapon_WOK.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_BULLPENIS:
      *szImageName = "Icons_Weapon_BULLPENIS";
      *szTexturePack = "Data\\UI\\Icons_Weapon_BULLPENIS_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_HANDGRINDER:
      *szImageName = "Icons_Weapon_HANDGRINDER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_HANDGRINDER_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_FISHWRAPPED:
      *szImageName = "Icons_Weapon_FISHWRAPPED";
      *szTexturePack = "Data\\UI\\Icons_Weapon_FISHWRAPPED_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_FIREEXTINGUISHER:
      *szImageName = "Icons_Weapon_FIREEXTINGUISHER";
      *szTexturePack = "Data\\UI\\Icons_Weapon_FIREEXTINGUISHER.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_PISTOL_50CAL_GOL:
    case eINVENTORY_ITEM_PISTOL_50CAL_SIL:
      *szImageName = "Icons_Weapon_GOLD50";
      *szTexturePack = "Data\\UI\\Icons_Weapon_GOLD50_TP.perm.bin";
      result = 1;
      break;
    case eINVENTORY_ITEM_DUFFLEBAG:
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
void __fastcall UFG::UIHKWeaponAmmoWidget::Update(
        UFG::UIHKWeaponAmmoWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rsi
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  float mEquipErrorTimer; // xmm0_4
  float v9; // xmm0_4
  bool v10; // di
  UFG::SimObject *v11; // rsi
  bool IsPlayerInVehicle; // r14
  bool v13; // si
  bool v14; // cl
  UFG::UIHKScreenHud *v15; // rax
  int ClipAmmo; // r9d
  char *IconTexture; // r8
  UFG::SimObjectProp *v18; // rcx
  __int16 v19; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::InputActionData *v21; // rcx
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-60h] BYREF
  bool weaponChanged; // [rsp+A8h] [rbp+10h] BYREF
  bool ammoChanged; // [rsp+B8h] [rbp+20h] BYREF

  if ( !screen )
    return;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  if ( !this->mTargetingSystemBaseComponent.m_pPointer )
  {
    if ( !LocalPlayer )
      return;
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
    }
    UFG::qSafePointer<Creature,Creature>::operator=(
      (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mTargetingSystemBaseComponent,
      m_pComponent);
    if ( !this->mTargetingSystemBaseComponent.m_pPointer )
      return;
  }
  mEquipErrorTimer = this->mEquipErrorTimer;
  if ( mEquipErrorTimer > 0.0 )
  {
    v9 = mEquipErrorTimer - elapsed;
    this->mEquipErrorTimer = v9;
    if ( v9 <= 0.0 )
      UFG::UIHKWeaponAmmoWidget::Flash_EquipError_SetVisible(this, screen, 0);
  }
  v10 = this->mVisible && !UFG::UIHKScreenHud::RacePosition->mVisible;
  if ( this->mVisibleChanged )
  {
    this->mVisibleChanged = 0;
  }
  else if ( v10 == this->mVisible )
  {
    goto LABEL_28;
  }
  value.pObjectInterface = 0i64;
  value.Type = VT_Boolean;
  value.mValue.BValue = v10;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_WeaponSwitcher._visible", &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Undefined;
LABEL_28:
  if ( !this->mVisible )
    return;
  v11 = *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                                + 25i64)
                           + *(_QWORD *)&this->mTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                           + 40);
  if ( !v11 )
  {
    this->mDisplayedWeapons[0].InventoryItem = eINVENTORY_ITEM_INVALID;
    v18 = *(UFG::SimObjectProp **)(56i64
                                 * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                                      + 50i64)
                                 + *(_QWORD *)&this->mTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                                 + 40);
    if ( !v18 )
    {
LABEL_54:
      ClipAmmo = -1;
      IconTexture = &customCaption;
      goto LABEL_55;
    }
    v19 = v18->m_Flags;
    if ( (v19 & 0x4000) != 0 || v19 < 0 )
      goto LABEL_46;
    if ( (v19 & 0x2000) != 0 )
    {
      UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v18);
      goto LABEL_48;
    }
    if ( (v19 & 0x1000) != 0 )
LABEL_46:
      UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    else
      UFG::SimObject::GetComponentOfType(v18, UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_48:
    if ( LocalPlayer )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(
                          LocalPlayer,
                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      if ( !ComponentOfType || ((__int64)ComponentOfType[3].m_BoundComponentHandles.mNode.mPrev & 0x200i64) == 0 )
      {
        v21 = UFG::ActionDef_Inventory.mDataPerController[UFG::gActiveControllerNum];
        if ( v21 )
        {
          if ( v21->mActionTrue )
          {
            this->mEquipErrorTimer = 2.0;
            UFG::UIHKWeaponAmmoWidget::Flash_EquipError_SetVisible(this, screen, 1);
          }
        }
      }
    }
    goto LABEL_54;
  }
  weaponChanged = 0;
  ammoChanged = 0;
  IsPlayerInVehicle = UFG::UI::IsPlayerInVehicle();
  UFG::UIWeaponAmmoData::Update(this->mDisplayedWeapons, v11, &weaponChanged, &ammoChanged);
  v13 = IsPlayerInVehicle != this->mVehicleReloadPromptActive || ammoChanged;
  if ( weaponChanged )
    UFG::UIHKWeaponAmmoWidget::LoadWeaponTexture(this, this->mDisplayedWeapons[0].TexturePack);
  if ( v13 )
  {
    v14 = this->mDisplayedWeapons[0].ClipAmmo > 0;
    v15 = UFG::UIHKScreenHud::mInstance;
    if ( UFG::UIHKScreenHud::mInstance )
    {
      if ( UFG::UIHKScreenHud::mInstance->Reticle.mHasAmmo != v14 )
      {
        UFG::UIHKScreenHud::mInstance->Reticle.mHasAmmo = v14;
        *(_WORD *)&v15->Reticle.mChanged = 257;
      }
    }
    UFG::UIHKWeaponAmmoWidget::Flash_SetAmmo(this, screen, this->mDisplayedWeapons, weaponChanged);
  }
  if ( this->mTextureRefeshFlag )
  {
    this->mTextureRefeshFlag = 0;
    ClipAmmo = this->mDisplayedWeapons[0].ClipAmmo;
    IconTexture = (char *)this->mDisplayedWeapons[0].IconTexture;
LABEL_55:
    UFG::UIHKWeaponAmmoWidget::Flash_SetWeapon(this, screen, IconTexture, ClipAmmo);
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
  char *mData; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  mData = this->mTexturePack.mData;
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v5, mData);
  if ( texturePack )
  {
    UFG::qString::Set(&this->mTexturePack, texturePack);
    v6 = this->mTexturePack.mData;
    v7 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v7,
      v6,
      DEFAULT_PRIORITY,
      (UFG::qReflectInventoryBase *)UFG::UIHKWeaponAmmoWidget::TextureLoadedCallback,
      0i64);
  }
}

// File Line: 607
// RVA: 0x5DF200
void __fastcall UFG::UIHKWeaponAmmoWidget::Flash_SetAmmo(
        UFG::UIHKWeaponAmmoWidget *this,
        UFG::UIScreen *screen,
        UFG::UIWeaponAmmoData *data,
        char weaponChanged)
{
  Scaleform::GFx::Movie *pObject; // rsi
  bool UnlimitedAmmo; // bl
  bool v9; // r15
  bool v10; // r12
  bool v11; // bl
  char *v12; // rbx
  unsigned int v13; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v15; // rbx
  const char *v16; // r13
  Scaleform::GFx::Value::ValueUnion v17; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v18; // xmm6_8
  char v19; // cl
  int ClipAmmo; // ebx
  int mLastClipAmmo; // ebx
  double v22; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::Value ptr[4]; // [rsp+60h] [rbp-78h] BYREF
  char vars0; // [rsp+1D0h] [rbp+F8h]
  void *retaddr; // [rsp+1D8h] [rbp+100h]

  ptr[0].pNext = (Scaleform::GFx::Value *)-2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Undefined;
  UnlimitedAmmo = data->UnlimitedAmmo;
  value.Type = VT_Boolean;
  value.mValue.BValue = UnlimitedAmmo;
  Scaleform::GFx::Movie::SetVariable(
    pObject,
    "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_infinity._visible",
    &value,
    1i64);
  v9 = !data->UnlimitedAmmo && (float)((float)data->ClipAmmo / (float)data->ClipCapacity) <= 0.2;
  v10 = data->Clips > 0;
  if ( data->ClipAmmo != this->mLastClipAmmo
    || v9 != this->mLastHasLowAmmo
    || v10 != this->mLastHasReserve
    || data->ReserveAmmo != data->OldReserveAmmo )
  {
    v11 = v9 && data->Clips > 0;
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Boolean;
    value.mValue.BValue = v11;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_WeaponSwitcher.mc_equipped.mc_reload._visible", &value, 1i64);
    if ( v11 && (_BYTE)retaddr != this->mVehicleReloadPromptActive )
    {
      this->mVehicleReloadPromptActive = (char)retaddr;
      if ( (_BYTE)retaddr )
      {
        if ( UFG::UI::IsPlayerVehiclePassenger() )
          v12 = (char *)UFG::UI::LocalizeText("$HUD_HELP_COMBAT_RELOAD_ALT");
        else
          v12 = &customCaption;
      }
      else
      {
        v13 = UFG::qStringHashUpper32("HUD_HELP_COMBAT_RELOAD", -1);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( !m_translator || (v12 = (char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v13)) == 0i64 )
          v12 = "HUD_HELP_COMBAT_RELOAD";
      }
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_String;
      value.mValue.pString = v12;
      Scaleform::GFx::Movie::SetVariable(
        pObject,
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
    v17.NValue = (double)data->ClipAmmo;
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Number;
    value.mValue = v17;
    Scaleform::GFx::Movie::SetVariable(
      pObject,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_currentAmmo.htmlText",
      &value,
      1i64);
    v18.NValue = (double)data->ReserveAmmo;
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Number;
    value.mValue = v18;
    Scaleform::GFx::Movie::SetVariable(
      pObject,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_reserveAmmo.htmlText",
      &value,
      1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_String;
    value.mValue.pString = v16;
    Scaleform::GFx::Movie::SetVariable(
      pObject,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_currentAmmo.textColor",
      &value,
      1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_String;
    value.mValue.pString = v15;
    Scaleform::GFx::Movie::SetVariable(
      pObject,
      "mc_WeaponSwitcher.mc_equipped.mc_ammo.tf_reserveAmmo.textColor",
      &value,
      1i64);
    this->mLastHasLowAmmo = v9;
    this->mLastHasReserve = v10;
    weaponChanged = vars0;
  }
  v19 = 0;
  ClipAmmo = data->ClipAmmo;
  if ( ClipAmmo < this->mLastClipAmmo )
  {
    do
    {
      UFG::qSPrintf(
        (char *)&ptr[0].Type,
        "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_ammoBullet.mc_bullet_%d._visible",
        (unsigned int)++ClipAmmo);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Boolean;
      value.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(pObject, (const char *)&ptr[0].Type, &value, 1i64);
    }
    while ( ClipAmmo < this->mLastClipAmmo );
    v19 = 1;
  }
  mLastClipAmmo = this->mLastClipAmmo;
  if ( data->ClipAmmo > mLastClipAmmo )
  {
    do
    {
      UFG::qSPrintf(
        (char *)&ptr[0].Type,
        "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_ammoBullet.mc_bullet_%d._visible",
        (unsigned int)++mLastClipAmmo);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Boolean;
      value.mValue.BValue = 1;
      Scaleform::GFx::Movie::SetVariable(pObject, (const char *)&ptr[0].Type, &value, 1i64);
    }
    while ( mLastClipAmmo < data->ClipAmmo );
    v19 = 1;
  }
  this->mLastClipAmmo = data->ClipAmmo;
  if ( v19 )
  {
    `eh vector constructor iterator(ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v22 = (double)(data->ClipAmmo - 1);
    if ( (ptr[0].Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&ptr[0].pObjectInterface->vfptr->gap8[8])(
        ptr[0].pObjectInterface,
        ptr,
        value.DataAux);
      ptr[0].pObjectInterface = 0i64;
    }
    ptr[0].Type = VT_Number;
    *(double *)&value.DataAux = v22;
    Scaleform::GFx::Movie::Invoke(pObject, "WeaponSwitcher_HighlightCurrentBullet", 0i64, ptr, 1u);
    `eh vector destructor iterator(ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  if ( !weaponChanged && data->ReserveAmmo > data->OldReserveAmmo )
    Scaleform::GFx::Movie::Invoke(pObject, "WeaponSwitcher_OnAmmoPickUp", 0i64);
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Undefined;
}

// File Line: 713
// RVA: 0x5E1F90
void __fastcall UFG::UIHKWeaponAmmoWidget::Flash_SetWeapon(
        UFG::UIHKWeaponAmmoWidget *this,
        UFG::UIScreen *screen,
        const char *iconTexture,
        int clipAmmo)
{
  Scaleform::GFx::Movie *pObject; // r13
  int v9; // edi
  int v10; // esi
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-78h] BYREF
  char v13[16]; // [rsp+98h] [rbp-40h] BYREF
  __int64 v14; // [rsp+A8h] [rbp-30h]
  int v15; // [rsp+B0h] [rbp-28h]
  __int64 v16; // [rsp+B8h] [rbp-20h]
  __int64 v17; // [rsp+C8h] [rbp-10h]
  char dest[296]; // [rsp+D8h] [rbp+0h] BYREF
  void *retaddr; // [rsp+228h] [rbp+150h]

  v17 = -2i64;
  if ( this->mForceUpdate
    || this->mLastClipAmmo != clipAmmo
    || this->mLastHasStowedWeapon != (_BYTE)retaddr
    || (unsigned int)UFG::qStringCompareInsensitive(iconTexture, this->mLastIconTexture.mData, -1) )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v9 = 0;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        value.DataAux);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    value.DataAux = (unsigned __int64)iconTexture;
    if ( (ptr.mValue.BValue & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&ptr.Type
                                                                                            + 16i64))(
        *(_QWORD *)&ptr.Type,
        &ptr.8,
        ptr.DataAux);
      *(_QWORD *)&ptr.Type = 0i64;
    }
    ptr.mValue.IValue = 5;
    *(double *)&ptr.DataAux = (double)clipAmmo;
    if ( (v15 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
      v14 = 0i64;
    }
    v15 = 2;
    LOBYTE(v16) = (_BYTE)retaddr;
    Scaleform::GFx::Movie::Invoke(pObject, "WeaponSwitcher_SetIcon", 0i64, &ptr, 3u);
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    do
    {
      v10 = v9 + 1;
      UFG::qSPrintf(
        dest,
        "mc_WeaponSwitcher.mc_equipped.mc_ammo.mc_ammoBullet.mc_bullet_%d._visible",
        (unsigned int)(v9 + 1));
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Boolean;
      value.mValue.BValue = v9 < clipAmmo;
      Scaleform::GFx::Movie::SetVariable(pObject, dest, &value, 1i64);
      ++v9;
    }
    while ( v10 < 40 );
    this->mForceUpdate = 0;
    this->mLastClipAmmo = clipAmmo;
    UFG::qString::Set(&this->mLastIconTexture, iconTexture);
    this->mLastHasStowedWeapon = (char)retaddr;
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 748
// RVA: 0x5DA8A0
void __fastcall UFG::UIHKWeaponAmmoWidget::Flash_EquipError_SetVisible(
        UFG::UIHKWeaponAmmoWidget *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Boolean;
  value.mValue.BValue = visible;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_WeaponSwitcher.mc_error._visible", &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

