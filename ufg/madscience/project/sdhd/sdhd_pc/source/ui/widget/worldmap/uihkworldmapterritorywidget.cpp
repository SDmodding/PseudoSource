// File Line: 26
// RVA: 0x5C8430
void __fastcall UFG::UIHKWorldMapTerritoryWidget::UIHKWorldMapTerritoryWidget(UFG::UIHKWorldMapTerritoryWidget *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF

  *(_WORD *)&this->mChanged = 257;
  *(_QWORD *)&this->mPlayerPos.x = 0i64;
  this->mPlayerPos.z = 0.0;
  `eh vector constructor iterator(
    this->mData,
    0x30ui64,
    20,
    (void (__fastcall *)(void *))UFG::UIHKTerritoryData::UIHKTerritoryData);
  v2 = UFG::qSymbol::create_from_string(&result, "default-unlockables-areaOwnership-list");
  this->mPSSet = UFG::PropertySetManager::GetPropertySet(v2);
}

// File Line: 33
// RVA: 0x6192E0
void __fastcall UFG::UIHKWorldMapTerritoryWidget::Update(
        UFG::UIHKWorldMapTerritoryWidget *this,
        UFG::UIScreen *screen,
        UFG::UITiledMapMath *geo)
{
  Scaleform::GFx::Movie *pObject; // rdi
  bool mVisible; // si
  Scaleform::GFx::Value::ValueUnion v7; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v8; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v9; // xmm6_8
  UFG::MinimapTilePoint2f iconPos; // [rsp+20h] [rbp-50h] BYREF
  __int64 v11; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-40h] BYREF
  UFG::ScreenPoint2f v13; // [rsp+A8h] [rbp+38h] BYREF
  UFG::MinimapPoint2f point; // [rsp+B8h] [rbp+48h] BYREF

  if ( screen )
  {
    v11 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      if ( this->mVisible || this->mChanged )
      {
        value.pObjectInterface = 0i64;
        value.Type = VT_Undefined;
        mVisible = this->mVisible;
        value.Type = VT_Boolean;
        value.mValue.BValue = mVisible;
        Scaleform::GFx::Movie::SetVariable(pObject, "mc_Territories._visible", &value, 1i64);
        if ( this->mVisible )
        {
          v13 = 0i64;
          point.x = UFG::UIHKTweakables::WorldMapTerritory_OffsetX;
          point.y = UFG::UIHKTweakables::WorldMapTerritory_OffsetY;
          UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &point, geo);
          UFG::ScreenPoint2f::InitFromIconPos(&v13, &iconPos, geo);
          v7.NValue = v13.x;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v7;
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_Territories._x", &value, 1i64);
          v8.NValue = v13.y;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v8;
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_Territories._y", &value, 1i64);
          v9.NValue = (float)((float)(UFG::UITiledMapMath::GetAdjustedScale(geo)
                                    * UFG::UIHKTweakables::WorldMapTerritory_Scale)
                            * 100.0);
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v9;
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_Territories._xscale", &value, 1i64);
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_Territories._yscale", &value, 1i64);
          if ( !this->mChanged )
            goto LABEL_15;
          UFG::UIHKWorldMapTerritoryWidget::RefreshTerritoryStates(this, pObject);
        }
        this->mChanged = 0;
LABEL_15:
        if ( (value.Type & 0x40) != 0 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
      }
    }
  }
}

// File Line: 92
// RVA: 0x6009D0
void __fastcall UFG::UIHKWorldMapTerritoryWidget::RefreshTerritoryStates(
        UFG::UIHKWorldMapTerritoryWidget *this,
        Scaleform::GFx::Movie *movie)
{
  unsigned int v2; // edi
  UFG::qPropertySet *mPSSet; // rcx
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // r15
  unsigned int mNumElements; // ebp
  UFG::UIHKTerritoryData *mData; // r14
  char *ValuePtr; // rax
  __int64 v11; // rcx
  UFG::GameStatTracker *v12; // rax
  UFG::eFactionClassEnum Stat; // eax
  UFG::eFactionClassEnum v14; // ebx
  const char *TerritoryName; // r8
  const char *v16; // r9
  UFG::qSymbol name; // [rsp+50h] [rbp+8h] BYREF

  v2 = 0;
  this->mNumTerritories = 0;
  mPSSet = this->mPSSet;
  if ( mPSSet )
  {
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           mPSSet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_List_20,
           DEPTH_RECURSE);
    v7 = v6;
    if ( v6 )
    {
      mNumElements = v6->mNumElements;
      if ( mNumElements )
      {
        mData = this->mData;
        do
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v2);
          if ( ValuePtr )
          {
            v11 = *(_QWORD *)ValuePtr;
            if ( *(_QWORD *)ValuePtr )
            {
              if ( &ValuePtr[v11] )
              {
                name.mUID = *(_DWORD *)&ValuePtr[v11 + 0x40];
                v12 = UFG::GameStatTracker::Instance();
                Stat = (unsigned int)UFG::GameStatTracker::GetStat(v12, Collectible_AreaOwnership, &name);
                ++this->mNumTerritories;
                v14 = Stat;
                if ( this->mNumTerritories > 20 )
                  return;
                mData->Owner = Stat;
                TerritoryName = UFG::UIHKWorldMapTerritoryWidget::GetTerritoryName(this, &name);
                if ( v14 == FACTION_TRIAD_WINSTON )
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_WINSTON";
                }
                else if ( (unsigned int)(v14 - 14) <= 1 )
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_SUNONYEE";
                }
                else if ( v14 == FACTION_TRIAD_DOGBOYS )
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_DOGBOYS";
                }
                else
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_18K";
                  if ( v14 != FACTION_TRIAD_18K )
                    v16 = "$COMMON_PLAYER";
                }
                UFG::UIHKWorldMapTerritoryWidget::Flash_SetTerritoryOwner(this, movie, TerritoryName, v16);
              }
            }
          }
          ++v2;
          ++mData;
        }
        while ( v2 < mNumElements );
      }
    }
  }
}

// File Line: 128
// RVA: 0x5E11D0
void __fastcall UFG::UIHKWorldMapTerritoryWidget::Flash_SetTerritoryOwner(
        UFG::UIHKWorldMapTerritoryWidget *this,
        Scaleform::GFx::Movie *movie,
        const char *territory,
        const char *owner)
{
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v8[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v9; // [rsp+80h] [rbp-28h]
  int v10; // [rsp+88h] [rbp-20h]
  const char *v11; // [rsp+90h] [rbp-18h]

  if ( movie && territory && owner )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = territory;
    if ( (v10 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, v8, v11);
      v9 = 0i64;
    }
    v10 = 6;
    v11 = owner;
    Scaleform::GFx::Movie::Invoke(movie, "SetTerritoryOwner", 0i64, &pargs, 2u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 142
// RVA: 0x5E9620
const char *__fastcall UFG::UIHKWorldMapTerritoryWidget::GetTerritoryName(
        UFG::UIHKWorldMapTerritoryWidget *this,
        UFG::qSymbol *territorySym)
{
  unsigned int mUID; // eax

  mUID = territorySym->mUID;
  if ( territorySym->mUID == qSymbol_NorthPointPark_20.mUID )
    return "NorthPointPark";
  if ( mUID == qSymbol_NorthPointTemple_20.mUID )
    return "NorthPointTemple";
  if ( mUID == qSymbol_ChopShop_20.mUID )
    return "ChopShop";
  if ( mUID == qSymbol_NightMarket_20.mUID )
    return "NightMarket";
  if ( mUID == qSymbol_BamBamClub_20.mUID )
    return "BamBamClub";
  if ( mUID == qSymbol_NorthPointWaterfront_20.mUID )
    return "NorthPointWaterfront";
  if ( mUID == qSymbol_NorthPointResidential_20.mUID )
    return "NorthPointResidential";
  if ( mUID == qSymbol_MinibusDepot_20.mUID )
    return "MinibusDepot";
  if ( mUID == qSymbol_TopGlamour_20.mUID )
    return "TopGlamour";
  if ( mUID == qSymbol_Sweatshop_20.mUID )
    return "Sweatshop";
  if ( mUID == qSymbol_TimeSquare_20.mUID )
    return "TimeSquare";
  if ( mUID == qSymbol_CentralResidential_20.mUID )
    return "CentralResidential";
  if ( mUID == qSymbol_CentralFinancial_20.mUID )
    return "CentralFinancial";
  if ( mUID == qSymbol_Soho_20.mUID )
    return "Soho";
  if ( mUID == qSymbol_DockYards_20.mUID )
    return "DockYards";
  if ( mUID == qSymbol_KennedyTown_20.mUID )
    return "KennedyTown";
  if ( mUID == qSymbol_Aberdeen_20.mUID )
    return "Aberdeen";
  if ( mUID == qSymbol_AberdeenIsland_20.mUID )
    return "AberdeenIsland";
  return 0i64;
}

