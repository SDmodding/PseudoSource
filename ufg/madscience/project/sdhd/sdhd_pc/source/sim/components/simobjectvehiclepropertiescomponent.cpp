// File Line: 26
// RVA: 0x1544060
__int64 dynamic_initializer_for__UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList__);
}

// File Line: 27
// RVA: 0x532560
const char *__fastcall UFG::SimObjectVehiclePropertiesComponent::GetTypeName(
        UFG::SimObjectVehiclePropertiesComponent *this)
{
  return "SimObjectVehiclePropertiesComponent";
}

// File Line: 35
// RVA: 0x518CE0
// bad sp value at call has been detected, the output may be wrong!
void __fastcall UFG::SimObjectVehiclePropertiesComponent::SimObjectVehiclePropertiesComponent(
        UFG::SimObjectVehiclePropertiesComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        component_VehicleProperties *dataPtr)
{
  component_VehicleProperties *v4; // r13
  UFG::qPropertySet *v7; // rsi
  UFG::qArray<UFG::SimObjectVehiclePropertiesComponent::AimLimit,0> *p_mAimLimit; // r14
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  __int64 mOffset; // rax
  unsigned int v15; // ebx
  UFG::qPropertyList *v16; // r9
  int mNumElements; // r8d
  unsigned int size; // ecx
  int v19; // eax
  unsigned int v20; // esi
  unsigned int capacity; // edx
  unsigned int v22; // edx
  unsigned int v23; // eax
  unsigned int v24; // r15d
  __int64 v25; // r14
  unsigned int v26; // r13d
  char *ValuePtr; // rax
  float *v28; // r12
  float *v29; // rcx
  float v30; // xmm0_4
  float v31; // xmm0_4
  __int64 v32; // rax
  UFG::qPropertyList *v33; // r15
  unsigned int v34; // r12d
  UFG::qArray<UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo,0> *p_mDoorPhantomInfo; // r14
  unsigned int v36; // ecx
  unsigned int v37; // esi
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // r14d
  __int64 v41; // rsi
  char *v42; // rax
  UFG::qPropertySet *v43; // rbx
  char *MemImagePtr; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v45; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v46; // rax
  UFG::qPropertyList *v47; // [rsp+0h] [rbp-69h]
  TracksEnumBinding<unsigned long> v48; // [rsp+10h] [rbp-59h] BYREF
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+30h] [rbp-39h] BYREF
  int v50; // [rsp+E0h] [rbp+77h]
  component_VehicleProperties *v51; // [rsp+E8h] [rbp+7Fh]

  v4 = dataPtr;
  UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(this, name_uid, dataPtr);
  this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>::mPrev = &this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>;
  this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>::mNext = &this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectVehiclePropertiesComponent::`vftable;
  v7 = 0i64;
  *(_QWORD *)&this->m_eSimObjectVehicleType = 0i64;
  p_mAimLimit = &this->mAimLimit;
  this->mAimLimit.p = 0i64;
  *(_QWORD *)&this->mAimLimit.size = 0i64;
  this->mFaceReplenishMultiplier = 1.0;
  this->mDoorPhantomInfo.p = 0i64;
  *(_QWORD *)&this->mDoorPhantomInfo.size = 0i64;
  this->mIsGarageVehicle = 0;
  mPrev = UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mPrev;
  UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>;
  this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>::mNext = (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList;
  UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mPrev = &this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::SimObjectVehiclePropertiesComponent::_SimObjectVehiclePropertiesComponentTypeUID,
    "SimObjectVehiclePropertiesComponent");
  if ( properties )
  {
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
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
      v10 = UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v10;
      pTrackEnumBinding.mNext = &UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    this->m_eSimObjectVehicleType = pTrackEnumBinding.m_EnumValue;
    if ( v4->simObjectBoatType.mUID != UFG::gNullQSymbol.mUID )
    {
      v48.mPrev = &v48;
      v48.mNext = &v48;
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
        v11 = UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
        UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &v48;
        v48.mPrev = v11;
        v48.mNext = &UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gSimObjectBoatTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &v48;
      }
      this->m_eSimObjectBoatType = v48.m_EnumValue;
      v12 = v48.mPrev;
      mNext = v48.mNext;
      v48.mPrev->mNext = v48.mNext;
      mNext->mPrev = v12;
      v48.mPrev = &v48;
      v48.mNext = &v48;
    }
    mOffset = v4->aim_limit.mOffset;
    v15 = 1;
    if ( mOffset )
    {
      v16 = (UFG::qPropertyList *)((char *)&v4->aim_limit + mOffset);
      v47 = v16;
      if ( v16 )
      {
        mNumElements = v16->mNumElements;
        v50 = mNumElements;
        size = p_mAimLimit->size;
        v19 = mNumElements - p_mAimLimit->size;
        if ( v19 <= 0 )
        {
          v23 = p_mAimLimit->size - mNumElements;
          if ( v23 )
          {
            if ( v23 < size )
              p_mAimLimit->size = size - v23;
            else
              p_mAimLimit->size = 0;
          }
        }
        else
        {
          v20 = size + v19;
          capacity = this->mAimLimit.capacity;
          if ( size + v19 > capacity )
          {
            if ( capacity )
              v22 = 2 * capacity;
            else
              v22 = 1;
            for ( ; v22 < v20; v22 *= 2 )
              ;
            if ( v22 <= 2 )
              v22 = 2;
            if ( v22 - v20 > 0x10000 )
              v22 = v20 + 0x10000;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mAimLimit,
              v22,
              "mAimLimit");
            mNumElements = v50;
            v16 = v47;
          }
          p_mAimLimit->size = v20;
          v7 = 0i64;
        }
        v24 = 0;
        if ( mNumElements )
        {
          v25 = 0i64;
          v26 = v50;
          do
          {
            ValuePtr = UFG::qPropertyList::GetValuePtr(v16, 0x1Au, v24);
            if ( ValuePtr && *(_QWORD *)ValuePtr )
              v7 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
            v28 = UFG::qPropertySet::Get<float>(v7, (UFG::qArray<unsigned long,0> *)&qSymbol_left, DEPTH_RECURSE);
            v29 = UFG::qPropertySet::Get<float>(v7, (UFG::qArray<unsigned long,0> *)&qSymbol_right, DEPTH_RECURSE);
            if ( v28 )
              v30 = (float)(*v28 * 3.1415927) * 0.0055555557;
            else
              v30 = FLOAT_0_78539819;
            this->mAimLimit.p[v25].left = v30;
            if ( v29 )
              v31 = (float)(*v29 * 3.1415927) * 0.0055555557;
            else
              v31 = FLOAT_N0_78539819;
            this->mAimLimit.p[v25].right = v31;
            ++v24;
            ++v25;
            v16 = v47;
            v7 = 0i64;
          }
          while ( v24 < v26 );
          v4 = v51;
        }
      }
    }
    this->mDefaultAimLimit.left = (float)(v4->default_left_aim_limit * 3.1415927) * 0.0055555557;
    this->mDefaultAimLimit.right = (float)(v4->default_right_aim_limit * 3.1415927) * 0.0055555557;
    v32 = v4->door_phantom_info.mOffset;
    if ( v32 )
    {
      v33 = (UFG::qPropertyList *)((char *)&v4->door_phantom_info + v32);
      if ( v33 )
      {
        v34 = v33->mNumElements;
        p_mDoorPhantomInfo = &this->mDoorPhantomInfo;
        v36 = this->mDoorPhantomInfo.size;
        if ( (int)(v34 - v36) <= 0 )
        {
          v39 = v36 - v33->mNumElements;
          if ( v39 )
          {
            if ( v39 < v36 )
              p_mDoorPhantomInfo->size = v33->mNumElements;
            else
              p_mDoorPhantomInfo->size = 0;
          }
        }
        else
        {
          v37 = v33->mNumElements;
          v38 = this->mDoorPhantomInfo.capacity;
          if ( v37 > v38 )
          {
            if ( v38 )
              v15 = 2 * v38;
            for ( ; v15 < v37; v15 *= 2 )
              ;
            if ( v15 - v37 > 0x10000 )
              v15 = v37 + 0x10000;
            UFG::qArray<UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo,0>::Reallocate(
              &this->mDoorPhantomInfo,
              v15,
              "mDoorPhantomInfo");
          }
          p_mDoorPhantomInfo->size = v37;
        }
        v40 = 0;
        if ( v34 )
        {
          v41 = 0i64;
          do
          {
            v42 = UFG::qPropertyList::GetValuePtr(v33, 0x1Au, v40);
            if ( v42 && *(_QWORD *)v42 )
              v43 = (UFG::qPropertySet *)&v42[*(_QWORD *)v42];
            else
              v43 = 0i64;
            if ( schema_doorphantominfo::IsClass(v43->mSchemaName.mUID) )
              MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v43);
            else
              MemImagePtr = 0i64;
            this->mDoorPhantomInfo.p[v41].door = *(_DWORD *)MemImagePtr;
            this->mDoorPhantomInfo.p[v41].extentX = *((float *)MemImagePtr + 1);
            this->mDoorPhantomInfo.p[v41].extentY = *((float *)MemImagePtr + 2);
            this->mDoorPhantomInfo.p[v41].height = *((float *)MemImagePtr + 3);
            this->mDoorPhantomInfo.p[v41].heightOffset = *((float *)MemImagePtr + 4);
            this->mDoorPhantomInfo.p[v41].extendLeft = MemImagePtr[20];
            this->mDoorPhantomInfo.p[v41].extendForward = MemImagePtr[21];
            ++v40;
            ++v41;
          }
          while ( v40 < v34 );
        }
      }
    }
    v45 = pTrackEnumBinding.mPrev;
    v46 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v46->mPrev = v45;
  }
}

// File Line: 113
// RVA: 0x51C850
void __fastcall UFG::SimObjectVehiclePropertiesComponent::~SimObjectVehiclePropertiesComponent(
        UFG::SimObjectVehiclePropertiesComponent *this)
{
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v2; // rdi
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *mPrev; // rcx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *mNext; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *p; // rcx
  UFG::SimObjectVehiclePropertiesComponent::AimLimit *v6; // rcx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v7; // rcx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectVehiclePropertiesComponent::`vftable;
  if ( this == UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentpCurrentIterator )
    UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentpCurrentIterator = (UFG::SimObjectVehiclePropertiesComponent *)&this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>::mPrev[-10].mNext;
  v2 = &this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>;
  mPrev = this->UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p = this->mDoorPhantomInfo.p;
  if ( p )
    operator delete[](p);
  this->mDoorPhantomInfo.p = 0i64;
  *(_QWORD *)&this->mDoorPhantomInfo.size = 0i64;
  v6 = this->mAimLimit.p;
  if ( v6 )
    operator delete[](v6);
  this->mAimLimit.p = 0i64;
  *(_QWORD *)&this->mAimLimit.size = 0i64;
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent(this);
}

// File Line: 127
// RVA: 0x546E50
UFG::SimComponent *__fastcall UFG::SimObjectVehiclePropertiesComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *mpConstProperties; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_VehicleProperties::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE8ui64, "SimObjectVehiclePropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    UFG::SimObjectVehiclePropertiesComponent::SimObjectVehiclePropertiesComponent(
      (UFG::SimObjectVehiclePropertiesComponent *)v10,
      pSceneObj->m_NameUID,
      mpConstProperties,
      (component_VehicleProperties *)MemImagePtr);
    v6 = v12;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v15 = 3;
  else
    v15 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v16, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 145
// RVA: 0x53E8D0
// attributes: thunk
void __fastcall UFG::SimObjectVehiclePropertiesComponent::OnAttach(
        UFG::SimObjectVehiclePropertiesComponent *this,
        UFG::SimObject *pObject)
{
  UFG::SimObjectPropertiesComponent::OnAttach(this, pObject);
}

// File Line: 162
// RVA: 0x52CC60
UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *__fastcall UFG::SimObjectVehiclePropertiesComponent::GetDoorPhantomInfo(
        UFG::SimObjectVehiclePropertiesComponent *this,
        unsigned int door)
{
  unsigned int size; // r8d
  __int64 v3; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *p; // r9
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *i; // rcx

  size = this->mDoorPhantomInfo.size;
  v3 = 0i64;
  if ( !size )
    return 0i64;
  p = this->mDoorPhantomInfo.p;
  for ( i = p; i->door != door; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= size )
      return 0i64;
  }
  return &p[v3];
}

