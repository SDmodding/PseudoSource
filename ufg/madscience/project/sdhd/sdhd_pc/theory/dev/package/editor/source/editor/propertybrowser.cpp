// File Line: 26
// RVA: 0x146D340
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::PropertyBrowserWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::PropertyBrowserWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory,
    "UFG::Editor::PropertyBrowserWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::PropertyBrowserWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::PropertyBrowserWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::PropertyBrowserWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 44
// RVA: 0x146DA50
__int64 UFG::Editor::_dynamic_initializer_for__gPropertyChangedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::Editor::gPropertyChangedChannel, 0x9670AC65, 0i64, 0i64);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gPropertyChangedChannel__);
}

// File Line: 49
// RVA: 0x146D8B0
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_PropertyBrowser_ControlOverrides__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PropertyBrowser_ControlOverrides", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_PropertyBrowser_ControlOverrides, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__Symbol_PropertyBrowser_ControlOverrides__);
}

// File Line: 50
// RVA: 0x146D7F0
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_ControlOverride_Control__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ControlOverride_Control", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_ControlOverride_Control, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__Symbol_ControlOverride_Control__);
}

// File Line: 51
// RVA: 0x146D830
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_ControlOverride_EnumValues__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ControlOverride_EnumValues", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_ControlOverride_EnumValues, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__Symbol_ControlOverride_EnumValues__);
}

// File Line: 53
// RVA: 0x146D7B0
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_ColourPicker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ColourPicker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_ColourPicker, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__Symbol_ColourPicker__);
}

// File Line: 54
// RVA: 0x146D870
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_Enum__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Enum", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_Enum, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__Symbol_Enum__);
}

// File Line: 57
// RVA: 0x20B720
UFG::qSymbol *__fastcall UFG::Editor::GetControlOverride(
        UFG::qSymbol *result,
        UFG::qSymbol *propertySymbol,
        UFG::qPropertySet **out_controlOverride)
{
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rsi
  unsigned int mNumElements; // edi
  unsigned int v11; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *v13; // rcx
  UFG::qSymbol *v14; // rax
  UFG::qSymbol *v15; // rcx
  unsigned int mUID; // eax
  UFG::qSymbol resulta; // [rsp+68h] [rbp+20h] BYREF

  if ( (_S23 & 1) != 0 )
  {
    PropertySet = config;
  }
  else
  {
    _S23 |= 1u;
    v6 = UFG::qSymbol::create_from_string(&resulta, "config-PropertyBrowser");
    PropertySet = UFG::PropertySetManager::FindPropertySet(v6);
    config = PropertySet;
  }
  if ( PropertySet
    && (v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
               PropertySet,
               (UFG::qArray<unsigned long,0> *)&Symbol_PropertyBrowser_ControlOverrides,
               DEPTH_RECURSE),
        (v9 = v8) != 0i64)
    && (mNumElements = v8->mNumElements, v11 = 0, mNumElements) )
  {
    while ( 1 )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v13 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v13 = 0i64;
      if ( v13->mName.mUID == propertySymbol->mUID )
        break;
      if ( ++v11 >= mNumElements )
        goto LABEL_19;
    }
    if ( out_controlOverride )
      *out_controlOverride = v13;
    v14 = UFG::qPropertySet::Get<UFG::qSymbol>(
            v13,
            (UFG::qArray<unsigned long,0> *)&Symbol_ControlOverride_Control,
            DEPTH_RECURSE);
    v15 = &UFG::gNullQSymbol;
    if ( v14 )
      v15 = v14;
    mUID = v15->mUID;
  }
  else
  {
LABEL_19:
    mUID = UFG::gNullQSymbol.mUID;
  }
  result->mUID = mUID;
  return result;
}

// File Line: 124
// RVA: 0x2127C0
void __fastcall UFG::Editor::VectoredValue::Set(UFG::Editor::VectoredValue *this, UFG::qMatrix44 *m)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  bool v7; // zf
  float v8; // xmm1_4
  float v9; // xmm0_4
  char v10; // al
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  __m128 x_low; // xmm3
  float v15; // xmm5_4
  __m128 v16; // xmm3
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  __m128 v21; // xmm3
  UFG::qVector3 soln; // [rsp+20h] [rbp-18h] BYREF

  x = m->v3.x;
  this->mbValid[0] = 1;
  this->mValue[0] = x;
  y = m->v3.y;
  this->mbValid[1] = 1;
  this->mValue[1] = y;
  z = m->v3.z;
  this->mbValid[2] = 1;
  this->mValue[2] = z;
  v7 = !this->mbValid[3];
  soln = UFG::qVector3::msZero;
  if ( !v7 && this->mbValid[4] && this->mbValid[5] )
  {
    v8 = this->mValue[4];
    soln.x = this->mValue[3];
    v9 = this->mValue[5];
    soln.y = v8;
    soln.z = v9;
  }
  v10 = UFG::Editor::Utility::DecomposeAffineEulerSmart_RoundedDegrees(&soln, m, 1);
  *(_WORD *)&this->mbValid[3] = 257;
  v11 = soln.x;
  v12 = soln.y;
  this->mbGimbalLock = v10;
  this->mValue[3] = v11;
  v13 = soln.z;
  this->mValue[4] = v12;
  this->mbValid[5] = 1;
  this->mValue[5] = v13;
  x_low = (__m128)LODWORD(m->v0.x);
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(m->v0.y * m->v0.y))
                            + (float)(m->v0.z * m->v0.z))
                    + (float)(m->v0.w * m->v0.w);
  LODWORD(v15) = _mm_sqrt_ps(x_low).m128_u32[0];
  v16 = (__m128)LODWORD(m->v1.x);
  v17 = m->v2.y * m->v2.y;
  v18 = m->v2.z * m->v2.z;
  v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(m->v1.y * m->v1.y))
                          + (float)(m->v1.z * m->v1.z))
                  + (float)(m->v1.w * m->v1.w);
  v19 = m->v2.w * m->v2.w;
  LODWORD(v20) = _mm_sqrt_ps(v16).m128_u32[0];
  v21 = (__m128)LODWORD(m->v2.x);
  *(_WORD *)&this->mbValid[6] = 257;
  this->mValue[6] = v15;
  this->mValue[7] = v20;
  this->mbValid[8] = 1;
  v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + v17) + v18) + v19;
  LODWORD(this->mValue[8]) = _mm_sqrt_ps(v21).m128_u32[0];
  this->mElementCount = 9;
}

// File Line: 227
// RVA: 0x2023B0
void __fastcall UFG::Editor::PropertyProxy_PropertySet::PropertyProxy_PropertySet(
        UFG::Editor::PropertyProxy_PropertySet *this,
        UFG::qSymbol *propertyName,
        int arrayIndex)
{
  this->mPrev = &this->UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy>;
  this->mNext = &this->UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy>;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  this->mDataType = UID_propertyset;
  this->mPropertyName = (UFG::qSymbol)propertyName->mUID;
  this->mArrayIndex = arrayIndex;
  this->mParent = 0i64;
  *(_WORD *)&this->mIsLocal = 0;
  this->mIsListProperty = 0;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_Container::`vftable;
  this->mChildren.mChildrenOrdered.mNode.UFG::Editor::PropertyProxy_Container::mPrev = &this->mChildren.mChildrenOrdered.mNode;
  this->mChildren.mChildrenOrdered.mNode.mNext = &this->mChildren.mChildrenOrdered.mNode;
  this->mHasGenerantedChildren = 0;
  this->mSelectedTypeOption = 0;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::qString(&this->mNewPropertyName);
}

// File Line: 250
// RVA: 0x213C80
void __fastcall UFG::Editor::PropertyProxySimple::TryGenerateSuggestions(UFG::Editor::PropertyProxySimple *this)
{
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *i; // r8
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rcx
  const char **p; // rcx

  if ( !this->mbSuggestionsGenerated )
  {
    mNext = this->mSuggestionList.mNode.mNext;
    for ( i = &this->mSuggestionList; mNext != (UFG::qNode<UFG::qString,UFG::qString> *)i; mNext = i->mNode.mNext )
    {
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
    }
    p = this->mSuggestions.p;
    if ( p )
      operator delete[](p);
    this->mSuggestions.p = 0i64;
    *(_QWORD *)&this->mSuggestions.size = 0i64;
    this->mbSuggestionsGenerated = 1;
  }
}

// File Line: 268
// RVA: 0x2135A0
void __fastcall UFG::Editor::PropertyProxySimple::Setup(
        UFG::Editor::PropertyProxySimple *this,
        UFG::qArray<UFG::qPropertySet *,0> *propertySets)
{
  qPropertySetVariant value; // [rsp+30h] [rbp-C8h] BYREF

  value.meType = UID_Invalid;
  UFG::qString::qString(&value.mValueString);
  *(_QWORD *)&value.mValueSymbol.mUID = -1i64;
  value.mValueWiseSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  if ( UFG::Editor::GetCommonValue(propertySets, (UFG::qArray<unsigned long,0> *)&this->mPropertyName, &value) )
    qPropertySetVariant::ToString(&value, &this->mValueString);
  _((AMD_HD3D *)value.mValueWiseSymbol.mUID);
  UFG::qString::~qString(&value.mValueString);
}

// File Line: 277
// RVA: 0x213500
void __fastcall UFG::Editor::PropertyProxySimple::Setup(
        UFG::Editor::PropertyProxySimple *this,
        UFG::qArray<UFG::qPropertyList *,0> *propertyLists)
{
  UFG::qPropertyList *v3; // rbx
  qPropertySetVariant value; // [rsp+30h] [rbp-C8h] BYREF

  v3 = *propertyLists->p;
  value.meType = UID_Invalid;
  UFG::qString::qString(&value.mValueString);
  *(_QWORD *)&value.mValueSymbol.mUID = -1i64;
  value.mValueWiseSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  UFG::qPropertyList::GetVariant(v3, this->mArrayIndex, &value);
  qPropertySetVariant::ToString(&value, &this->mValueString);
  _((AMD_HD3D *)value.mValueWiseSymbol.mUID);
  UFG::qString::~qString(&value.mValueString);
}

// File Line: 289
// RVA: 0x214840
void __fastcall UFG::Editor::PropertyProxySimple::UpdateCommon(
        UFG::Editor::PropertyProxySimple *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qPropertyPath *currentPath)
{
  const char **p; // r15
  UFG::qBaseTreeRB *v9; // rbx
  ePropertyType mDataType; // eax
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mSuggestionList; // rbx
  UFG::qPropertyList *v12; // rax
  unsigned int v13; // edi
  UFG::qPropertyList *v14; // r13
  UFG::qString *v15; // r12
  char *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  unsigned int v20; // eax
  UFG::qBaseTreeRB *v21; // rdi
  unsigned int v22; // eax
  UFG::qBaseTreeRB *v23; // rbx
  int v24; // edi
  char v25; // bl
  char mKeycodeDown; // al
  bool v27; // bl
  unsigned int v28; // ebx
  UFG::qPropertySet *out_controlOverride; // [rsp+30h] [rbp-98h] BYREF
  qPropertySetVariant other; // [rsp+40h] [rbp-88h] BYREF
  UFG::qSymbol result; // [rsp+148h] [rbp+80h] BYREF
  UFG::Editor::PropertyBrowser *v32; // [rsp+150h] [rbp+88h]
  UFG::qPropertyPath *v33; // [rsp+160h] [rbp+98h]
  char *name; // [rsp+168h] [rbp+A0h]

  *(_QWORD *)&other.mValueWiseSymbol.mUID = -2i64;
  p = 0i64;
  v9 = 0i64;
  if ( this->mIsSchemaProperty )
    v9 = UFG::PropertyMetadataDatabase::Get((UFG::qArray<unsigned long,0> *)&this->mPropertyName);
  out_controlOverride = 0i64;
  UFG::Editor::GetControlOverride(&result, &this->mPropertyName, &out_controlOverride);
  if ( result.mUID == Symbol_Enum.mUID )
  {
    mDataType = this->mDataType;
    if ( (unsigned int)mDataType <= UID_int64 || (unsigned int)(mDataType - 5) <= 3 )
    {
      UFG::DUIContext::BeginGridLayout(
        dui,
        2,
        1,
        browser->mColWidths,
        0i64,
        LayoutFlag_GridSplitting|LayoutFlag_FillLastCell);
      if ( !this->mIsLocal )
        UFG::DUIContext::PushColour(dui, TextColour, &UFG::qColour::Grey);
      UFG::DUIContext::Label(dui, name);
      if ( !this->mIsLocal )
        UFG::DUIContext::PopColour(dui, 0);
      p_mSuggestionList = &this->mSuggestionList;
      if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)this->mSuggestionList.mNode.mNext == &this->mSuggestionList )
      {
        v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                out_controlOverride,
                (UFG::qArray<unsigned long,0> *)&Symbol_ControlOverride_EnumValues,
                DEPTH_RECURSE);
        v13 = 0;
        if ( v12->mNumElements )
        {
          v14 = v12;
          do
          {
            out_controlOverride = (UFG::qPropertySet *)UFG::qPropertyList::Get<UFG::qSymbol>(v14, v13);
            v15 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
            *(_QWORD *)&other.mValueSymbol.mUID = v15;
            if ( v15 )
            {
              v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)out_controlOverride);
              UFG::qString::qString(v15, v16);
              v18 = v17;
            }
            else
            {
              v18 = 0i64;
            }
            mPrev = p_mSuggestionList->mNode.mPrev;
            mPrev->mNext = v18;
            v18->mPrev = mPrev;
            v18->mNext = &p_mSuggestionList->mNode;
            p_mSuggestionList->mNode.mPrev = v18;
            ++v13;
          }
          while ( v13 < v14->mNumElements );
          browser = v32;
        }
        currentPath = v33;
      }
      result.mUID = UFG::qToInt32(this->mValueString.mData, 0);
      if ( UFG::DUIContext::ComboBox(dui, (int *)&result, &this->mSuggestionList, 0i64, 0xFFFFFFFF) )
      {
        UFG::qString::FormatEx(&other.mValueString, "%d", result.mUID);
        other.meType = UID_Invalid;
        UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
        other.mValueMatrix44.v3.w = NAN;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        qPropertySetVariant::SetFromString(&other, (hkMemoryResourceContainer *)&other.mValueString, this->mDataType);
        browser->mPendingValueChange.mType = NVIDIA;
        qPropertySetVariant::operator=(&browser->mPendingValueChange.mSimpleValue, &other);
        UFG::qPropertyPath::operator=(&browser->mPendingValueChange.mPath, currentPath);
        _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
        UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        UFG::qString::~qString(&other.mValueString);
      }
      goto LABEL_56;
    }
  }
  UFG::DUIContext::BeginGridLayout(
    dui,
    2,
    1,
    browser->mColWidths,
    0i64,
    LayoutFlag_GridSplitting|LayoutFlag_FillLastCell);
  if ( !this->mIsLocal )
    UFG::DUIContext::PushColour(dui, TextColour, &UFG::qColour::Grey);
  UFG::DUIContext::Label(dui, name);
  if ( !this->mIsLocal )
    UFG::DUIContext::PopColour(dui, 0);
  if ( (unsigned int)(this->mDataType - 22) <= 2 )
    UFG::Editor::PropertyProxySimple::TryGenerateSuggestions(this);
  if ( v9 )
  {
    v20 = UFG::qStringHashUpper32("min", -1);
    if ( v20 )
      v21 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v9->mNULL, v20);
    else
      v21 = 0i64;
    v22 = UFG::qStringHashUpper32("max", -1);
    if ( v22 )
      v23 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v9->mNULL, v22);
    else
      v23 = 0i64;
    if ( v21 && v23 )
    {
      v24 = UFG::qToInt32(*(const char **)&v21[1].mRoot.mUID, 0);
      UFG::qToInt32(*(const char **)&v23[1].mRoot.mUID, 0);
      result.mUID = UFG::qToInt32(this->mValueString.mData, 0);
      if ( UFG::DUIContext::Slider(dui, &customCaption, &result.mUID, v24) )
      {
        UFG::qString::FormatEx(&other.mValueString, "%d", result.mUID);
        other.meType = UID_Invalid;
        UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
        other.mValueMatrix44.v3.w = NAN;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        qPropertySetVariant::SetFromString(&other, (hkMemoryResourceContainer *)&other.mValueString, this->mDataType);
        browser->mPendingValueChange.mType = NVIDIA;
        qPropertySetVariant::operator=(&browser->mPendingValueChange.mSimpleValue, &other);
        UFG::qPropertyPath::operator=(&browser->mPendingValueChange.mPath, v33);
        _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
        UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        UFG::qString::~qString(&other.mValueString);
      }
      goto LABEL_56;
    }
    currentPath = v33;
  }
  switch ( this->mDataType )
  {
    case UID_int8:
    case UID_int16:
    case UID_int32:
    case UID_int64:
    case UID_uint8:
    case UID_uint16:
    case UID_uint32:
    case UID_uint64:
    case UID_float:
    case UID_double:
    case UID_string:
    case UID_qSymbol:
    case UID_qSymbolUC:
    case UID_qWiseSymbol:
      if ( this->mPropertyName.mUID == UFG::Editor::gsymCreateObjectFlags.mUID )
      {
        UFG::DUIContext::BeginGridLayout(dui, 0, 1, 0i64, 0i64, LayoutFlag_None);
        v28 = UFG::qToUInt32(this->mValueString.mData, 0);
        result.mUID = v28;
        UFG::DUIContext::Checkbox(dui, "Immediate", &result.mUID, 1u);
        UFG::DUIContext::Checkbox(dui, "Delayed", &result.mUID, 2u);
        UFG::DUIContext::Checkbox(dui, "Deferred Deact.", &result.mUID, 4u);
        if ( result.mUID != v28 )
        {
          UFG::qString::FormatEx(&other.mValueString, "%d", result.mUID);
          other.meType = UID_Invalid;
          UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
          *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
          other.mValueMatrix44.v3.w = NAN;
          _((AMD_HD3D *)0xFFFFFFFFi64);
          qPropertySetVariant::SetFromString(&other, (hkMemoryResourceContainer *)&other.mValueString, this->mDataType);
          browser->mPendingValueChange.mType = NVIDIA;
          qPropertySetVariant::operator=(&browser->mPendingValueChange.mSimpleValue, &other);
          UFG::qPropertyPath::operator=(&browser->mPendingValueChange.mPath, currentPath);
          _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
          UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
          UFG::qString::~qString(&other.mValueString);
        }
        UFG::DUIContext::EndLayoutHorizontal(dui);
      }
      else
      {
        mKeycodeDown = dui->mInputState.mKeycodeDown;
        v27 = mKeycodeDown == 13 || mKeycodeDown == 94;
        if ( this->mSuggestions.size )
          p = this->mSuggestions.p;
        UFG::DUIContext::TextBox(dui, &this->mValueString, 0i64, 1, p, this->mSuggestions.size);
        if ( dui->mControlLostFocus || dui->mFocusedID == dui->mCurrentID && v27 )
        {
          other.meType = UID_Invalid;
          UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
          *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
          other.mValueMatrix44.v3.w = NAN;
          _((AMD_HD3D *)0xFFFFFFFFi64);
          qPropertySetVariant::SetFromString(&other, (hkMemoryResourceContainer *)&this->mValueString, this->mDataType);
          browser->mPendingValueChange.mType = NVIDIA;
          qPropertySetVariant::operator=(&browser->mPendingValueChange.mSimpleValue, &other);
          UFG::qPropertyPath::operator=(&browser->mPendingValueChange.mPath, v33);
          _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
          UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        }
      }
      break;
    case UID_bool:
      v25 = UFG::qToBool(this->mValueString.mData, 0);
      LOBYTE(result.mUID) = v25;
      UFG::DUIContext::Checkbox(dui, &customCaption, (bool *)&result);
      if ( v25 != LOBYTE(result.mUID) )
      {
        other.meType = UID_Invalid;
        UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
        other.mValueMatrix44.v3.w = NAN;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        other.mValueI8 = result.mUID;
        other.meType = UID_bool;
        browser->mPendingValueChange.mType = NVIDIA;
        qPropertySetVariant::operator=(&browser->mPendingValueChange.mSimpleValue, &other);
        UFG::qPropertyPath::operator=(&browser->mPendingValueChange.mPath, currentPath);
        _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
        UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
      }
      break;
    default:
      break;
  }
LABEL_56:
  UFG::DUIContext::EndLayoutHorizontal(dui);
}

// File Line: 474
// RVA: 0x21C200
void __fastcall UFG::Editor::PropertyProxySimple::UpdateUI(
        UFG::Editor::PropertyProxySimple *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::qPropertyList *,0> *selection,
        UFG::qPropertyPath *currentPath)
{
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  UFG::qString::FormatEx(&result, "[%d]", (unsigned int)this->mArrayIndex);
  UFG::Editor::PropertyProxySimple::UpdateCommon(this, browser, dui, currentPath);
  UFG::qString::~qString(&result);
}

// File Line: 480
// RVA: 0x21C280
void __fastcall UFG::Editor::PropertyProxySimple::UpdateUI(
        UFG::Editor::PropertyProxySimple *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::qPropertySet *,0> *selection,
        UFG::qPropertyPath *currentPath)
{
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  UFG::Editor::PropertyProxySimple::UpdateCommon(this, browser, dui, currentPath);
}

// File Line: 485
// RVA: 0x20CE10
char __fastcall UFG::Editor::GetVectorValue(
        UFG::qPropertySet *propertySet,
        UFG::qArray<unsigned long,0> *name,
        UFG::Editor::VectoredValue *value)
{
  float *mValue; // r8
  __int64 i; // rax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  UFG::qMatrix44 *v12; // rax
  UFG::qVector4 *v13; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  UFG::qVector3 *v18; // rax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  UFG::qVector2 *v22; // rax
  float v23; // xmm0_4
  float v24; // xmm1_4

  value->mElementCount = 0;
  mValue = value->mValue;
  for ( i = 0i64; i < 16; ++i )
  {
    value->mbValid[i] = 0;
    *mValue++ = 0.0;
  }
  value->mbGimbalLock = 0;
  v8 = UFG::qPropertySet::GetPropertyTypeFromName(propertySet, name, DEPTH_RECURSE) - 17;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 != 1 )
          return 0;
        v12 = UFG::qPropertySet::Get<UFG::qMatrix44>(propertySet, name, DEPTH_RECURSE);
        UFG::Editor::VectoredValue::Set(value, v12);
      }
      else
      {
        v13 = UFG::qPropertySet::Get<UFG::qVector4>(propertySet, name, DEPTH_RECURSE);
        x = v13->x;
        value->mbValid[0] = 1;
        value->mValue[0] = x;
        y = v13->y;
        value->mbValid[1] = 1;
        value->mValue[1] = y;
        z = v13->z;
        value->mbValid[2] = 1;
        value->mValue[2] = z;
        w = v13->w;
        value->mbValid[3] = 1;
        value->mValue[3] = w;
        value->mElementCount = 4;
      }
    }
    else
    {
      v18 = UFG::qPropertySet::Get<UFG::qVector3>(propertySet, name, DEPTH_RECURSE);
      v19 = v18->x;
      value->mbValid[0] = 1;
      value->mValue[0] = v19;
      v20 = v18->y;
      value->mbValid[1] = 1;
      value->mValue[1] = v20;
      v21 = v18->z;
      value->mbValid[2] = 1;
      value->mValue[2] = v21;
      value->mElementCount = 3;
    }
  }
  else
  {
    v22 = UFG::qPropertySet::Get<UFG::qVector2>(propertySet, name, DEPTH_RECURSE);
    v23 = v22->x;
    value->mbValid[0] = 1;
    value->mValue[0] = v23;
    v24 = v22->y;
    value->mbValid[1] = 1;
    value->mValue[1] = v24;
    value->mElementCount = 2;
  }
  return 1;
}

// File Line: 523
// RVA: 0x212F80
char __fastcall UFG::Editor::SetVectorValue(
        UFG::qPropertySet *propertySet,
        UFG::qArray<unsigned long,0> *name,
        UFG::Editor::VectoredValue *value)
{
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  UFG::qMatrix44 *v10; // rax
  bool v11; // zf
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  __m128 y_low; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm7
  __m128 v31; // xmm2
  __m128 v32; // xmm8
  __m128 v33; // xmm9
  __m128 v34; // xmm7
  __m128 v35; // xmm8
  UFG::qVector4 *v36; // rax
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  UFG::qVector3 *v40; // rax
  float v41; // xmm1_4
  float v42; // xmm2_4
  UFG::qVector2 *v43; // rax
  float v44; // xmm1_4
  UFG::qVector4 soln; // [rsp+20h] [rbp-79h] BYREF
  UFG::qMatrix44 affine; // [rsp+30h] [rbp-69h] BYREF
  UFG::qMatrix44 rot; // [rsp+70h] [rbp-29h] BYREF
  UFG::qVector2 v; // [rsp+118h] [rbp+7Fh] BYREF

  v6 = UFG::qPropertySet::GetPropertyTypeFromName(propertySet, name, DEPTH_RECURSE) - 17;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 != 1 )
          return 0;
        v10 = UFG::qPropertySet::Get<UFG::qMatrix44>(propertySet, name, DEPTH_RECURSE);
        v11 = !value->mbValid[0];
        z = v10->v0.z;
        w = v10->v0.w;
        x = v10->v0.x;
        affine.v0.y = v10->v0.y;
        affine.v0.z = z;
        affine.v0.x = x;
        affine.v0.w = w;
        y = v10->v1.y;
        v16 = v10->v1.z;
        v17 = v10->v1.w;
        affine.v1.x = v10->v1.x;
        affine.v1.y = y;
        affine.v1.z = v16;
        affine.v1.w = v17;
        v18 = v10->v2.z;
        v19 = v10->v2.x;
        v20 = v10->v2.w;
        affine.v2.y = v10->v2.y;
        affine.v2.x = v19;
        affine.v2.z = v18;
        affine.v2.w = v20;
        v21 = v10->v3.y;
        v22 = v10->v3.z;
        affine.v3.x = v10->v3.x;
        affine.v3.y = v21;
        affine.v3.z = v22;
        if ( !v11 )
          affine.v3.x = value->mValue[0];
        if ( value->mbValid[1] )
          affine.v3.y = value->mValue[1];
        if ( value->mbValid[2] )
          affine.v3.z = value->mValue[2];
        v11 = !value->mbValid[3];
        LODWORD(affine.v3.w) = (_DWORD)FLOAT_1_0;
        soln.x = UFG::qVector3::msZero.x;
        soln.y = UFG::qVector3::msZero.y;
        soln.z = UFG::qVector3::msZero.z;
        if ( !v11 && value->mbValid[4] && value->mbValid[5] )
        {
          v23 = value->mValue[4];
          soln.x = value->mValue[3];
          v24 = value->mValue[5];
          soln.y = v23;
          soln.z = v24;
        }
        UFG::Editor::Utility::DecomposeAffineEulerSmart_RoundedDegrees((UFG::qVector3 *)&soln, &affine, 1);
        if ( value->mbValid[3] )
          v25 = value->mValue[3];
        else
          v25 = soln.x;
        if ( value->mbValid[4] )
          v26 = value->mValue[4];
        else
          v26 = soln.y;
        if ( value->mbValid[5] )
          v27 = value->mValue[5];
        else
          v27 = soln.z;
        y_low = (__m128)LODWORD(affine.v0.y);
        v29 = (__m128)LODWORD(affine.v1.y);
        y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                          + (float)(affine.v0.x * affine.v0.x))
                                  + (float)(affine.v0.z * affine.v0.z))
                          + (float)(affine.v0.w * affine.v0.w);
        v30 = _mm_sqrt_ps(y_low);
        v31 = (__m128)LODWORD(affine.v2.y);
        v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(affine.v1.x * affine.v1.x))
                                + (float)(affine.v1.z * affine.v1.z))
                        + (float)(affine.v1.w * affine.v1.w);
        v32 = _mm_sqrt_ps(v29);
        v31.m128_f32[0] = (float)((float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(affine.v2.x * affine.v2.x))
                                + (float)(affine.v2.z * affine.v2.z))
                        + (float)(affine.v2.w * affine.v2.w);
        v33 = _mm_sqrt_ps(v31);
        if ( value->mbValid[6] )
          v30 = (__m128)LODWORD(value->mValue[6]);
        v34 = _mm_shuffle_ps(v30, v30, 0);
        if ( value->mbValid[7] )
          v32 = (__m128)LODWORD(value->mValue[7]);
        v35 = _mm_shuffle_ps(v32, v32, 0);
        if ( value->mbValid[8] )
          v33 = (__m128)LODWORD(value->mValue[8]);
        soln.x = (float)(v25 * 3.1415927) * 0.0055555557;
        soln.y = (float)(v26 * 3.1415927) * 0.0055555557;
        soln.z = (float)(v27 * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixEuler(&rot, (UFG::qVector3 *)&soln);
        affine.v0 = (UFG::qVector4)_mm_mul_ps((__m128)rot.v0, v34);
        affine.v1 = (UFG::qVector4)_mm_mul_ps((__m128)rot.v1, v35);
        affine.v2 = (UFG::qVector4)_mm_mul_ps((__m128)rot.v2, _mm_shuffle_ps(v33, v33, 0));
        UFG::qPropertySet::Set<UFG::qMatrix44>(propertySet, name, &affine);
      }
      else
      {
        v36 = UFG::qPropertySet::Get<UFG::qVector4>(propertySet, name, DEPTH_RECURSE);
        v11 = !value->mbValid[0];
        v37 = v36->z;
        v38 = v36->w;
        v39 = v36->x;
        soln.y = v36->y;
        soln.z = v37;
        soln.x = v39;
        soln.w = v38;
        if ( !v11 )
          soln.x = value->mValue[0];
        if ( value->mbValid[1] )
          soln.y = value->mValue[1];
        if ( value->mbValid[2] )
          soln.z = value->mValue[2];
        if ( value->mbValid[3] )
          soln.w = value->mValue[3];
        UFG::qPropertySet::Set<UFG::qVector4>(propertySet, name, &soln);
      }
    }
    else
    {
      v40 = UFG::qPropertySet::Get<UFG::qVector3>(propertySet, name, DEPTH_RECURSE);
      v11 = !value->mbValid[0];
      v41 = v40->y;
      v42 = v40->z;
      soln.x = v40->x;
      soln.y = v41;
      soln.z = v42;
      if ( !v11 )
        soln.x = value->mValue[0];
      if ( value->mbValid[1] )
        soln.y = value->mValue[1];
      if ( value->mbValid[2] )
        soln.z = value->mValue[2];
      UFG::qPropertySet::Set<UFG::qVector3>(propertySet, name, (UFG::qVector3 *)&soln);
    }
  }
  else
  {
    v43 = UFG::qPropertySet::Get<UFG::qVector2>(propertySet, name, DEPTH_RECURSE);
    v11 = !value->mbValid[0];
    v44 = v43->y;
    v.x = v43->x;
    v.y = v44;
    if ( !v11 )
      v.x = value->mValue[0];
    if ( value->mbValid[1] )
      v.y = value->mValue[1];
    UFG::qPropertySet::Set<UFG::qVector2>(propertySet, name, &v);
  }
  return 1;
}

// File Line: 612
// RVA: 0x213650
void __fastcall UFG::Editor::PropertyProxyVectored::Setup(
        UFG::Editor::PropertyProxyVectored *this,
        UFG::qArray<UFG::qPropertySet *,0> *selection)
{
  UFG::Editor::VectoredValue *p_mValues; // rbx
  unsigned int v4; // edi
  UFG::qSymbol *p_mPropertyName; // rbp
  UFG::qPropertySet **p; // rax
  UFG::qPropertySet *v7; // rcx
  __int64 i; // rax
  int v9; // r8d
  int mElementCount; // ecx
  __int64 v11; // rdx
  float v12; // eax
  bool *mbValid; // rax
  float *mValue; // rcx
  UFG::Editor::VectoredValue value; // [rsp+20h] [rbp-68h] BYREF

  p_mValues = &this->mValues;
  v4 = 0;
  if ( selection->size )
  {
    p_mPropertyName = &this->mPropertyName;
    do
    {
      p = selection->p;
      value.mElementCount = 0;
      v7 = p[v4];
      for ( i = 0i64; i < 16; ++i )
      {
        value.mbValid[i] = 0;
        value.mValue[i] = 0.0;
      }
      value.mbGimbalLock = 0;
      UFG::Editor::GetVectorValue(v7, (UFG::qArray<unsigned long,0> *)p_mPropertyName, &value);
      v9 = 0;
      p_mValues->mbGimbalLock = value.mbGimbalLock;
      if ( v4 )
      {
        if ( p_mValues->mElementCount > 0 )
        {
          mbValid = p_mValues->mbValid;
          mValue = value.mValue;
          do
          {
            if ( *mbValid && mbValid[(char *)&value - (char *)p_mValues] )
              *mbValid = *mValue == *(float *)((char *)mValue + (char *)p_mValues - (char *)value.mValue + 4);
            ++v9;
            ++mValue;
            ++mbValid;
          }
          while ( v9 < p_mValues->mElementCount );
        }
      }
      else
      {
        mElementCount = value.mElementCount;
        v11 = 0i64;
        p_mValues->mElementCount = value.mElementCount;
        if ( mElementCount > 0 )
        {
          do
          {
            if ( value.mbValid[v11] )
            {
              v12 = value.mValue[v11];
              p_mValues->mbValid[v11] = 1;
              *(float *)&value.mbValid[4 * v11 - 60 + (char *)p_mValues - (char *)value.mValue] = v12;
            }
            ++v9;
            ++v11;
          }
          while ( v9 < p_mValues->mElementCount );
        }
      }
      ++v4;
    }
    while ( v4 < selection->size );
  }
}

// File Line: 637
// RVA: 0x214FE0
void __fastcall UFG::Editor::PropertyProxyVectored::UpdateCommon(
        UFG::Editor::PropertyProxyVectored *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qPropertyPath *currentPath,
        const char *displayName)
{
  int v7; // r12d
  ePropertyType mDataType; // r8d
  int v9; // ecx
  __int32 v11; // r8d
  __int32 v12; // r8d
  __int32 v13; // r8d
  int v14; // r15d
  int v15; // edi
  UFG::qSymbol *p_mPropertyName; // rsi
  char *v17; // rax
  char *v18; // rax
  const char **v19; // rax
  int v20; // esi
  float v21; // xmm1_4
  float v22; // xmm0_4
  __int64 i; // rax
  signed int v24; // eax
  __int64 v25; // r12
  char *v26; // rdx
  float *v27; // rsi
  char mKeycodeDown; // al
  bool v29; // di
  __int64 k; // rax
  int v31; // eax
  __int64 v32; // rcx
  __int128 v33; // xmm0
  __int128 v34; // xmm1
  __int128 v35; // xmm1
  int v36; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol result; // [rsp+34h] [rbp-CCh] BYREF
  UFG::qColour current_colour_rgb; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v39; // [rsp+48h] [rbp-B8h]
  UFG::Editor::VectoredValue value; // [rsp+50h] [rbp-B0h] BYREF
  __int64 j; // [rsp+B0h] [rbp-50h]
  const char **v42; // [rsp+B8h] [rbp-48h]
  UFG::DUIRect v43; // [rsp+C0h] [rbp-40h] BYREF
  UFG::DUIRect rect; // [rsp+D0h] [rbp-30h] BYREF
  char dest[256]; // [rsp+E0h] [rbp-20h] BYREF
  unsigned int num_cols; // [rsp+230h] [rbp+130h]

  v7 = 0;
  mDataType = this->mDataType;
  v9 = 0;
  v36 = 0;
  num_cols = 0;
  v11 = mDataType - 17;
  if ( !v11 )
  {
    v9 = 2;
    goto LABEL_9;
  }
  v12 = v11 - 1;
  if ( !v12 )
  {
    v9 = 3;
    goto LABEL_9;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    v9 = 4;
LABEL_9:
    v7 = 1;
    v36 = 1;
    goto LABEL_10;
  }
  if ( v13 == 1 )
  {
    v9 = 3;
    v7 = 3;
    v36 = 3;
LABEL_10:
    num_cols = v9;
  }
  v14 = 0;
  v15 = v7 * v9;
  if ( v7 * v9 == 9 && this->mValues.mbGimbalLock )
  {
    p_mPropertyName = &this->mPropertyName;
    v17 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
    UFG::qSPrintf(dest, 256, "%s (G.L.)", v17);
  }
  else
  {
    p_mPropertyName = &this->mPropertyName;
    v18 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
    UFG::qSPrintf(dest, 256, "%s", v18);
  }
  v19 = vecLabels;
  if ( v15 == 9 )
    v19 = matLabels;
  v42 = v19;
  UFG::Editor::GetControlOverride(&result, p_mPropertyName, 0i64);
  v20 = num_cols;
  if ( result.mUID == Symbol_ColourPicker.mUID && v7 == 1 && num_cols - 3 <= 1 )
  {
    if ( !this->mIsLocal )
      UFG::DUIContext::PushColour(dui, TextColour, &UFG::qColour::Grey);
    UFG::DUIContext::Label(dui, dest);
    if ( !this->mIsLocal )
      UFG::DUIContext::PopColour(dui, 0);
    v21 = this->mValues.mValue[1];
    current_colour_rgb.r = this->mValues.mValue[0];
    v22 = this->mValues.mValue[2];
    current_colour_rgb.g = v21;
    current_colour_rgb.b = v22;
    LODWORD(current_colour_rgb.a) = (_DWORD)FLOAT_1_0;
    if ( num_cols == 4 )
      current_colour_rgb.a = this->mValues.mValue[3];
    if ( UFG::DUIContext::ColourPicker(dui, &customCaption, &current_colour_rgb, num_cols == 4) )
    {
      value.mElementCount = 0;
      for ( i = 0i64; i < 16; ++i )
      {
        value.mbValid[i] = 0;
        value.mValue[i] = 0.0;
      }
      value.mbGimbalLock = 0;
      *(_WORD *)value.mbValid = 257;
      value.mbValid[2] = 1;
      value.mValue[0] = current_colour_rgb.r;
      value.mValue[1] = current_colour_rgb.g;
      value.mValue[2] = current_colour_rgb.b;
      if ( num_cols == 4 )
      {
        value.mbValid[3] = 1;
        value.mValue[3] = current_colour_rgb.a;
      }
      UFG::Editor::PropertyBrowser::AddPendingValueChange(browser, currentPath, &value);
    }
  }
  else
  {
    UFG::DUIContext::GetLayoutRect(dui, &rect, 0, 0);
    UFG::DUIContext::SetLayoutRect(dui, &rect);
    v24 = 0;
    v25 = 0i64;
    result.mUID = 0;
    for ( j = v15; v24 < v36; result.mUID = v24 )
    {
      if ( v24 )
      {
        UFG::DUIContext::GetLayoutRect(dui, &v43, 0, 0);
        v43.mW = rect.mW;
        UFG::DUIContext::SetLayoutRect(dui, &v43);
      }
      UFG::DUIContext::BeginGridLayout(
        dui,
        2,
        1,
        browser->mColWidths,
        0i64,
        LayoutFlag_GridSplitting|LayoutFlag_FillLastCell);
      if ( !this->mIsLocal )
        UFG::DUIContext::PushColour(dui, TextColour, &UFG::qColour::Grey);
      v26 = dest;
      if ( result.mUID )
        v26 = &customCaption;
      UFG::DUIContext::Label(dui, v26);
      if ( !this->mIsLocal )
        UFG::DUIContext::PopColour(dui, 0);
      UFG::DUIContext::BeginGridLayout(dui, v20, 1, LayoutFlag_DistributeCells);
      if ( v20 > 0 )
      {
        v27 = &this->mValues.mValue[v25];
        v39 = num_cols;
        *(_QWORD *)&current_colour_rgb.r = (char *)value.mValue - (char *)this;
        do
        {
          mKeycodeDown = dui->mInputState.mKeycodeDown;
          v29 = mKeycodeDown == 13 || mKeycodeDown == 94;
          UFG::DUIContext::NumericTextBox(dui, v42[v25], &this->mValues.mValue[v14], 0, 0.20999999);
          if ( j == 9 && this->mValues.mbGimbalLock && v14 == 5 )
            *v27 = 0.0;
          if ( dui->mControlLostFocus || dui->mFocusedID == dui->mCurrentID && v29 )
          {
            value.mElementCount = 0;
            for ( k = 0i64; k < 16; ++k )
            {
              value.mbValid[k] = 0;
              value.mValue[k] = 0.0;
            }
            v31 = *(_DWORD *)v27;
            v32 = *(_QWORD *)&current_colour_rgb.r;
            value.mbGimbalLock = 0;
            value.mbValid[v25] = 1;
            *(_DWORD *)((char *)v27 + v32 - 60) = v31;
            v33 = *(_OWORD *)&value.mElementCount;
            v34 = *(_OWORD *)&value.mValue[3];
            browser->mPendingValueChange.mType = AMD;
            *(_OWORD *)&browser->mPendingValueChange.mVectoredValue.mElementCount = v33;
            *(_OWORD *)&browser->mPendingValueChange.mVectoredValue.mValue[3] = v34;
            v35 = *(_OWORD *)&value.mValue[11];
            *(_OWORD *)&browser->mPendingValueChange.mVectoredValue.mValue[7] = *(_OWORD *)&value.mValue[7];
            *(_OWORD *)&browser->mPendingValueChange.mVectoredValue.mValue[11] = v35;
            *(_QWORD *)&v35 = *(_QWORD *)&value.mbValid[12];
            *(_OWORD *)&browser->mPendingValueChange.mVectoredValue.mValue[15] = *(_OWORD *)&value.mValue[15];
            *(_QWORD *)&browser->mPendingValueChange.mVectoredValue.mbValid[12] = v35;
            UFG::qPropertyPath::operator=(&browser->mPendingValueChange.mPath, currentPath);
          }
          ++v14;
          ++v25;
          ++v27;
          --v39;
        }
        while ( v39 );
        v20 = num_cols;
      }
      UFG::DUIContext::EndLayoutHorizontal(dui);
      UFG::DUIContext::EndLayoutHorizontal(dui);
      v24 = result.mUID + 1;
    }
  }
}

// File Line: 731
// RVA: 0x21C2D0
void __fastcall UFG::Editor::PropertyProxyVectored::UpdateUI(
        UFG::Editor::PropertyProxyVectored *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::qPropertyList *,0> *selection,
        UFG::qPropertyPath *currentPath)
{
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  UFG::qString::FormatEx(&result, "[%d]", (unsigned int)this->mArrayIndex);
  UFG::Editor::PropertyProxyVectored::UpdateCommon(this, browser, dui, currentPath, result.mData);
  UFG::qString::~qString(&result);
}

// File Line: 737
// RVA: 0x21C350
void __fastcall UFG::Editor::PropertyProxyVectored::UpdateUI(
        UFG::Editor::PropertyProxyVectored *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::qPropertySet *,0> *selection,
        UFG::qPropertyPath *currentPath)
{
  char *v8; // rax

  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  UFG::Editor::PropertyProxyVectored::UpdateCommon(this, browser, dui, currentPath, v8);
}

// File Line: 771
// RVA: 0x20AE20
void __fastcall UFG::Editor::PropertyProxy_PropertySet::GenerateChildren(
        UFG::Editor::PropertyProxy_PropertySet *this,
        UFG::qArray<UFG::qPropertySet *,0> *propertySets,
        char localProperty)
{
  char p; // bl
  UFG::Editor::PropertyProxyCollection *p_mChildren; // rsi
  bool *p_mNext; // rax
  bool *i; // r15
  _QWORD *v8; // rdx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  unsigned int v11; // r12d
  bool *p_mIsDefault; // r14
  UFG::Editor::PropertyProxy_PropertySet *v13; // r15
  signed int PropertyTypeFromName; // edi
  UFG::qPropertySet *v15; // rax
  bool v16; // bp
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rbx
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rax
  __int64 v24; // rax
  _DWORD *v25; // rcx
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *mPrev; // rax
  __int64 v29; // rsi
  __int64 v30; // rbp
  __int64 *v31; // r14
  __int64 v32; // rdi
  int v33; // eax
  char *v34; // rbx
  char *v35; // rax
  __int64 v36; // rdx
  __int64 *v37; // r8
  _QWORD *v38; // rax
  __int64 v39; // rcx
  _QWORD *v40; // rax
  _QWORD *v41; // rax
  __int64 v42; // rax
  __int64 *v43; // r14
  __int64 v44; // rdi
  int v45; // eax
  char *v46; // rbx
  char *v47; // rax
  __int64 v48; // rdx
  __int64 *v49; // r8
  _QWORD *v50; // rax
  __int64 v51; // rcx
  _QWORD *v52; // rax
  __int64 **v53; // rax
  __int64 v54; // rax
  UFG::qArray<UFG::Editor::PropertyInstance,0> shared_property_uids; // [rsp+38h] [rbp-60h] BYREF
  bool v57; // [rsp+A0h] [rbp+8h]
  UFG::qArray<unsigned long,0> result; // [rsp+A8h] [rbp+10h] BYREF
  UFG::allocator::free_link *v59; // [rsp+B8h] [rbp+20h]

  LOBYTE(result.p) = localProperty;
  p = localProperty;
  p_mChildren = &this->mChildren;
  p_mNext = (bool *)&this->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
  for ( i = &this->mIsLocal; p_mNext != i; p_mNext = (bool *)&p_mChildren->mChildrenOrdered.mNode.mNext[-1].mNext )
  {
    v8 = p_mNext + 8;
    v9 = *((_QWORD *)p_mNext + 1);
    v10 = (_QWORD *)*((_QWORD *)p_mNext + 2);
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    *v8 = v8;
    v8[1] = v8;
    if ( v8 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v8 - 1))(v8 - 1, 1i64);
  }
  if ( !propertySets->size )
    return;
  shared_property_uids.p = 0i64;
  *(_QWORD *)&shared_property_uids.size = 0i64;
  UFG::Editor::GetSharedProperties(&shared_property_uids, propertySets);
  v11 = 0;
  if ( !shared_property_uids.size )
    goto LABEL_35;
  p_mIsDefault = &shared_property_uids.p->mIsDefault;
  v13 = this;
  do
  {
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, *((_DWORD *)p_mIsDefault - 5));
    PropertyTypeFromName = UFG::qPropertySet::GetPropertyTypeFromName(*propertySets->p, &result, DEPTH_RECURSE);
    v15 = *propertySets->p;
    v57 = v15->mSchemaName.mUID != UFG::gNullQSymbol.mUID;
    if ( p && v15 == *(UFG::qPropertySet **)(p_mIsDefault - 12) )
    {
      v16 = 1;
      if ( v15->mSchemaName.mUID != UFG::gNullQSymbol.mUID )
        v16 = !*p_mIsDefault;
    }
    else
    {
      v16 = 0;
    }
    if ( PropertyTypeFromName < 17 )
      goto LABEL_29;
    if ( PropertyTypeFromName > 20 )
    {
      if ( PropertyTypeFromName == 25 )
      {
        v20 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
        v19 = v20;
        v59 = v20;
        if ( v20 )
        {
          v21 = v20 + 1;
          v21->mNext = v21;
          v21[1].mNext = v21;
          v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
          LODWORD(v19[3].mNext) = 25;
          HIDWORD(v19[3].mNext) = result.size;
          LODWORD(v19[4].mNext) = -1;
          v19[5].mNext = 0i64;
          LOWORD(v19[6].mNext) = 0;
          BYTE2(v19[6].mNext) = 0;
          v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy_Container::`vftable;
          v19[7].mNext = v19 + 7;
          v19[8].mNext = v19 + 7;
          LOBYTE(v19[9].mNext) = 0;
          HIDWORD(v19[9].mNext) = 0;
          v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy_PropertyList::`vftable;
        }
        else
        {
          v19 = 0i64;
        }
        goto LABEL_33;
      }
      if ( PropertyTypeFromName == 26 )
      {
        v17 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
        v59 = v17;
        if ( v17 )
        {
          UFG::Editor::PropertyProxy_PropertySet::PropertyProxy_PropertySet(
            (UFG::Editor::PropertyProxy_PropertySet *)v17,
            (UFG::qSymbol *)&result,
            -1);
          v19 = v18;
        }
        else
        {
          v19 = 0i64;
        }
        goto LABEL_33;
      }
LABEL_29:
      v26 = UFG::qMalloc(0x88ui64, UFG::gGlobalNewName, 0i64);
      v19 = v26;
      v59 = v26;
      if ( v26 )
      {
        v27 = v26 + 1;
        v27->mNext = v27;
        v27[1].mNext = v27;
        v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
        LODWORD(v19[3].mNext) = PropertyTypeFromName;
        HIDWORD(v19[3].mNext) = result.size;
        LODWORD(v19[4].mNext) = v11;
        v19[5].mNext = 0i64;
        LOWORD(v19[6].mNext) = 0;
        BYTE2(v19[6].mNext) = 0;
        v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxySimple::`vftable;
        UFG::qString::qString((UFG::qString *)&v19[7]);
        LOBYTE(v19[12].mNext) = 0;
        v19[13].mNext = v19 + 13;
        v19[14].mNext = v19 + 13;
        v19[16].mNext = 0i64;
        v19[15].mNext = 0i64;
      }
      else
      {
        v19 = 0i64;
      }
      UFG::Editor::PropertyProxySimple::Setup((UFG::Editor::PropertyProxySimple *)v19, propertySets);
      goto LABEL_33;
    }
    v22 = UFG::qMalloc(0x90ui64, UFG::gGlobalNewName, 0i64);
    v19 = v22;
    v59 = v22;
    if ( v22 )
    {
      v23 = v22 + 1;
      v23->mNext = v23;
      v23[1].mNext = v23;
      v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
      LODWORD(v19[3].mNext) = PropertyTypeFromName;
      HIDWORD(v19[3].mNext) = result.size;
      LODWORD(v19[4].mNext) = v11;
      v19[5].mNext = 0i64;
      LOWORD(v19[6].mNext) = 0;
      BYTE2(v19[6].mNext) = 0;
      v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxyVectored::`vftable;
      LODWORD(v19[7].mNext) = 0;
      v24 = 0i64;
      v25 = (_DWORD *)&v19[7].mNext + 1;
      do
      {
        *((_BYTE *)&v19[15].mNext + v24 + 4) = 0;
        *v25 = 0;
        ++v24;
        ++v25;
      }
      while ( v24 < 16 );
      BYTE4(v19[17].mNext) = 0;
    }
    else
    {
      v19 = 0i64;
    }
    UFG::Editor::PropertyProxyVectored::Setup((UFG::Editor::PropertyProxyVectored *)v19, propertySets);
LABEL_33:
    LOBYTE(v19[6].mNext) = v16;
    BYTE1(v19[6].mNext) = v57;
    mPrev = p_mChildren->mChildrenOrdered.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v19[1];
    v19[1].mNext = (UFG::allocator::free_link *)mPrev;
    v19[2].mNext = (UFG::allocator::free_link *)p_mChildren;
    p_mChildren->mChildrenOrdered.mNode.mPrev = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v19[1];
    v19[5].mNext = (UFG::allocator::free_link *)v13;
    ++v11;
    p_mIsDefault += 24;
    p = (char)result.p;
  }
  while ( v11 < shared_property_uids.size );
  i = (bool *)&p_mChildren[-1].mChildrenOrdered.mNode.mNext;
LABEL_35:
  v29 = (__int64)&p_mChildren->mChildrenOrdered.mNode.mNext[-1].mNext;
  while ( 2 )
  {
    v30 = 0i64;
    if ( (bool *)v29 != i )
    {
      while ( 2 )
      {
        v31 = (__int64 *)(v29 + 8);
        v32 = *(_QWORD *)(v29 + 16) - 8i64;
        if ( (bool *)v32 == i )
          break;
        v33 = *(_DWORD *)(v32 + 24);
        if ( *(_DWORD *)(v29 + 24) == 26 )
        {
          if ( v33 != 26 )
            goto LABEL_43;
LABEL_42:
          v34 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v29 + 28));
          v35 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v32 + 28));
          if ( (int)UFG::qStringCompareInsensitive(v34, v35, -1) <= 0 )
          {
LABEL_43:
            v29 = v32;
            goto LABEL_45;
          }
        }
        else if ( v33 != 26 )
        {
          goto LABEL_42;
        }
        v36 = *v31;
        v37 = *(__int64 **)(v32 + 16);
        v38 = *(_QWORD **)(v29 + 16);
        *(_QWORD *)(v36 + 8) = v38;
        *v38 = v36;
        *v31 = (__int64)v31;
        *(_QWORD *)(v29 + 16) = v29 + 8;
        v39 = *(_QWORD *)(v32 + 8);
        v40 = *(_QWORD **)(v32 + 16);
        *(_QWORD *)(v39 + 8) = v40;
        *v40 = v39;
        *(_QWORD *)(v32 + 8) = v32 + 8;
        *(_QWORD *)(v32 + 16) = v32 + 8;
        v41 = *(_QWORD **)(v36 + 8);
        *(_QWORD *)(v36 + 8) = v32 + 8;
        *(_QWORD *)(v32 + 8) = v36;
        *(_QWORD *)(v32 + 16) = v41;
        *v41 = v32 + 8;
        v42 = *v37;
        *(_QWORD *)(v42 + 8) = v31;
        *v31 = v42;
        *(_QWORD *)(v29 + 16) = v37;
        *v37 = (__int64)v31;
        v30 = v32;
LABEL_45:
        if ( (bool *)v29 == i )
          break;
        continue;
      }
    }
    v29 = 0i64;
    if ( v30 && (bool *)v30 != i )
    {
LABEL_48:
      v43 = (__int64 *)(v30 + 8);
      v44 = *(_QWORD *)(v30 + 8) - 8i64;
      if ( (bool *)v44 == i )
      {
LABEL_57:
        if ( !v29 )
          break;
        continue;
      }
      v45 = *(_DWORD *)(v30 + 24);
      if ( *(_DWORD *)(v44 + 24) == 26 )
      {
        if ( v45 != 26 )
          goto LABEL_54;
LABEL_53:
        v46 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v44 + 28));
        v47 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v30 + 28));
        if ( (int)UFG::qStringCompareInsensitive(v46, v47, -1) <= 0 )
        {
LABEL_54:
          v30 = v44;
          goto LABEL_56;
        }
      }
      else if ( v45 != 26 )
      {
        goto LABEL_53;
      }
      v48 = *(_QWORD *)(v44 + 8);
      v49 = *(__int64 **)(v30 + 16);
      v50 = *(_QWORD **)(v44 + 16);
      *(_QWORD *)(v48 + 8) = v50;
      *v50 = v48;
      *(_QWORD *)(v44 + 8) = v44 + 8;
      *(_QWORD *)(v44 + 16) = v44 + 8;
      v51 = *v43;
      v52 = *(_QWORD **)(v30 + 16);
      *(_QWORD *)(v51 + 8) = v52;
      *v52 = v51;
      *v43 = (__int64)v43;
      *(_QWORD *)(v30 + 16) = v30 + 8;
      v53 = *(__int64 ***)(v48 + 8);
      *(_QWORD *)(v48 + 8) = v43;
      *v43 = v48;
      *(_QWORD *)(v30 + 16) = v53;
      *v53 = v43;
      v54 = *v49;
      *(_QWORD *)(v54 + 8) = v44 + 8;
      *(_QWORD *)(v44 + 8) = v54;
      *(_QWORD *)(v44 + 16) = v49;
      *v49 = v44 + 8;
      v29 = v44;
LABEL_56:
      if ( (bool *)v30 == i )
        goto LABEL_57;
      goto LABEL_48;
    }
    break;
  }
  if ( shared_property_uids.p )
    operator delete[](shared_property_uids.p);
}

// File Line: 835
// RVA: 0x2145A0
UFG::qPropertySet *__fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateAddPropertyUI(
        UFG::Editor::PropertyProxy_PropertySet *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qPropertySet *pset,
        UFG::qPropertyPath *currentPath)
{
  UFG::DUIContext *v9; // rax
  UFG::qArray<unsigned long,0> *v10; // rax
  UFG::SchemaDef *SchemaForProperty; // r14
  UFG::qSymbol *v12; // rax
  ePropertyType PropertySetDataTypeFromString; // eax
  UFG::qSymbol v15; // [rsp+30h] [rbp-68h] BYREF
  int column_widths[2]; // [rsp+38h] [rbp-60h] BYREF
  __int64 v17; // [rsp+40h] [rbp-58h]
  UFG::DUIRect result; // [rsp+48h] [rbp-50h] BYREF
  UFG::qString current_value; // [rsp+58h] [rbp-40h] BYREF

  v17 = -2i64;
  if ( !UFG::PropertySetManager::IsComponentPropertySet(pset) )
  {
    UFG::DUIContext::Label(dui, "Add Property:");
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    column_widths[0] = result.mW - result.mH;
    column_widths[1] = result.mH;
    v9 = UFG::DUIContext::SetLayoutRect(dui, &result);
    UFG::DUIContext::BeginGridLayout(v9, 2, 1, column_widths, 0i64, LayoutFlag_None);
    v10 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v15, this->mNewPropertyName.mData);
    SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(0i64, v10);
    if ( SchemaForProperty == 0i64 )
    {
      UFG::DUIContext::BeginGridLayout(dui, 2, 1, LayoutFlag_DistributeCells);
      UFG::DUIContext::TextBox(dui, &this->mNewPropertyName, 0i64, 1, 0i64, -1);
      UFG::DUIContext::ComboBox(
        dui,
        &this->mSelectedTypeOption,
        UFG::Editor::PropertyProxy_Container::mPropTypes,
        0xBu,
        0i64);
      UFG::DUIContext::EndLayoutHorizontal(dui);
      if ( UFG::DUIContext::Button(dui, "+", 0x10u) && this->mNewPropertyName.mLength )
      {
        v12 = UFG::qSymbol::create_from_string(&v15, this->mNewPropertyName.mData);
        UFG::qPropertyPath::Push(currentPath, v12);
        PropertySetDataTypeFromString = (unsigned int)GetPropertySetDataTypeFromString(UFG::Editor::PropertyProxy_Container::mPropTypes[this->mSelectedTypeOption]);
        browser->mPendingValueChange.mType = 4;
        browser->mPendingValueChange.mNewItemType = PropertySetDataTypeFromString;
        UFG::qPropertyPath::operator=(&browser->mPendingValueChange.mPath, currentPath);
        UFG::qString::Set(&this->mNewPropertyName, &customCaption);
        UFG::qPropertyPath::Pop(currentPath);
      }
    }
    else
    {
      UFG::DUIContext::BeginGridLayout(dui, 2, 1, LayoutFlag_DistributeCells);
      UFG::DUIContext::PushColour(dui, TextColour, &UFG::qColour::Red);
      UFG::DUIContext::TextBox(dui, &this->mNewPropertyName, 0i64, 1, 0i64, -1);
      UFG::DUIContext::PopColour(dui, 0);
      UFG::qString::FormatEx(
        &current_value,
        "%s (%s)",
        SchemaForProperty->mNameString.mData,
        SchemaForProperty->mPropertyNameString.mData);
      UFG::DUIContext::TextBox(dui, &current_value, 0i64, 1, 0i64, -1);
      UFG::qString::~qString(&current_value);
      UFG::DUIContext::EndLayoutHorizontal(dui);
      UFG::DUIContext::Label(dui, &customCaption);
    }
    UFG::DUIContext::EndLayoutHorizontal(dui);
    UFG::DUIContext::Separator(dui);
  }
  return pset;
}

// File Line: 892
// RVA: 0x21C7B0
void __fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateUI(
        UFG::Editor::PropertyProxy_PropertySet *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::qPropertyList *,0> *selection,
        UFG::qPropertyPath *currentPath)
{
  UFG::qArray<UFG::qPropertyList *,0> *v5; // rdi
  UFG::DUIContext *v6; // r13
  UFG::Editor::PropertyBrowser *v7; // r15
  char *v9; // rax
  char *mData; // rbx
  unsigned int Hash; // eax
  bool *v12; // rax
  char v13; // bl
  unsigned int v14; // r15d
  char *ValuePtr; // rax
  UFG::qPropertySet *v16; // r12
  __int64 size; // r13
  unsigned int v18; // edi
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::qPropertySet **p; // rsi
  UFG::qPropertySet **v23; // r9
  __int64 i; // r8
  UFG::qPropertySet **v25; // rbx
  UFG::qPropertySet **v26; // rbx
  UFG::Editor::PropertyProxy_PropertySet *j; // rdi
  int mH; // ebx
  UFG::DUIContext *v29; // rax
  UFG::qArray<UFG::qPropertySet *,0> propertySets; // [rsp+38h] [rbp-69h] BYREF
  UFG::DUIRect v31; // [rsp+50h] [rbp-51h] BYREF
  UFG::DUIRect v32; // [rsp+60h] [rbp-41h] BYREF
  UFG::DUIRect rect; // [rsp+70h] [rbp-31h] BYREF
  UFG::qString result; // [rsp+80h] [rbp-21h] BYREF

  v5 = selection;
  v6 = dui;
  v7 = browser;
  v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  UFG::qString::FormatEx(&result, "[%d] %s", (unsigned int)this->mArrayIndex, v9);
  if ( !this->mParent )
    goto LABEL_7;
  if ( !this->mIsLocal )
    UFG::DUIContext::PushColour(v6, TextColour, &UFG::qColour::Grey);
  mData = result.mData;
  Hash = UFG::qPropertyPath::GetHash(currentPath);
  v12 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(v7, Hash);
  v13 = UFG::DUIContext::Collapsible(v6, mData, v12);
  if ( !this->mIsLocal )
    UFG::DUIContext::PopColour(v6, 0);
  if ( v13 )
  {
LABEL_7:
    propertySets.p = 0i64;
    *(_QWORD *)&propertySets.size = 0i64;
    if ( v5->size )
    {
      v14 = 0;
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v5->p[v14], 0x1Au, this->mArrayIndex);
        if ( ValuePtr && *(_QWORD *)ValuePtr )
          v16 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
        else
          v16 = 0i64;
        size = propertySets.size;
        v18 = propertySets.size + 1;
        if ( propertySets.size + 1 <= propertySets.capacity )
          goto LABEL_31;
        if ( propertySets.capacity )
          v19 = 2 * propertySets.capacity;
        else
          v19 = 1;
        for ( ; v19 < v18; v19 *= 2 )
          ;
        if ( v19 <= 2 )
          v19 = 2;
        if ( v19 - v18 > 0x10000 )
          v19 = propertySets.size + 65537;
        if ( v19 == propertySets.size )
        {
LABEL_31:
          p = propertySets.p;
        }
        else
        {
          v20 = 8i64 * v19;
          if ( !is_mul_ok(v19, 8ui64) )
            v20 = -1i64;
          v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
          p = (UFG::qPropertySet **)v21;
          v23 = propertySets.p;
          if ( propertySets.p )
          {
            for ( i = 0i64; (unsigned int)i < propertySets.size; v23 = propertySets.p )
            {
              v21[i].mNext = (UFG::allocator::free_link *)v23[i];
              i = (unsigned int)(i + 1);
            }
            operator delete[](v23);
          }
          propertySets.p = p;
          propertySets.capacity = v19;
        }
        propertySets.size = v18;
        p[size] = v16;
        ++v14;
        v5 = selection;
      }
      while ( v14 < selection->size );
      v7 = browser;
      v6 = dui;
    }
    if ( !this->mHasGenerantedChildren )
    {
      UFG::Editor::PropertyProxy_PropertySet::GenerateChildren(this, &propertySets, this->mIsLocal);
      this->mHasGenerantedChildren = 1;
    }
    if ( propertySets.size == 1 )
    {
      v25 = propertySets.p;
      *v25 = UFG::Editor::PropertyProxy_PropertySet::UpdateParentListUI(this, v7, v6, *propertySets.p);
    }
    if ( this->mParent )
      UFG::DUIContext::BeginIndent(v6);
    v26 = propertySets.p;
    *v26 = UFG::Editor::PropertyProxy_PropertySet::UpdateAddPropertyUI(this, v7, v6, *propertySets.p, currentPath);
    for ( j = (UFG::Editor::PropertyProxy_PropertySet *)&this->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
          j != (UFG::Editor::PropertyProxy_PropertySet *)&this->mIsLocal;
          j = (UFG::Editor::PropertyProxy_PropertySet *)&j->mNext[-1].mNext )
    {
      if ( !v7->mHideUnassigned || j->mIsLocal )
      {
        UFG::qPropertyPath::Push(currentPath, &j->mPropertyName);
        UFG::DUIContext::GetLayoutRect(v6, &v31, 0, 0);
        mH = v31.mH;
        rect = v31;
        rect.mW = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v31, 8)) - v31.mH;
        UFG::DUIContext::SetLayoutRect(v6, &rect);
        j->vfptr->UpdateUI(j, v7, v6, &propertySets, currentPath);
        v32 = v31;
        v32.mW = mH;
        v32.mX = _mm_cvtsi128_si32((__m128i)v31) + _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v31, 8)) - mH;
        v29 = UFG::DUIContext::SetLayoutRect(v6, &v32);
        if ( UFG::DUIContext::Button(v29, "-", 0x10u) )
        {
          v7->mPendingValueChange.mType = AMD|NVIDIA;
          UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, currentPath);
        }
        UFG::qPropertyPath::Pop(currentPath);
      }
    }
    if ( this->mParent )
      UFG::DUIContext::EndIndent(v6);
    if ( propertySets.p )
      operator delete[](propertySets.p);
    propertySets.p = 0i64;
    *(_QWORD *)&propertySets.size = 0i64;
  }
  UFG::qString::~qString(&result);
}

// File Line: 977
// RVA: 0x21CB80
void __fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateUI(
        UFG::Editor::PropertyProxy_PropertySet *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::RoadNetworkNode *,0> *selection,
        UFG::qPropertyPath *currentPath)
{
  UFG::qArray<UFG::RoadNetworkNode *,0> *v5; // rdi
  UFG::DUIContext *v6; // r12
  UFG::Editor::PropertyBrowser *v7; // r14
  UFG::qSymbol *p_mPropertyName; // rsi
  char *v10; // rbx
  unsigned int Hash; // eax
  bool *v12; // rax
  char v13; // bl
  unsigned int v14; // r15d
  __int64 size; // r12
  unsigned int v16; // edi
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::RoadNetworkNode **p; // rsi
  UFG::RoadNetworkNode **v21; // r9
  __int64 i; // r8
  UFG::RoadNetworkNode **v23; // rbx
  UFG::RoadNetworkNode **v24; // rbx
  UFG::Editor::PropertyProxy_PropertySet *j; // rdi
  int mH; // ebx
  UFG::DUIContext *v27; // rax
  UFG::qArray<UFG::RoadNetworkNode *,0> _dst; // [rsp+38h] [rbp-39h] BYREF
  UFG::DUIRect result; // [rsp+50h] [rbp-21h] BYREF
  UFG::DUIRect v30; // [rsp+60h] [rbp-11h] BYREF
  UFG::DUIRect rect; // [rsp+70h] [rbp-1h] BYREF
  UFG::qPropertySet *v32; // [rsp+D0h] [rbp+5Fh]

  v5 = selection;
  v6 = dui;
  v7 = browser;
  p_mPropertyName = &this->mPropertyName;
  v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  if ( !this->mParent )
    goto LABEL_7;
  if ( !this->mIsLocal )
    UFG::DUIContext::PushColour(v6, TextColour, &UFG::qColour::Grey);
  Hash = UFG::qPropertyPath::GetHash(currentPath);
  v12 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(v7, Hash);
  v13 = UFG::DUIContext::Collapsible(v6, v10, v12);
  if ( !this->mIsLocal )
    UFG::DUIContext::PopColour(v6, 0);
  if ( v13 )
  {
LABEL_7:
    _dst.p = 0i64;
    *(_QWORD *)&_dst.size = 0i64;
    if ( this->mParent )
    {
      v14 = 0;
      if ( v5->size )
      {
        do
        {
          v32 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                  (UFG::qPropertySet *)v5->p[v14],
                  (UFG::qArray<unsigned long,0> *)p_mPropertyName,
                  DEPTH_RECURSE);
          if ( v32 )
          {
            size = _dst.size;
            v16 = _dst.size + 1;
            if ( _dst.size + 1 <= _dst.capacity )
              goto LABEL_29;
            if ( _dst.capacity )
              v17 = 2 * _dst.capacity;
            else
              v17 = 1;
            for ( ; v17 < v16; v17 *= 2 )
              ;
            if ( v17 <= 2 )
              v17 = 2;
            if ( v17 - v16 > 0x10000 )
              v17 = _dst.size + 65537;
            if ( v17 == _dst.size )
            {
LABEL_29:
              p = _dst.p;
            }
            else
            {
              v18 = 8i64 * v17;
              if ( !is_mul_ok(v17, 8ui64) )
                v18 = -1i64;
              v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
              p = (UFG::RoadNetworkNode **)v19;
              v21 = _dst.p;
              if ( _dst.p )
              {
                for ( i = 0i64; (unsigned int)i < _dst.size; v21 = _dst.p )
                {
                  v19[i].mNext = (UFG::allocator::free_link *)v21[i];
                  i = (unsigned int)(i + 1);
                }
                operator delete[](v21);
              }
              _dst.p = p;
              _dst.capacity = v17;
            }
            _dst.size = v16;
            p[size] = (UFG::RoadNetworkNode *)v32;
            v5 = selection;
            p_mPropertyName = &this->mPropertyName;
          }
          ++v14;
        }
        while ( v14 < v5->size );
        v7 = browser;
        v6 = dui;
      }
    }
    else
    {
      UFG::qArray<UFG::qPropertySet *,0>::Clone(v5, &_dst);
    }
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mPropertyName);
    if ( !this->mHasGenerantedChildren )
    {
      UFG::Editor::PropertyProxy_PropertySet::GenerateChildren(
        this,
        (UFG::qArray<UFG::qPropertySet *,0> *)&_dst,
        this->mIsLocal);
      this->mHasGenerantedChildren = 1;
    }
    if ( _dst.size == 1 )
    {
      v23 = _dst.p;
      *v23 = (UFG::RoadNetworkNode *)UFG::Editor::PropertyProxy_PropertySet::UpdateParentListUI(
                                       this,
                                       v7,
                                       v6,
                                       *(UFG::qPropertySet **)_dst.p);
    }
    if ( this->mParent )
      UFG::DUIContext::BeginIndent(v6);
    v24 = _dst.p;
    *v24 = (UFG::RoadNetworkNode *)UFG::Editor::PropertyProxy_PropertySet::UpdateAddPropertyUI(
                                     this,
                                     v7,
                                     v6,
                                     *(UFG::qPropertySet **)_dst.p,
                                     currentPath);
    for ( j = (UFG::Editor::PropertyProxy_PropertySet *)&this->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
          j != (UFG::Editor::PropertyProxy_PropertySet *)&this->mIsLocal;
          j = (UFG::Editor::PropertyProxy_PropertySet *)&j->mNext[-1].mNext )
    {
      if ( !v7->mHideUnassigned || j->mIsLocal )
      {
        UFG::qPropertyPath::Push(currentPath, &j->mPropertyName);
        UFG::DUIContext::GetLayoutRect(v6, &result, 0, 0);
        mH = result.mH;
        rect = result;
        rect.mW = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)result, 8)) - result.mH;
        UFG::DUIContext::SetLayoutRect(v6, &rect);
        j->vfptr->UpdateUI(j, v7, v6, (UFG::qArray<UFG::qPropertySet *,0> *)&_dst, currentPath);
        v30 = result;
        v30.mW = mH;
        v30.mX = _mm_cvtsi128_si32((__m128i)result) + _mm_cvtsi128_si32(_mm_srli_si128((__m128i)result, 8)) - mH;
        v27 = UFG::DUIContext::SetLayoutRect(v6, &v30);
        if ( UFG::DUIContext::Button(v27, "-", 0x10u) )
        {
          v7->mPendingValueChange.mType = AMD|NVIDIA;
          UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, currentPath);
        }
        UFG::qPropertyPath::Pop(currentPath);
      }
    }
    if ( this->mParent )
      UFG::DUIContext::EndIndent(v6);
    if ( _dst.p )
      operator delete[](_dst.p);
  }
}

// File Line: 1070
// RVA: 0x216440
UFG::qPropertySet *__fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateParentListUI(
        UFG::Editor::PropertyProxy_PropertySet *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qPropertySet *pset)
{
  UFG::qPropertySet *v4; // r15
  UFG::qSymbol *v8; // rax
  UFG::qPropertyPath *v9; // rbx
  unsigned int Hash; // eax
  bool *v11; // rax
  UFG::Editor::SelectionSet *SelectionSet; // rsi
  unsigned int i; // edi
  UFG::Editor::DAGPath *v14; // rbx
  UFG::Editor::FnModifier *Interface; // rax
  UFG::qSymbolUC *v16; // rbx
  signed int v17; // ebx
  int mRowHeight; // edx
  char *v19; // rax
  __int64 v20; // r13
  __int64 size; // rdi
  unsigned int v22; // ebx
  unsigned int v23; // edx
  UFG::Editor::SmartHandleObject *mPtr; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::Editor::SelectionSet *v27; // rsi
  UFG::Event *v28; // rax
  __int64 v29; // r14
  unsigned int v30; // ebx
  unsigned int capacity; // edx
  unsigned int v32; // edx
  __int64 v33; // rbx
  UFG::Editor::SmartHandleObject *v34; // rcx
  __int64 *p_mSmartHandleList; // rcx
  __int64 v36; // rax
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v38; // rbx
  UFG::Editor::SmartHandleObject *v39; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v40; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v41; // rax
  __int64 v42; // rcx
  _QWORD *v43; // rax
  __int64 v44; // rcx
  _QWORD *v45; // rax
  __int64 v47; // [rsp+10h] [rbp-79h]
  __int64 v48; // [rsp+10h] [rbp-79h]
  UFG::Editor::DAGPath item; // [rsp+18h] [rbp-71h] BYREF
  void *p_mTypeId; // [rsp+78h] [rbp-11h]
  int column_widths[4]; // [rsp+80h] [rbp-9h] BYREF
  UFG::DUIRect rect; // [rsp+90h] [rbp+7h] BYREF
  __int64 v53; // [rsp+A0h] [rbp+17h]
  UFG::Editor::PropertyProxy_PropertySet *v54; // [rsp+E8h] [rbp+5Fh]
  UFG::Editor::PropertyBrowser *v55; // [rsp+F0h] [rbp+67h]
  UFG::qPropertyPath *v56; // [rsp+108h] [rbp+7Fh]

  v53 = -2i64;
  v4 = pset;
  if ( !UFG::PropertySetManager::IsComponentPropertySet(pset) )
  {
    v8 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&item.mFnObject.mTypeId + 1, "Parent");
    v9 = v56;
    UFG::qPropertyPath::Push(v56, v8);
    if ( this->mParent )
      UFG::DUIContext::BeginIndent(dui);
    Hash = UFG::qPropertyPath::GetHash(v9);
    v11 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(browser, Hash);
    if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Parents", v11) )
    {
      UFG::DUIContext::BeginIndent(dui);
      if ( UFG::DUIContext::Button(dui, "Add Parent", 0x10u) )
      {
        SelectionSet = UFG::Editor::SelectionManager::GetSelectionSet("LastSelection");
        for ( i = 0; i < SelectionSet->mDAGPaths.size; ++i )
        {
          v14 = &SelectionSet->mDAGPaths.p[i];
          if ( UFG::Editor::DAGPath::GetSystemName(v14, (UFG::qSymbol *)&item.mFnObject.mTypeId + 1)->mUID == UFG::Editor::DAGTypeArchetype::TYPE_SYMBOL.mUID
            && v14->mElements.size )
          {
            p_mTypeId = &item.mFnObject.mTypeId;
            item.mFnObject.mTypeId = v14->mInterfaceName.mUID;
            Interface = UFG::Editor::DAGPath::GetInterface(v14, 0xA25DB8B2, (UFG::qSymbol *)&item.mFnObject.mTypeId);
            v16 = Interface ? (UFG::qSymbolUC *)Interface[1].vfptr->__vecDelDtor : 0i64;
            if ( v16 )
            {
              v4 = UFG::Editor::Core::OpenForEdit(v4);
              UFG::PropertySetManager::AppendParentLocal(v4, v16 + 16);
              browser->mbDirty = 1;
            }
          }
        }
      }
      v17 = UFG::qPropertySet::NumParents(v4) - 1;
      *(&item.mFnObject.mTypeId + 1) = v17;
      if ( v17 >= 0 )
      {
        do
        {
          item.mFnObject.mTypeId = *(_DWORD *)&UFG::qPropertySet::GetParentFromIdx(v4, v17)->mDebugName[12];
          UFG::DUIContext::GetLayoutRect(dui, &rect, 0, 0);
          UFG::DUIContext::SetLayoutRect(dui, &rect);
          mRowHeight = dui->mTheme.mRowHeight;
          column_widths[0] = rect.mW - 2 * mRowHeight;
          column_widths[1] = mRowHeight;
          column_widths[2] = mRowHeight;
          UFG::DUIContext::BeginGridLayout(dui, 3, 1, column_widths, 0i64, LayoutFlag_None);
          v19 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&item.mFnObject.mTypeId);
          UFG::DUIContext::Label(dui, v19);
          if ( UFG::DUIContext::Button(dui, "@", 0x10u) )
          {
            UFG::Editor::EditorWindowManager::CreateWindow(
              (UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *)&item.mSystemName,
              "UFG::Editor::PropertyBrowserWindow");
            v20 = v47;
            p_mTypeId = &item;
            item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
            item.mFnObject.mPtr = 0i64;
            item.mFnObject.mTypeId = -1998658210;
            item.mSystemName.mUID = UFG::Editor::DAGTypeArchetype::TYPE_SYMBOL.mUID;
            item.mElements.p = 0i64;
            *(_QWORD *)&item.mElements.size = 0i64;
            UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, 4u, "qArray.Reallocate(Constructor)");
            item.mInterfaceName.mUID = -1;
            memset(&item.mSubElements, 0, 20);
            size = item.mElements.size;
            v22 = item.mElements.size + 1;
            if ( item.mElements.size + 1 > item.mElements.capacity )
            {
              if ( item.mElements.capacity )
                v23 = 2 * item.mElements.capacity;
              else
                v23 = 1;
              for ( ; v23 < v22; v23 *= 2 )
                ;
              if ( v23 <= 4 )
                v23 = 4;
              if ( v23 - v22 > 0x10000 )
                v23 = item.mElements.size + 65537;
              UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, v23, "qArray.Add");
            }
            item.mElements.size = v22;
            item.mElements.p[size].mUID = item.mFnObject.mTypeId;
            mPtr = item.mFnObject.mPtr;
            if ( item.mFnObject.mPtr )
            {
              mPrev = item.mFnObject.mPrev;
              mNext = item.mFnObject.mNext;
              item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
              mNext->mPrev = mPrev;
              item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList
                && mPtr )
              {
                mPtr->vfptr->__vecDelDtor(mPtr, 1u);
              }
              item.mFnObject.mPtr = 0i64;
            }
            item.mFnObject.mPtr = 0i64;
            v27 = UFG::Editor::SelectionManager::GetCreateSelectionSet(*(const char **)(v20 + 912));
            v27->mDAGPaths.size = 0;
            v28 = (UFG::Event *)UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
            p_mTypeId = v28;
            if ( v28 )
            {
              v28->mPrev = &v28->UFG::qNode<UFG::Event,UFG::Event>;
              v28->mNext = &v28->UFG::qNode<UFG::Event,UFG::Event>;
              v28->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
              v28->m_EventUID = 609910773;
              v28->m_NamePTR = 0i64;
            }
            else
            {
              v28 = 0i64;
            }
            v28->mUserData0 = (unsigned __int64)v27;
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v28);
            if ( (int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(&v27->mDAGPaths, &item) <= -1 )
            {
              v29 = v27->mDAGPaths.size;
              v30 = v29 + 1;
              capacity = v27->mDAGPaths.capacity;
              if ( (int)v29 + 1 > capacity )
              {
                if ( capacity )
                  v32 = 2 * capacity;
                else
                  v32 = 1;
                for ( ; v32 < v30; v32 *= 2 )
                  ;
                if ( v32 - v30 > 0x10000 )
                  v32 = v29 + 65537;
                UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&v27->mDAGPaths, v32, "qArray.Add");
              }
              v27->mDAGPaths.size = v30;
              v33 = (__int64)&v27->mDAGPaths.p[v29];
              if ( &item != (UFG::Editor::DAGPath *)v33 )
              {
                UFG::Editor::DAGPath::Clear(&v27->mDAGPaths.p[v29]);
                if ( !*(_DWORD *)(v33 + 80) )
                {
                  v34 = item.mFnObject.mPtr;
                  if ( !*(_QWORD *)(v33 + 16) )
                  {
                    if ( item.mFnObject.mPtr )
                    {
                      *(_DWORD *)(v33 + 24) = item.mFnObject.mPtr->mTypeId;
                      *(_QWORD *)(v33 + 16) = v34;
                      p_mSmartHandleList = (__int64 *)&v34->mSmartHandleList;
                      v36 = *p_mSmartHandleList;
                      *(_QWORD *)(v36 + 8) = v33;
                      *(_QWORD *)v33 = v36;
                      *(_QWORD *)(v33 + 8) = p_mSmartHandleList;
                      *p_mSmartHandleList = v33;
                    }
                  }
                }
                *(_DWORD *)(v33 + 32) = item.mSystemName.mUID;
                UFG::qArray<UFG::qSymbol,0>::Clone(&item.mElements, (UFG::qArray<UFG::qSymbol,0> *)(v33 + 40));
                *(_DWORD *)(v33 + 56) = item.mInterfaceName.mUID;
                UFG::qArray<UFG::qString,0>::Clone(&item.mSubElements, (UFG::qArray<UFG::qString,0> *)(v33 + 64));
              }
              UFG::Editor::SelectionSet::DispatchChangedEvent(v27);
              browser = v55;
            }
            *(_QWORD *)(v20 + 448) = v27;
            *(_BYTE *)(v20 + 865) = 1;
            *(_BYTE *)(v20 + 880) = 1;
            if ( item.mSubElements.p )
            {
              p_mStringHash32 = &item.mSubElements.p[-1].mStringHash32;
              `eh vector destructor iterator(
                item.mSubElements.p,
                0x28ui64,
                item.mSubElements.p[-1].mStringHash32,
                (void (__fastcall *)(void *))UFG::qString::~qString);
              operator delete[](p_mStringHash32);
            }
            item.mSubElements.p = 0i64;
            *(_QWORD *)&item.mSubElements.size = 0i64;
            if ( item.mElements.p )
            {
              v38 = item.mElements.p - 1;
              `eh vector destructor iterator(
                item.mElements.p,
                4ui64,
                item.mElements.p[-1].mUID,
                (void (__fastcall *)(void *))_);
              operator delete[](v38);
            }
            item.mElements.p = 0i64;
            *(_QWORD *)&item.mElements.size = 0i64;
            p_mTypeId = &item;
            v39 = item.mFnObject.mPtr;
            if ( item.mFnObject.mPtr )
            {
              v40 = item.mFnObject.mPrev;
              v41 = item.mFnObject.mNext;
              item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
              v41->mPrev = v40;
              item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v39->mSmartHandleList.mNode.mNext == &v39->mSmartHandleList
                && v39 )
              {
                v39->vfptr->__vecDelDtor(v39, 1u);
              }
              item.mFnObject.mPtr = 0i64;
            }
            item.mFnObject.mPtr = 0i64;
            UFG::Editor::SmartHandle::~SmartHandle(&item.mFnObject);
            if ( v48 )
            {
              v42 = *(_QWORD *)&item.mSystemName.mUID;
              v43 = *(_QWORD **)&item.mElements.size;
              *(_QWORD *)(*(_QWORD *)&item.mSystemName.mUID + 8i64) = *(_QWORD *)&item.mElements.size;
              *v43 = v42;
              *(_QWORD *)&item.mSystemName.mUID = &item.mSystemName;
              *(_QWORD *)&item.mElements.size = &item.mSystemName;
            }
            v44 = *(_QWORD *)&item.mSystemName.mUID;
            v45 = *(_QWORD **)&item.mElements.size;
            *(_QWORD *)(*(_QWORD *)&item.mSystemName.mUID + 8i64) = *(_QWORD *)&item.mElements.size;
            *v45 = v44;
            *(_QWORD *)&item.mSystemName.mUID = &item.mSystemName;
            *(_QWORD *)&item.mElements.size = &item.mSystemName;
            v17 = *(&item.mFnObject.mTypeId + 1);
          }
          if ( UFG::DUIContext::Button(dui, "-", 0x10u) )
          {
            v4 = UFG::Editor::Core::OpenForEdit(v4);
            UFG::PropertySetManager::RemoveParentLocal(v4, (UFG::qArray<unsigned long,0> *)&item.mFnObject.mTypeId);
            browser->mbDirty = 1;
          }
          UFG::DUIContext::EndLayoutHorizontal(dui);
          *(&item.mFnObject.mTypeId + 1) = --v17;
        }
        while ( v17 >= 0 );
        this = v54;
      }
      UFG::DUIContext::EndIndent(dui);
      v9 = v56;
    }
    UFG::DUIContext::Separator(dui);
    if ( this->mParent )
      UFG::DUIContext::EndIndent(dui);
    UFG::qPropertyPath::Pop(v9);
  }
  return v4;
}

// File Line: 1159
// RVA: 0x20AB10
void __fastcall UFG::Editor::PropertyProxy_PropertyList::GenerateChildren(
        UFG::Editor::PropertyProxy_PropertyList *this,
        UFG::qArray<UFG::qPropertyList *,0> *propertyLists,
        bool localProperty)
{
  int mTypeUID; // edi
  unsigned int mNumElements; // esi
  unsigned int v7; // r8d
  UFG::qPropertyList *v8; // rcx
  unsigned int v9; // ebp
  UFG::Editor::PropertyProxyCollection *p_mChildren; // r14
  char *ValuePtr; // rax
  UFG::qSymbol *v12; // rbx
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbx
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax
  _DWORD *v21; // rcx
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *mPrev; // rax

  mTypeUID = 29;
  mNumElements = 0;
  v7 = 0;
  if ( propertyLists->size )
  {
    do
    {
      v8 = propertyLists->p[v7];
      if ( mTypeUID == 29 )
      {
        mTypeUID = v8->mTypeUID;
        mNumElements = v8->mNumElements;
      }
      else
      {
        if ( v8->mTypeUID != mTypeUID )
          return;
        if ( mNumElements >= v8->mNumElements )
          mNumElements = v8->mNumElements;
      }
      ++v7;
    }
    while ( v7 < propertyLists->size );
    if ( mTypeUID != 29 )
    {
      v9 = 0;
      if ( mNumElements )
      {
        p_mChildren = &this->mChildren;
        do
        {
          if ( mTypeUID < 17 )
            goto LABEL_29;
          if ( mTypeUID <= 20 )
          {
            v18 = UFG::qMalloc(0x90ui64, UFG::gGlobalNewName, 0i64);
            v15 = v18;
            if ( v18 )
            {
              v19 = v18 + 1;
              v19->mNext = v19;
              v19[1].mNext = v19;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
              LODWORD(v15[3].mNext) = mTypeUID;
              HIDWORD(v15[3].mNext) = UFG::gNullQSymbol;
              LODWORD(v15[4].mNext) = v9;
              v15[5].mNext = 0i64;
              LOWORD(v15[6].mNext) = 0;
              BYTE2(v15[6].mNext) = 0;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxyVectored::`vftable;
              LODWORD(v15[7].mNext) = 0;
              v20 = 0i64;
              v21 = (_DWORD *)&v15[7].mNext + 1;
              do
              {
                *((_BYTE *)&v15[15].mNext + v20 + 4) = 0;
                *v21 = 0;
                ++v20;
                ++v21;
              }
              while ( v20 < 16 );
              BYTE4(v15[17].mNext) = 0;
            }
            else
            {
              v15 = 0i64;
            }
          }
          else
          {
            if ( mTypeUID != 25 )
            {
              if ( mTypeUID == 26 )
              {
                ValuePtr = UFG::qPropertyList::GetValuePtr(*propertyLists->p, 0x1Au, v9);
                if ( !ValuePtr || (v12 = (UFG::qSymbol *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
                  v12 = 0i64;
                v13 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
                if ( v13 )
                {
                  UFG::Editor::PropertyProxy_PropertySet::PropertyProxy_PropertySet(
                    (UFG::Editor::PropertyProxy_PropertySet *)v13,
                    v12 + 16,
                    v9);
                  v15 = v14;
                }
                else
                {
                  v15 = 0i64;
                }
                goto LABEL_33;
              }
LABEL_29:
              v22 = UFG::qMalloc(0x88ui64, UFG::gGlobalNewName, 0i64);
              v15 = v22;
              if ( v22 )
              {
                v23 = v22 + 1;
                v23->mNext = v23;
                v23[1].mNext = v23;
                v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
                LODWORD(v15[3].mNext) = mTypeUID;
                HIDWORD(v15[3].mNext) = UFG::gNullQSymbol;
                LODWORD(v15[4].mNext) = v9;
                v15[5].mNext = 0i64;
                LOWORD(v15[6].mNext) = 0;
                BYTE2(v15[6].mNext) = 0;
                v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxySimple::`vftable;
                UFG::qString::qString((UFG::qString *)&v15[7]);
                LOBYTE(v15[12].mNext) = 0;
                v15[13].mNext = v15 + 13;
                v15[14].mNext = v15 + 13;
                v15[16].mNext = 0i64;
                v15[15].mNext = 0i64;
              }
              else
              {
                v15 = 0i64;
              }
              UFG::Editor::PropertyProxySimple::Setup((UFG::Editor::PropertyProxySimple *)v15, propertyLists);
              goto LABEL_33;
            }
            v16 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
            v15 = v16;
            if ( v16 )
            {
              v17 = v16 + 1;
              v17->mNext = v17;
              v17[1].mNext = v17;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
              LODWORD(v15[3].mNext) = 25;
              HIDWORD(v15[3].mNext) = UFG::gNullQSymbol;
              LODWORD(v15[4].mNext) = v9;
              v15[5].mNext = 0i64;
              LOWORD(v15[6].mNext) = 0;
              BYTE2(v15[6].mNext) = 0;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy_Container::`vftable;
              v15[7].mNext = v15 + 7;
              v15[8].mNext = v15 + 7;
              LOBYTE(v15[9].mNext) = 0;
              HIDWORD(v15[9].mNext) = 0;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy_PropertyList::`vftable;
            }
            else
            {
              v15 = 0i64;
            }
          }
LABEL_33:
          mPrev = p_mChildren->mChildrenOrdered.mNode.mPrev;
          mPrev->mNext = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v15[1];
          v15[1].mNext = (UFG::allocator::free_link *)mPrev;
          v15[2].mNext = (UFG::allocator::free_link *)p_mChildren;
          p_mChildren->mChildrenOrdered.mNode.mPrev = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v15[1];
          v15[5].mNext = (UFG::allocator::free_link *)this;
          ++v9;
        }
        while ( v9 < mNumElements );
      }
    }
  }
}

// File Line: 1241
// RVA: 0x21C3A0
void __fastcall UFG::Editor::PropertyProxy_PropertyList::UpdateUI(
        UFG::Editor::PropertyProxy_PropertyList *this,
        UFG::Editor::PropertyBrowser *browser,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::qPropertySet *,0> *selection,
        UFG::qPropertyPath *currentPath)
{
  UFG::qArray<UFG::qPropertySet *,0> *v5; // rsi
  UFG::DUIContext *v6; // r12
  UFG::Editor::PropertyBrowser *v7; // r13
  UFG::Editor::PropertyProxy_PropertyList *v8; // rdi
  char *v9; // rbx
  bool *p_mIsLocal; // r14
  UFG::qPropertyPath *v11; // r15
  unsigned int Hash; // eax
  bool *v13; // rax
  char v14; // bl
  unsigned int PropertySetDataTypeFromString; // ebx
  unsigned int v16; // r15d
  int mUID; // r13d
  UFG::qArray<unsigned long,0> *v18; // r12
  UFG::qSymbol *v19; // rax
  __int64 size; // r14
  unsigned int v21; // edi
  unsigned int v22; // ebx
  unsigned __int64 v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::qPropertyList **p; // rsi
  UFG::qPropertyList **v26; // r9
  __int64 i; // r8
  const char *StringFromPropertySetType; // rax
  __int64 j; // rbx
  unsigned __int64 v30; // xmm0_8
  int v31; // [rsp+30h] [rbp-51h]
  UFG::qSymbol *name[2]; // [rsp+40h] [rbp-41h] BYREF
  UFG::DUIRect rect; // [rsp+50h] [rbp-31h] BYREF
  __int64 v34; // [rsp+60h] [rbp-21h]
  UFG::qArray<UFG::qPropertyList *,0> propertyLists; // [rsp+68h] [rbp-19h] BYREF
  UFG::DUIRect result; // [rsp+80h] [rbp-1h] BYREF

  v34 = -2i64;
  v5 = selection;
  v6 = dui;
  v7 = browser;
  v8 = this;
  name[0] = &this->mPropertyName;
  v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  p_mIsLocal = &v8->mIsLocal;
  *(_QWORD *)&rect.mX = &v8->mIsLocal;
  if ( !v8->mIsLocal )
    UFG::DUIContext::PushColour(v6, TextColour, &UFG::qColour::Grey);
  v11 = currentPath;
  Hash = UFG::qPropertyPath::GetHash(currentPath);
  v13 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(v7, Hash);
  v14 = UFG::DUIContext::Collapsible(v6, v9, v13);
  if ( !*p_mIsLocal )
    UFG::DUIContext::PopColour(v6, 0);
  if ( v14 )
  {
    propertyLists.p = 0i64;
    *(_QWORD *)&propertyLists.size = 0i64;
    PropertySetDataTypeFromString = 29;
    if ( v5->size )
    {
      v16 = 0;
      mUID = 29;
      v18 = (UFG::qArray<unsigned long,0> *)name[0];
      do
      {
        v19 = (UFG::qSymbol *)UFG::qPropertySet::Get<UFG::qPropertyList>(v5->p[v16], v18, DEPTH_RECURSE);
        name[0] = v19;
        if ( mUID == 29 )
          mUID = v19[6].mUID;
        size = propertyLists.size;
        v21 = propertyLists.size + 1;
        if ( propertyLists.size + 1 <= propertyLists.capacity )
          goto LABEL_28;
        if ( propertyLists.capacity )
          v22 = 2 * propertyLists.capacity;
        else
          v22 = 1;
        for ( ; v22 < v21; v22 *= 2 )
          ;
        if ( v22 <= 2 )
          v22 = 2;
        if ( v22 - v21 > 0x10000 )
          v22 = propertyLists.size + 65537;
        if ( v22 == propertyLists.size )
        {
LABEL_28:
          p = propertyLists.p;
        }
        else
        {
          v23 = 8i64 * v22;
          if ( !is_mul_ok(v22, 8ui64) )
            v23 = -1i64;
          v24 = UFG::qMalloc(v23, "qArray.Add", 0i64);
          p = (UFG::qPropertyList **)v24;
          v26 = propertyLists.p;
          if ( propertyLists.p )
          {
            for ( i = 0i64; (unsigned int)i < propertyLists.size; v26 = propertyLists.p )
            {
              v24[i].mNext = (UFG::allocator::free_link *)v26[i];
              i = (unsigned int)(i + 1);
            }
            operator delete[](v26);
          }
          propertyLists.p = p;
          propertyLists.capacity = v22;
        }
        propertyLists.size = v21;
        p[size] = (UFG::qPropertyList *)name[0];
        ++v16;
        v5 = selection;
      }
      while ( v16 < selection->size );
      v31 = mUID;
      v11 = currentPath;
      v6 = dui;
      v7 = browser;
      PropertySetDataTypeFromString = v31;
      v8 = this;
      p_mIsLocal = *(bool **)&rect.mX;
    }
    UFG::DUIContext::BeginIndent(v6);
    if ( !v8->mHasGenerantedChildren )
    {
      UFG::Editor::PropertyProxy_PropertyList::GenerateChildren(v8, &propertyLists, *p_mIsLocal);
      v8->mHasGenerantedChildren = 1;
    }
    UFG::DUIContext::BeginGridLayout(v6, 2, 1, LayoutFlag_DistributeCells);
    if ( PropertySetDataTypeFromString == 29 )
    {
      UFG::DUIContext::ComboBox(
        v6,
        &v8->mSelectedTypeOption,
        UFG::Editor::PropertyProxy_Container::mPropTypes,
        0xBu,
        0i64);
    }
    else
    {
      StringFromPropertySetType = GetStringFromPropertySetType(PropertySetDataTypeFromString);
      UFG::DUIContext::Label(v6, StringFromPropertySetType);
    }
    if ( UFG::DUIContext::Button(v6, "Add Item", 0x10u) )
    {
      if ( PropertySetDataTypeFromString == 29 )
        PropertySetDataTypeFromString = GetPropertySetDataTypeFromString(UFG::Editor::PropertyProxy_Container::mPropTypes[v8->mSelectedTypeOption]);
      UFG::qPropertyPath::Push(v11, 0);
      v7->mPendingValueChange.mType = 4;
      v7->mPendingValueChange.mNewItemType = PropertySetDataTypeFromString;
      UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, v11);
      UFG::qPropertyPath::Pop(v11);
    }
    UFG::DUIContext::EndLayoutHorizontal(v6);
    for ( j = (__int64)&v8->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
          (bool *)j != p_mIsLocal;
          j = *(_QWORD *)(j + 16) - 8i64 )
    {
      UFG::qPropertyPath::Push(v11, *(_DWORD *)(j + 32));
      UFG::DUIContext::GetLayoutRect(v6, &result, 0, 0);
      rect = result;
      v30 = _mm_srli_si128((__m128i)result, 8).m128i_u64[0];
      rect.mW = v30 - HIDWORD(v30);
      UFG::DUIContext::SetLayoutRect(v6, &rect);
      (*(void (__fastcall **)(__int64, UFG::Editor::PropertyBrowser *, UFG::DUIContext *, UFG::qArray<UFG::qPropertyList *,0> *, UFG::qPropertyPath *))(*(_QWORD *)j + 8i64))(
        j,
        v7,
        v6,
        &propertyLists,
        v11);
      *(UFG::DUIRect *)name = result;
      LODWORD(name[1]) = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)result, 12));
      LODWORD(name[0]) = rect.mX + rect.mW;
      UFG::DUIContext::SetLayoutRect(v6, (UFG::DUIRect *)name);
      if ( UFG::DUIContext::Button(v6, "-", 0x10u) )
      {
        v7->mPendingValueChange.mType = AMD|NVIDIA;
        UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, v11);
      }
      UFG::qPropertyPath::Pop(v11);
    }
    UFG::DUIContext::EndIndent(v6);
    if ( propertyLists.p )
      operator delete[](propertyLists.p);
  }
}

// File Line: 1363
// RVA: 0x20C450
void __fastcall UFG::Editor::GetPropertyInstancesRecurse(
        UFG::qPropertySet *propertySet,
        UFG::qArray<UFG::Editor::PropertyInstance,0> *instances)
{
  unsigned int v2; // ebp
  UFG::qPropertySet *v4; // rbx
  unsigned int v5; // esi
  UFG::qSymbol *PropertyNameFromIndex; // rax
  int v7; // r8d
  bool IsDefaultIdx; // al
  unsigned int size; // ecx
  unsigned int capacity; // eax
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // r9
  unsigned int j; // r8d
  __int64 v16; // rcx
  __int64 v17; // rdx
  UFG::Editor::PropertyInstance *p; // rcx
  UFG::Editor::PropertyInstance *v19; // rdx
  UFG::qPropertySet *ParentFromIdx; // rax
  UFG::allocator::free_link *v21; // [rsp+20h] [rbp-38h]
  __int64 v22; // [rsp+28h] [rbp-30h]
  __int64 v23; // [rsp+38h] [rbp-20h]
  unsigned int i; // [rsp+60h] [rbp+8h]
  unsigned int v25; // [rsp+70h] [rbp+18h]

  if ( propertySet )
  {
    v2 = 0;
    v4 = propertySet;
    v5 = 0;
    for ( i = 0; v5 < v4->mNumProperties; i = ++v5 )
    {
      PropertyNameFromIndex = UFG::qPropertySet::GetPropertyNameFromIndex(v4, v5);
      v7 = 0;
      if ( instances->size )
      {
        while ( instances->p[v7].mPropertyNameUID != PropertyNameFromIndex->mUID )
        {
          if ( ++v7 >= instances->size )
            goto LABEL_6;
        }
      }
      else
      {
LABEL_6:
        LODWORD(v22) = (UFG::qSymbol)PropertyNameFromIndex->mUID;
        LODWORD(v23) = UFG::qPropertySet::GetPropertyTypeFromIndex(v4, v5);
        IsDefaultIdx = UFG::qPropertySet::PropertyIsDefaultIdx(v4, v5);
        size = instances->size;
        BYTE4(v23) = IsDefaultIdx;
        capacity = instances->capacity;
        v11 = instances->size + 1;
        v25 = instances->size;
        if ( v11 > capacity )
        {
          v12 = 1;
          if ( capacity )
            v12 = 2 * capacity;
          for ( ; v12 < v11; v12 *= 2 )
            ;
          if ( v12 - v11 > 0x10000 )
            v12 = instances->size + 65537;
          if ( v12 != size )
          {
            v13 = 24i64 * v12;
            if ( !is_mul_ok(v12, 0x18ui64) )
              v13 = -1i64;
            v14 = UFG::qMalloc(v13, "qArray.Add", 0i64);
            v21 = v14;
            if ( instances->p )
            {
              for ( j = 0; j < instances->size; v14[v17 * 3 + 2] = *(UFG::allocator::free_link *)&p[v17].mPropertyType )
              {
                v16 = j++;
                v17 = v16;
                p = instances->p;
                v14[v17 * 3] = *(UFG::allocator::free_link *)&p[v17].mPropertyNameUID;
                v14[v17 * 3 + 1] = (UFG::allocator::free_link)p[v17].mPropertySet;
              }
              operator delete[](instances->p);
              v14 = v21;
            }
            size = v25;
            instances->p = (UFG::Editor::PropertyInstance *)v14;
            instances->capacity = v12;
          }
          v4 = propertySet;
        }
        instances->size = v11;
        v5 = i;
        v19 = &instances->p[size];
        *(_QWORD *)&v19->mPropertyNameUID = v22;
        v19->mPropertySet = v4;
        *(_QWORD *)&v19->mPropertyType = v23;
      }
    }
    if ( (unsigned int)UFG::qPropertySet::NumParents(v4) )
    {
      do
      {
        ParentFromIdx = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v4, v2);
        if ( ParentFromIdx )
          UFG::Editor::GetPropertyInstancesRecurse(ParentFromIdx, instances);
        ++v2;
      }
      while ( v2 < (unsigned int)UFG::qPropertySet::NumParents(v4) );
    }
  }
}

// File Line: 1412
// RVA: 0x20C8B0
void __fastcall UFG::Editor::GetSharedProperties(
        UFG::qArray<UFG::Editor::PropertyInstance,0> *shared_property_uids,
        UFG::qArray<UFG::qPropertySet *,0> *propertySets)
{
  UFG::qArray<UFG::qPropertySet *,0> *v2; // rdi
  char *v3; // r15
  UFG::qArray<UFG::Editor::PropertyInstance,0> *v4; // rsi
  UFG::qPropertySet *v5; // rcx
  unsigned int v6; // r12d
  UFG::Editor::PropertyInstance *v7; // r13
  __int64 size; // r15
  unsigned int v9; // edi
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::Editor::PropertyInstance *p; // r14
  UFG::Editor::PropertyInstance *v13; // r8
  __int64 i; // r9
  __int64 v15; // rdx
  __int64 v16; // rcx
  unsigned int v17; // ebx
  UFG::qArray<UFG::Editor::PropertyInstance,0> *v18; // r14
  UFG::Editor::PropertyInstance *v19; // rcx
  UFG::qPropertySet *v20; // rbx
  unsigned int v21; // r12d
  unsigned int v22; // edi
  UFG::Editor::PropertyInstance *v23; // rbx
  int v24; // edx
  __int64 v25; // r8
  __int64 v26; // r13
  bool v27; // zf
  __int64 v28; // r15
  unsigned int v29; // edi
  unsigned int capacity; // ebx
  unsigned int v31; // ebx
  unsigned __int64 v32; // rax
  UFG::allocator::free_link *v33; // r14
  __int64 j; // r8
  __int64 v35; // rdx
  UFG::Editor::PropertyInstance *v36; // rcx
  UFG::Editor::PropertyInstance *v37; // rdx
  UFG::qPropertySet *v38; // [rsp+30h] [rbp-49h]
  char *v39; // [rsp+38h] [rbp-41h]
  UFG::qArray<UFG::Editor::PropertyInstance,0> instances; // [rsp+48h] [rbp-31h] BYREF
  __int64 v41; // [rsp+68h] [rbp-11h]
  char ptr[16]; // [rsp+70h] [rbp-9h] BYREF
  UFG::qArray<UFG::Editor::PropertyInstance,0> v43; // [rsp+80h] [rbp+7h] BYREF
  int v46; // [rsp+F0h] [rbp+77h]
  UFG::qArray<UFG::Editor::PropertyInstance,0> *v47; // [rsp+F8h] [rbp+7Fh]

  v2 = propertySets;
  `eh vector constructor iterator(
    ptr,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  v3 = ptr;
  v4 = &v43;
  v5 = *v2->p;
  instances.p = 0i64;
  *(_QWORD *)&instances.size = 0i64;
  UFG::Editor::GetPropertyInstancesRecurse(v5, &instances);
  v6 = 0;
  if ( instances.size )
  {
    do
    {
      v7 = &instances.p[v6];
      size = v43.size;
      v9 = v43.size + 1;
      if ( v43.size + 1 <= v43.capacity )
        goto LABEL_18;
      if ( v43.capacity )
        v10 = 2 * v43.capacity;
      else
        v10 = 1;
      for ( ; v10 < v9; v10 *= 2 )
        ;
      if ( v10 - v9 > 0x10000 )
        v10 = v43.size + 65537;
      if ( v10 == v43.size )
      {
LABEL_18:
        p = v43.p;
      }
      else
      {
        v11 = 24i64 * v10;
        if ( !is_mul_ok(v10, 0x18ui64) )
          v11 = -1i64;
        p = (UFG::Editor::PropertyInstance *)UFG::qMalloc(v11, "qArray.Add", 0i64);
        v13 = v43.p;
        if ( v43.p )
        {
          for ( i = 0i64; (unsigned int)i < v43.size; v13 = v43.p )
          {
            v15 = i;
            *(_QWORD *)&p[v15].mPropertyNameUID = *(_QWORD *)&v13[i].mPropertyNameUID;
            p[v15].mPropertySet = v13[i].mPropertySet;
            *(_QWORD *)&p[v15].mPropertyType = *(_QWORD *)&v13[i].mPropertyType;
            i = (unsigned int)(i + 1);
          }
          operator delete[](v13);
        }
        v43.p = p;
        v43.capacity = v10;
      }
      v43.size = v9;
      v16 = size;
      *(_QWORD *)&p[v16].mPropertyNameUID = *(_QWORD *)&v7->mPropertyNameUID;
      p[v16].mPropertySet = v7->mPropertySet;
      *(_QWORD *)&p[v16].mPropertyType = *(_QWORD *)&v7->mPropertyType;
      ++v6;
    }
    while ( v6 < instances.size );
    v4 = &v43;
    v2 = propertySets;
    v3 = ptr;
  }
  v17 = 1;
  v46 = 1;
  if ( v2->size > 1 )
  {
    do
    {
      v18 = v4;
      v47 = v4;
      v4 = (UFG::qArray<UFG::Editor::PropertyInstance,0> *)v3;
      v3 = (char *)v18;
      v39 = (char *)v18;
      v19 = v4->p;
      if ( v19 )
        operator delete[](v19);
      v4->p = 0i64;
      *(_QWORD *)&v4->size = 0i64;
      v20 = v2->p[v17];
      if ( instances.p )
        operator delete[](instances.p);
      instances.p = 0i64;
      *(_QWORD *)&instances.size = 0i64;
      UFG::Editor::GetPropertyInstancesRecurse(v20, &instances);
      v21 = 0;
      v22 = instances.size;
      if ( instances.size )
      {
        do
        {
          v23 = &instances.p[v21];
          v24 = 0;
          if ( v18->size )
          {
            while ( 1 )
            {
              v25 = (__int64)&v18->p[v24];
              if ( *(_DWORD *)v25 == v23->mPropertyNameUID )
                break;
              if ( ++v24 >= v18->size )
                goto LABEL_51;
            }
            v26 = *(_QWORD *)v25;
            v38 = *(UFG::qPropertySet **)(v25 + 8);
            v41 = *(_QWORD *)(v25 + 16);
            if ( !*(_BYTE *)(v25 + 20) || (v27 = !v23->mIsDefault, BYTE4(v41) = 1, v27) )
              BYTE4(v41) = 0;
            v28 = v4->size;
            v29 = v28 + 1;
            capacity = v4->capacity;
            if ( (int)v28 + 1 > capacity )
            {
              if ( capacity )
                v31 = 2 * capacity;
              else
                v31 = 1;
              for ( ; v31 < v29; v31 *= 2 )
                ;
              if ( v31 - v29 > 0x10000 )
                v31 = v28 + 65537;
              if ( v31 != (_DWORD)v28 )
              {
                v32 = 24i64 * v31;
                if ( !is_mul_ok(v31, 0x18ui64) )
                  v32 = -1i64;
                v33 = UFG::qMalloc(v32, "qArray.Add", 0i64);
                if ( v4->p )
                {
                  for ( j = 0i64; (unsigned int)j < v4->size; j = (unsigned int)(j + 1) )
                  {
                    v35 = 3 * j;
                    v36 = v4->p;
                    v33[v35] = *(UFG::allocator::free_link *)&v36[j].mPropertyNameUID;
                    v33[v35 + 1] = (UFG::allocator::free_link)v36[j].mPropertySet;
                    v33[v35 + 2] = *(UFG::allocator::free_link *)&v36[j].mPropertyType;
                  }
                  operator delete[](v4->p);
                }
                v4->p = (UFG::Editor::PropertyInstance *)v33;
                v4->capacity = v31;
                v18 = v47;
              }
            }
            v4->size = v29;
            v37 = &v4->p[v28];
            *(_QWORD *)&v37->mPropertyNameUID = v26;
            v37->mPropertySet = v38;
            *(_QWORD *)&v37->mPropertyType = v41;
            v22 = instances.size;
          }
LABEL_51:
          ++v21;
        }
        while ( v21 < v22 );
        v3 = v39;
      }
      v17 = v46 + 1;
      v46 = v17;
      v2 = propertySets;
    }
    while ( v17 < propertySets->size );
  }
  UFG::qArray<UFG::Editor::PropertyInstance,0>::Clone(v4, shared_property_uids);
  if ( instances.p )
    operator delete[](instances.p);
  instances.p = 0i64;
  *(_QWORD *)&instances.size = 0i64;
  `eh vector destructor iterator(
    ptr,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
}

// File Line: 1465
// RVA: 0x20B600
char __fastcall UFG::Editor::GetCommonValue(
        UFG::qArray<UFG::qPropertySet *,0> *selection,
        UFG::qArray<unsigned long,0> *propertyName,
        qPropertySetVariant *value)
{
  __int64 i; // rbx
  qPropertySetVariant valuea; // [rsp+30h] [rbp-C8h] BYREF

  for ( i = 0i64; (unsigned int)i < selection->size; i = (unsigned int)(i + 1) )
  {
    if ( (_DWORD)i )
    {
      valuea.meType = UID_Invalid;
      UFG::qString::qString(&valuea.mValueString);
      *(_QWORD *)&valuea.mValueSymbol.mUID = -1i64;
      valuea.mValueWiseSymbol.mUID = -1;
      _((AMD_HD3D *)0xFFFFFFFFi64);
      UFG::qPropertySet::GetVariant(selection->p[i], propertyName, &valuea, DEPTH_RECURSE);
      if ( !qPropertySetVariant::operator==(&valuea, value) )
      {
        _((AMD_HD3D *)valuea.mValueWiseSymbol.mUID);
        UFG::qString::~qString(&valuea.mValueString);
        return 0;
      }
      _((AMD_HD3D *)valuea.mValueWiseSymbol.mUID);
      UFG::qString::~qString(&valuea.mValueString);
    }
    else
    {
      UFG::qPropertySet::GetVariant(*selection->p, propertyName, value, DEPTH_RECURSE);
    }
  }
  return 1;
}

// File Line: 1496
// RVA: 0x2020C0
void __fastcall UFG::Editor::PropertyBrowser::PropertyBrowser(UFG::Editor::PropertyBrowser *this)
{
  UFG::Editor::PropertyProxy_PropertySet *p_mTopLevelProperties; // rcx
  fastdelegate::FastDelegate1<UFG::Event *,void> v3[3]; // [rsp+38h] [rbp-30h] BYREF

  p_mTopLevelProperties = &this->mTopLevelProperties;
  p_mTopLevelProperties->mPrev = &p_mTopLevelProperties->UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy>;
  p_mTopLevelProperties->mNext = &p_mTopLevelProperties->UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy>;
  p_mTopLevelProperties->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  p_mTopLevelProperties->mDataType = UID_propertyset;
  p_mTopLevelProperties->mPropertyName = UFG::gNullQSymbol;
  p_mTopLevelProperties->mArrayIndex = -1;
  p_mTopLevelProperties->mParent = 0i64;
  *(_WORD *)&p_mTopLevelProperties->mIsLocal = 0;
  p_mTopLevelProperties->mIsListProperty = 0;
  p_mTopLevelProperties->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_Container::`vftable;
  p_mTopLevelProperties->mChildren.mChildrenOrdered.mNode.UFG::Editor::PropertyProxy_Container::mPrev = &p_mTopLevelProperties->mChildren.mChildrenOrdered.mNode;
  p_mTopLevelProperties->mChildren.mChildrenOrdered.mNode.mNext = &p_mTopLevelProperties->mChildren.mChildrenOrdered.mNode;
  p_mTopLevelProperties->mHasGenerantedChildren = 0;
  p_mTopLevelProperties->mSelectedTypeOption = 0;
  p_mTopLevelProperties->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::qString(&p_mTopLevelProperties->mNewPropertyName);
  this->mpSelection = 0i64;
  UFG::Editor::ValueChange::ValueChange(&this->mPendingValueChange);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mExpansionStates.mTree);
  this->mScrollPosition = 0i64;
  *(_DWORD *)&this->mHideUnassigned = 65792;
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, v3, 0x23DF27A9u, 0i64, 0);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, v3, 0x23C51C72u, 0i64, 0);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnSelectionChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, v3, 0x245A7FF5u, 0i64, 0);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, v3, 0x65C2B07Bu, 0i64, 0);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, v3, 0x9670AC65, 0i64, 0);
  *(_QWORD *)this->mColWidths = 0i64;
}

// File Line: 1509
// RVA: 0x203740
void __fastcall UFG::Editor::PropertyBrowser::~PropertyBrowser(UFG::Editor::PropertyBrowser *this)
{
  Render::SkinningCacheNode *Head; // rbx
  fastdelegate::FastDelegate1<UFG::Event *,void> v3[2]; // [rsp+28h] [rbp-20h] BYREF

  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v3, 0x9670AC65);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v3, 0x65C2B07Bu);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnSelectionChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v3, 0x245A7FF5u);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v3, 0x23C51C72u);
  v3[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v3, 0x23DF27A9u);
  while ( this->mExpansionStates.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mExpansionStates);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mExpansionStates,
      &Head->mNode);
    operator delete[](Head);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mExpansionStates);
  UFG::Editor::ValueChange::~ValueChange(&this->mPendingValueChange);
  this->mTopLevelProperties.vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::~qString(&this->mTopLevelProperties.mNewPropertyName);
  UFG::Editor::PropertyProxy_Container::~PropertyProxy_Container(&this->mTopLevelProperties);
}

// File Line: 1519
// RVA: 0x210750
void __fastcall UFG::Editor::PropertyBrowser::Refresh(UFG::Editor::PropertyBrowser *this)
{
  UFG::Editor::PropertyBrowser *v1; // rax
  UFG::qPropertySet **v2; // r12
  unsigned int v3; // r14d
  unsigned int v4; // esi
  UFG::Editor::SelectionSet *mpSelection; // rdi
  int v6; // r13d
  __int64 v7; // rbx
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  UFG::Editor::FnObject *v10; // rax
  _QWORD *p_mPrev; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  __int64 v13; // rax
  __int64 v14; // rcx
  unsigned int v15; // edx
  __int64 v16; // r8
  UFG::Editor::FnModifier *Modifier; // rax
  void *(__fastcall *vecDelDtor)(UFG::Editor::FnModifier *, unsigned int); // rbp
  __int64 v19; // r15
  unsigned int v20; // edi
  unsigned int v21; // ebx
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::qPropertySet **v24; // rsi
  UFG::allocator::free_link *v25; // rdx
  __int64 v26; // r8
  UFG::qArray<UFG::qPropertySet *,0> propertySets; // [rsp+28h] [rbp-50h] BYREF
  UFG::qSymbol symbol; // [rsp+88h] [rbp+10h] BYREF
  UFG::Editor::SelectionSet *v30; // [rsp+90h] [rbp+18h]

  v1 = this;
  v2 = 0i64;
  propertySets.p = 0i64;
  v3 = 0;
  *(_QWORD *)&propertySets.size = 0i64;
  v4 = 0;
  mpSelection = this->mpSelection;
  if ( !mpSelection )
    mpSelection = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v30 = mpSelection;
  v6 = 0;
  if ( mpSelection->mDAGPaths.size )
  {
    while ( 1 )
    {
      v7 = (__int64)&mpSelection->mDAGPaths.p[v6];
      if ( *(_DWORD *)(v7 + 40) )
        break;
LABEL_45:
      if ( ++v6 >= mpSelection->mDAGPaths.size )
      {
        v1 = this;
        goto LABEL_47;
      }
    }
    symbol.mUID = *(_DWORD *)(v7 + 56);
    if ( *(_DWORD *)(v7 + 80) == 1 )
      goto LABEL_24;
    if ( !*(_QWORD *)(v7 + 16) )
    {
      v8 = *(_DWORD *)(v7 + 32);
      if ( v8 )
      {
        v9 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v8);
        if ( v9 )
        {
          if ( v9 != (UFG::qBaseTreeRB *)8 )
          {
            v10 = UFG::Editor::DAGType::AquireFnObject(
                    (UFG::Editor::DAGType *)&v9[-1].mCount,
                    (UFG::Editor::DAGPath *)v7);
            if ( !*(_QWORD *)(v7 + 16) )
            {
              if ( v10 )
              {
                *(_DWORD *)(v7 + 24) = v10->mTypeId;
                *(_QWORD *)(v7 + 16) = v10;
                p_mPrev = &v10->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                mPrev = v10->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                mPrev->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v7;
                *(_QWORD *)v7 = mPrev;
                *(_QWORD *)(v7 + 8) = p_mPrev;
                *p_mPrev = v7;
              }
            }
          }
        }
      }
    }
    v13 = *(_QWORD *)(v7 + 16);
    if ( !v13 )
      goto LABEL_24;
    if ( *(_DWORD *)(v7 + 56) == -1 )
    {
      v14 = 0i64;
      v15 = *(_DWORD *)(v13 + 64);
      if ( v15 )
      {
        v16 = *(_QWORD *)(v13 + 72);
        while ( 1 )
        {
          Modifier = *(UFG::Editor::FnModifier **)(v16 + 8 * v14);
          if ( Modifier->mTypeID == -1570916174 )
            break;
          v14 = (unsigned int)(v14 + 1);
          if ( (unsigned int)v14 >= v15 )
            goto LABEL_19;
        }
      }
      else
      {
LABEL_19:
        Modifier = 0i64;
      }
    }
    else
    {
      Modifier = UFG::Editor::FnObject::GetModifier(*(UFG::Editor::FnObject **)(v7 + 16), &symbol);
      if ( !Modifier || Modifier->mTypeID != -1570916174 )
        goto LABEL_24;
    }
    if ( Modifier )
    {
      vecDelDtor = Modifier[1].vfptr->__vecDelDtor;
      goto LABEL_25;
    }
LABEL_24:
    vecDelDtor = 0i64;
LABEL_25:
    if ( vecDelDtor )
    {
      v19 = v3;
      v20 = v3 + 1;
      if ( v3 + 1 > v4 )
      {
        v21 = 1;
        if ( v4 )
          v21 = 2 * v4;
        for ( ; v21 < v20; v21 *= 2 )
          ;
        if ( v21 <= 2 )
          v21 = 2;
        if ( v21 - v20 > 0x10000 )
          v21 = v3 + 65537;
        if ( v21 != v3 )
        {
          v22 = 8i64 * v21;
          if ( !is_mul_ok(v21, 8ui64) )
            v22 = -1i64;
          v23 = UFG::qMalloc(v22, "qArray.Add", 0i64);
          v24 = (UFG::qPropertySet **)v23;
          if ( v2 )
          {
            if ( v3 )
            {
              v25 = v23;
              v26 = v3;
              do
              {
                v25->mNext = *(UFG::allocator::free_link **)((char *)v25 + (char *)v2 - (char *)v23);
                ++v25;
                --v26;
              }
              while ( v26 );
            }
            operator delete[](v2);
          }
          v2 = v24;
          propertySets.p = v24;
          v4 = v21;
          propertySets.capacity = v21;
        }
      }
      ++v3;
      propertySets.size = v20;
      v2[v19] = (UFG::qPropertySet *)vecDelDtor;
      mpSelection = v30;
    }
    goto LABEL_45;
  }
LABEL_47:
  v1->mTopLevelProperties.mIsLocal = 1;
  v1->mTopLevelProperties.mHasGenerantedChildren = 0;
  UFG::Editor::PropertyProxy_PropertySet::GenerateChildren(&v1->mTopLevelProperties, &propertySets, 1);
  if ( v2 )
    operator delete[](v2);
}

// File Line: 1560
// RVA: 0x20FBF0
void __fastcall UFG::Editor::PropertyBrowser::OnSelectionChanged(UFG::Editor::PropertyBrowser *this, UFG::Event *evt)
{
  UFG::Editor::SelectionSet *mpSelection; // rax

  mpSelection = this->mpSelection;
  if ( !mpSelection )
    mpSelection = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  if ( (UFG::Editor::SelectionSet *)evt->mUserData0 == mpSelection )
    this->mbDirty = 1;
}

// File Line: 1576
// RVA: 0x20F700
void __fastcall UFG::Editor::PropertyBrowser::OnTransformationChanged(
        UFG::Editor::PropertyBrowser *this,
        UFG::Event *__formal)
{
  this->mbDirty = 1;
}

// File Line: 1582
// RVA: 0x20DDA0
UFG::qBaseNodeRB *__fastcall UFG::Editor::PropertyBrowser::IsExpanded(
        UFG::Editor::PropertyBrowser *this,
        unsigned int uid)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::allocator::free_link *v6; // rbx

  if ( uid )
  {
    v4 = UFG::qBaseTreeRB::Get(&this->mExpansionStates.mTree, uid);
    if ( v4 )
      return &v4->mNULL;
  }
  v6 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v6 )
  {
    v6->mNext = 0i64;
    v6[1].mNext = 0i64;
    v6[2].mNext = 0i64;
    LODWORD(v6[3].mNext) = uid;
    LOBYTE(v6[4].mNext) = 0;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&this->mExpansionStates.mTree, (UFG::qBaseNodeRB *)v6);
  return (UFG::qBaseNodeRB *)&v6[4];
}

// File Line: 1595
// RVA: 0x205110
void __fastcall UFG::Editor::PropertyBrowser::ApplyValueChange(UFG::Editor::PropertyBrowser *this)
{
  UFG::Editor::SelectionSet *mpSelection; // rax
  unsigned int v3; // r12d
  __int64 v4; // rdi
  UFG::Editor::DAGPath *v5; // rbx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::Editor::FnObject *v8; // rax
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *p_mSmartHandleList; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::Editor::DAGPath *v12; // rcx
  UFG::Editor::FnModifier *Interface; // rax
  UFG::qPropertySet *v14; // rbx
  unsigned int size; // r13d
  __int64 v16; // rsi
  unsigned int v17; // r15d
  UFG::qBaseNodeRB *SchemaForComponentPropertyName; // rdi
  unsigned int PropertyTypeFromName; // eax
  UFG::qPropertySet *v20; // rax
  UFG::qPropertySet *v21; // rdi
  UFG::qPropertyList *v22; // rax
  UFG::qPropertyList *v23; // rdi
  signed int v24; // ebp
  __int64 mOffset; // rax
  UFG::qPropertySet *v26; // rcx
  UFG::Editor::ValueChange::TYPE v27; // eax
  unsigned int v28; // eax
  char *v29; // rax
  char *v30; // rax
  char *ValuePtr; // rax
  UFG::qPropertyList *v32; // rcx
  UFG::allocator::free_link *v33; // rax
  UFG::Editor::ValueChange::TYPE v34; // eax
  UFG::Editor::ValueChange::TYPE mType; // eax
  UFG::qArray<unsigned long,0> result; // [rsp+80h] [rbp+8h] BYREF
  UFG::Editor::SelectionSet *v37; // [rsp+90h] [rbp+18h]
  unsigned int **p_p; // [rsp+98h] [rbp+20h]

  mpSelection = this->mpSelection;
  if ( !mpSelection )
    mpSelection = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v37 = mpSelection;
  v3 = 0;
  if ( mpSelection->mDAGPaths.size )
  {
    while ( 1 )
    {
      v4 = v3;
      v5 = &mpSelection->mDAGPaths.p[v4];
      if ( v5->mPathType != Half )
      {
        if ( !v5->mFnObject.mPtr )
        {
          mUID = v5->mSystemName.mUID;
          if ( mUID )
          {
            v7 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, mUID);
            if ( v7 )
            {
              if ( v7 != (UFG::qBaseTreeRB *)8 )
              {
                v8 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v7[-1].mCount, v5);
                if ( !v5->mFnObject.mPtr )
                {
                  if ( v8 )
                  {
                    v5->mFnObject.mTypeId = v8->mTypeId;
                    v5->mFnObject.mPtr = v8;
                    p_mSmartHandleList = &v8->mSmartHandleList;
                    mPrev = v8->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                    mPrev->mNext = &v5->mFnObject;
                    v5->mFnObject.mPrev = mPrev;
                    v5->mFnObject.mNext = &p_mSmartHandleList->mNode;
                    p_mSmartHandleList->mNode.mPrev = &v5->mFnObject;
                  }
                }
              }
            }
          }
        }
        mPtr = v5->mFnObject.mPtr;
        if ( mPtr )
        {
          if ( ((unsigned __int8 (__fastcall *)(UFG::Editor::SmartHandleObject *))mPtr->vfptr[4].__vecDelDtor)(mPtr) )
          {
            v12 = &v37->mDAGPaths.p[v4];
            if ( v12->mElements.size )
            {
              p_p = &result.p;
              LODWORD(result.p) = v12->mInterfaceName.mUID;
              Interface = UFG::Editor::DAGPath::GetInterface(v12, 0xA25DB8B2, (UFG::qSymbol)&result.p);
              v14 = Interface ? (UFG::qPropertySet *)Interface[1].vfptr->__vecDelDtor : 0i64;
              if ( v14 )
              {
                if ( (v14->mFlags & 1) == 0 )
                {
                  size = this->mPendingValueChange.mPath.mPath.size;
                  v16 = 0i64;
                  if ( size )
                    break;
                }
              }
            }
          }
        }
      }
LABEL_87:
      ++v3;
      mpSelection = v37;
      if ( v3 >= v37->mDAGPaths.size )
        return;
    }
    v17 = size - 1;
    while ( 1 )
    {
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, this->mPendingValueChange.mPath.mPath.p[v16]);
      if ( v14 )
      {
        if ( v14->mSchemaName.mUID == UFG::gNullQSymbol.mUID )
        {
          SchemaForComponentPropertyName = UFG::PropertySetManager::GetSchemaForComponentPropertyName(&result);
          if ( SchemaForComponentPropertyName )
          {
            if ( !UFG::qPropertySet::PropertyExists(v14, &result, DEPTH_LOCAL) )
              UFG::PropertySetManager::AddComponentPropertySet(
                v14,
                (UFG::SchemaDef *)SchemaForComponentPropertyName,
                0i64);
          }
        }
      }
      PropertyTypeFromName = UFG::qPropertySet::GetPropertyTypeFromName(v14, &result, DEPTH_RECURSE);
      if ( PropertyTypeFromName != 26 )
        break;
      if ( (_DWORD)v16 != v17 || this->mPendingValueChange.mType != (AMD|NVIDIA) )
      {
        v20 = UFG::qPropertySet::Get<UFG::qPropertySet>(v14, &result, DEPTH_RECURSE);
        v21 = v20;
        if ( (v20->mFlags & 1) != 0 )
        {
          v21 = UFG::qPropertySet::Clone(v20);
          UFG::qPropertySet::Set<UFG::qPropertySet>(v14, &result, v21);
        }
        v14 = v21;
LABEL_67:
        v16 = (unsigned int)(v16 + 1);
        goto LABEL_68;
      }
      UFG::qPropertySet::RemovePropertyByName(v14, &result);
LABEL_68:
      if ( (unsigned int)v16 >= size )
        goto LABEL_87;
    }
    if ( PropertyTypeFromName != 25 )
    {
      if ( (PropertyTypeFromName != 29 || (unsigned int)(this->mPendingValueChange.mType - 3) <= 1) && v14 )
      {
        mType = this->mPendingValueChange.mType;
        switch ( mType )
        {
          case 4:
            UFG::qPropertySet::AddProperty(v14, &result, this->mPendingValueChange.mNewItemType);
            break;
          case 3:
            UFG::qPropertySet::RemovePropertyByName(v14, &result);
            break;
          case 1:
            UFG::qPropertySet::SetVariant(v14, &result, &this->mPendingValueChange.mSimpleValue);
            break;
          case 2:
            UFG::Editor::SetVectorValue(v14, (UFG::qSymbol *)&result, &this->mPendingValueChange.mVectoredValue);
            break;
        }
      }
      goto LABEL_87;
    }
    v22 = UFG::qPropertySet::Get<UFG::qPropertyList>(v14, &result, DEPTH_RECURSE);
    v23 = v22;
    if ( (v22->mFlags & 1) != 0 )
    {
      v23 = (UFG::qPropertyList *)UFG::qPropertyList::Clone(v22);
      UFG::qPropertySet::Set<UFG::qPropertyList>(v14, &result, v23);
    }
    v14 = 0i64;
    v16 = (unsigned int)(v16 + 1);
    if ( (unsigned int)v16 >= this->mPendingValueChange.mPath.mPath.size )
    {
      v24 = -1;
    }
    else
    {
      v24 = this->mPendingValueChange.mPath.mPath.p[v16];
      if ( v24 >= 0 )
      {
LABEL_47:
        if ( v23->mTypeUID == 25 )
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v23, 0x19u, v24);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v32 = (UFG::qPropertyList *)&ValuePtr[*(_QWORD *)ValuePtr];
          else
            v32 = 0i64;
          if ( (v32->mFlags & 1) != 0 )
          {
            v33 = UFG::qPropertyList::Clone(v32);
            UFG::qPropertyList::Set<UFG::qPropertyList>(v23, v24, (UFG::qPropertyList *)v33);
          }
        }
        else
        {
          if ( v23->mTypeUID != 26 )
          {
            v34 = this->mPendingValueChange.mType;
            switch ( v34 )
            {
              case 1:
                UFG::qPropertyList::SetVariant(v23, v24, &this->mPendingValueChange.mSimpleValue);
                break;
              case 3:
                UFG::qPropertyList::Remove(v23, v24);
                break;
              case 4:
                UFG::qPropertyList::AddItem(v23, this->mPendingValueChange.mNewItemType);
                break;
            }
            goto LABEL_87;
          }
          if ( (_DWORD)v16 == v17 )
          {
            v27 = this->mPendingValueChange.mType;
            if ( v27 == 4 )
            {
              v28 = UFG::qPropertyList::AddItem(v23, 26);
              v29 = UFG::qPropertyList::GetValuePtr(v23, 0x1Au, v28);
              if ( v29 && *(_QWORD *)v29 )
                v14 = (UFG::qPropertySet *)&v29[*(_QWORD *)v29];
            }
            else if ( v27 == (AMD|NVIDIA) )
            {
              UFG::qPropertyList::Remove(v23, v24);
            }
          }
          else
          {
            v30 = UFG::qPropertyList::GetValuePtr(v23, 0x1Au, v24);
            if ( v30 && *(_QWORD *)v30 )
              v14 = (UFG::qPropertySet *)&v30[*(_QWORD *)v30];
            if ( (v14->mFlags & 1) != 0 )
            {
              v14 = UFG::qPropertySet::Clone(v14);
              UFG::qPropertyList::Set<UFG::qPropertySet>(v23, v24, v14);
            }
          }
        }
        goto LABEL_67;
      }
    }
    if ( this->mPendingValueChange.mType == (AMD|NVIDIA) )
    {
      if ( (v23->mFlags & 0x10) != 0 && (mOffset = v23->mOwner.mOffset) != 0 )
        v26 = (UFG::qPropertySet *)((char *)&v23->mOwner + mOffset);
      else
        v26 = 0i64;
      UFG::qPropertySet::RemovePropertyByName(v26, &result);
      goto LABEL_68;
    }
    goto LABEL_47;
  }
}

// File Line: 1803
// RVA: 0x21B8D0
void __fastcall UFG::Editor::PropertyBrowser::UpdateUI(UFG::Editor::PropertyBrowser *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r13
  UFG::Editor::PropertyBrowser *v3; // rbx
  int v4; // r15d
  int v5; // eax
  UFG::allocator::free_link *v6; // r12
  unsigned int v7; // r14d
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mpSelection; // rsi
  unsigned int v9; // eax
  char *v10; // rbx
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::Editor::FnObject *v13; // rax
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *p_mSmartHandleList; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v15; // rax
  __int64 v16; // rax
  __int64 v17; // rcx
  unsigned int v18; // edx
  __int64 v19; // r8
  UFG::Editor::FnModifier *Modifier; // rax
  void *(__fastcall *vecDelDtor)(UFG::Editor::FnModifier *, unsigned int); // r12
  __int64 v22; // r13
  unsigned int v23; // edi
  unsigned int v24; // ebx
  unsigned __int64 v25; // rax
  UFG::allocator::free_link *v26; // rax
  void *v27; // rsi
  char *v28; // rcx
  __int64 i; // r8
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mPrev; // rax
  UFG::qSymbol **v31; // rbx
  bool v32; // al
  UFG::qBaseNodeRB *SimObject; // r13
  unsigned int v34; // edi
  unsigned int v35; // ebx
  unsigned __int64 v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // rsi
  UFG::allocator::free_link *v39; // rdx
  __int64 v40; // r8
  UFG::Editor::DAGPath *v41; // rdi
  UFG::Editor::FnModifier *Interface; // rax
  __int64 v43; // rax
  UFG::qString *p; // rdx
  unsigned int v45; // esi
  bool v46; // bl
  bool v47; // bl
  bool v48; // bl
  bool v49; // bl
  bool v50; // bl
  bool v51; // bl
  __int64 v52; // r14
  UFG::Editor::FnModifier *v53; // rax
  __int64 v54; // rbx
  UFG::qString *SubElement; // rax
  UFG::Editor::Gizmo *v56; // rbx
  UFG::qMatrix44 *v57; // rax
  UFG::qVector4 v58; // xmm2
  UFG::qVector4 v59; // xmm1
  UFG::qVector4 v60; // xmm0
  UFG::qVector3 soln; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v62; // [rsp+40h] [rbp-C0h] BYREF
  void *mem; // [rsp+48h] [rbp-B8h]
  UFG::DUIRect result; // [rsp+50h] [rbp-B0h] BYREF
  float val; // [rsp+60h] [rbp-A0h] BYREF
  float y; // [rsp+64h] [rbp-9Ch] BYREF
  float z; // [rsp+68h] [rbp-98h] BYREF
  int v68; // [rsp+70h] [rbp-90h]
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v69; // [rsp+78h] [rbp-88h]
  UFG::qPropertyPath v70; // [rsp+80h] [rbp-80h] BYREF
  UFG::qSymbol v71; // [rsp+90h] [rbp-70h] BYREF
  __int64 v72; // [rsp+98h] [rbp-68h]
  UFG::qMatrix44 rot; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qMatrix44 affine; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qMatrix44 v75; // [rsp+120h] [rbp+20h] BYREF
  UFG::qSymbol interfaceName; // [rsp+1D0h] [rbp+D0h] BYREF
  UFG::qSymbol *symbol; // [rsp+1D8h] [rbp+D8h] BYREF

  v72 = -2i64;
  v2 = dui;
  v3 = this;
  v4 = 0;
  v68 = 0;
  if ( this->mUpdateColumns )
  {
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    UFG::DUIContext::SetLayoutRect(v2, &result);
    v5 = result.mW / 2;
    v3->mColWidths[0] = result.mW / 2;
    v3->mColWidths[1] = v5;
    v3->mUpdateColumns = 0;
  }
  if ( v3->mbDirty )
  {
    UFG::Editor::PropertyBrowser::Refresh(v3);
    v3->mbDirty = 0;
  }
  if ( v3->mPendingValueChange.mType )
  {
    UFG::Editor::PropertyBrowser::ApplyValueChange(v3);
    UFG::Editor::PropertyBrowser::Refresh(v3);
    v3->mPendingValueChange.mType = NONE;
  }
  UFG::qPropertyPath::qPropertyPath(&v70);
  mem = 0i64;
  v62 = 0i64;
  v6 = 0i64;
  *(_QWORD *)&result.mW = 0i64;
  v7 = 0;
  *(_QWORD *)&result.mX = 0i64;
  mpSelection = v3->mpSelection;
  if ( !mpSelection )
    mpSelection = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v69 = mpSelection;
  v9 = 0;
  interfaceName.mUID = 0;
  if ( LODWORD(mpSelection[3].mNext) )
  {
    while ( 1 )
    {
      *(_QWORD *)&soln.x = 88i64 * v9;
      v10 = (char *)mpSelection[4].mPrev + *(_QWORD *)&soln.x;
      if ( *((_DWORD *)v10 + 10) )
        break;
LABEL_53:
      mPrev = mpSelection[4].mPrev;
      v31 = (UFG::qSymbol **)((char *)mPrev + *(_QWORD *)&soln.x);
      v32 = 1;
      if ( *(_DWORD *)((char *)&mPrev[2].mNext + *(_QWORD *)&soln.x) )
      {
        v4 |= 1u;
        v68 = v4;
        if ( UFG::Editor::DAGPath::GetSystemName((UFG::Editor::DAGPath *)((char *)mPrev + *(_QWORD *)&soln.x), &v71)->mUID == UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
          v32 = 0;
      }
      if ( (v4 & 1) != 0 )
      {
        v4 &= ~1u;
        v68 = v4;
      }
      if ( !v32 )
      {
        SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, v31[6]);
        if ( SimObject )
        {
          LODWORD(symbol) = v7;
          v34 = v7 + 1;
          if ( v7 + 1 > result.mY )
          {
            v35 = 1;
            if ( result.mY )
              v35 = 2 * result.mY;
            for ( ; v35 < v34; v35 *= 2 )
              ;
            if ( v35 <= 2 )
              v35 = 2;
            if ( v35 - v34 > 0x10000 )
              v35 = v7 + 65537;
            if ( v35 != v7 )
            {
              v36 = 8i64 * v35;
              if ( !is_mul_ok(v35, 8ui64) )
                v36 = -1i64;
              v37 = UFG::qMalloc(v36, "qArray.Add", 0i64);
              v38 = v37;
              if ( v6 )
              {
                if ( v7 )
                {
                  v39 = v37;
                  v40 = v7;
                  do
                  {
                    v39->mNext = *(UFG::allocator::free_link **)((char *)v39 + (char *)v6 - (char *)v37);
                    ++v39;
                    --v40;
                  }
                  while ( v40 );
                }
                operator delete[](v6);
              }
              v6 = v38;
              *(_QWORD *)&result.mW = v38;
              result.mY = v35;
              mpSelection = v69;
            }
          }
          ++v7;
          result.mX = v34;
          v6[(unsigned int)symbol].mNext = (UFG::allocator::free_link *)SimObject;
        }
      }
      v9 = interfaceName.mUID + 1;
      interfaceName.mUID = v9;
      if ( v9 >= LODWORD(mpSelection[3].mNext) )
      {
        v3 = this;
        v2 = dui;
        goto LABEL_82;
      }
    }
    LODWORD(symbol) = *((_DWORD *)v10 + 14);
    if ( *((_DWORD *)v10 + 20) == 1 )
      goto LABEL_30;
    if ( !*((_QWORD *)v10 + 2) )
    {
      v11 = *((_DWORD *)v10 + 8);
      if ( v11 )
      {
        v12 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v11);
        if ( v12 )
        {
          if ( v12 != (UFG::qBaseTreeRB *)8 )
          {
            v13 = UFG::Editor::DAGType::AquireFnObject(
                    (UFG::Editor::DAGType *)&v12[-1].mCount,
                    (UFG::Editor::DAGPath *)v10);
            if ( !*((_QWORD *)v10 + 2) )
            {
              if ( v13 )
              {
                *((_DWORD *)v10 + 6) = v13->mTypeId;
                *((_QWORD *)v10 + 2) = v13;
                p_mSmartHandleList = &v13->mSmartHandleList;
                v15 = v13->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                v15->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v10;
                *(_QWORD *)v10 = v15;
                *((_QWORD *)v10 + 1) = p_mSmartHandleList;
                p_mSmartHandleList->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v10;
              }
            }
          }
        }
      }
    }
    v16 = *((_QWORD *)v10 + 2);
    if ( !v16 )
      goto LABEL_30;
    if ( *((_DWORD *)v10 + 14) == -1 )
    {
      v17 = 0i64;
      v18 = *(_DWORD *)(v16 + 64);
      if ( v18 )
      {
        v19 = *(_QWORD *)(v16 + 72);
        while ( 1 )
        {
          Modifier = *(UFG::Editor::FnModifier **)(v19 + 8 * v17);
          if ( Modifier->mTypeID == -1570916174 )
            break;
          v17 = (unsigned int)(v17 + 1);
          if ( (unsigned int)v17 >= v18 )
            goto LABEL_25;
        }
      }
      else
      {
LABEL_25:
        Modifier = 0i64;
      }
    }
    else
    {
      Modifier = UFG::Editor::FnObject::GetModifier(*((UFG::Editor::FnObject **)v10 + 2), (UFG::qSymbol *)&symbol);
      if ( !Modifier || Modifier->mTypeID != -1570916174 )
        goto LABEL_30;
    }
    if ( Modifier )
    {
      vecDelDtor = Modifier[1].vfptr->__vecDelDtor;
LABEL_31:
      if ( vecDelDtor )
      {
        v22 = (unsigned int)v62;
        v23 = v62 + 1;
        if ( (unsigned int)(v62 + 1) <= HIDWORD(v62) )
          goto LABEL_50;
        if ( HIDWORD(v62) )
          v24 = 2 * HIDWORD(v62);
        else
          v24 = 1;
        for ( ; v24 < v23; v24 *= 2 )
          ;
        if ( v24 <= 2 )
          v24 = 2;
        if ( v24 - v23 > 0x10000 )
          v24 = v62 + 65537;
        if ( v24 == (_DWORD)v62 )
        {
LABEL_50:
          v27 = mem;
        }
        else
        {
          v25 = 8i64 * v24;
          if ( !is_mul_ok(v24, 8ui64) )
            v25 = -1i64;
          v26 = UFG::qMalloc(v25, "qArray.Add", 0i64);
          v27 = v26;
          v28 = (char *)mem;
          if ( mem )
          {
            for ( i = 0i64; (unsigned int)i < (unsigned int)v62; v28 = (char *)mem )
            {
              v26[i] = *(UFG::allocator::free_link *)&v28[8 * i];
              i = (unsigned int)(i + 1);
            }
            operator delete[](v28);
          }
          mem = v27;
          HIDWORD(v62) = v24;
        }
        LODWORD(v62) = v23;
        *((_QWORD *)v27 + v22) = vecDelDtor;
        mpSelection = v69;
      }
      v6 = *(UFG::allocator::free_link **)&result.mW;
      goto LABEL_53;
    }
LABEL_30:
    vecDelDtor = 0i64;
    goto LABEL_31;
  }
LABEL_82:
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, LayoutFlag_FillLastCell);
  UFG::DUIContext::Checkbox(v2, "Hide Unassigned Properties", &v3->mHideUnassigned);
  UFG::DUIContext::BeginScrollView(v2, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v3->mScrollPosition);
  UFG::DUIContext::BeginVerticalLayout(v2);
  if ( LODWORD(mpSelection[3].mNext)
    && (unsigned __int8)UFG::DUIContext::Collapsible(v2, "World Transform", &v3->mWorldTransformExpanded) )
  {
    UFG::DUIContext::BeginIndent(v2);
    v41 = (UFG::Editor::DAGPath *)mpSelection[4].mPrev;
    symbol = &interfaceName;
    interfaceName.mUID = v41->mInterfaceName.mUID;
    Interface = UFG::Editor::DAGPath::GetInterface(v41, 0x6F1FDCF3u, &interfaceName);
    if ( Interface )
    {
      v43 = (__int64)Interface->vfptr->Gizmo(Interface);
      if ( v41->mSubElements.size )
        p = v41->mSubElements.p;
      else
        p = &UFG::Editor::DAGPath::sEmtpyString;
      (*(void (__fastcall **)(__int64, char *, UFG::qMatrix44 *))(*(_QWORD *)v43 + 8i64))(v43, p->mData, &affine);
      UFG::DUIContext::Label(v2, "Position");
      val = affine.v3.x;
      y = affine.v3.y;
      z = affine.v3.z;
      v45 = 0;
      UFG::DUIContext::BeginGridLayout(v2, 3, 1, 0i64, 0i64, LayoutFlag_None);
      v46 = UFG::DUIContext::NumericTextBox(v2, "x: ", &val, 0, 0.079999998);
      v47 = UFG::DUIContext::NumericTextBox(v2, "y: ", &y, 0, 0.079999998) || v46;
      v48 = UFG::DUIContext::NumericTextBox(v2, "z: ", &z, 0, 0.079999998) || v47;
      UFG::DUIContext::EndLayoutHorizontal(v2);
      UFG::DUIContext::Label(v2, "Rotation");
      soln = UFG::qVector3::msZero;
      UFG::Editor::Utility::DecomposeAffineEulerSmart_RoundedDegrees(&soln, &affine, 1);
      UFG::DUIContext::BeginGridLayout(v2, 3, 1, 0i64, 0i64, LayoutFlag_None);
      v49 = UFG::DUIContext::NumericTextBox(v2, "x: ", &soln.x, 0, 0.079999998) || v48;
      v50 = UFG::DUIContext::NumericTextBox(v2, "y: ", &soln.y, 0, 0.079999998) || v49;
      v51 = UFG::DUIContext::NumericTextBox(v2, "z: ", &soln.z, 0, 0.079999998) || v50;
      UFG::DUIContext::EndLayoutHorizontal(v2);
      if ( v51 )
      {
        soln.x = (float)(soln.x * 3.1415927) * 0.0055555557;
        soln.y = (float)(soln.y * 3.1415927) * 0.0055555557;
        soln.z = (float)(soln.z * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixEuler(&rot, &soln);
        rot.v3.x = val;
        rot.v3.y = y;
        rot.v3.z = z;
        LODWORD(rot.v3.w) = (_DWORD)FLOAT_1_0;
        v52 = (__int64)v69;
        if ( LODWORD(v69[3].mNext) )
        {
          symbol = &interfaceName;
          do
          {
            interfaceName.mUID = v41->mInterfaceName.mUID;
            v53 = UFG::Editor::DAGPath::GetInterface(v41, 0x6F1FDCF3u, &interfaceName);
            if ( v53 )
            {
              v54 = (__int64)v53->vfptr->Gizmo(v53);
              SubElement = UFG::Editor::DAGPath::GetSubElement(v41);
              (*(void (__fastcall **)(__int64, char *, UFG::qMatrix44 *))(*(_QWORD *)v54 + 16i64))(
                v54,
                SubElement->mData,
                &rot);
            }
            ++v45;
          }
          while ( v45 < *(_DWORD *)(v52 + 56) );
        }
        v56 = UFG::Editor::mGizmo;
        v57 = UFG::Editor::Gizmo::DetermineTransform(UFG::Editor::mGizmo, &v75);
        v58 = v57->v1;
        v59 = v57->v2;
        v60 = v57->v3;
        v56->mTransform.v0 = v57->v0;
        v56->mTransform.v1 = v58;
        v56->mTransform.v2 = v59;
        v56->mTransform.v3 = v60;
      }
      v3 = this;
    }
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (_DWORD)v62 )
    v3->mTopLevelProperties.vfptr->UpdateUI(
      &v3->mTopLevelProperties,
      v3,
      v2,
      (UFG::qArray<UFG::qPropertySet *,0> *)&v62,
      &v70);
  UFG::Editor::PropertyBrowser::UpdateUI(v3, v2, (UFG::qArray<UFG::Editor::PropertyBrowser::SimObjectEd *,0> *)&result);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( v6 )
    operator delete[](v6);
  *(_QWORD *)&result.mW = 0i64;
  *(_QWORD *)&result.mX = 0i64;
  if ( mem )
    operator delete[](mem);
  mem = 0i64;
  v62 = 0i64;
  if ( v70.mPath.p )
    operator delete[](v70.mPath.p);
}

// File Line: 1939
// RVA: 0x21B7A0
void __fastcall UFG::Editor::PropertyBrowser::UpdateUI(
        UFG::Editor::PropertyBrowser *this,
        UFG::DUIContext *dui,
        UFG::qArray<UFG::Editor::PropertyBrowser::SimObjectEd *,0> *objects)
{
  __int64 v5; // r14
  UFG::Editor::PropertyBrowser::SimObjectEd *v6; // rsi
  char *v7; // rax
  unsigned int i; // ebx
  UFG::SimComponent *m_pComponent; // rdi
  const char *v10; // rax
  unsigned __int16 m_Flags; // di
  UFG::qString v12; // [rsp+28h] [rbp-40h] BYREF

  if ( objects->size )
  {
    v5 = 0i64;
    do
    {
      v6 = objects->p[v5];
      if ( v6 )
      {
        v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6->m_Name);
        if ( v7 )
          UFG::DUIContext::Label(dui, v7);
        UFG::DUIContext::BeginIndent(dui);
        for ( i = 0; i < v6->m_Components.size; ++i )
        {
          m_pComponent = v6->m_Components.p[i].m_pComponent;
          if ( m_pComponent )
          {
            v10 = (const char *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[1].__vecDelDtor)(m_pComponent);
            if ( v10 )
            {
              m_Flags = m_pComponent->m_Flags;
              UFG::qString::qString(&v12, v10);
              if ( (m_Flags & 2) != 0 )
                UFG::qString::operator+=(&v12, ":skip_update");
              if ( (m_Flags & 0x10) != 0 )
                UFG::qString::operator+=(&v12, ":detaching");
              UFG::DUIContext::Label(dui, v12.mData);
              UFG::qString::~qString(&v12);
            }
          }
        }
        UFG::DUIContext::EndIndent(dui);
      }
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < objects->size );
  }
}

// File Line: 2000
// RVA: 0x204DC0
void __fastcall UFG::Editor::PropertyBrowser::AddPendingValueChange(
        UFG::Editor::PropertyBrowser *this,
        UFG::qPropertyPath *path,
        UFG::Editor::VectoredValue *value)
{
  UFG::qPropertyPath *p_mPath; // rcx

  this->mPendingValueChange.mType = AMD;
  p_mPath = &this->mPendingValueChange.mPath;
  *(UFG::Editor::VectoredValue *)&p_mPath[1].mPath.capacity = *value;
  UFG::qPropertyPath::operator=(p_mPath, path);
}

// File Line: 2021
// RVA: 0x20D6D0
void __fastcall UFG::Editor::PropertyBrowserWindow::Init(UFG::Editor::PropertyBrowserWindow *this)
{
  __int64 v2; // r8
  UFG::qString *v3; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  v2 = (unsigned int)nextSelSetIdx--;
  v3 = UFG::qString::FormatEx(&result, "PropertyBrowser(%x)", v2);
  UFG::qString::Set(&this->mLockedSelection, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::qString::Set(&this->mTitle, UFG::Editor::PropertyBrowserWindow::mTitle);
  UFG::qString::Set(&this->mDefaultSelection, "LastSelection");
  UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mLockedSelection.mData);
  this->mBrowser.mpSelection = UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mDefaultSelection.mData);
  this->mBrowser.mbDirty = 1;
  this->mLockSelection = 0;
}

// File Line: 2033
// RVA: 0x21C160
void __fastcall UFG::Editor::PropertyBrowserWindow::UpdateUI(
        UFG::Editor::PropertyBrowserWindow *this,
        UFG::DUIContext *dui)
{
  UFG::Editor::SelectionSet *mpSelection; // rdx
  bool current_value; // [rsp+30h] [rbp+8h] BYREF

  UFG::DUIContext::BeginGridLayout(dui, 1, 2, LayoutFlag_FillLastCell);
  current_value = this->mLockSelection;
  UFG::DUIContext::Checkbox(dui, "Lock Selection", &current_value);
  if ( current_value != this->mLockSelection )
    UFG::Editor::PropertyBrowserWindow::LockSelection(this, current_value);
  mpSelection = this->mBrowser.mpSelection;
  if ( !mpSelection )
    mpSelection = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  UFG::Editor::PropertyBrowserWindow::RefreshTitle(this, mpSelection);
  UFG::Editor::PropertyBrowser::UpdateUI(&this->mBrowser, dui);
  UFG::DUIContext::EndLayoutHorizontal(dui);
}

// File Line: 2050
// RVA: 0x2109D0
void __fastcall UFG::Editor::PropertyBrowserWindow::RefreshTitle(
        UFG::Editor::PropertyBrowserWindow *this,
        UFG::Editor::SelectionSet *set)
{
  __int64 size; // r8
  UFG::Editor::DAGPath *p; // r8
  unsigned int v5; // eax
  char *v6; // rax
  UFG::qString *p_mTitle; // rcx
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  size = set->mDAGPaths.size;
  if ( (_DWORD)size == 1 )
  {
    p = set->mDAGPaths.p;
    v5 = p->mElements.size;
    if ( v5 )
    {
      v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&p->mElements.p[v5 - 1]);
      if ( v6 )
      {
        UFG::qString::FormatEx(&result, "%s - Inspector", v6);
        UFG::qString::Set(&this->mTitle, result.mData);
        UFG::qString::~qString(&result);
        return;
      }
    }
    p_mTitle = &this->mTitle;
  }
  else
  {
    if ( (unsigned int)size > 1 )
    {
      UFG::qString::FormatEx(&result, "%d Objects - Inspector", size);
      UFG::qString::Set(&this->mTitle, result.mData);
      UFG::qString::~qString(&result);
      return;
    }
    p_mTitle = &this->mTitle;
  }
  UFG::qString::Set(p_mTitle, "Object Inspector");
}

// File Line: 2097
// RVA: 0x20DED0
void __fastcall UFG::Editor::PropertyBrowserWindow::LockSelection(
        UFG::Editor::PropertyBrowserWindow *this,
        bool locked)
{
  UFG::Editor::SelectionSet *SelectionSet; // rax
  UFG::Editor::SelectionSet *v4; // rbx
  UFG::Editor::SelectionSet *v5; // rax

  if ( this->mLockSelection )
  {
    if ( !locked )
    {
      SelectionSet = UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mDefaultSelection.mData);
      this->mBrowser.mbDirty = 1;
      this->mBrowser.mpSelection = SelectionSet;
      this->mLockSelection = 0;
    }
  }
  else if ( locked )
  {
    v4 = UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mLockedSelection.mData);
    v4->mDAGPaths.size = 0;
    UFG::Editor::SelectionSet::DispatchChangedEvent(v4);
    v5 = UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mDefaultSelection.mData);
    UFG::Editor::SelectionSet::Add(v4, v5);
    this->mBrowser.mpSelection = v4;
    this->mBrowser.mbDirty = 1;
    this->mLockSelection = 1;
  }
}

