// File Line: 26
// RVA: 0x5C8430
void __fastcall UFG::UIHKWorldMapTerritoryWidget::UIHKWorldMapTerritoryWidget(UFG::UIHKWorldMapTerritoryWidget *this)
{
  UFG::UIHKWorldMapTerritoryWidget *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]

  v1 = this;
  *(_WORD *)&this->mChanged = 257;
  *(_QWORD *)&this->mPlayerPos.x = 0i64;
  this->mPlayerPos.z = 0.0;
  `eh vector constructor iterator(
    this->mData,
    0x30ui64,
    20,
    (void (__fastcall *)(void *))UFG::UIHKTerritoryData::UIHKTerritoryData);
  v2 = UFG::qSymbol::create_from_string(&result, "default-unlockables-areaOwnership-list");
  v1->mPSSet = UFG::PropertySetManager::GetPropertySet(v2);
}

// File Line: 33
// RVA: 0x6192E0
void __fastcall UFG::UIHKWorldMapTerritoryWidget::Update(UFG::UIHKWorldMapTerritoryWidget *this, UFG::UIScreen *screen, UFG::UITiledMapMath *geo)
{
  UFG::UITiledMapMath *v3; // r14
  UFG::UIHKWorldMapTerritoryWidget *v4; // rbx
  Scaleform::GFx::Movie *v5; // rdi
  bool v6; // si
  double v7; // xmm6_8
  double v8; // xmm6_8
  double v9; // xmm6_8
  UFG::MinimapTilePoint2f iconPos; // [rsp+20h] [rbp-50h]
  __int64 v11; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-40h]
  UFG::ScreenPoint2f v13; // [rsp+A8h] [rbp+38h]
  UFG::MinimapPoint2f point; // [rsp+B8h] [rbp+48h]

  if ( screen )
  {
    v11 = -2i64;
    v3 = geo;
    v4 = this;
    v5 = screen->mRenderable->m_movie.pObject;
    if ( v5 )
    {
      if ( *(_WORD *)&this->mChanged )
      {
        value.pObjectInterface = 0i64;
        value.Type = 0;
        v6 = this->mVisible;
        value.Type = 2;
        value.mValue.BValue = v6;
        Scaleform::GFx::Movie::SetVariable(v5, "mc_Territories._visible", &value, 1i64);
        if ( v4->mVisible )
        {
          v13 = 0i64;
          point.x = UFG::UIHKTweakables::WorldMapTerritory_OffsetX;
          point.y = UFG::UIHKTweakables::WorldMapTerritory_OffsetY;
          UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &point, v3);
          UFG::ScreenPoint2f::InitFromIconPos(&v13, &iconPos, v3);
          v7 = v13.x;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v7;
          Scaleform::GFx::Movie::SetVariable(v5, "mc_Territories._x", &value, 1i64);
          v8 = v13.y;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v8;
          Scaleform::GFx::Movie::SetVariable(v5, "mc_Territories._y", &value, 1i64);
          v9 = (float)((float)(UFG::UITiledMapMath::GetAdjustedScale(v3) * UFG::UIHKTweakables::WorldMapTerritory_Scale)
                     * 100.0);
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v9;
          Scaleform::GFx::Movie::SetVariable(v5, "mc_Territories._xscale", &value, 1i64);
          Scaleform::GFx::Movie::SetVariable(v5, "mc_Territories._yscale", &value, 1i64);
          if ( !v4->mChanged )
            goto LABEL_14;
          UFG::UIHKWorldMapTerritoryWidget::RefreshTerritoryStates(v4, v5);
        }
        v4->mChanged = 0;
LABEL_14:
        if ( ((unsigned int)value.Type >> 6) & 1 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
        return;
      }
    }
  }
}

// File Line: 92
// RVA: 0x6009D0
void __fastcall UFG::UIHKWorldMapTerritoryWidget::RefreshTerritoryStates(UFG::UIHKWorldMapTerritoryWidget *this, Scaleform::GFx::Movie *movie)
{
  unsigned int v2; // edi
  UFG::UIHKWorldMapTerritoryWidget *v3; // rsi
  Scaleform::GFx::Movie *v4; // r12
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // r15
  unsigned int v8; // ebp
  UFG::UIHKTerritoryData *v9; // r14
  char *v10; // rax
  __int64 v11; // rcx
  UFG::GameStatTracker *v12; // rax
  UFG::eFactionClassEnum v13; // eax
  UFG::eFactionClassEnum v14; // ebx
  const char *v15; // r8
  const char *v16; // r9
  UFG::qSymbol name; // [rsp+50h] [rbp+8h]

  v2 = 0;
  v3 = this;
  v4 = movie;
  this->mNumTerritories = 0;
  v5 = this->mPSSet;
  if ( v5 )
  {
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v5, (UFG::qSymbol *)&qSymbol_List_20.mUID, DEPTH_RECURSE);
    v7 = v6;
    if ( v6 )
    {
      v8 = v6->mNumElements;
      if ( v8 )
      {
        v9 = v3->mData;
        do
        {
          v10 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v2);
          if ( v10 )
          {
            v11 = *(_QWORD *)v10;
            if ( *(_QWORD *)v10 )
            {
              if ( &v10[v11] )
              {
                name.mUID = *(_DWORD *)&v10[v11 + 0x40];
                v12 = UFG::GameStatTracker::Instance();
                v13 = (unsigned int)UFG::GameStatTracker::GetStat(v12, Collectible_AreaOwnership, &name);
                ++v3->mNumTerritories;
                v14 = v13;
                if ( v3->mNumTerritories > 20 )
                  return;
                v9->Owner = v13;
                v15 = UFG::UIHKWorldMapTerritoryWidget::GetTerritoryName(v3, &name);
                if ( v14 == 4 )
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_WINSTON";
                }
                else if ( (unsigned int)(v14 - 14) <= 1 )
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_SUNONYEE";
                }
                else if ( v14 == 13 )
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_DOGBOYS";
                }
                else
                {
                  v16 = "$WORLDMAP_FACTION_TRIAD_18K";
                  if ( v14 != 12 )
                    v16 = "$COMMON_PLAYER";
                }
                UFG::UIHKWorldMapTerritoryWidget::Flash_SetTerritoryOwner(v3, v4, v15, v16);
              }
            }
          }
          ++v2;
          ++v9;
        }
        while ( v2 < v8 );
      }
    }
  }
}

// File Line: 128
// RVA: 0x5E11D0
void __fastcall UFG::UIHKWorldMapTerritoryWidget::Flash_SetTerritoryOwner(UFG::UIHKWorldMapTerritoryWidget *this, Scaleform::GFx::Movie *movie, const char *territory, const char *owner)
{
  const char *v4; // rdi
  const char *v5; // rbx
  Scaleform::GFx::Movie *v6; // rsi
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-38h]
  __int64 v9; // [rsp+80h] [rbp-28h]
  unsigned int v10; // [rsp+88h] [rbp-20h]
  const char *v11; // [rsp+90h] [rbp-18h]

  if ( movie )
  {
    v4 = owner;
    v5 = territory;
    v6 = movie;
    if ( territory )
    {
      if ( owner )
      {
        `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 6;
        *(_QWORD *)&pargs.mValue.NValue = v5;
        if ( (v10 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, &v8, v11);
          v9 = 0i64;
        }
        v10 = 6;
        v11 = v4;
        Scaleform::GFx::Movie::Invoke(v6, "SetTerritoryOwner", 0i64, &pargs, 2u);
        `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 142
// RVA: 0x5E9620
const char *__fastcall UFG::UIHKWorldMapTerritoryWidget::GetTerritoryName(UFG::UIHKWorldMapTerritoryWidget *this, UFG::qSymbol *territorySym)
{
  unsigned int v2; // eax

  v2 = territorySym->mUID;
  if ( territorySym->mUID == qSymbol_NorthPointPark_20.mUID )
    return "NorthPointPark";
  if ( v2 == qSymbol_NorthPointTemple_20.mUID )
    return "NorthPointTemple";
  if ( v2 == qSymbol_ChopShop_20.mUID )
    return "ChopShop";
  if ( v2 == qSymbol_NightMarket_20.mUID )
    return "NightMarket";
  if ( v2 == qSymbol_BamBamClub_20.mUID )
    return "BamBamClub";
  if ( v2 == qSymbol_NorthPointWaterfront_20.mUID )
    return "NorthPointWaterfront";
  if ( v2 == qSymbol_NorthPointResidential_20.mUID )
    return "NorthPointResidential";
  if ( v2 == qSymbol_MinibusDepot_20.mUID )
    return "MinibusDepot";
  if ( v2 == qSymbol_TopGlamour_20.mUID )
    return "TopGlamour";
  if ( v2 == qSymbol_Sweatshop_20.mUID )
    return "Sweatshop";
  if ( v2 == qSymbol_TimeSquare_20.mUID )
    return "TimeSquare";
  if ( v2 == qSymbol_CentralResidential_20.mUID )
    return "CentralResidential";
  if ( v2 == qSymbol_CentralFinancial_20.mUID )
    return "CentralFinancial";
  if ( v2 == qSymbol_Soho_20.mUID )
    return "Soho";
  if ( v2 == qSymbol_DockYards_20.mUID )
    return "DockYards";
  if ( v2 == qSymbol_KennedyTown_20.mUID )
    return "KennedyTown";
  if ( v2 == qSymbol_Aberdeen_20.mUID )
    return "Aberdeen";
  if ( v2 == qSymbol_AberdeenIsland_20.mUID )
    return "AberdeenIsland";
  return 0i64;
}

