// File Line: 13
// RVA: 0x1585E60
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::SpawnRacketWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::SpawnRacketWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::SpawnRacketWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::SpawnRacketWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::SpawnRacketWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::SpawnRacketWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 21
// RVA: 0x69E370
void __fastcall UFG::Editor::SpawnRacketWindow::UpdateUI(UFG::Editor::SpawnRacketWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rsi
  UFG::Editor::SpawnRacketWindow *v3; // rdi
  unsigned __int64 v4; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v5; // rcx
  const char *v6; // rax
  unsigned __int64 v7; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  unsigned __int64 v10; // rbx
  UFG::qReflectWarehouse *v11; // rax
  UFG::qReflectInventoryBase *v12; // rax
  UFG::qTree64Base *v13; // rbp
  UFG::qTree64Base *v14; // rax
  signed __int64 v15; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v16; // rcx
  const char *v17; // rax
  UFG::qTree64Base::BaseNode *v18; // rdi
  unsigned __int64 v19; // rbx
  char *v20; // rax
  UFG::qTree64Base *v21; // rax
  UFG::qArray<UFG::RoadNetworkNode *,0> _dst; // [rsp+40h] [rbp-48h]
  UFG::qReflectHandleBase v23; // [rsp+50h] [rbp-38h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginVerticalLayout(dui);
  UFG::DUIContext::Checkbox(v2, "Is Ambient", &v3->mToggle_LocalPlayerRacket);
  UFG::DUIContext::Slider(v2, "Racket Level", &v3->mSlider_RacketLevel, 0);
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Spawn", 0x10u)
    && v3->mTree_Selection.vfptr->Count((UFG::IDUICollectionView *)&v3->mTree_Selection.vfptr) )
  {
    v4 = v3->mTree_Selection.vfptr->GetAt((UFG::IDUICollectionView *)&v3->mTree_Selection.vfptr, 0);
    UFG::qReflectHandleBase::qReflectHandleBase(&v23);
    v6 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v5);
    v7 = UFG::qStringHash64(v6, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v23, v7, v4);
    UFG::Editor::SpawnRacketWindow::SpawnRacket(v3, (UFG::qReflectHandle<UFG::RacketType> *)&v23);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v23);
  }
  UFG::DUIContext::Label(v2, "Racket Types");
  _dst.p = 0i64;
  *(_QWORD *)&_dst.size = 0i64;
  UFG::qArray<UFG::qPropertySet *,0>::Clone((UFG::qArray<UFG::RoadNetworkNode *,0> *)&v3->mTree_Selection.mData, &_dst);
  UFG::DUIContext::BeginTreeView(
    v2,
    (UFG::IDUICollectionView *)&v3->mTree_Selection.vfptr,
    (UFG::IDUICollectionView *)&v3->mTree_ExpandedItems.vfptr,
    0);
  v9 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v8);
  v10 = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
  v11 = UFG::qReflectWarehouse::Instance();
  v12 = UFG::qReflectWarehouse::GetInventory(v11, v10);
  v13 = &v12->mItems.mTree;
  v14 = UFG::qTree64Base::GetHead(&v12->mItems.mTree);
  if ( v14 )
  {
    v15 = (signed __int64)&v14[-1].mCount;
    if ( v14 != (UFG::qTree64Base *)8 )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v23);
        v17 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v16);
        v23.mTypeUID = UFG::qStringHash64(v17, 0xFFFFFFFFFFFFFFFFui64);
        v18 = (UFG::qTree64Base::BaseNode *)(v15 + 8);
        UFG::qReflectHandleBase::Init(&v23, v23.mTypeUID, *(_QWORD *)(v15 + 8));
        v19 = v23.mData->mBaseNode.mUID;
        v20 = UFG::qReflectObject::GetName(v23.mData);
        UFG::DUIContext::TreeViewItem(v2, v20, v19, 0);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v23);
        v21 = UFG::qTree64Base::GetNext(v13, v18);
        if ( !v21 )
          break;
        v15 = (signed __int64)&v21[-1].mCount;
      }
      while ( v21 != (UFG::qTree64Base *)8 );
    }
  }
  UFG::DUIContext::EndTreeView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( _dst.p )
    operator delete[](_dst.p);
}

// File Line: 58
// RVA: 0x69DCF0
void __fastcall UFG::Editor::SpawnRacketWindow::SpawnRacket(UFG::Editor::SpawnRacketWindow *this, UFG::qReflectHandle<UFG::RacketType> *racket_type)
{
  UFG::qReflectHandle<UFG::RacketType> *v2; // rbx
  UFG::Editor::SpawnRacketWindow *v3; // rsi
  int v4; // edi
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  char *v18; // rax
  char *v19; // rax
  char *v20; // rax
  char *v21; // rax
  char *v22; // rax
  char *v23; // rax
  char *v24; // rax
  char *v25; // rax
  char *v26; // rax
  char *v27; // rax
  char *v28; // rax
  char *v29; // rax
  char *v30; // rax
  char *v31; // rax
  char *v32; // rax
  char *v33; // rax
  UFG::qReflectObject *v34; // rcx
  char *v35; // rax
  UFG::qSymbol *v36; // rax
  char *v37; // rax
  char *v38; // rax
  UFG::qString v39; // [rsp+28h] [rbp-21h]
  UFG::qMatrix44 transform; // [rsp+50h] [rbp+7h]
  UFG::qSymbolUC v41; // [rsp+B0h] [rbp+67h]
  UFG::qSymbol result; // [rsp+B8h] [rbp+6Fh]

  v2 = racket_type;
  v3 = this;
  v4 = this->mSlider_RacketLevel;
  v5 = UFG::Editor::GetActiveView();
  v6 = *((float *)v5 + 29);
  v7 = *((float *)v5 + 30);
  v8 = *((float *)v5 + 31);
  transform.v0.x = *((float *)v5 + 28);
  transform.v0.y = v6;
  transform.v0.z = v7;
  transform.v0.w = v8;
  v9 = *((float *)v5 + 33);
  v10 = *((float *)v5 + 34);
  v11 = *((float *)v5 + 35);
  transform.v1.x = *((float *)v5 + 32);
  transform.v1.y = v9;
  transform.v1.z = v10;
  transform.v1.w = v11;
  v12 = *((float *)v5 + 37);
  v13 = *((float *)v5 + 38);
  v14 = *((float *)v5 + 39);
  transform.v2.x = *((float *)v5 + 36);
  transform.v2.y = v12;
  transform.v2.z = v13;
  transform.v2.w = v14;
  v15 = *((float *)v5 + 41);
  v16 = *((float *)v5 + 42);
  v17 = *((float *)v5 + 43);
  transform.v3.x = *((float *)v5 + 40);
  transform.v3.y = v15;
  transform.v3.z = v16;
  transform.v3.w = v17;
  v41.mUID = -1;
  UFG::qString::qString(&v39);
  v18 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v18);
  UFG::qString::operator+=(&v39, "_ExteriorCore_");
  v41.mUID = UFG::RacketInstance::ExteriorCorePrefab(&result, v2, v4, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v19 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v19, &transform, v39.mData);
  }
  v20 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v20);
  UFG::qString::operator+=(&v39, "_ExteriorCoreProps_");
  v41.mUID = UFG::RacketInstance::ExteriorCorePropsPrefab(&result, v2, v4, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v21 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v21, &transform, v39.mData);
  }
  v22 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v22);
  UFG::qString::operator+=(&v39, "_ExteriorCoreDoors_");
  v41.mUID = UFG::RacketInstance::ExteriorCoreDoorsPrefab(&result, v2, v4, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v23 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v23, &transform, v39.mData);
  }
  v24 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v24);
  UFG::qString::operator+=(&v39, "_InteriorCore_");
  v41.mUID = UFG::RacketInstance::InteriorCorePrefab(&result, v2, v4, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v25 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v25, &transform, v39.mData);
  }
  v26 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v26);
  UFG::qString::operator+=(&v39, "_InteriorCoreProps_");
  v41.mUID = UFG::RacketInstance::InteriorCorePropsPrefab(&result, v2, v4, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v27 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v27, &transform, v39.mData);
  }
  v28 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v28);
  UFG::qString::operator+=(&v39, "_InteriorCoreDoors_");
  v41.mUID = UFG::RacketInstance::InteriorCoreDoorsPrefab(&result, v2, v4, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v29 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v29, &transform, v39.mData);
  }
  v30 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v30);
  UFG::qString::operator+=(&v39, "_Decals_");
  v41.mUID = UFG::RacketInstance::DecalsPrefab(&result, v2, v4, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v31 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v31, &transform, v39.mData);
  }
  v32 = UFG::qReflectObject::GetName(v2->mData);
  UFG::qString::Set(&v39, v32);
  UFG::qString::operator+=(&v39, "_Theme_");
  v41.mUID = UFG::RacketInstance::ThemePrefab(&result, v2, v4)->mUID;
  if ( v41.mUID != -1 )
  {
    v33 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v33, &transform, v39.mData);
  }
  v34 = v2->mData;
  if ( v3->mToggle_LocalPlayerRacket )
  {
    v37 = UFG::qReflectObject::GetName(v34);
    UFG::qString::Set(&v39, v37);
    UFG::qString::operator+=(&v39, "_Ambient_");
    v36 = UFG::RacketInstance::AmbientPrefab(&result, v2, v4);
  }
  else
  {
    v35 = UFG::qReflectObject::GetName(v34);
    UFG::qString::Set(&v39, v35);
    UFG::qString::operator+=(&v39, "_Gameplay_");
    v36 = UFG::RacketInstance::GameplayPrefab(&result, v2, v4);
  }
  v41.mUID = v36->mUID;
  if ( v41.mUID != -1 )
  {
    v38 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v38, &transform, v39.mData);
  }
  UFG::qString::~qString(&v39);
}

