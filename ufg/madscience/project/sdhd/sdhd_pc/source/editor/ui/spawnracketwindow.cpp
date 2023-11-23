// File Line: 13
// RVA: 0x1585E60
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::SpawnRacketWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::SpawnRacketWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory,
    "UFG::Editor::SpawnRacketWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::SpawnRacketWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::SpawnRacketWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::SpawnRacketWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 21
// RVA: 0x69E370
void __fastcall UFG::Editor::SpawnRacketWindow::UpdateUI(UFG::Editor::SpawnRacketWindow *this, UFG::DUIContext *dui)
{
  unsigned __int64 v4; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v5; // rcx
  const char *TypeName; // rax
  unsigned __int64 v7; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  unsigned __int64 v10; // rbx
  UFG::qReflectWarehouse *v11; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rbp
  UFG::qTree64Base *Head; // rax
  __int64 *p_mCount; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v15; // rcx
  const char *v16; // rax
  UFG::qTree64Base::BaseNode *v17; // rdi
  unsigned __int64 mUID; // rbx
  char *Name; // rax
  UFG::qTree64Base *Next; // rax
  UFG::qArray<UFG::RoadNetworkNode *,0> _dst; // [rsp+40h] [rbp-48h] BYREF
  UFG::qReflectHandleBase v22; // [rsp+50h] [rbp-38h] BYREF

  UFG::DUIContext::BeginVerticalLayout(dui);
  UFG::DUIContext::Checkbox(dui, "Is Ambient", &this->mToggle_LocalPlayerRacket);
  UFG::DUIContext::Slider(dui, "Racket Level", (unsigned int *)&this->mSlider_RacketLevel, 0);
  if ( UFG::DUIContext::Button(dui, "Spawn", 0x10u) && this->mTree_Selection.vfptr->Count(&this->mTree_Selection) )
  {
    v4 = this->mTree_Selection.vfptr->GetAt(&this->mTree_Selection, 0);
    UFG::qReflectHandleBase::qReflectHandleBase(&v22);
    TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v5);
    v7 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v22, v7, v4);
    UFG::Editor::SpawnRacketWindow::SpawnRacket(this, (UFG::qReflectHandle<UFG::RacketType> *)&v22);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
  }
  UFG::DUIContext::Label(dui, "Racket Types");
  _dst.p = 0i64;
  *(_QWORD *)&_dst.size = 0i64;
  UFG::qArray<UFG::qPropertySet *,0>::Clone(
    (UFG::qArray<UFG::RoadNetworkNode *,0> *)&this->mTree_Selection.mData,
    &_dst);
  UFG::DUIContext::BeginTreeView(
    dui,
    (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mTree_Selection,
    (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mTree_ExpandedItems,
    0);
  v9 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v8);
  v10 = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
  v11 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v11, v10)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = &Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v22);
        v16 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v15);
        v22.mTypeUID = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
        v17 = (UFG::qTree64Base::BaseNode *)(p_mCount + 1);
        UFG::qReflectHandleBase::Init(&v22, v22.mTypeUID, p_mCount[1]);
        mUID = v22.mData->mBaseNode.mUID;
        Name = UFG::qReflectObject::GetName(v22.mData);
        UFG::DUIContext::TreeViewItem(dui, Name, mUID, 0);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, v17);
        if ( !Next )
          break;
        p_mCount = &Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
  UFG::DUIContext::EndTreeView(dui);
  UFG::DUIContext::EndLayoutHorizontal(dui);
  if ( _dst.p )
    operator delete[](_dst.p);
}

// File Line: 58
// RVA: 0x69DCF0
void __fastcall UFG::Editor::SpawnRacketWindow::SpawnRacket(
        UFG::Editor::SpawnRacketWindow *this,
        UFG::qReflectHandle<UFG::RacketType> *racket_type)
{
  int mSlider_RacketLevel; // edi
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **ActiveView; // rax
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
  char *Name; // rax
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
  UFG::qReflectObject *mData; // rcx
  char *v35; // rax
  UFG::qSymbol *v36; // rax
  char *v37; // rax
  char *v38; // rax
  UFG::qString v39; // [rsp+28h] [rbp-21h] BYREF
  UFG::qMatrix44 transform; // [rsp+50h] [rbp+7h] BYREF
  UFG::qSymbolUC v41; // [rsp+B0h] [rbp+67h] BYREF
  UFG::qSymbol result; // [rsp+B8h] [rbp+6Fh] BYREF

  mSlider_RacketLevel = this->mSlider_RacketLevel;
  ActiveView = UFG::Editor::GetActiveView();
  v6 = *((float *)ActiveView + 29);
  v7 = *((float *)ActiveView + 30);
  v8 = *((float *)ActiveView + 31);
  transform.v0.x = *((float *)ActiveView + 28);
  transform.v0.y = v6;
  transform.v0.z = v7;
  transform.v0.w = v8;
  v9 = *((float *)ActiveView + 33);
  v10 = *((float *)ActiveView + 34);
  v11 = *((float *)ActiveView + 35);
  transform.v1.x = *((float *)ActiveView + 32);
  transform.v1.y = v9;
  transform.v1.z = v10;
  transform.v1.w = v11;
  v12 = *((float *)ActiveView + 37);
  v13 = *((float *)ActiveView + 38);
  v14 = *((float *)ActiveView + 39);
  transform.v2.x = *((float *)ActiveView + 36);
  transform.v2.y = v12;
  transform.v2.z = v13;
  transform.v2.w = v14;
  v15 = *((float *)ActiveView + 41);
  v16 = *((float *)ActiveView + 42);
  v17 = *((float *)ActiveView + 43);
  transform.v3.x = *((float *)ActiveView + 40);
  transform.v3.y = v15;
  transform.v3.z = v16;
  transform.v3.w = v17;
  v41.mUID = -1;
  UFG::qString::qString(&v39);
  Name = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, Name);
  UFG::qString::operator+=(&v39, "_ExteriorCore_");
  v41.mUID = UFG::RacketInstance::ExteriorCorePrefab(&result, racket_type, mSlider_RacketLevel, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v19 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v19, &transform, v39.mData);
  }
  v20 = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, v20);
  UFG::qString::operator+=(&v39, "_ExteriorCoreProps_");
  v41.mUID = UFG::RacketInstance::ExteriorCorePropsPrefab(&result, racket_type, mSlider_RacketLevel, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v21 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v21, &transform, v39.mData);
  }
  v22 = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, v22);
  UFG::qString::operator+=(&v39, "_ExteriorCoreDoors_");
  v41.mUID = UFG::RacketInstance::ExteriorCoreDoorsPrefab(&result, racket_type, mSlider_RacketLevel, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v23 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v23, &transform, v39.mData);
  }
  v24 = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, v24);
  UFG::qString::operator+=(&v39, "_InteriorCore_");
  v41.mUID = UFG::RacketInstance::InteriorCorePrefab(&result, racket_type, mSlider_RacketLevel, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v25 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v25, &transform, v39.mData);
  }
  v26 = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, v26);
  UFG::qString::operator+=(&v39, "_InteriorCoreProps_");
  v41.mUID = UFG::RacketInstance::InteriorCorePropsPrefab(&result, racket_type, mSlider_RacketLevel, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v27 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v27, &transform, v39.mData);
  }
  v28 = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, v28);
  UFG::qString::operator+=(&v39, "_InteriorCoreDoors_");
  v41.mUID = UFG::RacketInstance::InteriorCoreDoorsPrefab(&result, racket_type, mSlider_RacketLevel, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v29 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v29, &transform, v39.mData);
  }
  v30 = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, v30);
  UFG::qString::operator+=(&v39, "_Decals_");
  v41.mUID = UFG::RacketInstance::DecalsPrefab(&result, racket_type, mSlider_RacketLevel, 0)->mUID;
  if ( v41.mUID != -1 )
  {
    v31 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v31, &transform, v39.mData);
  }
  v32 = UFG::qReflectObject::GetName(racket_type->mData);
  UFG::qString::Set(&v39, v32);
  UFG::qString::operator+=(&v39, "_Theme_");
  v41.mUID = UFG::RacketInstance::ThemePrefab(&result, racket_type, mSlider_RacketLevel)->mUID;
  if ( v41.mUID != -1 )
  {
    v33 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v33, &transform, v39.mData);
  }
  mData = racket_type->mData;
  if ( this->mToggle_LocalPlayerRacket )
  {
    v37 = UFG::qReflectObject::GetName(mData);
    UFG::qString::Set(&v39, v37);
    UFG::qString::operator+=(&v39, "_Ambient_");
    v36 = UFG::RacketInstance::AmbientPrefab(&result, racket_type, mSlider_RacketLevel);
  }
  else
  {
    v35 = UFG::qReflectObject::GetName(mData);
    UFG::qString::Set(&v39, v35);
    UFG::qString::operator+=(&v39, "_Gameplay_");
    v36 = UFG::RacketInstance::GameplayPrefab(&result, racket_type, mSlider_RacketLevel);
  }
  v41.mUID = v36->mUID;
  if ( v41.mUID != -1 )
  {
    v38 = UFG::qSymbol::as_cstr_dbg(&v41);
    UFG::Editor::ObjectFactory::CreateObjectFromArcy(v38, &transform, v39.mData);
  }
  UFG::qString::~qString(&v39);
}

