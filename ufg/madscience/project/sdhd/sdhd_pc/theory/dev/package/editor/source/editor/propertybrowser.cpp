// File Line: 26
// RVA: 0x146D340
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::PropertyBrowserWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::PropertyBrowserWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::PropertyBrowserWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::PropertyBrowserWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::PropertyBrowserWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::PropertyBrowserWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 44
// RVA: 0x146DA50
__int64 UFG::Editor::_dynamic_initializer_for__gPropertyChangedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::Editor::gPropertyChangedChannel, 0x9670AC65, 0i64, 0i64);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gPropertyChangedChannel__);
}

// File Line: 49
// RVA: 0x146D8B0
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_PropertyBrowser_ControlOverrides__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PropertyBrowser_ControlOverrides", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_PropertyBrowser_ControlOverrides, v0);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__Symbol_PropertyBrowser_ControlOverrides__);
}

// File Line: 50
// RVA: 0x146D7F0
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_ControlOverride_Control__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ControlOverride_Control", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_ControlOverride_Control, v0);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__Symbol_ControlOverride_Control__);
}

// File Line: 51
// RVA: 0x146D830
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_ControlOverride_EnumValues__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ControlOverride_EnumValues", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_ControlOverride_EnumValues, v0);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__Symbol_ControlOverride_EnumValues__);
}

// File Line: 53
// RVA: 0x146D7B0
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_ColourPicker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ColourPicker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_ColourPicker, v0);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__Symbol_ColourPicker__);
}

// File Line: 54
// RVA: 0x146D870
__int64 UFG::Editor::_dynamic_initializer_for__Symbol_Enum__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Enum", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Symbol_Enum, v0);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__Symbol_Enum__);
}

// File Line: 57
// RVA: 0x20B720
UFG::qSymbol *__fastcall UFG::Editor::GetControlOverride(UFG::qSymbol *result, UFG::qSymbol *propertySymbol, UFG::qPropertySet **out_controlOverride)
{
  UFG::qPropertySet **v3; // rbp
  UFG::qSymbol *v4; // r15
  UFG::qSymbol *v5; // r14
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rsi
  unsigned int v10; // edi
  unsigned int v11; // ebx
  char *v12; // rax
  UFG::qPropertySet *v13; // rcx
  UFG::qSymbol *v14; // rax
  UFG::qSymbol *v15; // rcx
  unsigned int v16; // eax
  UFG::qSymbol resulta; // [rsp+68h] [rbp+20h]

  v3 = out_controlOverride;
  v4 = propertySymbol;
  v5 = result;
  if ( _S23 & 1 )
  {
    v7 = config;
  }
  else
  {
    _S23 |= 1u;
    v6 = UFG::qSymbol::create_from_string(&resulta, "config-PropertyBrowser");
    v7 = UFG::PropertySetManager::FindPropertySet(v6);
    config = v7;
  }
  if ( v7
    && (v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
               v7,
               (UFG::qSymbol *)&Symbol_PropertyBrowser_ControlOverrides.mUID,
               DEPTH_RECURSE),
        (v9 = v8) != 0i64)
    && (v10 = v8->mNumElements, v11 = 0, v10) )
  {
    while ( 1 )
    {
      v12 = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
      if ( v12 && *(_QWORD *)v12 )
        v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12];
      else
        v13 = 0i64;
      if ( v13->mName.mUID == v4->mUID )
        break;
      if ( ++v11 >= v10 )
        goto LABEL_19;
    }
    if ( v3 )
      *v3 = v13;
    v14 = UFG::qPropertySet::Get<UFG::qSymbol>(v13, (UFG::qSymbol *)&Symbol_ControlOverride_Control.mUID, DEPTH_RECURSE);
    v15 = &UFG::gNullQSymbol;
    if ( v14 )
      v15 = v14;
    v16 = v15->mUID;
  }
  else
  {
LABEL_19:
    v16 = UFG::gNullQSymbol.mUID;
  }
  v5->mUID = v16;
  return v5;
}

// File Line: 124
// RVA: 0x2127C0
void __fastcall UFG::Editor::VectoredValue::Set(UFG::Editor::VectoredValue *this, UFG::qMatrix44 *m)
{
  float v2; // xmm0_4
  UFG::qMatrix44 *v3; // rdi
  float v4; // xmm1_4
  UFG::Editor::VectoredValue *v5; // rbx
  float v6; // xmm0_4
  bool v7; // zf
  float v8; // xmm1_4
  float v9; // xmm0_4
  char v10; // al
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  __m128 v14; // xmm3
  float v15; // xmm5_4
  __m128 v16; // xmm3
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  __m128 v21; // xmm3
  UFG::qVector3 soln; // [rsp+20h] [rbp-18h]

  v2 = m->v3.x;
  this->mbValid[0] = 1;
  v3 = m;
  this->mValue[0] = v2;
  v4 = m->v3.y;
  this->mbValid[1] = 1;
  v5 = this;
  this->mValue[1] = v4;
  v6 = m->v3.z;
  this->mbValid[2] = 1;
  this->mValue[2] = v6;
  v7 = this->mbValid[3] == 0;
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
  *(_WORD *)&v5->mbValid[3] = 257;
  v11 = soln.x;
  v12 = soln.y;
  v5->mbGimbalLock = v10;
  v5->mValue[3] = v11;
  v13 = soln.z;
  v5->mValue[4] = v12;
  v5->mbValid[5] = 1;
  v5->mValue[5] = v13;
  v14 = (__m128)LODWORD(v3->v0.x);
  v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v3->v0.y * v3->v0.y))
                          + (float)(v3->v0.z * v3->v0.z))
                  + (float)(v3->v0.w * v3->v0.w);
  LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v14);
  v16 = (__m128)LODWORD(v3->v1.x);
  v17 = v3->v2.y * v3->v2.y;
  v18 = v3->v2.z * v3->v2.z;
  v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v3->v1.y * v3->v1.y))
                          + (float)(v3->v1.z * v3->v1.z))
                  + (float)(v3->v1.w * v3->v1.w);
  v19 = v3->v2.w * v3->v2.w;
  LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v16);
  v21 = (__m128)LODWORD(v3->v2.x);
  *(_WORD *)&v5->mbValid[6] = 257;
  v5->mValue[6] = v15;
  v5->mValue[7] = v20;
  v5->mbValid[8] = 1;
  v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + v17) + v18) + v19;
  LODWORD(v5->mValue[8]) = (unsigned __int128)_mm_sqrt_ps(v21);
  v5->mElementCount = 9;
}

// File Line: 227
// RVA: 0x2023B0
void __fastcall UFG::Editor::PropertyProxy_PropertySet::PropertyProxy_PropertySet(UFG::Editor::PropertyProxy_PropertySet *this, UFG::qSymbol *propertyName, int arrayIndex)
{
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v3; // rax
  UFG::Editor::PropertyProxyCollection *v4; // [rsp+48h] [rbp+10h]

  v3 = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  this->mDataType = 26;
  this->mPropertyName = (UFG::qSymbol)propertyName->mUID;
  this->mArrayIndex = arrayIndex;
  this->mParent = 0i64;
  *(_WORD *)&this->mIsLocal = 0;
  this->mIsListProperty = 0;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_Container::`vftable;
  v4 = &this->mChildren;
  v4->mChildrenOrdered.mNode.mPrev = &v4->mChildrenOrdered.mNode;
  v4->mChildrenOrdered.mNode.mNext = &v4->mChildrenOrdered.mNode;
  this->mHasGenerantedChildren = 0;
  this->mSelectedTypeOption = 0;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::qString(&this->mNewPropertyName);
}

// File Line: 250
// RVA: 0x213C80
void __fastcall UFG::Editor::PropertyProxySimple::TryGenerateSuggestions(UFG::Editor::PropertyProxySimple *this)
{
  UFG::Editor::PropertyProxySimple *v1; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v3; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rcx
  const char **v6; // rcx

  v1 = this;
  if ( !this->mbSuggestionsGenerated )
  {
    v2 = this->mSuggestionList.mNode.mNext;
    v3 = &this->mSuggestionList;
    if ( v2 != (UFG::qNode<UFG::qString,UFG::qString> *)&this->mSuggestionList )
    {
      do
      {
        v4 = v2->mPrev;
        v5 = v2->mNext;
        v4->mNext = v5;
        v5->mPrev = v4;
        v2->mPrev = v2;
        v2->mNext = v2;
        v2 = v3->mNode.mNext;
      }
      while ( v2 != (UFG::qNode<UFG::qString,UFG::qString> *)v3 );
    }
    v6 = v1->mSuggestions.p;
    if ( v6 )
      operator delete[](v6);
    v1->mSuggestions.p = 0i64;
    *(_QWORD *)&v1->mSuggestions.size = 0i64;
    v1->mbSuggestionsGenerated = 1;
  }
}

// File Line: 268
// RVA: 0x2135A0
void __fastcall UFG::Editor::PropertyProxySimple::Setup(UFG::Editor::PropertyProxySimple *this, UFG::qArray<UFG::qPropertySet *,0> *propertySets)
{
  UFG::qArray<UFG::qPropertySet *,0> *v2; // rbx
  UFG::Editor::PropertyProxySimple *v3; // rdi
  qPropertySetVariant value; // [rsp+30h] [rbp-C8h]

  v2 = propertySets;
  v3 = this;
  value.meType = 29;
  UFG::qString::qString(&value.mValueString);
  *(_QWORD *)&value.mValueSymbol.mUID = -1i64;
  value.mValueWiseSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  if ( UFG::Editor::GetCommonValue(v2, &v3->mPropertyName, &value) )
    qPropertySetVariant::ToString(&value, &v3->mValueString);
  _((AMD_HD3D *)value.mValueWiseSymbol.mUID);
  UFG::qString::~qString(&value.mValueString);
}

// File Line: 277
// RVA: 0x213500
void __fastcall UFG::Editor::PropertyProxySimple::Setup(UFG::Editor::PropertyProxySimple *this, UFG::qArray<UFG::qPropertyList *,0> *propertyLists)
{
  UFG::Editor::PropertyProxySimple *v2; // rdi
  UFG::qPropertyList *v3; // rbx
  qPropertySetVariant value; // [rsp+30h] [rbp-C8h]

  v2 = this;
  v3 = *propertyLists->p;
  value.meType = 29;
  UFG::qString::qString(&value.mValueString);
  *(_QWORD *)&value.mValueSymbol.mUID = -1i64;
  value.mValueWiseSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  UFG::qPropertyList::GetVariant(v3, v2->mArrayIndex, &value);
  qPropertySetVariant::ToString(&value, &v2->mValueString);
  _((AMD_HD3D *)value.mValueWiseSymbol.mUID);
  UFG::qString::~qString(&value.mValueString);
}

// File Line: 289
// RVA: 0x214840
void __fastcall UFG::Editor::PropertyProxySimple::UpdateCommon(UFG::Editor::PropertyProxySimple *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qPropertyPath *currentPath)
{
  UFG::qPropertyPath *v4; // rdi
  UFG::DUIContext *v5; // r14
  UFG::Editor::PropertyBrowser *v6; // r13
  UFG::Editor::PropertyProxySimple *v7; // rsi
  const char **v8; // r15
  UFG::qBaseTreeRB *v9; // rbx
  unsigned int v10; // eax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v11; // rbx
  UFG::qPropertyList *v12; // rax
  unsigned int v13; // edi
  UFG::qPropertyList *v14; // r13
  UFG::qString *v15; // r12
  char *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  unsigned int v20; // eax
  UFG::qBaseTreeRB *v21; // rdi
  unsigned int v22; // eax
  UFG::qBaseTreeRB *v23; // rbx
  int v24; // edi
  char v25; // bl
  char v26; // al
  bool v27; // bl
  unsigned int v28; // ebx
  UFG::qPropertySet *out_controlOverride; // [rsp+30h] [rbp-98h]
  qPropertySetVariant other; // [rsp+40h] [rbp-88h]
  UFG::qSymbol result; // [rsp+148h] [rbp+80h]
  UFG::Editor::PropertyBrowser *v32; // [rsp+150h] [rbp+88h]
  UFG::qPropertyPath *v33; // [rsp+160h] [rbp+98h]
  char *name; // [rsp+168h] [rbp+A0h]

  *(_QWORD *)&other.mValueWiseSymbol.mUID = -2i64;
  v4 = currentPath;
  v5 = dui;
  v6 = browser;
  v7 = this;
  v8 = 0i64;
  v9 = 0i64;
  if ( this->mIsSchemaProperty )
    v9 = UFG::PropertyMetadataDatabase::Get(&this->mPropertyName);
  out_controlOverride = 0i64;
  UFG::Editor::GetControlOverride(&result, &v7->mPropertyName, &out_controlOverride);
  if ( result.mUID == Symbol_Enum.mUID )
  {
    v10 = v7->mDataType;
    if ( v10 <= 3 || v10 - 5 <= 3 )
    {
      UFG::DUIContext::BeginGridLayout(v5, 2, 1, v6->mColWidths, 0i64, 11);
      if ( !v7->mIsLocal )
        UFG::DUIContext::PushColour(v5, 0, &UFG::qColour::Grey);
      UFG::DUIContext::Label(v5, name);
      if ( !v7->mIsLocal )
        UFG::DUIContext::PopColour(v5, 0);
      v11 = &v7->mSuggestionList;
      if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v7->mSuggestionList.mNode.mNext == &v7->mSuggestionList )
      {
        v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                out_controlOverride,
                (UFG::qSymbol *)&Symbol_ControlOverride_EnumValues.mUID,
                DEPTH_RECURSE);
        v13 = 0;
        if ( v12->mNumElements > 0 )
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
            v19 = v11->mNode.mPrev;
            v19->mNext = v18;
            v18->mPrev = v19;
            v18->mNext = &v11->mNode;
            v11->mNode.mPrev = v18;
            ++v13;
          }
          while ( v13 < v14->mNumElements );
          v6 = v32;
        }
        v4 = v33;
      }
      result.mUID = UFG::qToInt32(v7->mValueString.mData, 0);
      if ( UFG::DUIContext::ComboBox(v5, (int *)&result, &v7->mSuggestionList, 0i64, 0xFFFFFFFF) )
      {
        UFG::qString::FormatEx(&other.mValueString, "%d", result.mUID);
        other.meType = 29;
        UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
        other.mValueMatrix44.v3.w = -6.8056469e38/*NaN*/;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        qPropertySetVariant::SetFromString(&other, &other.mValueString, v7->mDataType);
        v6->mPendingValueChange.mType = 1;
        qPropertySetVariant::operator=(&v6->mPendingValueChange.mSimpleValue, &other);
        UFG::qPropertyPath::operator=(&v6->mPendingValueChange.mPath, v4);
        _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
        UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        UFG::qString::~qString(&other.mValueString);
      }
      goto LABEL_56;
    }
  }
  UFG::DUIContext::BeginGridLayout(v5, 2, 1, v6->mColWidths, 0i64, 11);
  if ( !v7->mIsLocal )
    UFG::DUIContext::PushColour(v5, 0, &UFG::qColour::Grey);
  UFG::DUIContext::Label(v5, name);
  if ( !v7->mIsLocal )
    UFG::DUIContext::PopColour(v5, 0);
  if ( (unsigned int)(v7->mDataType - 22) <= 2 )
    UFG::Editor::PropertyProxySimple::TryGenerateSuggestions(v7);
  if ( v9 )
  {
    v20 = UFG::qStringHashUpper32("min", 0xFFFFFFFF);
    if ( v20 )
      v21 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v9 + 32), v20);
    else
      v21 = 0i64;
    v22 = UFG::qStringHashUpper32("max", 0xFFFFFFFF);
    if ( v22 )
      v23 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v9 + 32), v22);
    else
      v23 = 0i64;
    if ( v21 && v23 )
    {
      v24 = UFG::qToInt32(*(const char **)&v21[1].mRoot.mUID, 0);
      UFG::qToInt32(*(const char **)&v23[1].mRoot.mUID, 0);
      result.mUID = UFG::qToInt32(v7->mValueString.mData, 0);
      if ( (unsigned __int8)UFG::DUIContext::Slider(v5, &customWorldMapCaption, (int *)&result, v24) )
      {
        UFG::qString::FormatEx(&other.mValueString, "%d", result.mUID);
        other.meType = 29;
        UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
        other.mValueMatrix44.v3.w = -6.8056469e38/*NaN*/;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        qPropertySetVariant::SetFromString(&other, &other.mValueString, v7->mDataType);
        v6->mPendingValueChange.mType = 1;
        qPropertySetVariant::operator=(&v6->mPendingValueChange.mSimpleValue, &other);
        UFG::qPropertyPath::operator=(&v6->mPendingValueChange.mPath, v33);
        _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
        UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        UFG::qString::~qString(&other.mValueString);
      }
      goto LABEL_56;
    }
    v4 = v33;
  }
  switch ( v7->mDataType )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0x16:
    case 0x17:
    case 0x18:
      if ( v7->mPropertyName.mUID == UFG::Editor::gsymCreateObjectFlags.mUID )
      {
        UFG::DUIContext::BeginGridLayout(v5, 0, 1, 0i64, 0i64, 0);
        v28 = UFG::qToUInt32(v7->mValueString.mData, 0);
        result.mUID = v28;
        UFG::DUIContext::Checkbox(v5, "Immediate", &result.mUID, 1u);
        UFG::DUIContext::Checkbox(v5, "Delayed", &result.mUID, 2u);
        UFG::DUIContext::Checkbox(v5, "Deferred Deact.", &result.mUID, 4u);
        if ( result.mUID != v28 )
        {
          UFG::qString::FormatEx(&other.mValueString, "%d");
          other.meType = 29;
          UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
          *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
          other.mValueMatrix44.v3.w = -6.8056469e38/*NaN*/;
          _((AMD_HD3D *)0xFFFFFFFFi64);
          qPropertySetVariant::SetFromString(&other, &other.mValueString, v7->mDataType);
          v6->mPendingValueChange.mType = 1;
          qPropertySetVariant::operator=(&v6->mPendingValueChange.mSimpleValue, &other);
          UFG::qPropertyPath::operator=(&v6->mPendingValueChange.mPath, v4);
          _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
          UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
          UFG::qString::~qString(&other.mValueString);
        }
        UFG::DUIContext::EndLayoutHorizontal(v5);
      }
      else
      {
        v26 = v5->mInputState.mKeycodeDown;
        v27 = v26 == 13 || v26 == 94;
        if ( v7->mSuggestions.size )
          v8 = v7->mSuggestions.p;
        UFG::DUIContext::TextBox(v5, &v7->mValueString, 0i64, 1, v8, v7->mSuggestions.size);
        if ( v5->mControlLostFocus || v5->mFocusedID == v5->mCurrentID && v27 )
        {
          other.meType = 29;
          UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
          *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
          other.mValueMatrix44.v3.w = -6.8056469e38/*NaN*/;
          _((AMD_HD3D *)0xFFFFFFFFi64);
          qPropertySetVariant::SetFromString(&other, &v7->mValueString, v7->mDataType);
          v6->mPendingValueChange.mType = 1;
          qPropertySetVariant::operator=(&v6->mPendingValueChange.mSimpleValue, &other);
          UFG::qPropertyPath::operator=(&v6->mPendingValueChange.mPath, v33);
          _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
          UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        }
      }
      break;
    case 9:
      v25 = UFG::qToBool(v7->mValueString.mData, 0);
      LOBYTE(result.mUID) = v25;
      UFG::DUIContext::Checkbox(v5, &customWorldMapCaption, (bool *)&result);
      if ( v25 != LOBYTE(result.mUID) )
      {
        other.meType = 29;
        UFG::qString::qString((UFG::qString *)&other.mValueMatrix44.v0.w);
        *(_QWORD *)&other.mValueMatrix44.v3.y = -1i64;
        other.mValueMatrix44.v3.w = -6.8056469e38/*NaN*/;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        other.mValueI8 = result.mUID;
        other.meType = 9;
        v6->mPendingValueChange.mType = 1;
        qPropertySetVariant::operator=(&v6->mPendingValueChange.mSimpleValue, &other);
        UFG::qPropertyPath::operator=(&v6->mPendingValueChange.mPath, v4);
        _((AMD_HD3D *)LODWORD(other.mValueMatrix44.v3.w));
        UFG::qString::~qString((UFG::qString *)&other.mValueMatrix44.v0.w);
      }
      break;
    default:
      break;
  }
LABEL_56:
  UFG::DUIContext::EndLayoutHorizontal(v5);
}

// File Line: 474
// RVA: 0x21C200
void __fastcall UFG::Editor::PropertyProxySimple::UpdateUI(UFG::Editor::PropertyProxySimple *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qArray<UFG::qPropertyList *,0> *selection, UFG::qPropertyPath *currentPath)
{
  UFG::DUIContext *v5; // rbx
  UFG::Editor::PropertyBrowser *v6; // rdi
  UFG::Editor::PropertyProxySimple *v7; // rsi
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v5 = dui;
  v6 = browser;
  v7 = this;
  UFG::qString::FormatEx(&result, "[%d]", (unsigned int)this->mArrayIndex, selection);
  UFG::Editor::PropertyProxySimple::UpdateCommon(v7, v6, v5, currentPath);
  UFG::qString::~qString(&result);
}

// File Line: 480
// RVA: 0x21C280
void __fastcall UFG::Editor::PropertyProxySimple::UpdateUI(UFG::Editor::PropertyProxySimple *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qArray<UFG::qPropertySet *,0> *selection, UFG::qPropertyPath *currentPath)
{
  UFG::Editor::PropertyProxySimple *v5; // rsi
  UFG::DUIContext *v6; // rbx
  UFG::Editor::PropertyBrowser *v7; // rdi

  v5 = this;
  v6 = dui;
  v7 = browser;
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  UFG::Editor::PropertyProxySimple::UpdateCommon(v5, v7, v6, currentPath);
}

// File Line: 485
// RVA: 0x20CE10
char __fastcall UFG::Editor::GetVectorValue(UFG::qPropertySet *propertySet, UFG::qSymbol *name, UFG::Editor::VectoredValue *value)
{
  UFG::qPropertySet *v3; // rsi
  UFG::Editor::VectoredValue *v4; // rbx
  _DWORD *v5; // r8
  UFG::qSymbol *v6; // rdi
  signed __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // eax
  int v10; // eax
  UFG::qMatrix44 *v12; // rax
  UFG::qVector4 *v13; // rax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::qVector3 *v18; // rax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  UFG::qVector2 *v22; // rax
  float v23; // xmm0_4
  float v24; // xmm1_4

  v3 = propertySet;
  v4 = value;
  value->mElementCount = 0;
  v5 = (_DWORD *)value->mValue;
  v6 = name;
  v7 = 0i64;
  do
  {
    v4->mbValid[v7++] = 0;
    *v5 = 0;
    ++v5;
  }
  while ( v7 < 16 );
  v4->mbGimbalLock = 0;
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
        v12 = UFG::qPropertySet::Get<UFG::qMatrix44>(v3, v6, DEPTH_RECURSE);
        UFG::Editor::VectoredValue::Set(v4, v12);
      }
      else
      {
        v13 = UFG::qPropertySet::Get<UFG::qVector4>(v3, v6, DEPTH_RECURSE);
        v14 = v13->x;
        v4->mbValid[0] = 1;
        v4->mValue[0] = v14;
        v15 = v13->y;
        v4->mbValid[1] = 1;
        v4->mValue[1] = v15;
        v16 = v13->z;
        v4->mbValid[2] = 1;
        v4->mValue[2] = v16;
        v17 = v13->w;
        v4->mbValid[3] = 1;
        v4->mValue[3] = v17;
        v4->mElementCount = 4;
      }
    }
    else
    {
      v18 = UFG::qPropertySet::Get<UFG::qVector3>(v3, v6, DEPTH_RECURSE);
      v19 = v18->x;
      v4->mbValid[0] = 1;
      v4->mValue[0] = v19;
      v20 = v18->y;
      v4->mbValid[1] = 1;
      v4->mValue[1] = v20;
      v21 = v18->z;
      v4->mbValid[2] = 1;
      v4->mValue[2] = v21;
      v4->mElementCount = 3;
    }
  }
  else
  {
    v22 = UFG::qPropertySet::Get<UFG::qVector2>(v3, v6, DEPTH_RECURSE);
    v23 = v22->x;
    v4->mbValid[0] = 1;
    v4->mValue[0] = v23;
    v24 = v22->y;
    v4->mbValid[1] = 1;
    v4->mValue[1] = v24;
    v4->mElementCount = 2;
  }
  return 1;
}

// File Line: 523
// RVA: 0x212F80
char __fastcall UFG::Editor::SetVectorValue(UFG::qPropertySet *propertySet, UFG::qSymbol *name, UFG::Editor::VectoredValue *value)
{
  UFG::Editor::VectoredValue *v3; // rbx
  UFG::qSymbol *v4; // rdi
  UFG::qPropertySet *v5; // rsi
  unsigned int v6; // eax
  int v7; // eax
  int v8; // eax
  UFG::qMatrix44 *v10; // rax
  bool v11; // zf
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
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
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm7
  __m128 v31; // xmm2
  __m128 v32; // xmm8
  __m128 v33; // xmm9
  __m128 v34; // xmm7
  __m128 v35; // xmm8
  UFG::qVector4 *v36; // rax
  float v37; // xmm2_4
  int v38; // xmm3_4
  float v39; // xmm0_4
  UFG::qVector3 *v40; // rax
  float v41; // xmm1_4
  float v42; // xmm2_4
  UFG::qVector2 *v43; // rax
  float v44; // xmm1_4
  UFG::qVector3 soln; // [rsp+20h] [rbp-79h]
  int v46; // [rsp+2Ch] [rbp-6Dh]
  UFG::qMatrix44 affine; // [rsp+30h] [rbp-69h]
  UFG::qMatrix44 rot; // [rsp+70h] [rbp-29h]
  UFG::qVector2 v; // [rsp+118h] [rbp+7Fh]

  v3 = value;
  v4 = name;
  v5 = propertySet;
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
        v10 = UFG::qPropertySet::Get<UFG::qMatrix44>(v5, v4, DEPTH_RECURSE);
        v11 = v3->mbValid[0] == 0;
        v12 = v10->v0.z;
        v13 = v10->v0.w;
        v14 = v10->v0.x;
        affine.v0.y = v10->v0.y;
        affine.v0.z = v12;
        affine.v0.x = v14;
        affine.v0.w = v13;
        v15 = v10->v1.y;
        v16 = v10->v1.z;
        v17 = v10->v1.w;
        affine.v1.x = v10->v1.x;
        affine.v1.y = v15;
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
          affine.v3.x = v3->mValue[0];
        if ( v3->mbValid[1] )
          affine.v3.y = v3->mValue[1];
        if ( v3->mbValid[2] )
          affine.v3.z = v3->mValue[2];
        v11 = v3->mbValid[3] == 0;
        LODWORD(affine.v3.w) = (_DWORD)FLOAT_1_0;
        soln = UFG::qVector3::msZero;
        if ( !v11 && v3->mbValid[4] && v3->mbValid[5] )
        {
          v23 = v3->mValue[4];
          soln.x = v3->mValue[3];
          v24 = v3->mValue[5];
          soln.y = v23;
          soln.z = v24;
        }
        UFG::Editor::Utility::DecomposeAffineEulerSmart_RoundedDegrees(&soln, &affine, 1);
        if ( v3->mbValid[3] )
          v25 = v3->mValue[3];
        else
          v25 = soln.x;
        if ( v3->mbValid[4] )
          v26 = v3->mValue[4];
        else
          v26 = soln.y;
        if ( v3->mbValid[5] )
          v27 = v3->mValue[5];
        else
          v27 = soln.z;
        v28 = (__m128)LODWORD(affine.v0.y);
        v29 = (__m128)LODWORD(affine.v1.y);
        v28.m128_f32[0] = (float)((float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(affine.v0.x * affine.v0.x))
                                + (float)(affine.v0.z * affine.v0.z))
                        + (float)(affine.v0.w * affine.v0.w);
        v30 = _mm_sqrt_ps(v28);
        v31 = (__m128)LODWORD(affine.v2.y);
        v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(affine.v1.x * affine.v1.x))
                                + (float)(affine.v1.z * affine.v1.z))
                        + (float)(affine.v1.w * affine.v1.w);
        v32 = _mm_sqrt_ps(v29);
        v31.m128_f32[0] = (float)((float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(affine.v2.x * affine.v2.x))
                                + (float)(affine.v2.z * affine.v2.z))
                        + (float)(affine.v2.w * affine.v2.w);
        v33 = _mm_sqrt_ps(v31);
        if ( v3->mbValid[6] )
          v30 = (__m128)LODWORD(v3->mValue[6]);
        v34 = _mm_shuffle_ps(v30, v30, 0);
        if ( v3->mbValid[7] )
          v32 = (__m128)LODWORD(v3->mValue[7]);
        v35 = _mm_shuffle_ps(v32, v32, 0);
        if ( v3->mbValid[8] )
          v33 = (__m128)LODWORD(v3->mValue[8]);
        soln.x = (float)(v25 * 3.1415927) * 0.0055555557;
        soln.y = (float)(v26 * 3.1415927) * 0.0055555557;
        soln.z = (float)(v27 * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixEuler(&rot, &soln);
        affine.v0 = (UFG::qVector4)_mm_mul_ps((__m128)rot.v0, v34);
        affine.v1 = (UFG::qVector4)_mm_mul_ps((__m128)rot.v1, v35);
        affine.v2 = (UFG::qVector4)_mm_mul_ps((__m128)rot.v2, _mm_shuffle_ps(v33, v33, 0));
        UFG::qPropertySet::Set<UFG::qMatrix44>(v5, v4, &affine);
      }
      else
      {
        v36 = UFG::qPropertySet::Get<UFG::qVector4>(v5, v4, DEPTH_RECURSE);
        v11 = v3->mbValid[0] == 0;
        v37 = v36->z;
        v38 = LODWORD(v36->w);
        v39 = v36->x;
        soln.y = v36->y;
        soln.z = v37;
        soln.x = v39;
        v46 = v38;
        if ( !v11 )
          soln.x = v3->mValue[0];
        if ( v3->mbValid[1] )
          soln.y = v3->mValue[1];
        if ( v3->mbValid[2] )
          soln.z = v3->mValue[2];
        if ( v3->mbValid[3] )
          v46 = LODWORD(v3->mValue[3]);
        UFG::qPropertySet::Set<UFG::qVector4>(v5, v4, (UFG::qVector4 *)&soln);
      }
    }
    else
    {
      v40 = UFG::qPropertySet::Get<UFG::qVector3>(v5, v4, DEPTH_RECURSE);
      v11 = v3->mbValid[0] == 0;
      v41 = v40->y;
      v42 = v40->z;
      soln.x = v40->x;
      soln.y = v41;
      soln.z = v42;
      if ( !v11 )
        soln.x = v3->mValue[0];
      if ( v3->mbValid[1] )
        soln.y = v3->mValue[1];
      if ( v3->mbValid[2] )
        soln.z = v3->mValue[2];
      UFG::qPropertySet::Set<UFG::qVector3>(v5, v4, &soln);
    }
  }
  else
  {
    v43 = UFG::qPropertySet::Get<UFG::qVector2>(v5, v4, DEPTH_RECURSE);
    v11 = v3->mbValid[0] == 0;
    v44 = v43->y;
    v.x = v43->x;
    v.y = v44;
    if ( !v11 )
      v.x = v3->mValue[0];
    if ( v3->mbValid[1] )
      v.y = v3->mValue[1];
    UFG::qPropertySet::Set<UFG::qVector2>(v5, v4, &v);
  }
  return 1;
}

// File Line: 612
// RVA: 0x213650
void __fastcall UFG::Editor::PropertyProxyVectored::Setup(UFG::Editor::PropertyProxyVectored *this, UFG::qArray<UFG::qPropertySet *,0> *selection)
{
  UFG::qArray<UFG::qPropertySet *,0> *v2; // rsi
  UFG::Editor::VectoredValue *v3; // rbx
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rbp
  UFG::qPropertySet **v6; // rax
  UFG::qPropertySet *v7; // rcx
  signed __int64 v8; // rax
  int v9; // er8
  int v10; // ecx
  __int64 v11; // rdx
  float v12; // eax
  char *v13; // rax
  float *v14; // rcx
  char v15; // dl
  UFG::Editor::VectoredValue value; // [rsp+20h] [rbp-68h]

  v2 = selection;
  v3 = &this->mValues;
  v4 = 0;
  if ( selection->size )
  {
    v5 = &this->mPropertyName;
    do
    {
      v6 = v2->p;
      value.mElementCount = 0;
      v7 = v6[v4];
      v8 = 0i64;
      do
      {
        value.mbValid[v8] = 0;
        value.mValue[v8++] = 0.0;
      }
      while ( v8 < 16 );
      value.mbGimbalLock = 0;
      UFG::Editor::GetVectorValue(v7, v5, &value);
      v9 = 0;
      v3->mbGimbalLock = value.mbGimbalLock;
      if ( v4 )
      {
        if ( v3->mElementCount > 0 )
        {
          v13 = (char *)v3->mbValid;
          v14 = value.mValue;
          do
          {
            if ( *v13 && v13[(char *)&value - (char *)v3] )
            {
              v15 = 1;
              if ( *v14 != *(float *)((char *)v14 + (char *)v3 - (char *)value.mValue + 4) )
                v15 = 0;
              *v13 = v15;
            }
            ++v9;
            ++v14;
            ++v13;
          }
          while ( v9 < v3->mElementCount );
        }
      }
      else
      {
        v10 = value.mElementCount;
        v11 = 0i64;
        v3->mElementCount = value.mElementCount;
        if ( v10 > 0 )
        {
          do
          {
            if ( value.mbValid[v11] )
            {
              v12 = value.mValue[v11];
              v3->mbValid[v11] = 1;
              *(float *)((char *)&value.mValue[v11 + 1] + (char *)v3 - (char *)value.mValue) = v12;
            }
            ++v9;
            ++v11;
          }
          while ( v9 < v3->mElementCount );
        }
      }
      ++v4;
    }
    while ( v4 < v2->size );
  }
}

// File Line: 637
// RVA: 0x214FE0
void __fastcall UFG::Editor::PropertyProxyVectored::UpdateCommon(UFG::Editor::PropertyProxyVectored *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qPropertyPath *currentPath, const char *displayName)
{
  UFG::Editor::PropertyProxyVectored *v5; // r14
  UFG::DUIContext *v6; // rbx
  signed int v7; // er12
  ePropertyType v8; // er8
  signed int v9; // ecx
  UFG::Editor::PropertyBrowser *v10; // r13
  int v11; // er8
  int v12; // er8
  int v13; // er8
  int v14; // er15
  int v15; // edi
  UFG::qSymbol *v16; // rsi
  char *v17; // rax
  const char *v18; // r8
  const char **v19; // rax
  int v20; // esi
  float v21; // xmm1_4
  bool v22; // di
  float v23; // xmm0_4
  signed __int64 v24; // rax
  signed int v25; // eax
  __int64 v26; // r12
  char *v27; // rdx
  int *v28; // rsi
  char v29; // al
  bool v30; // di
  signed __int64 v31; // rax
  int v32; // eax
  __int64 v33; // rcx
  __int128 v34; // xmm0
  __int128 v35; // xmm1
  __int128 v36; // xmm1
  signed int v37; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol result; // [rsp+34h] [rbp-CCh]
  UFG::qColour current_colour_rgb; // [rsp+38h] [rbp-C8h]
  __int64 v40; // [rsp+48h] [rbp-B8h]
  UFG::Editor::VectoredValue value; // [rsp+50h] [rbp-B0h]
  __int64 i; // [rsp+B0h] [rbp-50h]
  const char **v43; // [rsp+B8h] [rbp-48h]
  UFG::DUIRect v44; // [rsp+C0h] [rbp-40h]
  UFG::DUIRect rect; // [rsp+D0h] [rbp-30h]
  char dest; // [rsp+E0h] [rbp-20h]
  unsigned int num_cols; // [rsp+230h] [rbp+130h]
  UFG::qPropertyPath *path; // [rsp+248h] [rbp+148h]

  path = currentPath;
  v5 = this;
  v6 = dui;
  v7 = 0;
  v8 = this->mDataType;
  v9 = 0;
  v10 = browser;
  v37 = 0;
  num_cols = 0;
  v11 = v8 - 17;
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
    v37 = 1;
    goto LABEL_10;
  }
  if ( v13 == 1 )
  {
    v9 = 3;
    v7 = 3;
    v37 = 3;
LABEL_10:
    num_cols = v9;
  }
  v14 = 0;
  v15 = v7 * v9;
  if ( v7 * v9 == 9 && v5->mValues.mbGimbalLock )
  {
    v16 = &v5->mPropertyName;
    v17 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mPropertyName);
    v18 = "%s (G.L.)";
  }
  else
  {
    v16 = &v5->mPropertyName;
    v17 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mPropertyName);
    v18 = "%s";
  }
  UFG::qSPrintf(&dest, 256, v18, v17);
  v19 = vecLabels;
  if ( v15 == 9 )
    v19 = matLabels;
  v43 = v19;
  UFG::Editor::GetControlOverride(&result, v16, 0i64);
  v20 = num_cols;
  if ( result.mUID != Symbol_ColourPicker.mUID || v7 != 1 || num_cols - 3 > 1 )
  {
    UFG::DUIContext::GetLayoutRect(v6, &rect, 0, 0);
    UFG::DUIContext::SetLayoutRect(v6, &rect);
    v25 = 0;
    v26 = 0i64;
    result.mUID = 0;
    for ( i = v15; v25 < v37; result.mUID = v25 )
    {
      if ( v25 )
      {
        UFG::DUIContext::GetLayoutRect(v6, &v44, 0, 0);
        v44.mW = rect.mW;
        UFG::DUIContext::SetLayoutRect(v6, &v44);
      }
      UFG::DUIContext::BeginGridLayout(v6, 2, 1, v10->mColWidths, 0i64, 11);
      if ( !v5->mIsLocal )
        UFG::DUIContext::PushColour(v6, 0, &UFG::qColour::Grey);
      v27 = &dest;
      if ( result.mUID )
        v27 = &customWorldMapCaption;
      UFG::DUIContext::Label(v6, v27);
      if ( !v5->mIsLocal )
        UFG::DUIContext::PopColour(v6, 0);
      UFG::DUIContext::BeginGridLayout(v6, v20, 1, 4);
      if ( v20 > 0 )
      {
        v28 = (int *)&v5->mValues.mValue[v26];
        v40 = num_cols;
        *(_QWORD *)&current_colour_rgb.r = (char *)value.mValue - (char *)v5;
        do
        {
          v29 = v6->mInputState.mKeycodeDown;
          v30 = v29 == 13 || v29 == 94;
          UFG::DUIContext::NumericTextBox(v6, v43[v26], (float *)v5 + v14 + 15i64, 0, 0.20999999);
          if ( i == 9 && v5->mValues.mbGimbalLock && v14 == 5 )
            *v28 = 0;
          if ( v6->mControlLostFocus || v6->mFocusedID == v6->mCurrentID && v30 )
          {
            value.mElementCount = 0;
            v31 = 0i64;
            do
            {
              value.mbValid[v31] = 0;
              value.mValue[v31++] = 0.0;
            }
            while ( v31 < 16 );
            v32 = *v28;
            v33 = *(_QWORD *)&current_colour_rgb.r;
            value.mbGimbalLock = 0;
            value.mbValid[v26] = 1;
            *(int *)((char *)v28 + v33 - 60) = v32;
            v34 = *(_OWORD *)&value.mElementCount;
            v35 = *(_OWORD *)&value.mValue[3];
            v10->mPendingValueChange.mType = 2;
            *(_OWORD *)&v10->mPendingValueChange.mVectoredValue.mElementCount = v34;
            *(_OWORD *)&v10->mPendingValueChange.mVectoredValue.mValue[3] = v35;
            v36 = *(_OWORD *)&value.mValue[11];
            *(_OWORD *)&v10->mPendingValueChange.mVectoredValue.mValue[7] = *(_OWORD *)&value.mValue[7];
            *(_OWORD *)&v10->mPendingValueChange.mVectoredValue.mValue[11] = v36;
            *(_QWORD *)&v36 = *(_QWORD *)&value.mbValid[12];
            *(_OWORD *)&v10->mPendingValueChange.mVectoredValue.mValue[15] = *(_OWORD *)&value.mValue[15];
            *(_QWORD *)&v10->mPendingValueChange.mVectoredValue.mbValid[12] = v36;
            UFG::qPropertyPath::operator=(&v10->mPendingValueChange.mPath, path);
          }
          ++v14;
          ++v26;
          ++v28;
          --v40;
        }
        while ( v40 );
        v20 = num_cols;
      }
      UFG::DUIContext::EndLayoutHorizontal(v6);
      UFG::DUIContext::EndLayoutHorizontal(v6);
      v25 = result.mUID + 1;
    }
  }
  else
  {
    if ( !v5->mIsLocal )
      UFG::DUIContext::PushColour(v6, 0, &UFG::qColour::Grey);
    UFG::DUIContext::Label(v6, &dest);
    if ( !v5->mIsLocal )
      UFG::DUIContext::PopColour(v6, 0);
    v21 = v5->mValues.mValue[1];
    v22 = num_cols == 4;
    current_colour_rgb.r = v5->mValues.mValue[0];
    v23 = v5->mValues.mValue[2];
    current_colour_rgb.g = v21;
    current_colour_rgb.b = v23;
    LODWORD(current_colour_rgb.a) = (_DWORD)FLOAT_1_0;
    if ( num_cols == 4 )
      current_colour_rgb.a = v5->mValues.mValue[3];
    if ( (unsigned __int8)UFG::DUIContext::ColourPicker(v6, &customWorldMapCaption, &current_colour_rgb, v22) )
    {
      value.mElementCount = 0;
      v24 = 0i64;
      do
      {
        value.mbValid[v24] = 0;
        value.mValue[v24++] = 0.0;
      }
      while ( v24 < 16 );
      value.mbGimbalLock = 0;
      *(_WORD *)value.mbValid = 257;
      value.mbValid[2] = 1;
      value.mValue[0] = current_colour_rgb.r;
      value.mValue[1] = current_colour_rgb.g;
      value.mValue[2] = current_colour_rgb.b;
      if ( v22 )
      {
        value.mbValid[3] = 1;
        value.mValue[3] = current_colour_rgb.a;
      }
      UFG::Editor::PropertyBrowser::AddPendingValueChange(v10, path, &value);
    }
  }
}

// File Line: 731
// RVA: 0x21C2D0
void __fastcall UFG::Editor::PropertyProxyVectored::UpdateUI(UFG::Editor::PropertyProxyVectored *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qArray<UFG::qPropertyList *,0> *selection, UFG::qPropertyPath *currentPath)
{
  UFG::DUIContext *v5; // rbx
  UFG::Editor::PropertyBrowser *v6; // rdi
  UFG::Editor::PropertyProxyVectored *v7; // rsi
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v5 = dui;
  v6 = browser;
  v7 = this;
  UFG::qString::FormatEx(&result, "[%d]", (unsigned int)this->mArrayIndex, selection);
  UFG::Editor::PropertyProxyVectored::UpdateCommon(v7, v6, v5, currentPath, result.mData);
  UFG::qString::~qString(&result);
}

// File Line: 737
// RVA: 0x21C350
void __fastcall UFG::Editor::PropertyProxyVectored::UpdateUI(UFG::Editor::PropertyProxyVectored *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qArray<UFG::qPropertySet *,0> *selection, UFG::qPropertyPath *currentPath)
{
  UFG::Editor::PropertyProxyVectored *v5; // rsi
  UFG::DUIContext *v6; // rbx
  UFG::Editor::PropertyBrowser *v7; // rdi
  char *v8; // rax

  v5 = this;
  v6 = dui;
  v7 = browser;
  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  UFG::Editor::PropertyProxyVectored::UpdateCommon(v5, v7, v6, currentPath, v8);
}

// File Line: 771
// RVA: 0x20AE20
void __fastcall UFG::Editor::PropertyProxy_PropertySet::GenerateChildren(UFG::Editor::PropertyProxy_PropertySet *this, UFG::qArray<UFG::qPropertySet *,0> *propertySets, bool localProperty)
{
  char v3; // bl
  UFG::qArray<UFG::qPropertySet *,0> *v4; // r13
  UFG::Editor::PropertyProxyCollection *v5; // rsi
  bool *v6; // rax
  char *v7; // r15
  _QWORD *v8; // rdx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  unsigned int v11; // er12
  bool *v12; // r14
  UFG::Editor::PropertyProxy_PropertySet *v13; // r15
  signed int v14; // edi
  UFG::qPropertySet *v15; // rax
  bool v16; // bp
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rbx
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // ST28_8
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // rax
  signed __int64 v25; // rax
  _DWORD *v26; // rcx
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::allocator::free_link *v29; // ST30_8
  UFG::allocator::free_link *v30; // rcx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v31; // rax
  signed __int64 v32; // rsi
  signed __int64 v33; // rbp
  __int64 *v34; // r14
  signed __int64 v35; // rdi
  int v36; // eax
  char *v37; // rbx
  char *v38; // rax
  __int64 v39; // rdx
  _QWORD *v40; // r9
  __int64 *v41; // r8
  _QWORD *v42; // rax
  __int64 v43; // rcx
  _QWORD *v44; // rax
  _QWORD *v45; // rax
  __int64 v46; // rax
  __int64 *v47; // r14
  signed __int64 v48; // rdi
  int v49; // eax
  char *v50; // rbx
  char *v51; // rax
  _QWORD *v52; // r9
  __int64 v53; // rdx
  __int64 *v54; // r8
  _QWORD *v55; // rax
  __int64 v56; // rcx
  _QWORD *v57; // rax
  __int64 **v58; // rax
  __int64 v59; // rax
  UFG::qArray<UFG::Editor::PropertyInstance,0> shared_property_uids; // [rsp+38h] [rbp-60h]
  UFG::Editor::PropertyProxy_PropertySet *v61; // [rsp+A0h] [rbp+8h]
  bool v62; // [rsp+A0h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+A8h] [rbp+10h]
  bool v64; // [rsp+B0h] [rbp+18h]
  UFG::allocator::free_link *v65; // [rsp+B8h] [rbp+20h]

  v64 = localProperty;
  v61 = this;
  v3 = localProperty;
  v4 = propertySets;
  v5 = &this->mChildren;
  v6 = (bool *)&this->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
  v7 = (char *)&this->mIsLocal;
  if ( v6 != &this->mIsLocal )
  {
    do
    {
      v8 = v6 + 8;
      v9 = *((_QWORD *)v6 + 1);
      v10 = (_QWORD *)*((_QWORD *)v6 + 2);
      *(_QWORD *)(v9 + 8) = v10;
      *v10 = v9;
      *v8 = v8;
      v8[1] = v8;
      if ( v8 != (_QWORD *)8 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v8 - 1))(v8 - 1, 1i64);
      v6 = (bool *)&v5->mChildrenOrdered.mNode.mNext[-1].mNext;
    }
    while ( v6 != (bool *)v7 );
  }
  if ( !v4->size )
    return;
  shared_property_uids.p = 0i64;
  *(_QWORD *)&shared_property_uids.size = 0i64;
  UFG::Editor::GetSharedProperties(&shared_property_uids, v4);
  v11 = 0;
  if ( !shared_property_uids.size )
    goto LABEL_37;
  v12 = &shared_property_uids.p->mIsDefault;
  v13 = v61;
  do
  {
    UFG::qSymbol::qSymbol(&result, *((_DWORD *)v12 - 5));
    v14 = UFG::qPropertySet::GetPropertyTypeFromName(*v4->p, (UFG::qSymbol *)&result, DEPTH_RECURSE);
    v15 = *v4->p;
    v62 = v15->mSchemaName.mUID != UFG::gNullQSymbol.mUID;
    if ( v3 && v15 == *(UFG::qPropertySet **)(v12 - 12) )
    {
      v16 = 1;
      if ( v15->mSchemaName.mUID != UFG::gNullQSymbol.mUID )
        v16 = *v12 == 0;
    }
    else
    {
      v16 = 0;
    }
    if ( v14 < 17 )
      goto LABEL_31;
    if ( v14 > 20 )
    {
      if ( v14 == 25 )
      {
        v20 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
        v19 = v20;
        v65 = v20;
        if ( v20 )
        {
          v21 = v20 + 1;
          v21->mNext = v21;
          v21[1].mNext = v21;
          v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
          LODWORD(v19[3].mNext) = 25;
          HIDWORD(v19[3].mNext) = result;
          LODWORD(v19[4].mNext) = -1;
          v19[5].mNext = 0i64;
          LOWORD(v19[6].mNext) = 0;
          BYTE2(v19[6].mNext) = 0;
          v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy_Container::`vftable;
          v22 = v19 + 7;
          v22->mNext = v22;
          v22[1].mNext = v22;
          LOBYTE(v19[9].mNext) = 0;
          HIDWORD(v19[9].mNext) = 0;
          v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy_PropertyList::`vftable;
        }
        else
        {
          v19 = 0i64;
        }
        goto LABEL_35;
      }
      if ( v14 == 26 )
      {
        v17 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
        v65 = v17;
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
        goto LABEL_35;
      }
LABEL_31:
      v27 = UFG::qMalloc(0x88ui64, UFG::gGlobalNewName, 0i64);
      v19 = v27;
      v65 = v27;
      if ( v27 )
      {
        v28 = v27 + 1;
        v28->mNext = v28;
        v28[1].mNext = v28;
        v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
        LODWORD(v19[3].mNext) = v14;
        HIDWORD(v19[3].mNext) = result;
        LODWORD(v19[4].mNext) = v11;
        v19[5].mNext = 0i64;
        LOWORD(v19[6].mNext) = 0;
        BYTE2(v19[6].mNext) = 0;
        v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxySimple::`vftable;
        UFG::qString::qString((UFG::qString *)&v19[7]);
        LOBYTE(v19[12].mNext) = 0;
        v29 = v19 + 13;
        v29->mNext = v29;
        v29[1].mNext = v29;
        v19[16].mNext = 0i64;
        v19[15].mNext = 0i64;
      }
      else
      {
        v19 = 0i64;
      }
      UFG::Editor::PropertyProxySimple::Setup((UFG::Editor::PropertyProxySimple *)v19, v4);
      goto LABEL_35;
    }
    v23 = UFG::qMalloc(0x90ui64, UFG::gGlobalNewName, 0i64);
    v19 = v23;
    v65 = v23;
    if ( v23 )
    {
      v24 = v23 + 1;
      v24->mNext = v24;
      v24[1].mNext = v24;
      v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
      LODWORD(v19[3].mNext) = v14;
      HIDWORD(v19[3].mNext) = result;
      LODWORD(v19[4].mNext) = v11;
      v19[5].mNext = 0i64;
      LOWORD(v19[6].mNext) = 0;
      BYTE2(v19[6].mNext) = 0;
      v19->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxyVectored::`vftable;
      LODWORD(v19[7].mNext) = 0;
      v25 = 0i64;
      v26 = (_DWORD *)((char *)&v19[7].mNext + 4);
      do
      {
        *((_BYTE *)&v19[15].mNext + v25 + 4) = 0;
        *v26 = 0;
        ++v25;
        ++v26;
      }
      while ( v25 < 16 );
      BYTE4(v19[17].mNext) = 0;
    }
    else
    {
      v19 = 0i64;
    }
    UFG::Editor::PropertyProxyVectored::Setup((UFG::Editor::PropertyProxyVectored *)v19, v4);
LABEL_35:
    LOBYTE(v19[6].mNext) = v16;
    BYTE1(v19[6].mNext) = v62;
    v30 = v19 + 1;
    v31 = v5->mChildrenOrdered.mNode.mPrev;
    v31->mNext = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v19[1];
    v30->mNext = (UFG::allocator::free_link *)v31;
    v30[1].mNext = (UFG::allocator::free_link *)v5;
    v5->mChildrenOrdered.mNode.mPrev = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v19[1];
    v19[5].mNext = (UFG::allocator::free_link *)v13;
    ++v11;
    v12 += 24;
    v3 = v64;
  }
  while ( v11 < shared_property_uids.size );
  v7 = (char *)&v5[-1].mChildrenOrdered.mNode.mNext;
LABEL_37:
  v32 = (signed __int64)&v5->mChildrenOrdered.mNode.mNext[-1].mNext;
  while ( 2 )
  {
    v33 = 0i64;
    if ( (char *)v32 != v7 )
    {
      while ( 2 )
      {
        v34 = (__int64 *)(v32 + 8);
        v35 = *(_QWORD *)(v32 + 16) - 8i64;
        if ( (char *)v35 == v7 )
          break;
        v36 = *(_DWORD *)(v35 + 24);
        if ( *(_DWORD *)(v32 + 24) == 26 )
        {
          if ( v36 != 26 )
            goto LABEL_45;
LABEL_44:
          v37 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v32 + 28));
          v38 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v35 + 28));
          if ( (signed int)UFG::qStringCompareInsensitive(v37, v38, -1) <= 0 )
          {
LABEL_45:
            v32 = v35;
            goto LABEL_47;
          }
        }
        else if ( v36 != 26 )
        {
          goto LABEL_44;
        }
        v39 = *v34;
        v40 = (_QWORD *)(v35 + 8);
        v41 = *(__int64 **)(v35 + 16);
        v42 = *(_QWORD **)(v32 + 16);
        *(_QWORD *)(v39 + 8) = v42;
        *v42 = v39;
        *v34 = (__int64)v34;
        *(_QWORD *)(v32 + 16) = v32 + 8;
        v43 = *(_QWORD *)(v35 + 8);
        v44 = *(_QWORD **)(v35 + 16);
        *(_QWORD *)(v43 + 8) = v44;
        *v44 = v43;
        *v40 = v40;
        v40[1] = v40;
        v45 = *(_QWORD **)(v39 + 8);
        *(_QWORD *)(v39 + 8) = v35 + 8;
        *v40 = v39;
        v40[1] = v45;
        *v45 = v35 + 8;
        v46 = *v41;
        *(_QWORD *)(v46 + 8) = v34;
        *v34 = v46;
        *(_QWORD *)(v32 + 16) = v41;
        *v41 = (__int64)v34;
        v33 = v35;
LABEL_47:
        if ( (char *)v32 == v7 )
          break;
        continue;
      }
    }
    v32 = 0i64;
    if ( v33 && (char *)v33 != v7 )
    {
LABEL_50:
      v47 = (__int64 *)(v33 + 8);
      v48 = *(_QWORD *)(v33 + 8) - 8i64;
      if ( (char *)v48 == v7 )
      {
LABEL_59:
        if ( !v32 )
          break;
        continue;
      }
      v49 = *(_DWORD *)(v33 + 24);
      if ( *(_DWORD *)(v48 + 24) == 26 )
      {
        if ( v49 != 26 )
          goto LABEL_56;
LABEL_55:
        v50 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v48 + 28));
        v51 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v33 + 28));
        if ( (signed int)UFG::qStringCompareInsensitive(v50, v51, -1) <= 0 )
        {
LABEL_56:
          v33 = v48;
          goto LABEL_58;
        }
      }
      else if ( v49 != 26 )
      {
        goto LABEL_55;
      }
      v52 = (_QWORD *)(v48 + 8);
      v53 = *(_QWORD *)(v48 + 8);
      v54 = *(__int64 **)(v33 + 16);
      v55 = *(_QWORD **)(v48 + 16);
      *(_QWORD *)(v53 + 8) = v55;
      *v55 = v53;
      *v52 = v52;
      v52[1] = v52;
      v56 = *v47;
      v57 = *(_QWORD **)(v33 + 16);
      *(_QWORD *)(v56 + 8) = v57;
      *v57 = v56;
      *v47 = (__int64)v47;
      *(_QWORD *)(v33 + 16) = v33 + 8;
      v58 = *(__int64 ***)(v53 + 8);
      *(_QWORD *)(v53 + 8) = v47;
      *v47 = v53;
      *(_QWORD *)(v33 + 16) = v58;
      *v58 = v47;
      v59 = *v54;
      *(_QWORD *)(v59 + 8) = v48 + 8;
      *v52 = v59;
      v52[1] = v54;
      *v54 = v48 + 8;
      v32 = v48;
LABEL_58:
      if ( (char *)v33 == v7 )
        goto LABEL_59;
      goto LABEL_50;
    }
    break;
  }
  if ( shared_property_uids.p )
    operator delete[](shared_property_uids.p);
}

// File Line: 835
// RVA: 0x2145A0
UFG::qPropertySet *__fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateAddPropertyUI(UFG::Editor::PropertyProxy_PropertySet *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qPropertySet *pset, UFG::qPropertyPath *currentPath)
{
  UFG::qPropertySet *v5; // rsi
  UFG::DUIContext *v6; // rdi
  UFG::Editor::PropertyBrowser *v7; // rbp
  UFG::Editor::PropertyProxy_PropertySet *v8; // rbx
  UFG::DUIContext *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::SchemaDef *v11; // r14
  UFG::qSymbol *v12; // rax
  ePropertyType v13; // eax
  UFG::qSymbol v15; // [rsp+30h] [rbp-68h]
  int column_widths; // [rsp+38h] [rbp-60h]
  int v17; // [rsp+3Ch] [rbp-5Ch]
  __int64 v18; // [rsp+40h] [rbp-58h]
  UFG::DUIRect result; // [rsp+48h] [rbp-50h]
  UFG::qString current_value; // [rsp+58h] [rbp-40h]

  v18 = -2i64;
  v5 = pset;
  v6 = dui;
  v7 = browser;
  v8 = this;
  if ( !UFG::PropertySetManager::IsComponentPropertySet(pset) )
  {
    UFG::DUIContext::Label(v6, "Add Property:");
    UFG::DUIContext::GetLayoutRect(v6, &result, 0, 0);
    column_widths = result.mW - result.mH;
    v17 = result.mH;
    v9 = UFG::DUIContext::SetLayoutRect(v6, &result);
    UFG::DUIContext::BeginGridLayout(v9, 2, 1, &column_widths, 0i64, 0);
    v10 = UFG::qSymbol::create_from_string(&v15, v8->mNewPropertyName.mData);
    v11 = UFG::PropertySetManager::GetSchemaForProperty(0i64, v10);
    if ( (v11 == 0i64) == 1 )
    {
      UFG::DUIContext::BeginGridLayout(v6, 2, 1, 4);
      UFG::DUIContext::TextBox(v6, &v8->mNewPropertyName, 0i64, 1, 0i64, 0xFFFFFFFF);
      UFG::DUIContext::ComboBox(
        v6,
        &v8->mSelectedTypeOption,
        UFG::Editor::PropertyProxy_Container::mPropTypes,
        0xBu,
        0i64);
      UFG::DUIContext::EndLayoutHorizontal(v6);
      if ( (unsigned __int8)UFG::DUIContext::Button(v6, "+", 0x10u) && v8->mNewPropertyName.mLength )
      {
        v12 = UFG::qSymbol::create_from_string(&v15, v8->mNewPropertyName.mData);
        UFG::qPropertyPath::Push(currentPath, v12);
        v13 = (unsigned int)GetPropertySetDataTypeFromString(UFG::Editor::PropertyProxy_Container::mPropTypes[v8->mSelectedTypeOption]);
        v7->mPendingValueChange.mType = 4;
        v7->mPendingValueChange.mNewItemType = v13;
        UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, currentPath);
        UFG::qString::Set(&v8->mNewPropertyName, &customWorldMapCaption);
        UFG::qPropertyPath::Pop(currentPath);
      }
    }
    else
    {
      UFG::DUIContext::BeginGridLayout(v6, 2, 1, 4);
      UFG::DUIContext::PushColour(v6, 0, &UFG::qColour::Red);
      UFG::DUIContext::TextBox(v6, &v8->mNewPropertyName, 0i64, 1, 0i64, 0xFFFFFFFF);
      UFG::DUIContext::PopColour(v6, 0);
      UFG::qString::FormatEx(&current_value, "%s (%s)", v11->mNameString.mData, v11->mPropertyNameString.mData);
      UFG::DUIContext::TextBox(v6, &current_value, 0i64, 1, 0i64, 0xFFFFFFFF);
      UFG::qString::~qString(&current_value);
      UFG::DUIContext::EndLayoutHorizontal(v6);
      UFG::DUIContext::Label(v6, &customWorldMapCaption);
    }
    UFG::DUIContext::EndLayoutHorizontal(v6);
    UFG::DUIContext::Separator(v6);
  }
  return v5;
}

// File Line: 892
// RVA: 0x21C7B0
void __fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateUI(UFG::Editor::PropertyProxy_PropertySet *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qArray<UFG::qPropertyList *,0> *selection, UFG::qPropertyPath *currentPath)
{
  UFG::qArray<UFG::qPropertyList *,0> *v5; // rdi
  UFG::DUIContext *v6; // r13
  UFG::Editor::PropertyBrowser *v7; // r15
  UFG::Editor::PropertyProxy_PropertySet *v8; // r14
  char *v9; // rax
  char *v10; // rbx
  unsigned int v11; // eax
  bool *v12; // rax
  bool v13; // bl
  unsigned int v14; // er15
  char *v15; // rax
  UFG::qPropertySet *v16; // r12
  __int64 v17; // r13
  unsigned int v18; // edi
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::qPropertySet **v22; // rsi
  UFG::qPropertySet **v23; // r9
  __int64 v24; // r8
  UFG::qPropertySet **v25; // rbx
  UFG::qPropertySet **v26; // rbx
  signed __int64 i; // rdi
  int v28; // ebx
  UFG::DUIRect v29; // xmm0
  UFG::DUIRect v30; // xmm1
  UFG::DUIContext *v31; // rax
  UFG::qArray<UFG::qPropertySet *,0> propertySets; // [rsp+38h] [rbp-69h]
  UFG::DUIRect v33; // [rsp+50h] [rbp-51h]
  UFG::DUIRect v34; // [rsp+60h] [rbp-41h]
  UFG::DUIRect rect; // [rsp+70h] [rbp-31h]
  UFG::qString result; // [rsp+80h] [rbp-21h]
  UFG::Editor::PropertyBrowser *v37; // [rsp+108h] [rbp+67h]
  UFG::DUIContext *v38; // [rsp+110h] [rbp+6Fh]
  UFG::qArray<UFG::qPropertyList *,0> *v39; // [rsp+118h] [rbp+77h]

  v39 = selection;
  v38 = dui;
  v37 = browser;
  v5 = selection;
  v6 = dui;
  v7 = browser;
  v8 = this;
  v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  UFG::qString::FormatEx(&result, "[%d] %s", (unsigned int)v8->mArrayIndex, v9);
  if ( !v8->mParent )
    goto LABEL_55;
  if ( !v8->mIsLocal )
    UFG::DUIContext::PushColour(v6, 0, &UFG::qColour::Grey);
  v10 = result.mData;
  v11 = UFG::qPropertyPath::GetHash(currentPath);
  v12 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(v7, v11);
  v13 = UFG::DUIContext::Collapsible(v6, v10, v12);
  if ( !v8->mIsLocal )
    UFG::DUIContext::PopColour(v6, 0);
  if ( v13 )
  {
LABEL_55:
    propertySets.p = 0i64;
    *(_QWORD *)&propertySets.size = 0i64;
    if ( v5->size )
    {
      v14 = 0;
      do
      {
        v15 = UFG::qPropertyList::GetValuePtr(v5->p[v14], 0x1Au, v8->mArrayIndex);
        if ( v15 && *(_QWORD *)v15 )
          v16 = (UFG::qPropertySet *)&v15[*(_QWORD *)v15];
        else
          v16 = 0i64;
        v17 = propertySets.size;
        v18 = propertySets.size + 1;
        if ( propertySets.size + 1 <= propertySets.capacity )
          goto LABEL_56;
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
LABEL_56:
          v22 = propertySets.p;
        }
        else
        {
          v20 = 8i64 * v19;
          if ( !is_mul_ok(v19, 8ui64) )
            v20 = -1i64;
          v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
          v22 = (UFG::qPropertySet **)v21;
          v23 = propertySets.p;
          if ( propertySets.p )
          {
            v24 = 0i64;
            if ( propertySets.size )
            {
              do
              {
                v21[v24].mNext = (UFG::allocator::free_link *)v23[v24];
                v24 = (unsigned int)(v24 + 1);
                v23 = propertySets.p;
              }
              while ( (unsigned int)v24 < propertySets.size );
            }
            operator delete[](v23);
          }
          propertySets.p = v22;
          propertySets.capacity = v19;
        }
        propertySets.size = v18;
        v22[v17] = v16;
        ++v14;
        v5 = v39;
      }
      while ( v14 < v39->size );
      v7 = v37;
      v6 = v38;
    }
    if ( !v8->mHasGenerantedChildren )
    {
      UFG::Editor::PropertyProxy_PropertySet::GenerateChildren(v8, &propertySets, v8->mIsLocal);
      v8->mHasGenerantedChildren = 1;
    }
    if ( propertySets.size == 1 )
    {
      v25 = propertySets.p;
      *v25 = UFG::Editor::PropertyProxy_PropertySet::UpdateParentListUI(v8, v7, v6, *propertySets.p);
    }
    if ( v8->mParent )
      UFG::DUIContext::BeginIndent(v6);
    v26 = propertySets.p;
    *v26 = UFG::Editor::PropertyProxy_PropertySet::UpdateAddPropertyUI(v8, v7, v6, *propertySets.p, currentPath);
    for ( i = (signed __int64)&v8->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
          (bool *)i != &v8->mIsLocal;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      if ( !v7->mHideUnassigned || *(_BYTE *)(i + 48) )
      {
        UFG::qPropertyPath::Push(currentPath, (UFG::qSymbol *)(i + 28));
        UFG::DUIContext::GetLayoutRect(v6, &v33, 0, 0);
        v28 = v33.mH;
        v29 = v33;
        _mm_store_si128((__m128i *)&rect, (__m128i)v33);
        rect.mW = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v29, 8)) - v28;
        UFG::DUIContext::SetLayoutRect(v6, &rect);
        (*(void (__fastcall **)(signed __int64, UFG::Editor::PropertyBrowser *, UFG::DUIContext *, UFG::qArray<UFG::qPropertySet *,0> *, UFG::qPropertyPath *))(*(_QWORD *)i + 16i64))(
          i,
          v7,
          v6,
          &propertySets,
          currentPath);
        v30 = v33;
        _mm_store_si128((__m128i *)&v34, (__m128i)v33);
        v34.mW = v28;
        v34.mX = _mm_cvtsi128_si32((__m128i)v30) + _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v30, 8)) - v28;
        v31 = UFG::DUIContext::SetLayoutRect(v6, &v34);
        if ( (unsigned __int8)UFG::DUIContext::Button(v31, "-", 0x10u) )
        {
          v7->mPendingValueChange.mType = 3;
          UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, currentPath);
        }
        UFG::qPropertyPath::Pop(currentPath);
      }
    }
    if ( v8->mParent )
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
void __fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateUI(UFG::Editor::PropertyProxy_PropertySet *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qArray<UFG::qPropertySet *,0> *selection, UFG::qPropertyPath *currentPath)
{
  UFG::qArray<UFG::RoadNetworkNode *,0> *v5; // rdi
  UFG::DUIContext *v6; // r12
  UFG::Editor::PropertyBrowser *v7; // r14
  UFG::Editor::PropertyProxy_PropertySet *v8; // r13
  UFG::qSymbol *v9; // rsi
  char *v10; // rbx
  unsigned int v11; // eax
  bool *v12; // rax
  bool v13; // bl
  unsigned int v14; // er15
  __int64 v15; // r12
  unsigned int v16; // edi
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::RoadNetworkNode **v20; // rsi
  UFG::RoadNetworkNode **v21; // r9
  __int64 v22; // r8
  UFG::RoadNetworkNode **v23; // rbx
  UFG::RoadNetworkNode **v24; // rbx
  signed __int64 i; // rdi
  int v26; // ebx
  UFG::DUIRect v27; // xmm0
  UFG::DUIRect v28; // xmm1
  UFG::DUIContext *v29; // rax
  UFG::qArray<UFG::RoadNetworkNode *,0> _dst; // [rsp+38h] [rbp-39h]
  UFG::DUIRect result; // [rsp+50h] [rbp-21h]
  UFG::DUIRect v32; // [rsp+60h] [rbp-11h]
  UFG::DUIRect rect; // [rsp+70h] [rbp-1h]
  UFG::qPropertySet *v34; // [rsp+D0h] [rbp+5Fh]
  UFG::Editor::PropertyBrowser *v35; // [rsp+D8h] [rbp+67h]
  UFG::DUIContext *v36; // [rsp+E0h] [rbp+6Fh]
  UFG::qArray<UFG::qPropertySet *,0> *v37; // [rsp+E8h] [rbp+77h]

  v37 = selection;
  v36 = dui;
  v35 = browser;
  v5 = (UFG::qArray<UFG::RoadNetworkNode *,0> *)selection;
  v6 = dui;
  v7 = browser;
  v8 = this;
  v9 = &this->mPropertyName;
  v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  if ( !v8->mParent )
    goto LABEL_52;
  if ( !v8->mIsLocal )
    UFG::DUIContext::PushColour(v6, 0, &UFG::qColour::Grey);
  v11 = UFG::qPropertyPath::GetHash(currentPath);
  v12 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(v7, v11);
  v13 = UFG::DUIContext::Collapsible(v6, v10, v12);
  if ( !v8->mIsLocal )
    UFG::DUIContext::PopColour(v6, 0);
  if ( v13 )
  {
LABEL_52:
    _dst.p = 0i64;
    *(_QWORD *)&_dst.size = 0i64;
    if ( v8->mParent )
    {
      v14 = 0;
      if ( v5->size > 0 )
      {
        do
        {
          v34 = UFG::qPropertySet::Get<UFG::qPropertySet>((UFG::qPropertySet *)v5->p[v14], v9, DEPTH_RECURSE);
          if ( v34 )
          {
            v15 = _dst.size;
            v16 = _dst.size + 1;
            if ( _dst.size + 1 <= _dst.capacity )
              goto LABEL_53;
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
LABEL_53:
              v20 = _dst.p;
            }
            else
            {
              v18 = 8i64 * v17;
              if ( !is_mul_ok(v17, 8ui64) )
                v18 = -1i64;
              v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
              v20 = (UFG::RoadNetworkNode **)v19;
              v21 = _dst.p;
              if ( _dst.p )
              {
                v22 = 0i64;
                if ( _dst.size )
                {
                  do
                  {
                    v19[v22].mNext = (UFG::allocator::free_link *)v21[v22];
                    v22 = (unsigned int)(v22 + 1);
                    v21 = _dst.p;
                  }
                  while ( (unsigned int)v22 < _dst.size );
                }
                operator delete[](v21);
              }
              _dst.p = v20;
              _dst.capacity = v17;
            }
            _dst.size = v16;
            v20[v15] = (UFG::RoadNetworkNode *)v34;
            v5 = (UFG::qArray<UFG::RoadNetworkNode *,0> *)v37;
            v9 = &v8->mPropertyName;
          }
          ++v14;
        }
        while ( v14 < v5->size );
        v7 = v35;
        v6 = v36;
      }
    }
    else
    {
      UFG::qArray<UFG::qPropertySet *,0>::Clone(v5, &_dst);
    }
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v9);
    if ( !v8->mHasGenerantedChildren )
    {
      UFG::Editor::PropertyProxy_PropertySet::GenerateChildren(
        v8,
        (UFG::qArray<UFG::qPropertySet *,0> *)&_dst,
        v8->mIsLocal);
      v8->mHasGenerantedChildren = 1;
    }
    if ( _dst.size == 1 )
    {
      v23 = _dst.p;
      *v23 = (UFG::RoadNetworkNode *)UFG::Editor::PropertyProxy_PropertySet::UpdateParentListUI(
                                       v8,
                                       v7,
                                       v6,
                                       *(UFG::qPropertySet **)_dst.p);
    }
    if ( v8->mParent )
      UFG::DUIContext::BeginIndent(v6);
    v24 = _dst.p;
    *v24 = (UFG::RoadNetworkNode *)UFG::Editor::PropertyProxy_PropertySet::UpdateAddPropertyUI(
                                     v8,
                                     v7,
                                     v6,
                                     *(UFG::qPropertySet **)_dst.p,
                                     currentPath);
    for ( i = (signed __int64)&v8->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
          (bool *)i != &v8->mIsLocal;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      if ( !v7->mHideUnassigned || *(_BYTE *)(i + 48) )
      {
        UFG::qPropertyPath::Push(currentPath, (UFG::qSymbol *)(i + 28));
        UFG::DUIContext::GetLayoutRect(v6, &result, 0, 0);
        v26 = result.mH;
        v27 = result;
        _mm_store_si128((__m128i *)&rect, (__m128i)result);
        rect.mW = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v27, 8)) - v26;
        UFG::DUIContext::SetLayoutRect(v6, &rect);
        (*(void (__fastcall **)(signed __int64, UFG::Editor::PropertyBrowser *, UFG::DUIContext *, UFG::qArray<UFG::RoadNetworkNode *,0> *, UFG::qPropertyPath *))(*(_QWORD *)i + 16i64))(
          i,
          v7,
          v6,
          &_dst,
          currentPath);
        v28 = result;
        _mm_store_si128((__m128i *)&v32, (__m128i)result);
        v32.mW = v26;
        v32.mX = _mm_cvtsi128_si32((__m128i)v28) + _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v28, 8)) - v26;
        v29 = UFG::DUIContext::SetLayoutRect(v6, &v32);
        if ( (unsigned __int8)UFG::DUIContext::Button(v29, "-", 0x10u) )
        {
          v7->mPendingValueChange.mType = 3;
          UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, currentPath);
        }
        UFG::qPropertyPath::Pop(currentPath);
      }
    }
    if ( v8->mParent )
      UFG::DUIContext::EndIndent(v6);
    if ( _dst.p )
      operator delete[](_dst.p);
  }
}

// File Line: 1070
// RVA: 0x216440
UFG::qPropertySet *__fastcall UFG::Editor::PropertyProxy_PropertySet::UpdateParentListUI(UFG::Editor::PropertyProxy_PropertySet *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qPropertySet *pset)
{
  UFG::qPropertySet *v4; // r15
  UFG::DUIContext *v5; // r12
  UFG::Editor::PropertyBrowser *v6; // r14
  UFG::Editor::PropertyProxy_PropertySet *v7; // r13
  UFG::qSymbol *v8; // rax
  UFG::qPropertyPath *v9; // rbx
  unsigned int v10; // eax
  bool *v11; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v12; // rsi
  unsigned int v13; // edi
  UFG::Editor::DAGPath *v14; // rbx
  UFG::Editor::FnModifier *v15; // rax
  UFG::qSymbol *v16; // rbx
  int v17; // eax
  signed int v18; // ebx
  int v19; // edx
  char *v20; // rax
  __int64 v21; // ST10_8
  __int64 v22; // r13
  __int64 v23; // rdi
  unsigned int v24; // ebx
  unsigned int v25; // edx
  UFG::Editor::SmartHandleObject *v26; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v27; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v28; // rax
  UFG::Editor::SelectionSet *v29; // rax
  UFG::Editor::SelectionSet *v30; // rsi
  UFG::Event *v31; // rax
  UFG::qNode<UFG::Event,UFG::Event> *v32; // rcx
  __int64 v33; // r14
  unsigned int v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // edx
  signed __int64 v37; // rbx
  UFG::Editor::SmartHandleObject *v38; // rcx
  __int64 *v39; // rcx
  __int64 v40; // rax
  unsigned int *v41; // rbx
  UFG::qSymbol *v42; // rbx
  UFG::Editor::SmartHandleObject *v43; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v44; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v45; // rax
  __int64 v46; // ST10_8
  __int64 v47; // rcx
  _QWORD *v48; // rax
  __int64 v49; // rcx
  _QWORD *v50; // rax
  UFG::Editor::DAGPath item; // [rsp+18h] [rbp-71h]
  void *v53; // [rsp+78h] [rbp-11h]
  int column_widths; // [rsp+80h] [rbp-9h]
  int v55; // [rsp+84h] [rbp-5h]
  int v56; // [rsp+88h] [rbp-1h]
  UFG::DUIRect rect; // [rsp+90h] [rbp+7h]
  __int64 v58; // [rsp+A0h] [rbp+17h]
  UFG::Editor::PropertyProxy_PropertySet *v59; // [rsp+E8h] [rbp+5Fh]
  UFG::Editor::PropertyBrowser *v60; // [rsp+F0h] [rbp+67h]
  UFG::qPropertyPath *v61; // [rsp+108h] [rbp+7Fh]

  v58 = -2i64;
  v4 = pset;
  v5 = dui;
  v6 = browser;
  v7 = this;
  if ( !UFG::PropertySetManager::IsComponentPropertySet(pset) )
  {
    v8 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&item.mFnObject.mTypeId + 1, "Parent");
    v9 = v61;
    UFG::qPropertyPath::Push(v61, v8);
    if ( v7->mParent )
      UFG::DUIContext::BeginIndent(v5);
    v10 = UFG::qPropertyPath::GetHash(v9);
    v11 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(v6, v10);
    if ( (unsigned __int8)UFG::DUIContext::Collapsible(v5, "Parents", v11) )
    {
      UFG::DUIContext::BeginIndent(v5);
      if ( (unsigned __int8)UFG::DUIContext::Button(v5, "Add Parent", 0x10u) )
      {
        v12 = UFG::Editor::SelectionManager::GetSelectionSet("LastSelection");
        v13 = 0;
        if ( LODWORD(v12[3].mNext) )
        {
          do
          {
            v14 = (UFG::Editor::DAGPath *)((char *)v12[4].mPrev + 88 * v13);
            if ( UFG::Editor::DAGPath::GetSystemName(v14, (UFG::qSymbol *)&item.mFnObject.mTypeId + 1)->mUID == UFG::Editor::DAGTypeArchetype::TYPE_SYMBOL.mUID
              && v14->mElements.size )
            {
              v53 = &item.mFnObject.mTypeId;
              item.mFnObject.mTypeId = v14->mInterfaceName.mUID;
              v15 = UFG::Editor::DAGPath::GetInterface(v14, 0xA25DB8B2, (__int64)&item.mFnObject.mTypeId);
              v16 = (UFG::qSymbol *)(v15 ? v15[1].vfptr->__vecDelDtor : 0i64);
              if ( v16 )
              {
                v4 = UFG::Editor::Core::OpenForEdit(v4);
                UFG::PropertySetManager::AppendParentLocal(v4, v16 + 16);
                v6->mbDirty = 1;
              }
            }
            ++v13;
          }
          while ( v13 < LODWORD(v12[3].mNext) );
        }
      }
      v17 = UFG::qPropertySet::NumParents(v4);
      v18 = v17 - 1;
      *(&item.mFnObject.mTypeId + 1) = v17 - 1;
      if ( v17 - 1 >= 0 )
      {
        do
        {
          item.mFnObject.mTypeId = *(_DWORD *)&UFG::qPropertySet::GetParentFromIdx(v4, v18)->mDebugName[12];
          UFG::DUIContext::GetLayoutRect(v5, &rect, 0, 0);
          UFG::DUIContext::SetLayoutRect(v5, &rect);
          v19 = v5->mTheme.mRowHeight;
          column_widths = rect.mW - 2 * v19;
          v55 = v19;
          v56 = v19;
          UFG::DUIContext::BeginGridLayout(v5, 3, 1, &column_widths, 0i64, 0);
          v20 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&item.mFnObject.mTypeId);
          UFG::DUIContext::Label(v5, v20);
          if ( (unsigned __int8)UFG::DUIContext::Button(v5, "@", 0x10u) )
          {
            UFG::Editor::EditorWindowManager::CreateWindow(
              (UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *)&item.mSystemName,
              "UFG::Editor::PropertyBrowserWindow");
            v22 = v21;
            v53 = &item;
            item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
            item.mFnObject.mPtr = 0i64;
            item.mFnObject.mTypeId = -1998658210;
            item.mSystemName.mUID = UFG::Editor::DAGTypeArchetype::TYPE_SYMBOL.mUID;
            item.mElements.p = 0i64;
            *(_QWORD *)&item.mElements.size = 0i64;
            UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, 4u, "qArray.Reallocate(Constructor)");
            item.mInterfaceName.mUID = -1;
            item.mSubElements.p = 0i64;
            *(_QWORD *)&item.mSubElements.size = 0i64;
            item.mPathType = 0;
            v23 = item.mElements.size;
            v24 = item.mElements.size + 1;
            if ( item.mElements.size + 1 > item.mElements.capacity )
            {
              if ( item.mElements.capacity )
                v25 = 2 * item.mElements.capacity;
              else
                v25 = 1;
              for ( ; v25 < v24; v25 *= 2 )
                ;
              if ( v25 <= 4 )
                v25 = 4;
              if ( v25 - v24 > 0x10000 )
                v25 = item.mElements.size + 65537;
              UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, v25, "qArray.Add");
            }
            item.mElements.size = v24;
            item.mElements.p[v23].mUID = item.mFnObject.mTypeId;
            v26 = item.mFnObject.mPtr;
            if ( item.mFnObject.mPtr )
            {
              v27 = item.mFnObject.mPrev;
              v28 = item.mFnObject.mNext;
              item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
              v28->mPrev = v27;
              item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v26->mSmartHandleList.mNode.mNext == &v26->mSmartHandleList
                && v26 )
              {
                v26->vfptr->__vecDelDtor(v26, 1u);
              }
              item.mFnObject.mPtr = 0i64;
            }
            item.mFnObject.mPtr = 0i64;
            v29 = UFG::Editor::SelectionManager::GetCreateSelectionSet(*(const char **)(v22 + 912));
            v30 = v29;
            v29->mDAGPaths.size = 0;
            v31 = (UFG::Event *)UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
            v53 = v31;
            if ( v31 )
            {
              v32 = (UFG::qNode<UFG::Event,UFG::Event> *)&v31->mPrev;
              v32->mPrev = v32;
              v32->mNext = v32;
              v31->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
              v31->m_EventUID = 609910773;
              v31->m_NamePTR = 0i64;
            }
            else
            {
              v31 = 0i64;
            }
            v31->mUserData0 = (unsigned __int64)v30;
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v31);
            if ( (signed int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(&v30->mDAGPaths, &item) <= -1 )
            {
              v33 = v30->mDAGPaths.size;
              v34 = v33 + 1;
              v35 = v30->mDAGPaths.capacity;
              if ( (signed int)v33 + 1 > v35 )
              {
                if ( v35 )
                  v36 = 2 * v35;
                else
                  v36 = 1;
                for ( ; v36 < v34; v36 *= 2 )
                  ;
                if ( v36 - v34 > 0x10000 )
                  v36 = v33 + 65537;
                UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&v30->mDAGPaths, v36, "qArray.Add");
              }
              v30->mDAGPaths.size = v34;
              v37 = (signed __int64)&v30->mDAGPaths.p[v33];
              if ( &item != (UFG::Editor::DAGPath *)v37 )
              {
                UFG::Editor::DAGPath::Clear(&v30->mDAGPaths.p[v33]);
                if ( !*(_DWORD *)(v37 + 80) )
                {
                  v38 = item.mFnObject.mPtr;
                  if ( !*(_QWORD *)(v37 + 16) )
                  {
                    if ( item.mFnObject.mPtr )
                    {
                      *(_DWORD *)(v37 + 24) = item.mFnObject.mPtr->mTypeId;
                      *(_QWORD *)(v37 + 16) = v38;
                      v39 = (__int64 *)&v38->mSmartHandleList;
                      v40 = *v39;
                      *(_QWORD *)(v40 + 8) = v37;
                      *(_QWORD *)v37 = v40;
                      *(_QWORD *)(v37 + 8) = v39;
                      *v39 = v37;
                    }
                  }
                }
                *(_DWORD *)(v37 + 32) = item.mSystemName.mUID;
                UFG::qArray<UFG::qSymbol,0>::Clone(&item.mElements, (UFG::qArray<UFG::qSymbol,0> *)(v37 + 40));
                *(_DWORD *)(v37 + 56) = item.mInterfaceName.mUID;
                UFG::qArray<UFG::qString,0>::Clone(&item.mSubElements, (UFG::qArray<UFG::qString,0> *)(v37 + 64));
              }
              UFG::Editor::SelectionSet::DispatchChangedEvent(v30);
              v6 = v60;
            }
            *(_QWORD *)(v22 + 448) = v30;
            *(_BYTE *)(v22 + 865) = 1;
            *(_BYTE *)(v22 + 880) = 1;
            if ( item.mSubElements.p )
            {
              v41 = &item.mSubElements.p[-1].mStringHash32;
              `eh vector destructor iterator(
                item.mSubElements.p,
                0x28ui64,
                item.mSubElements.p[-1].mStringHash32,
                (void (__fastcall *)(void *))UFG::qString::~qString);
              operator delete[](v41);
            }
            item.mSubElements.p = 0i64;
            *(_QWORD *)&item.mSubElements.size = 0i64;
            if ( item.mElements.p )
            {
              v42 = item.mElements.p - 1;
              `eh vector destructor iterator(
                item.mElements.p,
                4ui64,
                item.mElements.p[-1].mUID,
                (void (__fastcall *)(void *))_);
              operator delete[](v42);
            }
            item.mElements.p = 0i64;
            *(_QWORD *)&item.mElements.size = 0i64;
            v53 = &item;
            v43 = item.mFnObject.mPtr;
            if ( item.mFnObject.mPtr )
            {
              v44 = item.mFnObject.mPrev;
              v45 = item.mFnObject.mNext;
              item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
              v45->mPrev = v44;
              item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
              if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v43->mSmartHandleList.mNode.mNext == &v43->mSmartHandleList
                && v43 )
              {
                v43->vfptr->__vecDelDtor(v43, 1u);
              }
              item.mFnObject.mPtr = 0i64;
            }
            item.mFnObject.mPtr = 0i64;
            UFG::Editor::SmartHandle::~SmartHandle((UFG::Editor::SmartHandle *)&item.mFnObject.mPrev);
            if ( v46 )
            {
              v47 = *(_QWORD *)&item.mSystemName.mUID;
              v48 = *(_QWORD **)&item.mElements.size;
              *(_QWORD *)(*(_QWORD *)&item.mSystemName.mUID + 8i64) = *(_QWORD *)&item.mElements.size;
              *v48 = v47;
              *(_QWORD *)&item.mSystemName.mUID = (char *)&item + 32;
              *(_QWORD *)&item.mElements.size = (char *)&item + 32;
            }
            v49 = *(_QWORD *)&item.mSystemName.mUID;
            v50 = *(_QWORD **)&item.mElements.size;
            *(_QWORD *)(*(_QWORD *)&item.mSystemName.mUID + 8i64) = *(_QWORD *)&item.mElements.size;
            *v50 = v49;
            *(_QWORD *)&item.mSystemName.mUID = (char *)&item + 32;
            *(_QWORD *)&item.mElements.size = (char *)&item + 32;
            v18 = *(&item.mFnObject.mTypeId + 1);
          }
          if ( (unsigned __int8)UFG::DUIContext::Button(v5, "-", 0x10u) )
          {
            v4 = UFG::Editor::Core::OpenForEdit(v4);
            UFG::PropertySetManager::RemoveParentLocal(v4, (UFG::qSymbol *)&item.mFnObject.mTypeId);
            v6->mbDirty = 1;
          }
          UFG::DUIContext::EndLayoutHorizontal(v5);
          *(&item.mFnObject.mTypeId + 1) = --v18;
        }
        while ( v18 >= 0 );
        v7 = v59;
      }
      UFG::DUIContext::EndIndent(v5);
      v9 = v61;
    }
    UFG::DUIContext::Separator(v5);
    if ( v7->mParent )
      UFG::DUIContext::EndIndent(v5);
    UFG::qPropertyPath::Pop(v9);
  }
  return v4;
}

// File Line: 1159
// RVA: 0x20AB10
void __fastcall UFG::Editor::PropertyProxy_PropertyList::GenerateChildren(UFG::Editor::PropertyProxy_PropertyList *this, UFG::qArray<UFG::qPropertyList *,0> *propertyLists, bool localProperty)
{
  UFG::qArray<UFG::qPropertyList *,0> *v3; // r15
  UFG::Editor::PropertyProxy_PropertyList *v4; // r13
  signed int v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // er8
  UFG::qPropertyList *v8; // rcx
  unsigned int v9; // ebp
  UFG::Editor::PropertyProxyCollection *v10; // r14
  char *v11; // rax
  UFG::qSymbol *v12; // rbx
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbx
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  signed __int64 v20; // rax
  _DWORD *v21; // rcx
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // rcx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v25; // rax
  UFG::allocator::free_link *v26; // [rsp+88h] [rbp+20h]
  UFG::allocator::free_link *v27; // [rsp+88h] [rbp+20h]

  v3 = propertyLists;
  v4 = this;
  v5 = 29;
  v6 = 0;
  v7 = 0;
  if ( propertyLists->size )
  {
    do
    {
      v8 = propertyLists->p[v7];
      if ( v5 == 29 )
      {
        v5 = v8->mTypeUID;
        v6 = v8->mNumElements;
      }
      else
      {
        if ( v8->mTypeUID != v5 )
          return;
        if ( v6 >= v8->mNumElements )
          v6 = v8->mNumElements;
      }
      ++v7;
    }
    while ( v7 < propertyLists->size );
    if ( v5 != 29 )
    {
      v9 = 0;
      if ( v6 )
      {
        v10 = &v4->mChildren;
        do
        {
          if ( v5 < 17 )
            goto LABEL_32;
          if ( v5 <= 20 )
          {
            v18 = UFG::qMalloc(0x90ui64, UFG::gGlobalNewName, 0i64);
            v15 = v18;
            if ( v18 )
            {
              v19 = v18 + 1;
              v19->mNext = v19;
              v19[1].mNext = v19;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
              LODWORD(v15[3].mNext) = v5;
              HIDWORD(v15[3].mNext) = UFG::gNullQSymbol;
              LODWORD(v15[4].mNext) = v9;
              v15[5].mNext = 0i64;
              LOWORD(v15[6].mNext) = 0;
              BYTE2(v15[6].mNext) = 0;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxyVectored::`vftable;
              LODWORD(v15[7].mNext) = 0;
              v20 = 0i64;
              v21 = (_DWORD *)((char *)&v15[7].mNext + 4);
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
            if ( v5 != 25 )
            {
              if ( v5 == 26 )
              {
                v11 = UFG::qPropertyList::GetValuePtr(*v3->p, 0x1Au, v9);
                if ( !v11 || (v12 = (UFG::qSymbol *)&v11[*(_QWORD *)v11], !*(_QWORD *)v11) )
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
                goto LABEL_36;
              }
LABEL_32:
              v22 = UFG::qMalloc(0x88ui64, UFG::gGlobalNewName, 0i64);
              v15 = v22;
              if ( v22 )
              {
                v23 = v22 + 1;
                v23->mNext = v23;
                v23[1].mNext = v23;
                v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy::`vftable;
                LODWORD(v15[3].mNext) = v5;
                HIDWORD(v15[3].mNext) = UFG::gNullQSymbol;
                LODWORD(v15[4].mNext) = v9;
                v15[5].mNext = 0i64;
                LOWORD(v15[6].mNext) = 0;
                BYTE2(v15[6].mNext) = 0;
                v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxySimple::`vftable;
                UFG::qString::qString((UFG::qString *)&v15[7]);
                LOBYTE(v15[12].mNext) = 0;
                v27 = v15 + 13;
                v27->mNext = v27;
                v27[1].mNext = v27;
                v15[16].mNext = 0i64;
                v15[15].mNext = 0i64;
              }
              else
              {
                v15 = 0i64;
              }
              UFG::Editor::PropertyProxySimple::Setup((UFG::Editor::PropertyProxySimple *)v15, v3);
              goto LABEL_36;
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
              v26 = v15 + 7;
              v26->mNext = v26;
              v26[1].mNext = v26;
              LOBYTE(v15[9].mNext) = 0;
              HIDWORD(v15[9].mNext) = 0;
              v15->mNext = (UFG::allocator::free_link *)&UFG::Editor::PropertyProxy_PropertyList::`vftable;
            }
            else
            {
              v15 = 0i64;
            }
          }
LABEL_36:
          v24 = v15 + 1;
          v25 = v10->mChildrenOrdered.mNode.mPrev;
          v25->mNext = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v15[1];
          v24->mNext = (UFG::allocator::free_link *)v25;
          v24[1].mNext = (UFG::allocator::free_link *)v10;
          v10->mChildrenOrdered.mNode.mPrev = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v15[1];
          v15[5].mNext = (UFG::allocator::free_link *)v4;
          ++v9;
        }
        while ( v9 < v6 );
      }
    }
  }
}

// File Line: 1241
// RVA: 0x21C3A0
void __fastcall UFG::Editor::PropertyProxy_PropertyList::UpdateUI(UFG::Editor::PropertyProxy_PropertyList *this, UFG::Editor::PropertyBrowser *browser, UFG::DUIContext *dui, UFG::qArray<UFG::qPropertySet *,0> *selection, UFG::qPropertyPath *currentPath)
{
  UFG::qArray<UFG::qPropertySet *,0> *v5; // rsi
  UFG::DUIContext *v6; // r12
  UFG::Editor::PropertyBrowser *v7; // r13
  UFG::Editor::PropertyProxy_PropertyList *v8; // rdi
  char *v9; // rbx
  bool *v10; // r14
  UFG::qPropertyPath *v11; // r15
  unsigned int v12; // eax
  bool *v13; // rax
  bool v14; // bl
  ePropertyType v15; // ebx
  unsigned int v16; // er15
  signed int v17; // er13
  UFG::qSymbol *v18; // r12
  UFG::qSymbol *v19; // rax
  __int64 v20; // r14
  unsigned int v21; // edi
  unsigned int v22; // ebx
  unsigned __int64 v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::qPropertyList **v25; // rsi
  UFG::qPropertyList **v26; // r9
  __int64 v27; // r8
  signed int v28; // ST30_4
  const char *v29; // rax
  signed __int64 i; // rbx
  UFG::DUIRect v31; // xmm0
  UFG::DUIRect v32; // xmm0
  UFG::qSymbol *name[2]; // [rsp+40h] [rbp-41h]
  UFG::DUIRect rect; // [rsp+50h] [rbp-31h]
  __int64 v35; // [rsp+60h] [rbp-21h]
  UFG::qArray<UFG::qPropertyList *,0> propertyLists; // [rsp+68h] [rbp-19h]
  UFG::DUIRect result; // [rsp+80h] [rbp-1h]
  UFG::Editor::PropertyProxy_PropertyList *v38; // [rsp+E0h] [rbp+5Fh]
  UFG::Editor::PropertyBrowser *v39; // [rsp+E8h] [rbp+67h]
  UFG::DUIContext *v40; // [rsp+F0h] [rbp+6Fh]
  UFG::qArray<UFG::qPropertySet *,0> *v41; // [rsp+F8h] [rbp+77h]

  v41 = selection;
  v40 = dui;
  v39 = browser;
  v38 = this;
  v35 = -2i64;
  v5 = selection;
  v6 = dui;
  v7 = browser;
  v8 = this;
  name[0] = &this->mPropertyName;
  v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mPropertyName);
  v10 = &v8->mIsLocal;
  *(_QWORD *)&rect.mX = (char *)v8 + 48;
  if ( !v8->mIsLocal )
    UFG::DUIContext::PushColour(v6, 0, &UFG::qColour::Grey);
  v11 = currentPath;
  v12 = UFG::qPropertyPath::GetHash(currentPath);
  v13 = (bool *)UFG::Editor::PropertyBrowser::IsExpanded(v7, v12);
  v14 = UFG::DUIContext::Collapsible(v6, v9, v13);
  if ( !*v10 )
    UFG::DUIContext::PopColour(v6, 0);
  if ( v14 )
  {
    propertyLists.p = 0i64;
    *(_QWORD *)&propertyLists.size = 0i64;
    v15 = 29;
    if ( v5->size > 0 )
    {
      v16 = 0;
      v17 = 29;
      v18 = name[0];
      do
      {
        v19 = (UFG::qSymbol *)UFG::qPropertySet::Get<UFG::qPropertyList>(v5->p[v16], v18, DEPTH_RECURSE);
        name[0] = v19;
        if ( v17 == 29 )
          v17 = v19[6].mUID;
        v20 = propertyLists.size;
        v21 = propertyLists.size + 1;
        if ( propertyLists.size + 1 <= propertyLists.capacity )
          goto LABEL_48;
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
LABEL_48:
          v25 = propertyLists.p;
        }
        else
        {
          v23 = 8i64 * v22;
          if ( !is_mul_ok(v22, 8ui64) )
            v23 = -1i64;
          v24 = UFG::qMalloc(v23, "qArray.Add", 0i64);
          v25 = (UFG::qPropertyList **)v24;
          v26 = propertyLists.p;
          if ( propertyLists.p )
          {
            v27 = 0i64;
            if ( propertyLists.size )
            {
              do
              {
                v24[v27].mNext = (UFG::allocator::free_link *)v26[v27];
                v27 = (unsigned int)(v27 + 1);
                v26 = propertyLists.p;
              }
              while ( (unsigned int)v27 < propertyLists.size );
            }
            operator delete[](v26);
          }
          propertyLists.p = v25;
          propertyLists.capacity = v22;
        }
        propertyLists.size = v21;
        v25[v20] = (UFG::qPropertyList *)name[0];
        ++v16;
        v5 = v41;
      }
      while ( v16 < v41->size );
      v28 = v17;
      v11 = currentPath;
      v6 = v40;
      v7 = v39;
      v15 = v28;
      v8 = v38;
      v10 = *(bool **)&rect.mX;
    }
    UFG::DUIContext::BeginIndent(v6);
    if ( !v8->mHasGenerantedChildren )
    {
      UFG::Editor::PropertyProxy_PropertyList::GenerateChildren(v8, &propertyLists, *v10);
      v8->mHasGenerantedChildren = 1;
    }
    UFG::DUIContext::BeginGridLayout(v6, 2, 1, 4);
    if ( v15 == 29 )
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
      v29 = GetStringFromPropertySetType(v15);
      UFG::DUIContext::Label(v6, v29);
    }
    if ( (unsigned __int8)UFG::DUIContext::Button(v6, "Add Item", 0x10u) )
    {
      if ( v15 == 29 )
        v15 = (unsigned int)GetPropertySetDataTypeFromString(UFG::Editor::PropertyProxy_Container::mPropTypes[v8->mSelectedTypeOption]);
      UFG::qPropertyPath::Push(v11, 0);
      v7->mPendingValueChange.mType = 4;
      v7->mPendingValueChange.mNewItemType = v15;
      UFG::qPropertyPath::operator=(&v7->mPendingValueChange.mPath, v11);
      UFG::qPropertyPath::Pop(v11);
    }
    UFG::DUIContext::EndLayoutHorizontal(v6);
    for ( i = (signed __int64)&v8->mChildren.mChildrenOrdered.mNode.mNext[-1].mNext;
          (bool *)i != v10;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      UFG::qPropertyPath::Push(v11, *(_DWORD *)(i + 32));
      UFG::DUIContext::GetLayoutRect(v6, &result, 0, 0);
      v31 = result;
      _mm_store_si128((__m128i *)&rect, (__m128i)result);
      *(_QWORD *)&v31.mX = (unsigned __int128)_mm_srli_si128((__m128i)v31, 8);
      rect.mW = v31.mX - v31.mY;
      UFG::DUIContext::SetLayoutRect(v6, &rect);
      (*(void (__fastcall **)(signed __int64, UFG::Editor::PropertyBrowser *, UFG::DUIContext *, UFG::qArray<UFG::qPropertyList *,0> *, UFG::qPropertyPath *))(*(_QWORD *)i + 8i64))(
        i,
        v7,
        v6,
        &propertyLists,
        v11);
      v32 = result;
      _mm_store_si128((__m128i *)name, (__m128i)result);
      LODWORD(name[1]) = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v32, 12));
      LODWORD(name[0]) = rect.mX + rect.mW;
      UFG::DUIContext::SetLayoutRect(v6, (UFG::DUIRect *)name);
      if ( (unsigned __int8)UFG::DUIContext::Button(v6, "-", 0x10u) )
      {
        v7->mPendingValueChange.mType = 3;
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
void __fastcall UFG::Editor::GetPropertyInstancesRecurse(UFG::qPropertySet *propertySet, UFG::qArray<UFG::Editor::PropertyInstance,0> *instances)
{
  unsigned int v2; // ebp
  UFG::qArray<UFG::Editor::PropertyInstance,0> *v3; // rdi
  UFG::qPropertySet *v4; // rbx
  unsigned int v5; // esi
  UFG::qSymbol *v6; // rax
  int v7; // er8
  bool v8; // al
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // r9
  unsigned int i; // er8
  signed __int64 v16; // rcx
  signed __int64 v17; // rdx
  UFG::Editor::PropertyInstance *v18; // rcx
  UFG::Editor::PropertyInstance *v19; // rdx
  UFG::qPropertySet *v20; // rax
  UFG::allocator::free_link *v21; // [rsp+20h] [rbp-38h]
  __int64 v22; // [rsp+28h] [rbp-30h]
  __int64 v23; // [rsp+38h] [rbp-20h]
  unsigned int v24; // [rsp+60h] [rbp+8h]
  unsigned int v25; // [rsp+70h] [rbp+18h]
  UFG::qPropertySet *v26; // [rsp+78h] [rbp+20h]

  if ( propertySet )
  {
    v2 = 0;
    v3 = instances;
    v4 = propertySet;
    v26 = propertySet;
    v5 = 0;
    v24 = 0;
    if ( propertySet->mNumProperties > 0u )
    {
      do
      {
        v6 = UFG::qPropertySet::GetPropertyNameFromIndex(v4, v5);
        v7 = 0;
        if ( v3->size )
        {
          while ( v3->p[v7].mPropertyNameUID != v6->mUID )
          {
            if ( ++v7 >= v3->size )
              goto LABEL_6;
          }
        }
        else
        {
LABEL_6:
          LODWORD(v22) = (UFG::qSymbol)v6->mUID;
          LODWORD(v23) = UFG::qPropertySet::GetPropertyTypeFromIndex(v4, v5);
          v8 = UFG::qPropertySet::PropertyIsDefaultIdx(v4, v5);
          v9 = v3->size;
          BYTE4(v23) = v8;
          v10 = v3->capacity;
          v11 = v3->size + 1;
          v25 = v3->size;
          if ( v11 > v10 )
          {
            v12 = 1;
            if ( v10 )
              v12 = 2 * v10;
            for ( ; v12 < v11; v12 *= 2 )
              ;
            if ( v12 - v11 > 0x10000 )
              v12 = v3->size + 65537;
            if ( v12 != v9 )
            {
              v13 = 24i64 * v12;
              if ( !is_mul_ok(v12, 0x18ui64) )
                v13 = -1i64;
              v14 = UFG::qMalloc(v13, "qArray.Add", 0i64);
              v21 = v14;
              if ( v3->p )
              {
                for ( i = 0; i < v3->size; v14[v17 * 3 + 2] = *(UFG::allocator::free_link *)&v18[v17].mPropertyType )
                {
                  v16 = i++;
                  v17 = v16;
                  v18 = v3->p;
                  v14[v17 * 3] = *(UFG::allocator::free_link *)&v18[v17].mPropertyNameUID;
                  v14[v17 * 3 + 1] = (UFG::allocator::free_link)v18[v17].mPropertySet;
                }
                operator delete[](v3->p);
                v14 = v21;
              }
              v9 = v25;
              v3->p = (UFG::Editor::PropertyInstance *)v14;
              v3->capacity = v12;
            }
            v4 = v26;
          }
          v3->size = v11;
          v5 = v24;
          v19 = &v3->p[v9];
          *(_QWORD *)&v19->mPropertyNameUID = v22;
          v19->mPropertySet = v4;
          *(_QWORD *)&v19->mPropertyType = v23;
        }
        v24 = ++v5;
      }
      while ( v5 < v4->mNumProperties );
    }
    if ( (unsigned int)UFG::qPropertySet::NumParents(v4) )
    {
      do
      {
        v20 = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v4, v2);
        if ( v20 )
          UFG::Editor::GetPropertyInstancesRecurse(v20, v3);
        ++v2;
      }
      while ( v2 < (unsigned int)UFG::qPropertySet::NumParents(v4) );
    }
  }
}

// File Line: 1412
// RVA: 0x20C8B0
void __fastcall UFG::Editor::GetSharedProperties(UFG::qArray<UFG::Editor::PropertyInstance,0> *shared_property_uids, UFG::qArray<UFG::qPropertySet *,0> *propertySets)
{
  UFG::qArray<UFG::qPropertySet *,0> *v2; // rdi
  char *v3; // r15
  UFG::qArray<UFG::Editor::PropertyInstance,0> *v4; // rsi
  UFG::qPropertySet *v5; // rcx
  unsigned int v6; // er12
  UFG::Editor::PropertyInstance *v7; // r13
  signed __int64 v8; // r15
  unsigned int v9; // edi
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::Editor::PropertyInstance *v12; // r14
  UFG::Editor::PropertyInstance *v13; // r8
  signed __int64 v14; // r9
  signed __int64 v15; // rdx
  signed __int64 v16; // rcx
  unsigned int v17; // ebx
  UFG::qArray<UFG::Editor::PropertyInstance,0> *v18; // r14
  UFG::Editor::PropertyInstance *v19; // rcx
  UFG::qPropertySet *v20; // rbx
  unsigned int v21; // er12
  unsigned int v22; // edi
  UFG::Editor::PropertyInstance *v23; // rbx
  int v24; // edx
  signed __int64 v25; // r8
  __int64 v26; // r13
  bool v27; // zf
  __int64 v28; // r15
  unsigned int v29; // edi
  unsigned int v30; // ebx
  unsigned int v31; // ebx
  unsigned __int64 v32; // rax
  UFG::allocator::free_link *v33; // r14
  __int64 v34; // r8
  signed __int64 v35; // rdx
  UFG::Editor::PropertyInstance *v36; // rcx
  UFG::Editor::PropertyInstance *v37; // rdx
  UFG::qPropertySet *v38; // [rsp+30h] [rbp-49h]
  char *v39; // [rsp+38h] [rbp-41h]
  UFG::qArray<UFG::Editor::PropertyInstance,0> instances; // [rsp+48h] [rbp-31h]
  __int64 v41; // [rsp+68h] [rbp-11h]
  char ptr; // [rsp+70h] [rbp-9h]
  UFG::qArray<UFG::Editor::PropertyInstance,0> v43; // [rsp+80h] [rbp+7h]
  UFG::qArray<UFG::Editor::PropertyInstance,0> *_dst; // [rsp+E0h] [rbp+67h]
  UFG::qArray<UFG::qPropertySet *,0> *v45; // [rsp+E8h] [rbp+6Fh]
  signed int v46; // [rsp+F0h] [rbp+77h]
  UFG::qArray<UFG::Editor::PropertyInstance,0> *v47; // [rsp+F8h] [rbp+7Fh]

  v45 = propertySets;
  _dst = shared_property_uids;
  v2 = propertySets;
  `eh vector constructor iterator(
    &ptr,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  v3 = &ptr;
  v4 = &v43;
  v5 = *v2->p;
  instances.p = 0i64;
  *(_QWORD *)&instances.size = 0i64;
  UFG::Editor::GetPropertyInstancesRecurse(v5, &instances);
  v6 = 0;
  if ( instances.size > 0 )
  {
    do
    {
      v7 = &instances.p[v6];
      v8 = v43.size;
      v9 = v43.size + 1;
      if ( v43.size + 1 <= v43.capacity )
        goto LABEL_59;
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
LABEL_59:
        v12 = v43.p;
      }
      else
      {
        v11 = 24i64 * v10;
        if ( !is_mul_ok(v10, 0x18ui64) )
          v11 = -1i64;
        v12 = (UFG::Editor::PropertyInstance *)UFG::qMalloc(v11, "qArray.Add", 0i64);
        v13 = v43.p;
        if ( v43.p )
        {
          v14 = 0i64;
          if ( v43.size )
          {
            do
            {
              v15 = v14;
              *(_QWORD *)&v12[v15].mPropertyNameUID = *(_QWORD *)&v13[v14].mPropertyNameUID;
              v12[v15].mPropertySet = v13[v14].mPropertySet;
              *(_QWORD *)&v12[v15].mPropertyType = *(_QWORD *)&v13[v14].mPropertyType;
              v14 = (unsigned int)(v14 + 1);
              v13 = v43.p;
            }
            while ( (unsigned int)v14 < v43.size );
          }
          operator delete[](v13);
        }
        v43.p = v12;
        v43.capacity = v10;
      }
      v43.size = v9;
      v16 = v8;
      *(_QWORD *)&v12[v16].mPropertyNameUID = *(_QWORD *)&v7->mPropertyNameUID;
      v12[v16].mPropertySet = v7->mPropertySet;
      *(_QWORD *)&v12[v16].mPropertyType = *(_QWORD *)&v7->mPropertyType;
      ++v6;
    }
    while ( v6 < instances.size );
    v4 = &v43;
    v2 = v45;
    v3 = &ptr;
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
              v25 = (signed __int64)&v18->p[v24];
              if ( *(_DWORD *)v25 == v23->mPropertyNameUID )
                break;
              if ( ++v24 >= v18->size )
                goto LABEL_51;
            }
            v26 = *(_QWORD *)v25;
            v38 = *(UFG::qPropertySet **)(v25 + 8);
            v41 = *(_QWORD *)(v25 + 16);
            if ( !*(_BYTE *)(v25 + 20) || (v27 = v23->mIsDefault == 0, BYTE4(v41) = 1, v27) )
              BYTE4(v41) = 0;
            v28 = v4->size;
            v29 = v28 + 1;
            v30 = v4->capacity;
            if ( (signed int)v28 + 1 > v30 )
            {
              if ( v30 )
                v31 = 2 * v30;
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
                  v34 = 0i64;
                  if ( v4->size )
                  {
                    do
                    {
                      v35 = 3 * v34;
                      v36 = v4->p;
                      v33[v35] = *(UFG::allocator::free_link *)&v36[v34].mPropertyNameUID;
                      v33[v35 + 1] = (UFG::allocator::free_link)v36[v34].mPropertySet;
                      v33[v35 + 2] = *(UFG::allocator::free_link *)&v36[v34].mPropertyType;
                      v34 = (unsigned int)(v34 + 1);
                    }
                    while ( (unsigned int)v34 < v4->size );
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
      v2 = v45;
    }
    while ( v17 < v45->size );
  }
  UFG::qArray<UFG::Editor::PropertyInstance,0>::Clone(v4, _dst);
  if ( instances.p )
    operator delete[](instances.p);
  instances.p = 0i64;
  *(_QWORD *)&instances.size = 0i64;
  `eh vector destructor iterator(
    &ptr,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
}

// File Line: 1465
// RVA: 0x20B600
char __fastcall UFG::Editor::GetCommonValue(UFG::qArray<UFG::qPropertySet *,0> *selection, UFG::qSymbol *propertyName, qPropertySetVariant *value)
{
  qPropertySetVariant *v3; // rsi
  UFG::qSymbol *v4; // rbp
  UFG::qArray<UFG::qPropertySet *,0> *v5; // rdi
  __int64 v6; // rbx
  qPropertySetVariant valuea; // [rsp+30h] [rbp-C8h]

  v3 = value;
  v4 = propertyName;
  v5 = selection;
  v6 = 0i64;
  if ( selection->size )
  {
    do
    {
      if ( (_DWORD)v6 )
      {
        valuea.meType = 29;
        UFG::qString::qString(&valuea.mValueString);
        *(_QWORD *)&valuea.mValueSymbol.mUID = -1i64;
        valuea.mValueWiseSymbol.mUID = -1;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        UFG::qPropertySet::GetVariant(v5->p[v6], v4, &valuea, DEPTH_RECURSE);
        if ( !qPropertySetVariant::operator==(&valuea, v3) )
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
        UFG::qPropertySet::GetVariant(*v5->p, v4, v3, DEPTH_RECURSE);
      }
      v6 = (unsigned int)(v6 + 1);
    }
    while ( (unsigned int)v6 < v5->size );
  }
  return 1;
}

// File Line: 1496
// RVA: 0x2020C0
void __fastcall UFG::Editor::PropertyBrowser::PropertyBrowser(UFG::Editor::PropertyBrowser *this)
{
  UFG::Editor::PropertyBrowser *v1; // rbx
  UFG::Editor::PropertyProxy_PropertySet *v2; // rcx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v3; // rax
  UFG::Editor::PropertyProxyCollection *v4; // rax
  UFG::Editor::PropertyBrowser *v5; // [rsp+38h] [rbp-30h]
  void (__fastcall *v6)(UFG::Editor::PropertyBrowser *, UFG::Event *); // [rsp+40h] [rbp-28h]

  v1 = this;
  v2 = &this->mTopLevelProperties;
  v3 = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  v2->mDataType = 26;
  v2->mPropertyName = UFG::gNullQSymbol;
  v2->mArrayIndex = -1;
  v2->mParent = 0i64;
  *(_WORD *)&v2->mIsLocal = 0;
  v2->mIsListProperty = 0;
  v2->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_Container::`vftable;
  v4 = &v2->mChildren;
  v4->mChildrenOrdered.mNode.mPrev = &v4->mChildrenOrdered.mNode;
  v4->mChildrenOrdered.mNode.mNext = &v4->mChildrenOrdered.mNode;
  v2->mHasGenerantedChildren = 0;
  v2->mSelectedTypeOption = 0;
  v2->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::qString(&v2->mNewPropertyName);
  v1->mpSelection = 0i64;
  UFG::Editor::ValueChange::ValueChange(&v1->mPendingValueChange);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mExpansionStates.mTree);
  v1->mScrollPosition = 0i64;
  *(_DWORD *)&v1->mHideUnassigned = 65792;
  v6 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v5 = v1;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v5,
    0x23DF27A9u,
    0i64,
    0);
  v6 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v5 = v1;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v5,
    0x23C51C72u,
    0i64,
    0);
  v6 = UFG::Editor::PropertyBrowser::OnSelectionChanged;
  v5 = v1;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v5,
    0x245A7FF5u,
    0i64,
    0);
  v6 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v5 = v1;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v5,
    0x65C2B07Bu,
    0i64,
    0);
  v6 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v5 = v1;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v5,
    0x9670AC65,
    0i64,
    0);
  *(_QWORD *)v1->mColWidths = 0i64;
}

// File Line: 1509
// RVA: 0x203740
void __fastcall UFG::Editor::PropertyBrowser::~PropertyBrowser(UFG::Editor::PropertyBrowser *this)
{
  UFG::Editor::PropertyBrowser *v1; // rsi
  Render::SkinningCacheNode *v2; // rbx
  UFG::Editor::PropertyBrowser *v3; // [rsp+28h] [rbp-20h]
  void (__fastcall *v4)(UFG::Editor::PropertyBrowser *, UFG::Event *); // [rsp+30h] [rbp-18h]

  v1 = this;
  v4 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3 = this;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v3,
    0x9670AC65);
  v4 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3 = v1;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v3,
    0x65C2B07Bu);
  v4 = UFG::Editor::PropertyBrowser::OnSelectionChanged;
  v3 = v1;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v3,
    0x245A7FF5u);
  v4 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3 = v1;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v3,
    0x23C51C72u);
  v4 = UFG::Editor::PropertyBrowser::OnTransformationChanged;
  v3 = v1;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v3,
    0x23DF27A9u);
  while ( v1->mExpansionStates.mTree.mCount )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mExpansionStates);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mExpansionStates,
      &v2->mNode);
    operator delete[](v2);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mExpansionStates);
  UFG::Editor::ValueChange::~ValueChange(&v1->mPendingValueChange);
  v1->mTopLevelProperties.vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::~qString(&v1->mTopLevelProperties.mNewPropertyName);
  UFG::Editor::PropertyProxy_Container::~PropertyProxy_Container((UFG::Editor::PropertyProxy_Container *)&v1->mTopLevelProperties.vfptr);
}

// File Line: 1519
// RVA: 0x210750
void __fastcall UFG::Editor::PropertyBrowser::Refresh(UFG::Editor::PropertyBrowser *this)
{
  UFG::Editor::PropertyBrowser *v1; // rax
  UFG::qPropertySet **v2; // r12
  unsigned int v3; // er14
  unsigned int v4; // esi
  UFG::Editor::SelectionSet *v5; // rdi
  int v6; // er13
  signed __int64 v7; // rbx
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  UFG::Editor::SmartHandleObject *v10; // rax
  _QWORD *v11; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rcx
  unsigned int v15; // edx
  __int64 v16; // r8
  UFG::Editor::FnModifier *v17; // rax
  void *(__fastcall *v18)(UFG::Editor::FnModifier *, unsigned int); // rbp
  __int64 v19; // r15
  unsigned int v20; // edi
  unsigned int v21; // ebx
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::qPropertySet **v24; // rsi
  UFG::allocator::free_link *v25; // rdx
  __int64 v26; // r8
  UFG::qArray<UFG::qPropertySet *,0> propertySets; // [rsp+28h] [rbp-50h]
  UFG::Editor::PropertyBrowser *v28; // [rsp+80h] [rbp+8h]
  UFG::qSymbol symbol; // [rsp+88h] [rbp+10h]
  UFG::Editor::SelectionSet *v30; // [rsp+90h] [rbp+18h]

  v28 = this;
  v1 = this;
  v2 = 0i64;
  propertySets.p = 0i64;
  v3 = 0;
  *(_QWORD *)&propertySets.size = 0i64;
  v4 = 0;
  v5 = this->mpSelection;
  if ( !v5 )
    v5 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v30 = v5;
  v6 = 0;
  if ( v5->mDAGPaths.size )
  {
    while ( 1 )
    {
      v7 = (signed __int64)&v5->mDAGPaths.p[v6];
      if ( *(_DWORD *)(v7 + 40) )
        break;
LABEL_45:
      if ( ++v6 >= v5->mDAGPaths.size )
      {
        v1 = v28;
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
                v11 = &v10->mSmartHandleList.mNode.mPrev;
                v12 = v10->mSmartHandleList.mNode.mPrev;
                v12->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v7;
                *(_QWORD *)v7 = v12;
                *(_QWORD *)(v7 + 8) = v11;
                *v11 = v7;
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
          v17 = *(UFG::Editor::FnModifier **)(v16 + 8 * v14);
          if ( v17->mTypeID == -1570916174 )
            break;
          v14 = (unsigned int)(v14 + 1);
          if ( (unsigned int)v14 >= v15 )
            goto LABEL_19;
        }
      }
      else
      {
LABEL_19:
        v17 = 0i64;
      }
    }
    else
    {
      v17 = UFG::Editor::FnObject::GetModifier(*(UFG::Editor::FnObject **)(v7 + 16), &symbol);
      if ( !v17 || v17->mTypeID != -1570916174 )
        goto LABEL_24;
    }
    if ( v17 )
    {
      v18 = v17[1].vfptr->__vecDelDtor;
      goto LABEL_25;
    }
LABEL_24:
    v18 = 0i64;
LABEL_25:
    if ( v18 )
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
      v2[v19] = (UFG::qPropertySet *)v18;
      v5 = v30;
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
  UFG::Editor::SelectionSet *v2; // rax

  v2 = this->mpSelection;
  if ( !v2 )
    v2 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  if ( (UFG::Editor::SelectionSet *)evt->mUserData0 == v2 )
    this->mbDirty = 1;
}

// File Line: 1576
// RVA: 0x20F700
void __fastcall UFG::Editor::PropertyBrowser::OnTransformationChanged(UFG::Editor::PropertyBrowser *this, UFG::Event *__formal)
{
  this->mbDirty = 1;
}

// File Line: 1582
// RVA: 0x20DDA0
UFG::qBaseNodeRB *__fastcall UFG::Editor::PropertyBrowser::IsExpanded(UFG::Editor::PropertyBrowser *this, unsigned int uid)
{
  unsigned int v2; // edi
  UFG::Editor::PropertyBrowser *v3; // rsi
  UFG::qBaseTreeRB *v4; // rax
  UFG::allocator::free_link *v6; // rbx

  v2 = uid;
  v3 = this;
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
    LODWORD(v6[3].mNext) = v2;
    LOBYTE(v6[4].mNext) = 0;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&v3->mExpansionStates.mTree, (UFG::qBaseNodeRB *)v6);
  return (UFG::qBaseNodeRB *)&v6[4];
}

// File Line: 1595
// RVA: 0x205110
void __fastcall UFG::Editor::PropertyBrowser::ApplyValueChange(UFG::Editor::PropertyBrowser *this)
{
  UFG::Editor::PropertyBrowser *v1; // r14
  UFG::Editor::SelectionSet *v2; // rax
  unsigned int v3; // er12
  signed __int64 v4; // rdi
  UFG::Editor::DAGPath *v5; // rbx
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::Editor::FnObject *v8; // rax
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *v9; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v10; // rax
  UFG::Editor::SmartHandleObject *v11; // rcx
  UFG::Editor::DAGPath *v12; // rcx
  UFG::Editor::FnModifier *v13; // rax
  UFG::qPropertySet *v14; // rbx
  unsigned int v15; // er13
  __int64 v16; // rsi
  int v17; // er15
  UFG::qBaseNodeRB *v18; // rdi
  unsigned int v19; // eax
  UFG::qPropertySet *v20; // rax
  UFG::qPropertySet *v21; // rdi
  UFG::qPropertyList *v22; // rax
  UFG::qPropertyList *v23; // rdi
  signed int v24; // ebp
  __int64 v25; // rax
  UFG::qPropertySet *v26; // rcx
  UFG::Editor::ValueChange::TYPE v27; // eax
  unsigned int v28; // eax
  char *v29; // rax
  char *v30; // rax
  char *v31; // rax
  UFG::qPropertyList *v32; // rcx
  UFG::allocator::free_link *v33; // rax
  UFG::Editor::ValueChange::TYPE v34; // eax
  UFG::Editor::ValueChange::TYPE v35; // eax
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+8h]
  UFG::qSymbol interfaceName; // [rsp+88h] [rbp+10h]
  UFG::Editor::SelectionSet *v38; // [rsp+90h] [rbp+18h]
  UFG::qSymbol *v39; // [rsp+98h] [rbp+20h]

  v1 = this;
  v2 = this->mpSelection;
  if ( !v2 )
    v2 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v38 = v2;
  v3 = 0;
  if ( v2->mDAGPaths.size )
  {
    while ( 1 )
    {
      v4 = v3;
      v5 = &v2->mDAGPaths.p[v4];
      if ( v5->mPathType != 1 )
      {
        if ( !v5->mFnObject.mPtr )
        {
          v6 = v5->mSystemName.mUID;
          if ( v6 )
          {
            v7 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v6);
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
                    v5->mFnObject.mPtr = (UFG::Editor::SmartHandleObject *)&v8->vfptr;
                    v9 = &v8->mSmartHandleList;
                    v10 = v8->mSmartHandleList.mNode.mPrev;
                    v10->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v5->mFnObject.mPrev;
                    v5->mFnObject.mPrev = v10;
                    v5->mFnObject.mNext = &v9->mNode;
                    v9->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v5->mFnObject.mPrev;
                  }
                }
              }
            }
          }
        }
        v11 = v5->mFnObject.mPtr;
        if ( v11 )
        {
          if ( ((unsigned __int8 (__cdecl *)(UFG::Editor::SmartHandleObject *))v11->vfptr[4].__vecDelDtor)(v11) )
          {
            v12 = &v38->mDAGPaths.p[v4];
            if ( v12->mElements.size )
            {
              v39 = &interfaceName;
              interfaceName.mUID = v12->mInterfaceName.mUID;
              v13 = UFG::Editor::DAGPath::GetInterface(v12, 0xA25DB8B2, (UFG::qSymbol)&interfaceName);
              v14 = (UFG::qPropertySet *)(v13 ? v13[1].vfptr->__vecDelDtor : 0i64);
              if ( v14 )
              {
                if ( !(v14->mFlags & 1) )
                {
                  v15 = v1->mPendingValueChange.mPath.mPath.size;
                  v16 = 0i64;
                  if ( v15 )
                    break;
                }
              }
            }
          }
        }
      }
LABEL_87:
      ++v3;
      v2 = v38;
      if ( v3 >= v38->mDAGPaths.size )
        return;
    }
    v17 = v15 - 1;
    while ( 1 )
    {
      UFG::qSymbol::qSymbol(&result, v1->mPendingValueChange.mPath.mPath.p[v16]);
      if ( v14 )
      {
        if ( v14->mSchemaName.mUID == UFG::gNullQSymbol.mUID )
        {
          v18 = UFG::PropertySetManager::GetSchemaForComponentPropertyName((UFG::qSymbol *)&result);
          if ( v18 )
          {
            if ( !UFG::qPropertySet::PropertyExists(v14, (UFG::qSymbol *)&result, 0) )
              UFG::PropertySetManager::AddComponentPropertySet(v14, (UFG::SchemaDef *)v18, 0i64);
          }
        }
      }
      v19 = UFG::qPropertySet::GetPropertyTypeFromName(v14, (UFG::qSymbol *)&result, DEPTH_RECURSE);
      if ( v19 != 26 )
        break;
      if ( (_DWORD)v16 != v17 || v1->mPendingValueChange.mType != 3 )
      {
        v20 = UFG::qPropertySet::Get<UFG::qPropertySet>(v14, (UFG::qSymbol *)&result, DEPTH_RECURSE);
        v21 = v20;
        if ( v20->mFlags & 1 )
        {
          v21 = UFG::qPropertySet::Clone(v20);
          UFG::qPropertySet::Set<UFG::qPropertySet>(v14, (UFG::qSymbol *)&result, v21);
        }
        v14 = v21;
LABEL_67:
        v16 = (unsigned int)(v16 + 1);
        goto LABEL_68;
      }
      UFG::qPropertySet::RemovePropertyByName(v14, (UFG::qSymbol *)&result);
LABEL_68:
      if ( (unsigned int)v16 >= v15 )
        goto LABEL_87;
    }
    if ( v19 != 25 )
    {
      if ( (v19 != 29 || (unsigned int)(v1->mPendingValueChange.mType - 3) <= 1) && v14 )
      {
        v35 = v1->mPendingValueChange.mType;
        switch ( v35 )
        {
          case 4:
            UFG::qPropertySet::AddProperty(v14, (UFG::qSymbol *)&result, v1->mPendingValueChange.mNewItemType);
            break;
          case 3:
            UFG::qPropertySet::RemovePropertyByName(v14, (UFG::qSymbol *)&result);
            break;
          case 1:
            UFG::qPropertySet::SetVariant(v14, (UFG::qSymbol *)&result, &v1->mPendingValueChange.mSimpleValue);
            break;
          case 2:
            UFG::Editor::SetVectorValue(v14, (UFG::qSymbol *)&result, &v1->mPendingValueChange.mVectoredValue);
            break;
        }
      }
      goto LABEL_87;
    }
    v22 = UFG::qPropertySet::Get<UFG::qPropertyList>(v14, (UFG::qSymbol *)&result, DEPTH_RECURSE);
    v23 = v22;
    if ( v22->mFlags & 1 )
    {
      v23 = (UFG::qPropertyList *)UFG::qPropertyList::Clone(v22);
      UFG::qPropertySet::Set<UFG::qPropertyList>(v14, (UFG::qSymbol *)&result, v23);
    }
    v14 = 0i64;
    v16 = (unsigned int)(v16 + 1);
    if ( (unsigned int)v16 >= v1->mPendingValueChange.mPath.mPath.size )
    {
      v24 = -1;
    }
    else
    {
      v24 = v1->mPendingValueChange.mPath.mPath.p[v16];
      if ( v24 >= 0 )
      {
LABEL_47:
        if ( v23->mTypeUID == 25 )
        {
          v31 = UFG::qPropertyList::GetValuePtr(v23, 0x19u, v24);
          if ( v31 && *(_QWORD *)v31 )
            v32 = (UFG::qPropertyList *)&v31[*(_QWORD *)v31];
          else
            v32 = 0i64;
          if ( v32->mFlags & 1 )
          {
            v33 = UFG::qPropertyList::Clone(v32);
            UFG::qPropertyList::Set<UFG::qPropertyList>(v23, v24, (UFG::qPropertyList *)v33);
          }
        }
        else
        {
          if ( v23->mTypeUID != 26 )
          {
            v34 = v1->mPendingValueChange.mType;
            switch ( v34 )
            {
              case 1:
                UFG::qPropertyList::SetVariant(v23, v24, &v1->mPendingValueChange.mSimpleValue);
                break;
              case 3:
                UFG::qPropertyList::Remove(v23, v24);
                break;
              case 4:
                UFG::qPropertyList::AddItem(v23, v1->mPendingValueChange.mNewItemType);
                break;
            }
            goto LABEL_87;
          }
          if ( (_DWORD)v16 == v17 )
          {
            v27 = v1->mPendingValueChange.mType;
            if ( v27 == 4 )
            {
              v28 = UFG::qPropertyList::AddItem(v23, UID_propertyset);
              v29 = UFG::qPropertyList::GetValuePtr(v23, 0x1Au, v28);
              if ( v29 && *(_QWORD *)v29 )
                v14 = (UFG::qPropertySet *)&v29[*(_QWORD *)v29];
            }
            else if ( v27 == 3 )
            {
              UFG::qPropertyList::Remove(v23, v24);
            }
          }
          else
          {
            v30 = UFG::qPropertyList::GetValuePtr(v23, 0x1Au, v24);
            if ( v30 && *(_QWORD *)v30 )
              v14 = (UFG::qPropertySet *)&v30[*(_QWORD *)v30];
            if ( v14->mFlags & 1 )
            {
              v14 = UFG::qPropertySet::Clone(v14);
              UFG::qPropertyList::Set<UFG::qPropertySet>(v23, v24, v14);
            }
          }
        }
        goto LABEL_67;
      }
    }
    if ( v1->mPendingValueChange.mType == 3 )
    {
      if ( v23->mFlags & 0x10 && (v25 = v23->mOwner.mOffset) != 0 )
        v26 = (UFG::qPropertySet *)((char *)&v23->mOwner + v25);
      else
        v26 = 0i64;
      UFG::qPropertySet::RemovePropertyByName(v26, (UFG::qSymbol *)&result);
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
  int v4; // er15
  int v5; // eax
  UFG::allocator::free_link *v6; // r12
  unsigned int v7; // er14
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v8; // rsi
  unsigned int v9; // eax
  signed __int64 v10; // rbx
  char *v11; // rbx
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  UFG::Editor::SmartHandleObject *v14; // rax
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *v15; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v16; // rax
  __int64 v17; // rax
  __int64 v18; // rcx
  unsigned int v19; // edx
  __int64 v20; // r8
  UFG::Editor::FnModifier *v21; // rax
  void *(__fastcall *v22)(UFG::Editor::FnModifier *, unsigned int); // r12
  __int64 v23; // r13
  unsigned int v24; // edi
  unsigned int v25; // ebx
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  void *v28; // rsi
  char *v29; // rcx
  __int64 v30; // r8
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v31; // rax
  UFG::qSymbol **v32; // rbx
  bool v33; // al
  UFG::qBaseNodeRB *v34; // r13
  unsigned int v35; // edi
  unsigned int v36; // ebx
  unsigned __int64 v37; // rax
  UFG::allocator::free_link *v38; // rax
  UFG::allocator::free_link *v39; // rsi
  UFG::allocator::free_link *v40; // rdx
  __int64 v41; // r8
  UFG::Editor::DAGPath *v42; // rdi
  UFG::Editor::FnModifier *v43; // rax
  __int64 v44; // rax
  UFG::qString *v45; // rdx
  unsigned int v46; // esi
  bool v47; // bl
  bool v48; // bl
  bool v49; // bl
  bool v50; // bl
  bool v51; // bl
  bool v52; // bl
  __int64 v53; // r14
  UFG::Editor::FnModifier *v54; // rax
  __int64 v55; // rbx
  UFG::qString *v56; // rax
  UFG::Editor::Gizmo *v57; // rbx
  UFG::qMatrix44 *v58; // rax
  UFG::qVector4 v59; // xmm2
  UFG::qVector4 v60; // xmm1
  UFG::qVector4 v61; // xmm0
  UFG::qVector3 soln; // [rsp+30h] [rbp-D0h]
  __int64 v63; // [rsp+40h] [rbp-C0h]
  void *mem; // [rsp+48h] [rbp-B8h]
  UFG::DUIRect result; // [rsp+50h] [rbp-B0h]
  float val; // [rsp+60h] [rbp-A0h]
  float v67; // [rsp+64h] [rbp-9Ch]
  float v68; // [rsp+68h] [rbp-98h]
  int v69; // [rsp+70h] [rbp-90h]
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v70; // [rsp+78h] [rbp-88h]
  UFG::qPropertyPath v71; // [rsp+80h] [rbp-80h]
  UFG::qSymbol v72; // [rsp+90h] [rbp-70h]
  __int64 v73; // [rsp+98h] [rbp-68h]
  UFG::qMatrix44 rot; // [rsp+A0h] [rbp-60h]
  UFG::qMatrix44 affine; // [rsp+E0h] [rbp-20h]
  UFG::qMatrix44 v76; // [rsp+120h] [rbp+20h]
  UFG::Editor::PropertyBrowser *v77; // [rsp+1C0h] [rbp+C0h]
  UFG::DUIContext *v78; // [rsp+1C8h] [rbp+C8h]
  UFG::qSymbol interfaceName; // [rsp+1D0h] [rbp+D0h]
  UFG::qSymbol symbol; // [rsp+1D8h] [rbp+D8h]

  v78 = dui;
  v77 = this;
  v73 = -2i64;
  v2 = dui;
  v3 = this;
  v4 = 0;
  v69 = 0;
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
    v3->mPendingValueChange.mType = 0;
  }
  UFG::qPropertyPath::qPropertyPath(&v71);
  mem = 0i64;
  v63 = 0i64;
  v6 = 0i64;
  *(_QWORD *)&result.mW = 0i64;
  v7 = 0;
  *(_QWORD *)&result.mX = 0i64;
  v8 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&v3->mpSelection->mPrev;
  if ( !v8 )
    v8 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v70 = v8;
  v9 = 0;
  interfaceName.mUID = 0;
  if ( LODWORD(v8[3].mNext) )
  {
    while ( 1 )
    {
      v10 = 88i64 * v9;
      *(_QWORD *)&soln.x = v10;
      v11 = (char *)v8[4].mPrev + v10;
      if ( *((_DWORD *)v11 + 10) )
        break;
LABEL_53:
      v31 = v8[4].mPrev;
      v32 = (UFG::qSymbol **)((char *)v31 + *(_QWORD *)&soln.x);
      v33 = 1;
      if ( *(_DWORD *)((char *)&v31[2].mNext + *(_QWORD *)&soln.x) )
      {
        v4 |= 1u;
        v69 = v4;
        if ( UFG::Editor::DAGPath::GetSystemName((UFG::Editor::DAGPath *)((char *)v31 + *(_QWORD *)&soln.x), &v72)->mUID == UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
          v33 = 0;
      }
      if ( v4 & 1 )
      {
        v4 &= 0xFFFFFFFE;
        v69 = v4;
      }
      if ( !v33 )
      {
        v34 = UFG::Simulation::GetSimObject(&UFG::gSim, v32[6]);
        if ( v34 )
        {
          symbol.mUID = v7;
          v35 = v7 + 1;
          if ( v7 + 1 > result.mY )
          {
            v36 = 1;
            if ( result.mY )
              v36 = 2 * result.mY;
            for ( ; v36 < v35; v36 *= 2 )
              ;
            if ( v36 <= 2 )
              v36 = 2;
            if ( v36 - v35 > 0x10000 )
              v36 = v7 + 65537;
            if ( v36 != v7 )
            {
              v37 = 8i64 * v36;
              if ( !is_mul_ok(v36, 8ui64) )
                v37 = -1i64;
              v38 = UFG::qMalloc(v37, "qArray.Add", 0i64);
              v39 = v38;
              if ( v6 )
              {
                if ( v7 )
                {
                  v40 = v38;
                  v41 = v7;
                  do
                  {
                    v40->mNext = *(UFG::allocator::free_link **)((char *)v40 + (char *)v6 - (char *)v38);
                    ++v40;
                    --v41;
                  }
                  while ( v41 );
                }
                operator delete[](v6);
              }
              v6 = v39;
              *(_QWORD *)&result.mW = v39;
              result.mY = v36;
              v8 = v70;
            }
          }
          ++v7;
          result.mX = v35;
          v6[symbol.mUID].mNext = (UFG::allocator::free_link *)v34;
        }
      }
      v9 = interfaceName.mUID + 1;
      interfaceName.mUID = v9;
      if ( v9 >= LODWORD(v8[3].mNext) )
      {
        v3 = v77;
        v2 = v78;
        goto LABEL_82;
      }
    }
    symbol.mUID = *((_DWORD *)v11 + 14);
    if ( *((_DWORD *)v11 + 20) == 1 )
      goto LABEL_30;
    if ( !*((_QWORD *)v11 + 2) )
    {
      v12 = *((_DWORD *)v11 + 8);
      if ( v12 )
      {
        v13 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v12);
        if ( v13 )
        {
          if ( v13 != (UFG::qBaseTreeRB *)8 )
          {
            v14 = UFG::Editor::DAGType::AquireFnObject(
                    (UFG::Editor::DAGType *)&v13[-1].mCount,
                    (UFG::Editor::DAGPath *)v11);
            if ( !*((_QWORD *)v11 + 2) )
            {
              if ( v14 )
              {
                *((_DWORD *)v11 + 6) = v14->mTypeId;
                *((_QWORD *)v11 + 2) = v14;
                v15 = &v14->mSmartHandleList;
                v16 = v14->mSmartHandleList.mNode.mPrev;
                v16->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v11;
                *(_QWORD *)v11 = v16;
                *((_QWORD *)v11 + 1) = v15;
                v15->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v11;
              }
            }
          }
        }
      }
    }
    v17 = *((_QWORD *)v11 + 2);
    if ( !v17 )
      goto LABEL_30;
    if ( *((_DWORD *)v11 + 14) == -1 )
    {
      v18 = 0i64;
      v19 = *(_DWORD *)(v17 + 64);
      if ( v19 )
      {
        v20 = *(_QWORD *)(v17 + 72);
        while ( 1 )
        {
          v21 = *(UFG::Editor::FnModifier **)(v20 + 8 * v18);
          if ( v21->mTypeID == -1570916174 )
            break;
          v18 = (unsigned int)(v18 + 1);
          if ( (unsigned int)v18 >= v19 )
            goto LABEL_25;
        }
      }
      else
      {
LABEL_25:
        v21 = 0i64;
      }
    }
    else
    {
      v21 = UFG::Editor::FnObject::GetModifier(*((UFG::Editor::FnObject **)v11 + 2), &symbol);
      if ( !v21 || v21->mTypeID != -1570916174 )
        goto LABEL_30;
    }
    if ( v21 )
    {
      v22 = v21[1].vfptr->__vecDelDtor;
LABEL_31:
      if ( v22 )
      {
        v23 = (unsigned int)v63;
        v24 = v63 + 1;
        if ( (unsigned int)(v63 + 1) <= HIDWORD(v63) )
          goto LABEL_107;
        if ( HIDWORD(v63) )
          v25 = 2 * HIDWORD(v63);
        else
          v25 = 1;
        for ( ; v25 < v24; v25 *= 2 )
          ;
        if ( v25 <= 2 )
          v25 = 2;
        if ( v25 - v24 > 0x10000 )
          v25 = v63 + 65537;
        if ( v25 == (_DWORD)v63 )
        {
LABEL_107:
          v28 = mem;
        }
        else
        {
          v26 = 8i64 * v25;
          if ( !is_mul_ok(v25, 8ui64) )
            v26 = -1i64;
          v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
          v28 = v27;
          v29 = (char *)mem;
          if ( mem )
          {
            v30 = 0i64;
            if ( (_DWORD)v63 )
            {
              do
              {
                v27[v30] = *(UFG::allocator::free_link *)&v29[8 * v30];
                v30 = (unsigned int)(v30 + 1);
                v29 = (char *)mem;
              }
              while ( (unsigned int)v30 < (unsigned int)v63 );
            }
            operator delete[](v29);
          }
          mem = v28;
          HIDWORD(v63) = v25;
        }
        LODWORD(v63) = v24;
        *((_QWORD *)v28 + v23) = v22;
        v8 = v70;
      }
      v6 = *(UFG::allocator::free_link **)&result.mW;
      goto LABEL_53;
    }
LABEL_30:
    v22 = 0i64;
    goto LABEL_31;
  }
LABEL_82:
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, 3);
  UFG::DUIContext::Checkbox(v2, "Hide Unassigned Properties", &v3->mHideUnassigned);
  UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPosition);
  UFG::DUIContext::BeginVerticalLayout(v2);
  if ( LODWORD(v8[3].mNext)
    && (unsigned __int8)UFG::DUIContext::Collapsible(v2, "World Transform", &v3->mWorldTransformExpanded) )
  {
    UFG::DUIContext::BeginIndent(v2);
    v42 = (UFG::Editor::DAGPath *)v8[4].mPrev;
    *(_QWORD *)&symbol.mUID = &interfaceName;
    interfaceName.mUID = v42->mInterfaceName.mUID;
    v43 = UFG::Editor::DAGPath::GetInterface(v42, 0x6F1FDCF3u, (__int64)&interfaceName);
    if ( v43 )
    {
      v44 = (__int64)v43->vfptr->Gizmo(v43);
      if ( v42->mSubElements.size )
        v45 = v42->mSubElements.p;
      else
        v45 = &UFG::Editor::DAGPath::sEmtpyString;
      (*(void (__fastcall **)(__int64, char *, UFG::qMatrix44 *))(*(_QWORD *)v44 + 8i64))(v44, v45->mData, &affine);
      UFG::DUIContext::Label(v2, "Position");
      val = affine.v3.x;
      v67 = affine.v3.y;
      v68 = affine.v3.z;
      v46 = 0;
      UFG::DUIContext::BeginGridLayout(v2, 3, 1, 0i64, 0i64, 0);
      v47 = UFG::DUIContext::NumericTextBox(v2, "x: ", &val, 0, 0.079999998);
      v48 = UFG::DUIContext::NumericTextBox(v2, "y: ", &v67, 0, 0.079999998) || v47;
      v49 = UFG::DUIContext::NumericTextBox(v2, "z: ", &v68, 0, 0.079999998) || v48;
      UFG::DUIContext::EndLayoutHorizontal(v2);
      UFG::DUIContext::Label(v2, "Rotation");
      soln = UFG::qVector3::msZero;
      UFG::Editor::Utility::DecomposeAffineEulerSmart_RoundedDegrees(&soln, &affine, 1);
      UFG::DUIContext::BeginGridLayout(v2, 3, 1, 0i64, 0i64, 0);
      v50 = UFG::DUIContext::NumericTextBox(v2, "x: ", &soln.x, 0, 0.079999998) || v49;
      v51 = UFG::DUIContext::NumericTextBox(v2, "y: ", &soln.y, 0, 0.079999998) || v50;
      v52 = UFG::DUIContext::NumericTextBox(v2, "z: ", &soln.z, 0, 0.079999998) || v51;
      UFG::DUIContext::EndLayoutHorizontal(v2);
      if ( v52 )
      {
        soln.x = (float)(soln.x * 3.1415927) * 0.0055555557;
        soln.y = (float)(soln.y * 3.1415927) * 0.0055555557;
        soln.z = (float)(soln.z * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixEuler(&rot, &soln);
        rot.v3.x = val;
        rot.v3.y = v67;
        rot.v3.z = v68;
        LODWORD(rot.v3.w) = (_DWORD)FLOAT_1_0;
        v53 = (__int64)v70;
        if ( LODWORD(v70[3].mNext) > 0 )
        {
          *(_QWORD *)&symbol.mUID = &interfaceName;
          do
          {
            interfaceName.mUID = v42->mInterfaceName.mUID;
            v54 = UFG::Editor::DAGPath::GetInterface(v42, 0x6F1FDCF3u, (__int64)&interfaceName);
            if ( v54 )
            {
              v55 = (__int64)v54->vfptr->Gizmo(v54);
              v56 = UFG::Editor::DAGPath::GetSubElement(v42);
              (*(void (__fastcall **)(__int64, char *, UFG::qMatrix44 *))(*(_QWORD *)v55 + 16i64))(
                v55,
                v56->mData,
                &rot);
            }
            ++v46;
          }
          while ( v46 < *(_DWORD *)(v53 + 56) );
        }
        v57 = UFG::Editor::mGizmo;
        v58 = UFG::Editor::Gizmo::DetermineTransform(UFG::Editor::mGizmo, &v76);
        v59 = v58->v1;
        v60 = v58->v2;
        v61 = v58->v3;
        v57->mTransform.v0 = v58->v0;
        v57->mTransform.v1 = v59;
        v57->mTransform.v2 = v60;
        v57->mTransform.v3 = v61;
      }
      v3 = v77;
    }
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (_DWORD)v63 )
    v3->mTopLevelProperties.vfptr->UpdateUI(
      (UFG::Editor::PropertyProxy *)&v3->mTopLevelProperties.vfptr,
      v3,
      v2,
      (UFG::qArray<UFG::qPropertySet *,0> *)&v63,
      &v71);
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
  v63 = 0i64;
  if ( v71.mPath.p )
    operator delete[](v71.mPath.p);
}

// File Line: 1939
// RVA: 0x21B7A0
void __fastcall UFG::Editor::PropertyBrowser::UpdateUI(UFG::Editor::PropertyBrowser *this, UFG::DUIContext *dui, UFG::qArray<UFG::Editor::PropertyBrowser::SimObjectEd *,0> *objects)
{
  UFG::qArray<UFG::Editor::PropertyBrowser::SimObjectEd *,0> *v3; // r15
  UFG::DUIContext *v4; // rbp
  __int64 v5; // r14
  UFG::Editor::PropertyBrowser::SimObjectEd *v6; // rsi
  char *v7; // rax
  unsigned int v8; // ebx
  UFG::SimComponent *v9; // rdi
  const char *v10; // rax
  unsigned __int16 v11; // di
  UFG::qString v12; // [rsp+28h] [rbp-40h]

  v3 = objects;
  v4 = dui;
  if ( objects->size )
  {
    v5 = 0i64;
    if ( objects->size )
    {
      do
      {
        v6 = v3->p[v5];
        if ( v6 )
        {
          v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6->m_Name);
          if ( v7 )
            UFG::DUIContext::Label(v4, v7);
          UFG::DUIContext::BeginIndent(v4);
          v8 = 0;
          if ( v6->m_Components.size )
          {
            do
            {
              v9 = v6->m_Components.p[v8].m_pComponent;
              if ( v9 )
              {
                v10 = (const char *)((__int64 (__fastcall *)(UFG::SimComponent *))v9->vfptr[1].__vecDelDtor)(v9);
                if ( v10 )
                {
                  v11 = v9->m_Flags;
                  UFG::qString::qString(&v12, v10);
                  if ( v11 & 2 )
                    UFG::qString::operator+=(&v12, ":skip_update");
                  if ( v11 & 0x10 )
                    UFG::qString::operator+=(&v12, ":detaching");
                  UFG::DUIContext::Label(v4, v12.mData);
                  UFG::qString::~qString(&v12);
                }
              }
              ++v8;
            }
            while ( v8 < v6->m_Components.size );
          }
          UFG::DUIContext::EndIndent(v4);
        }
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < v3->size );
    }
  }
}

// File Line: 2000
// RVA: 0x204DC0
void __fastcall UFG::Editor::PropertyBrowser::AddPendingValueChange(UFG::Editor::PropertyBrowser *this, UFG::qPropertyPath *path, UFG::Editor::VectoredValue *value)
{
  UFG::qPropertyPath *v3; // rcx

  this->mPendingValueChange.mType = 2;
  v3 = &this->mPendingValueChange.mPath;
  v3[1].mPath.capacity = value->mElementCount;
  *(float *)&v3[1].mPath.p = value->mValue[0];
  HIDWORD(v3[1].mPath.p) = LODWORD(value->mValue[1]);
  v3[2].mPath.size = LODWORD(value->mValue[2]);
  v3[2].mPath.capacity = LODWORD(value->mValue[3]);
  *(float *)&v3[2].mPath.p = value->mValue[4];
  HIDWORD(v3[2].mPath.p) = LODWORD(value->mValue[5]);
  v3[3].mPath.size = LODWORD(value->mValue[6]);
  v3[3].mPath.capacity = LODWORD(value->mValue[7]);
  *(float *)&v3[3].mPath.p = value->mValue[8];
  HIDWORD(v3[3].mPath.p) = LODWORD(value->mValue[9]);
  v3[4].mPath.size = LODWORD(value->mValue[10]);
  v3[4].mPath.capacity = LODWORD(value->mValue[11]);
  *(float *)&v3[4].mPath.p = value->mValue[12];
  HIDWORD(v3[4].mPath.p) = LODWORD(value->mValue[13]);
  v3[5].mPath.size = LODWORD(value->mValue[14]);
  v3[5].mPath.capacity = LODWORD(value->mValue[15]);
  LODWORD(v3[5].mPath.p) = *(_DWORD *)value->mbValid;
  HIDWORD(v3[5].mPath.p) = *(_DWORD *)&value->mbValid[4];
  v3[6].mPath.size = *(_DWORD *)&value->mbValid[8];
  v3[6].mPath.capacity = *(_DWORD *)&value->mbValid[12];
  LODWORD(v3[6].mPath.p) = *(_DWORD *)&value->mbGimbalLock;
  UFG::qPropertyPath::operator=(v3, path);
}

// File Line: 2021
// RVA: 0x20D6D0
void __fastcall UFG::Editor::PropertyBrowserWindow::Init(UFG::Editor::PropertyBrowserWindow *this)
{
  UFG::Editor::PropertyBrowserWindow *v1; // rbx
  __int64 v2; // r8
  UFG::qString *v3; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v1 = this;
  v2 = (unsigned int)nextSelSetIdx--;
  v3 = UFG::qString::FormatEx(&result, "PropertyBrowser(%x)", v2);
  UFG::qString::Set(&v1->mLockedSelection, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::qString::Set(&v1->mTitle, UFG::Editor::PropertyBrowserWindow::mTitle);
  UFG::qString::Set(&v1->mDefaultSelection, "LastSelection");
  UFG::Editor::SelectionManager::GetCreateSelectionSet(v1->mLockedSelection.mData);
  v1->mBrowser.mpSelection = UFG::Editor::SelectionManager::GetCreateSelectionSet(v1->mDefaultSelection.mData);
  v1->mBrowser.mbDirty = 1;
  v1->mLockSelection = 0;
}

// File Line: 2033
// RVA: 0x21C160
void __fastcall UFG::Editor::PropertyBrowserWindow::UpdateUI(UFG::Editor::PropertyBrowserWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rsi
  UFG::Editor::PropertyBrowserWindow *v3; // rdi
  UFG::Editor::SelectionSet *v4; // rdx
  bool current_value; // [rsp+30h] [rbp+8h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginGridLayout(dui, 1, 2, 3);
  current_value = v3->mLockSelection;
  UFG::DUIContext::Checkbox(v2, "Lock Selection", &current_value);
  if ( current_value != v3->mLockSelection )
    UFG::Editor::PropertyBrowserWindow::LockSelection(v3, current_value);
  v4 = v3->mBrowser.mpSelection;
  if ( !v4 )
    v4 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  UFG::Editor::PropertyBrowserWindow::RefreshTitle(v3, v4);
  UFG::Editor::PropertyBrowser::UpdateUI(&v3->mBrowser, v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

// File Line: 2050
// RVA: 0x2109D0
void __fastcall UFG::Editor::PropertyBrowserWindow::RefreshTitle(UFG::Editor::PropertyBrowserWindow *this, UFG::Editor::SelectionSet *set)
{
  UFG::Editor::PropertyBrowserWindow *v2; // rbx
  unsigned int v3; // er8
  UFG::Editor::DAGPath *v4; // r8
  unsigned int v5; // eax
  char *v6; // rax
  UFG::qString *v7; // rcx
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = set->mDAGPaths.size;
  if ( v3 == 1 )
  {
    v4 = set->mDAGPaths.p;
    v5 = v4->mElements.size;
    if ( v5 )
    {
      v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->mElements.p[v5 - 1]);
      if ( v6 )
      {
        UFG::qString::FormatEx(&result, "%s - Inspector", v6);
        UFG::qString::Set(&v2->mTitle, result.mData);
        UFG::qString::~qString(&result);
        return;
      }
    }
    v7 = &v2->mTitle;
  }
  else
  {
    if ( v3 > 1 )
    {
      UFG::qString::FormatEx(&result, "%d Objects - Inspector");
      UFG::qString::Set(&v2->mTitle, result.mData);
      UFG::qString::~qString(&result);
      return;
    }
    v7 = &this->mTitle;
  }
  UFG::qString::Set(v7, "Object Inspector");
}

// File Line: 2097
// RVA: 0x20DED0
void __fastcall UFG::Editor::PropertyBrowserWindow::LockSelection(UFG::Editor::PropertyBrowserWindow *this, bool locked)
{
  bool v2; // al
  UFG::Editor::PropertyBrowserWindow *v3; // rdi
  UFG::Editor::SelectionSet *v4; // rax
  UFG::Editor::SelectionSet *v5; // rbx
  UFG::Editor::SelectionSet *v6; // rax

  v2 = this->mLockSelection;
  v3 = this;
  if ( !v2 )
    goto LABEL_9;
  if ( !locked )
  {
    v4 = UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mDefaultSelection.mData);
    v3->mBrowser.mbDirty = 1;
    v3->mBrowser.mpSelection = v4;
    v3->mLockSelection = 0;
    return;
  }
  if ( !v2 )
  {
LABEL_9:
    if ( locked )
    {
      v5 = UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mLockedSelection.mData);
      v5->mDAGPaths.size = 0;
      UFG::Editor::SelectionSet::DispatchChangedEvent(v5);
      v6 = UFG::Editor::SelectionManager::GetCreateSelectionSet(v3->mDefaultSelection.mData);
      UFG::Editor::SelectionSet::Add(v5, v6);
      v3->mBrowser.mpSelection = v5;
      v3->mBrowser.mbDirty = 1;
      v3->mLockSelection = 1;
    }
  }
}

