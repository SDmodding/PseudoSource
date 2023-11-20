// File Line: 26
// RVA: 0x1544060
__int64 dynamic_initializer_for__UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList__);
}

// File Line: 27
// RVA: 0x532560
const char *__fastcall UFG::SimObjectVehiclePropertiesComponent::GetTypeName(UFG::SimObjectVehiclePropertiesComponent *this)
{
  return "SimObjectVehiclePropertiesComponent";
}

// File Line: 35
// RVA: 0x518CE0
void __fastcall UFG::SimObjectVehiclePropertiesComponent::SimObjectVehiclePropertiesComponent(UFG::SimObjectVehiclePropertiesComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, component_VehicleProperties *dataPtr)
{
  component_VehicleProperties *v4; // r13
  UFG::qPropertySet *v5; // rbx
  UFG::SimObjectVehiclePropertiesComponent *v6; // rdi
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v7; // rdx
  UFG::qPropertySet *v8; // rsi
  UFG::qArray<UFG::SimObjectVehiclePropertiesComponent::AimLimit,0> *v9; // r14
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v10; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rax
  __int64 v15; // rax
  unsigned int v16; // ebx
  UFG::qPropertyList *v17; // r9
  int v18; // er8
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int v21; // esi
  unsigned int v22; // edx
  unsigned int v23; // edx
  unsigned int v24; // eax
  unsigned int v25; // er15
  __int64 v26; // r14
  unsigned int v27; // er13
  char *v28; // rax
  float *v29; // r12
  float *v30; // rcx
  float v31; // xmm0_4
  float v32; // xmm0_4
  __int64 v33; // rax
  UFG::qPropertyList *v34; // r15
  unsigned int v35; // er12
  UFG::qArray<UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo,0> *v36; // r14
  unsigned int v37; // ecx
  unsigned int v38; // esi
  unsigned int v39; // eax
  unsigned int v40; // er14
  __int64 v41; // rsi
  char *v42; // rax
  UFG::qPropertySet *v43; // rbx
  char *v44; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v45; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v46; // rax
  signed __int64 v47; // [rsp+0h] [rbp-69h]
  TracksEnumBinding<unsigned long> v48; // [rsp+10h] [rbp-59h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+30h] [rbp-39h]
  int v50; // [rsp+E0h] [rbp+77h]
  component_VehicleProperties *v51; // [rsp+E8h] [rbp+7Fh]

  v4 = dataPtr;
  v5 = properties;
  v6 = this;
  UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(
    (UFG::SimObjectPropertiesComponent *)&this->vfptr,
    name_uid,
    &dataPtr->0);
  v7 = (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectVehiclePropertiesComponent::`vftable';
  v8 = 0i64;
  *(_QWORD *)&v6->m_eSimObjectVehicleType = 0i64;
  v9 = &v6->mAimLimit;
  v9->p = 0i64;
  *(_QWORD *)&v9->size = 0i64;
  v6->mFaceReplenishMultiplier = 1.0;
  v6->mDoorPhantomInfo.p = 0i64;
  *(_QWORD *)&v6->mDoorPhantomInfo.size = 0i64;
  v6->mIsGarageVehicle = 0;
  v10 = UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mPrev;
  UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *)&v6->mPrev;
  v7->mPrev = v10;
  v6->mNext = (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList;
  UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mPrev = (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *)&v6->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v6->vfptr,
    UFG::SimObjectVehiclePropertiesComponent::_SimObjectVehiclePropertiesComponentTypeUID,
    "SimObjectVehiclePropertiesComponent");
  if ( v5 )
  {
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol.mUID = v4->simObjectVehicleType.mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gSimObjectVehicleTypeTracksEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectVehicleTypeTracksEnum, &pTrackEnumBinding);
    }
    else
    {
      v11 = UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v11;
      pTrackEnumBinding.mNext = &UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v6->m_eSimObjectVehicleType = pTrackEnumBinding.m_EnumValue;
    if ( v4->simObjectBoatType.mUID != UFG::gNullQSymbol.mUID )
    {
      v48.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v48;
      v48.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v48;
      v48.m_EnumSymbol.mUID = -1;
      v48.m_EnumSymbol.mUID = v4->simObjectBoatType.mUID;
      *(_QWORD *)&v48.m_EnumValue = 0i64;
      v48.m_uEnumUID = 0;
      if ( UFG::gSimObjectBoatTypeTracksEnum.m_enumLists.size )
      {
        TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectBoatTypeTracksEnum, &v48);
      }
      else
      {
        v12 = UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
        UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v48;
        v48.mPrev = v12;
        v48.mNext = &UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v48;
      }
      v6->m_eSimObjectBoatType = v48.m_EnumValue;
      v13 = v48.mPrev;
      v14 = v48.mNext;
      v48.mPrev->mNext = v48.mNext;
      v14->mPrev = v13;
      v48.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v48;
      v48.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v48;
    }
    v15 = v4->aim_limit.mOffset;
    v16 = 1;
    if ( v15 )
    {
      v17 = (UFG::qPropertyList *)((char *)&v4->aim_limit + v15);
      v47 = (signed __int64)&v4->aim_limit + v15;
      if ( (UFG::qOffset64<UFG::qPropertyList *> *)((char *)&v4->aim_limit + v15) )
      {
        v18 = v17->mNumElements;
        v50 = v18;
        v19 = v9->size;
        v20 = v18 - v9->size;
        if ( (signed int)(v18 - v9->size) <= 0 )
        {
          v24 = v9->size - v18;
          if ( v9->size != v18 )
          {
            if ( v24 < v19 )
              v9->size = v19 - v24;
            else
              v9->size = 0;
          }
        }
        else
        {
          v21 = v19 + v20;
          v22 = v6->mAimLimit.capacity;
          if ( v19 + v20 > v22 )
          {
            if ( v22 )
              v23 = 2 * v22;
            else
              v23 = 1;
            for ( ; v23 < v21; v23 *= 2 )
              ;
            if ( v23 <= 2 )
              v23 = 2;
            if ( v23 - v21 > 0x10000 )
              v23 = v21 + 0x10000;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v6->mAimLimit,
              v23,
              "mAimLimit");
            v18 = v50;
            v17 = (UFG::qPropertyList *)v47;
          }
          v9->size = v21;
          v8 = 0i64;
        }
        v25 = 0;
        if ( v18 )
        {
          v26 = 0i64;
          v27 = v50;
          do
          {
            v28 = UFG::qPropertyList::GetValuePtr(v17, 0x1Au, v25);
            if ( v28 && *(_QWORD *)v28 )
              v8 = (UFG::qPropertySet *)&v28[*(_QWORD *)v28];
            v29 = UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&qSymbol_left.mUID, DEPTH_RECURSE);
            v30 = UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&qSymbol_right.mUID, DEPTH_RECURSE);
            if ( v29 )
              v31 = (float)(*v29 * 3.1415927) * 0.0055555557;
            else
              v31 = FLOAT_0_78539819;
            v6->mAimLimit.p[v26].left = v31;
            if ( v30 )
              v32 = (float)(*v30 * 3.1415927) * 0.0055555557;
            else
              v32 = FLOAT_N0_78539819;
            v6->mAimLimit.p[v26].right = v32;
            ++v25;
            ++v26;
            v17 = (UFG::qPropertyList *)v47;
            v8 = 0i64;
          }
          while ( v25 < v27 );
          v4 = v51;
        }
      }
    }
    v6->mDefaultAimLimit.left = (float)(v4->default_left_aim_limit * 3.1415927) * 0.0055555557;
    v6->mDefaultAimLimit.right = (float)(v4->default_right_aim_limit * 3.1415927) * 0.0055555557;
    v33 = v4->door_phantom_info.mOffset;
    if ( v33 )
    {
      v34 = (UFG::qPropertyList *)((char *)&v4->door_phantom_info + v33);
      if ( v34 )
      {
        v35 = v34->mNumElements;
        v36 = &v6->mDoorPhantomInfo;
        v37 = v6->mDoorPhantomInfo.size;
        if ( (signed int)(v34->mNumElements - v37) <= 0 )
        {
          if ( v37 != v34->mNumElements )
          {
            if ( v37 - v34->mNumElements < v37 )
              v36->size = v34->mNumElements;
            else
              v36->size = 0;
          }
        }
        else
        {
          v38 = v34->mNumElements;
          v39 = v6->mDoorPhantomInfo.capacity;
          if ( v38 > v39 )
          {
            if ( v39 )
              v16 = 2 * v39;
            for ( ; v16 < v38; v16 *= 2 )
              ;
            if ( v16 - v38 > 0x10000 )
              v16 = v38 + 0x10000;
            UFG::qArray<UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo,0>::Reallocate(
              &v6->mDoorPhantomInfo,
              v16,
              "mDoorPhantomInfo");
          }
          v36->size = v38;
        }
        v40 = 0;
        if ( v35 )
        {
          v41 = 0i64;
          do
          {
            v42 = UFG::qPropertyList::GetValuePtr(v34, 0x1Au, v40);
            if ( v42 && *(_QWORD *)v42 )
              v43 = (UFG::qPropertySet *)&v42[*(_QWORD *)v42];
            else
              v43 = 0i64;
            if ( schema_doorphantominfo::IsClass(v43->mSchemaName.mUID) )
              v44 = UFG::qPropertySet::GetMemImagePtr(v43);
            else
              v44 = 0i64;
            v6->mDoorPhantomInfo.p[v41].door = *(_DWORD *)v44;
            v6->mDoorPhantomInfo.p[v41].extentX = *((float *)v44 + 1);
            v6->mDoorPhantomInfo.p[v41].extentY = *((float *)v44 + 2);
            v6->mDoorPhantomInfo.p[v41].height = *((float *)v44 + 3);
            v6->mDoorPhantomInfo.p[v41].heightOffset = *((float *)v44 + 4);
            v6->mDoorPhantomInfo.p[v41].extendLeft = v44[20];
            v6->mDoorPhantomInfo.p[v41].extendForward = v44[21];
            ++v40;
            ++v41;
          }
          while ( v40 < v35 );
        }
      }
    }
    v45 = pTrackEnumBinding.mPrev;
    v46 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v46->mPrev = v45;
  }
}4[21];
            ++v40;
            ++v41;
          }
          while ( v40 < v35 );
        }
      }
    }
    v45 = pTrackEnumBinding.mPrev;
    v46 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.m

// File Line: 113
// RVA: 0x51C850
void __fastcall UFG::SimObjectVehiclePropertiesComponent::~SimObjectVehiclePropertiesComponent(UFG::SimObjectVehiclePropertiesComponent *this)
{
  UFG::SimObjectVehiclePropertiesComponent *v1; // rbx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v2; // rdi
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v3; // rcx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v4; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *v5; // rcx
  UFG::SimObjectVehiclePropertiesComponent::AimLimit *v6; // rcx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v7; // rcx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectVehiclePropertiesComponent::`vftable';
  if ( this == UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentpCurrentIterator )
    UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentpCurrentIterator = (UFG::SimObjectVehiclePropertiesComponent *)&this->mPrev[-10].mNext;
  v2 = (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mDoorPhantomInfo.p;
  if ( v5 )
    operator delete[](v5);
  v1->mDoorPhantomInfo.p = 0i64;
  *(_QWORD *)&v1->mDoorPhantomInfo.size = 0i64;
  v6 = v1->mAimLimit.p;
  if ( v6 )
    operator delete[](v6);
  v1->mAimLimit.p = 0i64;
  *(_QWORD *)&v1->mAimLimit.size = 0i64;
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent((UFG::SimObjectPropertiesComponent *)&v1->vfptr);
}

// File Line: 127
// RVA: 0x546E50
UFG::SimComponent *__fastcall UFG::SimObjectVehiclePropertiesComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rdx
  unsigned __int16 v14; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_VehicleProperties::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0xE8ui64, "SimObjectVehiclePropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = v3->mpWritableProperties;
    if ( !v11 )
      v11 = v3->mpConstProperties;
    UFG::SimObjectVehiclePropertiesComponent::SimObjectVehiclePropertiesComponent(
      (UFG::SimObjectVehiclePropertiesComponent *)v10,
      v3->m_NameUID,
      v11,
      (component_VehicleProperties *)v7);
    v6 = v12;
  }
  v13 = v3->m_pSimObject;
  v14 = v13->m_Flags;
  if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 )
    v15 = 3;
  else
    v15 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v16, v13, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 145
// RVA: 0x53E8D0
void __fastcall UFG::SimObjectVehiclePropertiesComponent::OnAttach(UFG::SimObjectVehiclePropertiesComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObjectPropertiesComponent::OnAttach((UFG::SimObjectPropertiesComponent *)&this->vfptr, pObject);
}

// File Line: 162
// RVA: 0x52CC60
UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *__fastcall UFG::SimObjectVehiclePropertiesComponent::GetDoorPhantomInfo(UFG::SimObjectVehiclePropertiesComponent *this, unsigned int door)
{
  unsigned int v2; // er8
  __int64 v3; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *v4; // r9
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *v5; // rcx

  v2 = this->mDoorPhantomInfo.size;
  v3 = 0i64;
  if ( !v2 )
    return 0i64;
  v4 = this->mDoorPhantomInfo.p;
  v5 = this->mDoorPhantomInfo.p;
  while ( v5->door != door )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v5;
    if ( (unsigned int)v3 >= v2 )
      return 0i64;
  }
  return &v4[v3];
}

