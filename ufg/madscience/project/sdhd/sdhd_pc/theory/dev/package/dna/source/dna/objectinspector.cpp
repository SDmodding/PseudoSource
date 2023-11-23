// File Line: 15
// RVA: 0x146A7F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::ValueTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::ValueTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory,
    "UITest::ValueTest",
    v0);
  UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::ValueTest>::`vftable;
  UFG::qReflectInventory<UITest::ValueTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::ValueTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 16
// RVA: 0x146A770
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::ValueSubClass_UITest::ValueTest_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::ValueSubClass", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory,
    "UITest::ValueSubClass",
    v0);
  UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::ValueSubClass>::`vftable;
  UFG::qReflectInventory<UITest::ValueSubClass>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::ValueSubClass_UITest::ValueTest_::sInventory__);
}

// File Line: 17
// RVA: 0x146A570
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::PointerTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::PointerTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory,
    "UITest::PointerTest",
    v0);
  UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::PointerTest>::`vftable;
  UFG::qReflectInventory<UITest::PointerTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::PointerTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 18
// RVA: 0x146A020
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::StringTest_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UITest::StringTest,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 19
// RVA: 0x146A370
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::EnumValueTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::EnumValueTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory,
    "UITest::EnumValueTest",
    v0);
  UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::EnumValueTest>::`vftable;
  UFG::qReflectInventory<UITest::EnumValueTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::EnumValueTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 20
// RVA: 0x1469B50
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::ArrayTest_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UITest::ArrayTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UITest::ArrayTest,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UITest::ArrayTest>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 21
// RVA: 0x146A070
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::ArrayPointerTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::ArrayPointerTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory,
    "UITest::ArrayPointerTest",
    v0);
  UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::ArrayPointerTest>::`vftable;
  UFG::qReflectInventory<UITest::ArrayPointerTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::ArrayPointerTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 22
// RVA: 0x1469D10
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::HandleTest_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UITest::HandleTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UITest::HandleTest,UFG::qReflectObject>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UITest::HandleTest>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 23
// RVA: 0x1469FE0
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::HandleArrayTest_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 24
// RVA: 0x146A670
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::SymbolTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::SymbolTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory,
    "UITest::SymbolTest",
    v0);
  UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::SymbolTest>::`vftable;
  UFG::qReflectInventory<UITest::SymbolTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::SymbolTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 25
// RVA: 0x146A4F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::MathValueTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::MathValueTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory,
    "UITest::MathValueTest",
    v0);
  UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::MathValueTest>::`vftable;
  UFG::qReflectInventory<UITest::MathValueTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::MathValueTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 26
// RVA: 0x1469FC0
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::DefaultValues_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UITest::DefaultValues,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 27
// RVA: 0x1469B90
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::ColourTest_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UITest::ColourTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UITest::ColourTest,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UITest::ColourTest>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 28
// RVA: 0x146A6F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::UITestCase_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::UITestCase", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory,
    "UITest::UITestCase",
    v0);
  UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::UITestCase>::`vftable;
  UFG::qReflectInventory<UITest::UITestCase>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::UITestCase_UFG::qReflectObject_::sInventory__);
}

// File Line: 29
// RVA: 0x146A1F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_DNA::DUIDNAInspector_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("DNA::DUIDNAInspector", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory,
    "DNA::DUIDNAInspector",
    v0);
  UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<DNA::DUIDNAInspector>::`vftable;
  UFG::qReflectInventory<DNA::DUIDNAInspector>::OnAddToWarehouse(&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_DNA::DUIDNAInspector_UFG::DUIWindow_::sInventory__);
}

// File Line: 30
// RVA: 0x1469F80
void dynamic_initializer_for__UFG::qReflectObjectType_DNA::DUIReflectInspector_UFG::DUIWindow_::sFactoryOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("DNA::DUIReflectInspector", 0xFFFFFFFFFFFFFFFFui64);
  UFG::FactoryOperation::FactoryOperation(
    &UFG::qReflectObjectType<DNA::DUIReflectInspector,UFG::DUIWindow>::sFactoryOp,
    v0,
    UFG::OnCreateClass<DNA::DUIReflectInspector>,
    (void (__fastcall *)(char *))UFG::OnDeleteClass<UFG::DUIThemeEditorWindow>);
}

// File Line: 49
// RVA: 0x1B0850
void __fastcall DNA::DUIDNAWidget::~DUIDNAWidget(DNA::DUIDNAWidget *this)
{
  UFG::qReflectType **p; // rcx
  DNA::DUIDNAWidget::ExpandState *v3; // rcx
  DNA::PropertyBagWrapper *mWrapper; // rdi
  DNA::DUIDNAWidget::ExpandState *v5; // rcx
  UFG::qReflectType **v6; // rcx

  p = this->mTypeStack.p;
  if ( p )
    operator delete[](p);
  this->mTypeStack.p = 0i64;
  *(_QWORD *)&this->mTypeStack.size = 0i64;
  v3 = this->mExpandState.p;
  if ( v3 )
    operator delete[](v3);
  this->mExpandState.p = 0i64;
  *(_QWORD *)&this->mExpandState.size = 0i64;
  mWrapper = this->mWrapper;
  if ( mWrapper )
  {
    DNA::PropertyBagWrapper::~PropertyBagWrapper(this->mWrapper);
    operator delete[](mWrapper);
  }
  UFG::qString::~qString(&this->mEditValue);
  v5 = this->mExpandState.p;
  if ( v5 )
    operator delete[](v5);
  this->mExpandState.p = 0i64;
  *(_QWORD *)&this->mExpandState.size = 0i64;
  v6 = this->mTypeStack.p;
  if ( v6 )
    operator delete[](v6);
  this->mTypeStack.p = 0i64;
  *(_QWORD *)&this->mTypeStack.size = 0i64;
}

// File Line: 86
// RVA: 0x1B51B0
void __fastcall DNA::DUIDNAWidget::PopulateUIRecursive(
        DNA::DUIDNAWidget *this,
        DNA::PropertyBagWrapper *wrapper,
        UFG::qReflectField *parent_field)
{
  DNA::PropertyBagWrapper *mReflectionType; // r8
  UFG::qArray<UFG::qReflectType const *,0> *p_mTypeStack; // r9
  __int64 size; // rsi
  unsigned int v7; // edi
  unsigned int capacity; // edx
  unsigned int v9; // edx
  UFG::qReflectField *mPrev; // rsi
  UFG::ReflectionDB *v11; // rax
  UFG::qReflectType *v12; // rdi
  DNA::PropertyWrapper *Property; // rax
  unsigned int mFlags; // edx
  unsigned int v15; // ecx
  unsigned __int64 i; // rdi
  DNA::PropertyWrapper *v17; // rax
  UFG::qString *v18; // rax
  unsigned int v19; // eax
  bool *ExpandedState; // rax
  UFG::qString *DisplayName; // rax
  DNA::PropertyBagWrapper *mNext; // rdi
  UFG::ReflectionDB *v23; // rax
  UFG::qReflectType *v24; // r8
  DNA::PropertyBagWrapper *v25; // rax
  int p; // ecx
  unsigned int v27; // edi
  DNA::PropertyWrapper *v28; // rsi
  bool *v29; // rax
  UFG::qString *v30; // rcx
  bool *v31; // rax
  unsigned int v32; // edi
  unsigned __int64 j; // rdi
  char *mData; // rdi
  bool *v35; // rax
  unsigned __int64 k; // rdi
  unsigned int v37; // [rsp+30h] [rbp-D0h]
  DNA::PropertyBagWrapper *wrappera; // [rsp+38h] [rbp-C8h] BYREF
  UFG::qReflectType *type; // [rsp+40h] [rbp-C0h]
  DNA::PropertyInfo v40; // [rsp+48h] [rbp-B8h] BYREF
  __int64 v41; // [rsp+60h] [rbp-A0h]
  UFG::qReflectField *v42; // [rsp+68h] [rbp-98h]
  UFG::qArray<UFG::qReflectType const *,0> *v43; // [rsp+70h] [rbp-90h]
  UFG::qReflectField *v44; // [rsp+78h] [rbp-88h]
  UFG::qString result; // [rsp+80h] [rbp-80h] BYREF
  __int64 v46; // [rsp+A8h] [rbp-58h]
  UFG::qString v47; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qString v48; // [rsp+D8h] [rbp-28h] BYREF
  UFG::qString v49; // [rsp+100h] [rbp+0h] BYREF
  UFG::qString v50; // [rsp+128h] [rbp+28h] BYREF
  UFG::qString v51; // [rsp+150h] [rbp+50h] BYREF
  UFG::qString v52; // [rsp+178h] [rbp+78h] BYREF
  UFG::qString v53; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qString v54; // [rsp+1C8h] [rbp+C8h] BYREF
  DNA::PropertyBagWrapper *v; // [rsp+220h] [rbp+120h] BYREF
  DNA::PropertyBagWrapper *v56; // [rsp+228h] [rbp+128h]
  UFG::qReflectField *field; // [rsp+230h] [rbp+130h]
  DNA::PropertyWrapper *property_wrapper; // [rsp+238h] [rbp+138h]

  field = parent_field;
  v56 = wrapper;
  v46 = -2i64;
  v37 = 0;
  mReflectionType = (DNA::PropertyBagWrapper *)wrapper->mSchema->mReflectionType;
  v = mReflectionType;
  p_mTypeStack = &this->mTypeStack;
  v43 = &this->mTypeStack;
  size = this->mTypeStack.size;
  v7 = size + 1;
  capacity = this->mTypeStack.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v7 > 0x10000 )
      v9 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mTypeStack,
      v9,
      "qArray.Add");
    mReflectionType = v;
    p_mTypeStack = &this->mTypeStack;
  }
  p_mTypeStack->size = v7;
  p_mTypeStack->p[size] = (UFG::qReflectType *)mReflectionType;
  mPrev = (UFG::qReflectField *)mReflectionType[4].mProperties.mNode.mPrev;
  v42 = mPrev;
  v44 = (UFG::qReflectField *)&mReflectionType[4];
  if ( mPrev != (UFG::qReflectField *)&mReflectionType[4] )
  {
    while ( 1 )
    {
      v11 = UFG::ReflectionDB::Instance();
      v12 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v11, mPrev->mTypeName);
      DNA::DUIDNAWidget::GetDisplayName(this, &result, mPrev);
      Property = DNA::PropertyBagWrapper::GetProperty(v56, mPrev->mName);
      property_wrapper = Property;
      mFlags = mPrev->mFlags;
      if ( (mFlags & 0x40) == 0 )
      {
        v15 = v12->mFlags;
        if ( (v15 & 8) != 0 || (v15 & 0x80u) != 0 || (v15 & 1) != 0 || (v15 & 4) != 0 )
        {
          DNA::DUIDNAWidget::AddField(this, Property, mPrev, v12);
        }
        else if ( (mFlags & 0x2000) != 0 )
        {
          if ( (v15 & 0x10) != 0 )
          {
            for ( i = 0i64; i < mPrev->mArrayLength; ++i )
            {
              v = 0i64;
              v17 = DNA::PropertyBagWrapper::GetProperty(v56, mPrev->mName);
              DNA::PropertyWrapper::Get(v17, i, &v, 0);
              if ( v )
              {
                DNA::DUIDNAWidget::GetDisplayName(this, &v47, mPrev);
                if ( mPrev->mArrayLength <= 1 )
                {
                  v18 = UFG::qString::FormatEx(&v52, "%s", v47.mData);
                  v37 |= 2u;
                }
                else
                {
                  v18 = UFG::qString::FormatEx(&v53, "%s[%d]", v47.mData, i);
                  v37 |= 1u;
                }
                UFG::qString::qString(&v49, v18);
                v19 = v37;
                if ( (v37 & 2) != 0 )
                {
                  v37 &= ~2u;
                  UFG::qString::~qString(&v52);
                  v19 = v37;
                }
                if ( (v19 & 1) != 0 )
                {
                  v37 = v19 & 0xFFFFFFFE;
                  UFG::qString::~qString(&v53);
                }
                ExpandedState = DNA::DUIDNAWidget::GetExpandedState(this, property_wrapper, i);
                if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, v49.mData, ExpandedState) )
                {
                  UFG::DUIContext::BeginIndent(this->mContext);
                  DNA::DUIDNAWidget::PopulateUIRecursive(this, v, mPrev);
                  UFG::DUIContext::EndIndent(this->mContext);
                }
                UFG::qString::~qString(&v49);
                UFG::qString::~qString(&v47);
              }
            }
          }
        }
        else if ( (mFlags & 0x20) != 0 )
        {
          DisplayName = DNA::DUIDNAWidget::GetDisplayName(this, &v54, field);
          UFG::qString::Set(&result, DisplayName->mData, DisplayName->mLength, 0i64, 0);
          UFG::qString::~qString(&v54);
          mNext = (DNA::PropertyBagWrapper *)v12->mOrderedFields.mNode.mNext;
          v = mNext;
          v41 = 0i64;
          if ( mPrev->mArrayLength )
          {
            while ( 1 )
            {
              DNA::PropertyWrapper::GetPropertyInfo(property_wrapper, &v40);
              v23 = UFG::ReflectionDB::Instance();
              v24 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v23, (const char *)mNext[1].mPropertyBags.p);
              type = v24;
              if ( !v40.Size )
                goto LABEL_60;
              v25 = v;
              p = (int)v[2].mPropertyBags.p;
              if ( (p & 8) == 0 && (p & 0x80u) == 0 && (p & 4) == 0 && (p & 1) == 0 )
                break;
              v32 = 0;
              do
              {
                UFG::DUIContext::BeginIndent(this->mContext);
                UFG::DUIContext::BeginGridLayout(this->mContext, 2, 1, LayoutFlag_DistributeCells);
                UFG::DUIContext::BeginIndent(this->mContext);
                UFG::qString::FormatEx(&v48, "%s[%d]", result.mData, v32);
                UFG::DUIContext::Label(this->mContext, v48.mData);
                UFG::DUIContext::EndIndent(this->mContext);
                DNA::DUIDNAWidget::AddBasicType(this, property_wrapper, mPrev, type);
                UFG::DUIContext::EndLayoutHorizontal(this->mContext);
                UFG::DUIContext::EndIndent(this->mContext);
                UFG::qString::~qString(&v48);
                ++v32;
              }
              while ( v32 < v40.Size );
              mNext = v;
LABEL_60:
              if ( v40.States.p )
                operator delete[](v40.States.p);
              v40.States.p = 0i64;
              *(_QWORD *)&v40.States.size = 0i64;
              if ( ++v41 >= mPrev->mArrayLength )
                goto LABEL_78;
            }
            v27 = 0;
            v28 = property_wrapper;
            while ( 2 )
            {
              if ( ((__int64)v25[2].mPropertyBags.p & 0x4000) != 0 )
              {
                if ( (v24->mFlags & 0x10) != 0 )
                {
                  wrappera = 0i64;
                  DNA::PropertyWrapper::Get(v28, v27, &wrappera, 0);
                  if ( wrappera )
                  {
                    UFG::DUIContext::BeginIndent(this->mContext);
                    UFG::qString::FormatEx(&v51, "%s[%d] [%s]", result.mData, v27, wrappera->mSchema->mName.mData);
                    v29 = DNA::DUIDNAWidget::GetExpandedState(this, v28, v27);
                    if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, v51.mData, v29) )
                    {
                      UFG::DUIContext::BeginIndent(this->mContext);
                      DNA::DUIDNAWidget::PopulateUIRecursive(this, wrappera, (UFG::qReflectField *)v);
                      UFG::DUIContext::EndIndent(this->mContext);
                    }
                    UFG::DUIContext::EndIndent(this->mContext);
                    v30 = &v51;
                    goto LABEL_53;
                  }
                  goto LABEL_54;
                }
              }
              else
              {
                wrappera = 0i64;
                DNA::PropertyWrapper::Get(v28, v27, &wrappera, 0);
                UFG::DUIContext::BeginIndent(this->mContext);
                UFG::qString::FormatEx(&v50, "%s[%d]", result.mData, v27);
                v31 = DNA::DUIDNAWidget::GetExpandedState(this, v28, v27);
                if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, v50.mData, v31) )
                {
                  if ( DNA::HasEditor(type, "ColourPicker") )
                  {
                    DNA::DUIDNAWidget::AddColourType(this, wrappera);
                  }
                  else
                  {
                    UFG::DUIContext::BeginIndent(this->mContext);
                    DNA::DUIDNAWidget::PopulateUIRecursive(this, wrappera, (UFG::qReflectField *)v);
                    UFG::DUIContext::EndIndent(this->mContext);
                  }
                }
                UFG::DUIContext::EndIndent(this->mContext);
                v30 = &v50;
LABEL_53:
                UFG::qString::~qString(v30);
LABEL_54:
                v25 = v;
                v24 = type;
              }
              if ( ++v27 >= v40.Size )
              {
                mPrev = v42;
                mNext = v;
                goto LABEL_60;
              }
              continue;
            }
          }
        }
        else if ( (mFlags & 1) == 0 )
        {
          if ( (mFlags & 2) != 0 )
          {
            for ( j = 0i64; j < mPrev->mArrayLength; Property = property_wrapper )
            {
              v = 0i64;
              DNA::PropertyWrapper::Get(Property, j, &v, 0);
              DNA::DUIDNAWidget::PopulateUIRecursive(this, v, mPrev);
              ++j;
            }
          }
          else if ( !DNA::IsHidden(this->mTypeStack.p[this->mTypeStack.size - 1], mPrev) )
          {
            mData = result.mData;
            v35 = DNA::DUIDNAWidget::GetExpandedState(this, property_wrapper, 0);
            if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, mData, v35) )
            {
              for ( k = 0i64; k < mPrev->mArrayLength; ++k )
              {
                v = 0i64;
                DNA::PropertyWrapper::Get(property_wrapper, k, &v, 0);
                if ( DNA::HasEditor(mPrev, "ColourPicker") )
                {
                  DNA::DUIDNAWidget::AddColourType(this, v);
                }
                else
                {
                  UFG::DUIContext::BeginIndent(this->mContext);
                  DNA::DUIDNAWidget::PopulateUIRecursive(this, v, mPrev);
                  UFG::DUIContext::EndIndent(this->mContext);
                }
              }
            }
          }
        }
      }
LABEL_78:
      UFG::qString::~qString(&result);
      mPrev = (UFG::qReflectField *)mPrev->mNext;
      v42 = mPrev;
      if ( mPrev == v44 )
      {
        p_mTypeStack = v43;
        break;
      }
    }
  }
  if ( p_mTypeStack->size > 1 )
    --p_mTypeStack->size;
  else
    p_mTypeStack->size = 0;
} }
LABEL_78:
      UFG::qS

// File Line: 284
// RVA: 0x1B3D80
UFG::qString *__fastcall DNA::DUIDNAWidget::GetDisplayName(
        DNA::DUIDNAWidget *this,
        UFG::qString *result,
        UFG::qReflectField *field)
{
  DNA::GetDisplayName(result, this->mTypeStack.p[this->mTypeStack.size - 1], field);
  return result;
}

// File Line: 304
// RVA: 0x1B3E20
bool *__fastcall DNA::DUIDNAWidget::GetExpandedState(
        DNA::DUIDNAWidget *this,
        DNA::PropertyWrapper *property_wrapper,
        unsigned int array_index)
{
  __int64 size; // r14
  unsigned int v4; // ebp
  unsigned int v8; // r9d
  DNA::DUIDNAWidget::ExpandState *p; // rax
  unsigned int capacity; // ebx
  unsigned int v11; // esi
  unsigned int v12; // ebx
  bool *result; // rax
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // r13
  DNA::DUIDNAWidget::ExpandState *v16; // rcx
  __int64 v17; // rdx
  DNA::DUIDNAWidget::ExpandState *v18; // rcx

  size = this->mExpandState.size;
  v4 = 0;
  v8 = 0;
  if ( (_DWORD)size )
  {
    p = this->mExpandState.p;
    while ( p->mData != property_wrapper || p->mArrayIndex != array_index )
    {
      ++v8;
      ++p;
      if ( v8 >= (unsigned int)size )
        goto LABEL_6;
    }
    return &p->mExpanded;
  }
  else
  {
LABEL_6:
    capacity = this->mExpandState.capacity;
    v11 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v12 = 2 * capacity;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 - v11 > 0x10000 )
        v12 = size + 65537;
      if ( v12 != this->mExpandState.size )
      {
        v14 = 16i64 * v12;
        if ( !is_mul_ok(v12, 0x10ui64) )
          v14 = -1i64;
        v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
        if ( this->mExpandState.p )
        {
          if ( this->mExpandState.size )
          {
            do
            {
              v16 = this->mExpandState.p;
              v17 = v4++;
              v17 *= 2i64;
              v15[v17] = (UFG::allocator::free_link)*(&v16->mData + v17);
              v15[v17 + 1] = *(UFG::allocator::free_link *)(&v16->mArrayIndex + 2 * v17);
            }
            while ( v4 < this->mExpandState.size );
          }
          operator delete[](this->mExpandState.p);
        }
        this->mExpandState.p = (DNA::DUIDNAWidget::ExpandState *)v15;
        this->mExpandState.capacity = v12;
      }
    }
    this->mExpandState.size = v11;
    v18 = &this->mExpandState.p[size];
    v18->mExpanded = 0;
    result = &v18->mExpanded;
    v18->mData = property_wrapper;
    v18->mArrayIndex = array_index;
  }
  return result;
}

// File Line: 322
// RVA: 0x1B2A10
void __fastcall DNA::DUIDNAWidget::AddField(
        DNA::DUIDNAWidget *this,
        DNA::PropertyWrapper *property_wrapper,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type)
{
  int v7; // ebx
  int mArrayLength; // r14d
  char *mData; // rdi
  bool *ExpandedState; // rax
  unsigned int i; // edi
  UFG::qString *v12; // rax
  UFG::qString result; // [rsp+10h] [rbp-71h] BYREF
  UFG::qString text; // [rsp+38h] [rbp-49h] BYREF
  __int64 v15; // [rsp+60h] [rbp-21h]
  UFG::qString v16; // [rsp+68h] [rbp-19h] BYREF
  UFG::qString v17; // [rsp+90h] [rbp+Fh] BYREF
  UFG::qReflectType *field_typea; // [rsp+100h] [rbp+7Fh]

  v15 = -2i64;
  v7 = 0;
  if ( !DNA::IsHidden(this->mTypeStack.p[this->mTypeStack.size - 1], field) )
  {
    mArrayLength = property_wrapper->mSchemaField->mArrayLength;
    if ( mArrayLength < 0 )
    {
      DNA::PropertyWrapper::GetPropertyInfo(property_wrapper, (DNA::PropertyInfo *)&result);
      mArrayLength = HIDWORD(result.mPrev);
      if ( *(_QWORD *)&result.mMagic )
        operator delete[](*(void **)&result.mMagic);
      *(_QWORD *)&result.mMagic = 0i64;
      result.mNext = 0i64;
    }
    DNA::DUIDNAWidget::GetDisplayName(this, &text, field);
    if ( mArrayLength <= 1
      || (mData = text.mData,
          ExpandedState = DNA::DUIDNAWidget::GetExpandedState(this, property_wrapper, 0),
          (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, mData, ExpandedState)) )
    {
      for ( i = 0; (int)i < mArrayLength; ++i )
      {
        UFG::DUIContext::BeginGridLayout(this->mContext, 2, 1, LayoutFlag_DistributeCells);
        UFG::DUIContext::BeginIndent(this->mContext);
        if ( mArrayLength <= 1i64 )
        {
          UFG::qString::qString(&v16, &text);
          v7 |= 2u;
        }
        else
        {
          v12 = UFG::qString::FormatEx(&v17, "%s[%d]", text.mData, i);
          v7 |= 1u;
        }
        UFG::qString::qString(&result, v12);
        if ( (v7 & 2) != 0 )
        {
          v7 &= ~2u;
          UFG::qString::~qString(&v16);
        }
        if ( (v7 & 1) != 0 )
        {
          v7 &= ~1u;
          UFG::qString::~qString(&v17);
        }
        UFG::DUIContext::Label(this->mContext, result.mData);
        UFG::DUIContext::EndIndent(this->mContext);
        result.mMagic = i;
        DNA::DUIDNAWidget::AddBasicType(this, property_wrapper, field, field_typea);
        UFG::DUIContext::EndLayoutHorizontal(this->mContext);
        UFG::qString::~qString(&result);
      }
    }
    UFG::qString::~qString(&text);
  }
}

// File Line: 357
// RVA: 0x1B2870
void __fastcall DNA::DUIDNAWidget::AddColourType(DNA::DUIDNAWidget *this, DNA::PropertyBagWrapper *field_bag)
{
  DNA::PropertyWrapper *Property; // rax
  DNA::PropertyWrapper *v5; // rax
  DNA::PropertyWrapper *v6; // rax
  DNA::PropertyWrapper *v7; // rax
  UFG::DUIContext *mContext; // rcx
  DNA::PropertyWrapper *v9; // rax
  DNA::PropertyWrapper *v10; // rax
  DNA::PropertyWrapper *v11; // rax
  DNA::PropertyWrapper *v12; // rax
  float v13; // [rsp+20h] [rbp-28h] BYREF
  UFG::qColour current_colour_rgb; // [rsp+28h] [rbp-20h] BYREF
  float v; // [rsp+50h] [rbp+8h] BYREF
  float v16; // [rsp+60h] [rbp+18h] BYREF
  float v17; // [rsp+68h] [rbp+20h] BYREF

  v = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  v13 = 0.0;
  Property = DNA::PropertyBagWrapper::GetProperty(field_bag, "r");
  DNA::PropertyWrapper::Get(Property, 0, &v, 0);
  v5 = DNA::PropertyBagWrapper::GetProperty(field_bag, "g");
  DNA::PropertyWrapper::Get(v5, 0, &v16, 0);
  v6 = DNA::PropertyBagWrapper::GetProperty(field_bag, "b");
  DNA::PropertyWrapper::Get(v6, 0, &v17, 0);
  v7 = DNA::PropertyBagWrapper::GetProperty(field_bag, "a");
  DNA::PropertyWrapper::Get(v7, 0, &v13, 0);
  mContext = this->mContext;
  current_colour_rgb.r = v;
  current_colour_rgb.g = v16;
  current_colour_rgb.b = v17;
  current_colour_rgb.a = v13;
  if ( UFG::DUIContext::ColourPicker(mContext, &customCaption, &current_colour_rgb, 1) )
  {
    v9 = DNA::PropertyBagWrapper::GetProperty(field_bag, "r");
    DNA::PropertyWrapper::Set(v9, 0, current_colour_rgb.r, 0);
    v10 = DNA::PropertyBagWrapper::GetProperty(field_bag, "g");
    DNA::PropertyWrapper::Set(v10, 0, current_colour_rgb.g, 0);
    v11 = DNA::PropertyBagWrapper::GetProperty(field_bag, "b");
    DNA::PropertyWrapper::Set(v11, 0, current_colour_rgb.b, 0);
    v12 = DNA::PropertyBagWrapper::GetProperty(field_bag, "a");
    DNA::PropertyWrapper::Set(v12, 0, current_colour_rgb.a, 0);
  }
}

// File Line: 378
// RVA: 0x1B13C0
void __fastcall DNA::DUIDNAWidget::AddBasicType(
        DNA::DUIDNAWidget *this,
        DNA::PropertyWrapper *property_wrapper,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type)
{
  __int64 v8; // r15
  DNA::PropertyType::Enum mType; // ecx
  UFG::qString *v10; // rax
  char v11; // bl
  UFG::qString *v12; // rax
  char v13; // bl
  UFG::qString *v14; // rax
  char v15; // bl
  UFG::qString *v16; // rax
  char v17; // bl
  UFG::qString *v18; // rax
  __int16 v19; // bx
  char v20; // bl
  char v21; // al
  UFG::ReflectionDB *v22; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *Enum; // rax
  unsigned int v24; // r14d
  UFG::qTree64Base::BaseNode *v25; // rbx
  UFG::qTree64Base::BaseNode **p_mParent; // r12
  char *v27; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v29; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  int v31; // eax
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // r8
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v35; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v36; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+38h] [rbp-90h] BYREF
  UFG::qString current_value; // [rsp+48h] [rbp-80h] BYREF
  DNA::PropertyInfo result; // [rsp+70h] [rbp-58h] BYREF
  UFG::qString v41; // [rsp+A8h] [rbp-20h] BYREF
  UFG::qString v42; // [rsp+D0h] [rbp+8h] BYREF
  UFG::qString v43; // [rsp+F8h] [rbp+30h] BYREF
  UFG::qString v44; // [rsp+120h] [rbp+58h] BYREF
  UFG::qString v45; // [rsp+148h] [rbp+80h] BYREF
  UFG::qString v46; // [rsp+170h] [rbp+A8h] BYREF
  UFG::qString v47; // [rsp+198h] [rbp+D0h] BYREF
  UFG::qString v48; // [rsp+1C0h] [rbp+F8h] BYREF
  UFG::qString v49; // [rsp+220h] [rbp+158h] BYREF
  unsigned int index; // [rsp+258h] [rbp+190h] BYREF

  current_value.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)-2i64;
  DNA::PropertyWrapper::GetPropertyInfo(property_wrapper, &result);
  v8 = index;
  if ( !*((_DWORD *)&current_value.mPrev->mPrev + index) )
    UFG::DUIContext::PushColour(this->mContext, TextColour, &UFG::qColour::Grey);
  mType = property_wrapper->mSchemaField->mType;
  if ( mType > 224407815 )
  {
    switch ( mType )
    {
      case 826535573:
        UFG::qString::qString(&current_value);
        DNA::PropertyWrapper::Get(property_wrapper, v8, &current_value, 0);
        if ( (property_wrapper->mSchemaField->mReflectionField->mFlags & 4) != 0 )
        {
          *(float *)&index = 0.0;
          options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
          options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
          v22 = UFG::ReflectionDB::Instance();
          Enum = UFG::ReflectionDB::GetEnum(v22, field_type->mName);
          if ( Enum )
          {
            v24 = 0;
            v25 = Enum[1].mTree.mHead.mChildren[0];
            p_mParent = &Enum[1].mTree.mHead.mParent;
            if ( v25 != (UFG::qTree64Base::BaseNode *)&Enum[1].mTree.mHead.mParent )
            {
              while ( 1 )
              {
                v27 = (char *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
                v49.mData = v27;
                if ( v27 )
                {
                  UFG::qString::qString((UFG::qString *)v27, (const char *)v25->mChildren[0]);
                  v29 = v28;
                }
                else
                {
                  v29 = 0i64;
                }
                mPrev = options.mNode.mPrev;
                options.mNode.mPrev->mNext = v29;
                v29->mPrev = mPrev;
                v29->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
                options.mNode.mPrev = v29;
                if ( !(unsigned int)UFG::qStringCompare((const char *)v25->mChildren[0], current_value.mData, -1) )
                  break;
                ++v24;
                v25 = v25->mParent;
                if ( v25 == (UFG::qTree64Base::BaseNode *)p_mParent )
                  goto LABEL_79;
              }
              index = v24;
            }
          }
LABEL_79:
          if ( UFG::DUIContext::ComboBox(this->mContext, (int *)&index, &options, 0i64, 0xFFFFFFFF) )
          {
            v31 = 0;
            mNext = options.mNode.mNext;
            if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options )
            {
              while ( v31 != index )
              {
                ++v31;
                mNext = mNext->mNext;
                if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&options )
                  goto LABEL_85;
              }
              DNA::PropertyWrapper::Set(property_wrapper, v8, (char *)mNext[1].mNext, 0);
            }
          }
LABEL_85:
          for ( i = (UFG::qString *)options.mNode.mNext;
                (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
                i = (UFG::qString *)options.mNode.mNext )
          {
            v34 = i->mPrev;
            v35 = i->mNext;
            v34->mNext = v35;
            v35->mPrev = v34;
            i->mPrev = i;
            i->mNext = i;
            UFG::qString::~qString(i);
            operator delete[](i);
          }
          v36 = options.mNode.mPrev;
          v37 = options.mNode.mNext;
          options.mNode.mPrev->mNext = options.mNode.mNext;
          v37->mPrev = v36;
          options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
          options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
        }
        else if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &current_value, 0i64, 1, 0i64, -1) )
        {
          DNA::PropertyWrapper::Set(property_wrapper, v8, current_value.mData, 0);
        }
        goto LABEL_90;
      case 1138723642:
        LOBYTE(index) = 0;
        DNA::PropertyWrapper::Get(property_wrapper, v8, (bool *)&index, 0);
        v20 = index;
        v21 = UFG::DUIContext::Checkbox(this->mContext, &customCaption, (bool *)&index);
        LOBYTE(index) = v21;
        if ( v20 != v21 )
          DNA::PropertyWrapper::Set(property_wrapper, v8, v21, 0);
        break;
      case 1208522079:
        *(float *)&index = 0.0;
        DNA::PropertyWrapper::Get(property_wrapper, v8, (float *)&index, 0);
        v49.mStringHash32 = 0;
        LODWORD(v49.mData) = 0;
        if ( !DNA::HasRange(
                this->mTypeStack.p[this->mTypeStack.size - 1],
                field,
                (float *)&v49.mStringHash32,
                (float *)&v49.mData) )
        {
          if ( this->mActiveEdit == property_wrapper )
          {
            UFG::qString::qString(&v48, &this->mEditValue);
            v19 = 256;
          }
          else
          {
            v18 = UFG::qString::FormatEx(&v46, "%f", index);
            v19 = 512;
          }
          UFG::qString::qString(&current_value, v18);
          if ( (v19 & 0x200) != 0 )
          {
            v19 &= ~0x200u;
            UFG::qString::~qString(&v46);
          }
          if ( (v19 & 0x100) != 0 )
            UFG::qString::~qString(&v48);
          if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &current_value, 0i64, 1, 0i64, -1) )
          {
            this->mActiveEdit = property_wrapper;
            UFG::qString::Set(&this->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
            *(float *)&index = UFG::qToFloat(this->mEditValue.mData, *(float *)&index);
            DNA::PropertyWrapper::Set(property_wrapper, v8, *(float *)&index, 0);
          }
          goto LABEL_90;
        }
        if ( UFG::DUIContext::Slider(this->mContext, &customCaption, (float *)&index, *(float *)&v49.mStringHash32) )
          DNA::PropertyWrapper::Set(property_wrapper, v8, *(float *)&index, 0);
        break;
    }
  }
  else
  {
    switch ( mType )
    {
      case 224407815:
        v49.mData = 0i64;
        DNA::PropertyWrapper::Get(property_wrapper, v8, (__int64 *)&v49.mData, 0);
        if ( this->mActiveEdit == property_wrapper )
        {
          UFG::qString::qString(&v44, &this->mEditValue);
          v17 = 4;
        }
        else
        {
          v16 = UFG::qString::FormatEx(&v42, "%d", v49.mData);
          v17 = 8;
        }
        UFG::qString::qString(&current_value, v16);
        if ( (v17 & 8) != 0 )
        {
          v17 &= ~8u;
          UFG::qString::~qString(&v42);
        }
        if ( (v17 & 4) != 0 )
          UFG::qString::~qString(&v44);
        if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &current_value, 0i64, 1, 0i64, -1) )
        {
          this->mActiveEdit = property_wrapper;
          UFG::qString::Set(&this->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
          v49.mData = (char *)UFG::qToInt64(this->mEditValue.mData, (__int64)v49.mData);
          DNA::PropertyWrapper::Set(property_wrapper, v8, (__int64)v49.mData, 0);
        }
        goto LABEL_90;
      case -2133091136:
        *(float *)&index = 0.0;
        DNA::PropertyWrapper::Get(property_wrapper, v8, (int *)&index, 0);
        v49.mStringHash32 = 0;
        LODWORD(v49.mData) = 0;
        if ( !DNA::HasRange(
                this->mTypeStack.p[this->mTypeStack.size - 1],
                field,
                (int *)&v49.mStringHash32,
                (int *)&v49.mData) )
        {
          if ( this->mActiveEdit == property_wrapper )
          {
            UFG::qString::qString((UFG::qString *)&result.States.p, &this->mEditValue);
            v15 = 1;
          }
          else
          {
            v14 = UFG::qString::FormatEx(&v47, "%d", index);
            v15 = 2;
          }
          UFG::qString::qString(&current_value, v14);
          if ( (v15 & 2) != 0 )
          {
            v15 &= ~2u;
            UFG::qString::~qString(&v47);
          }
          if ( (v15 & 1) != 0 )
            UFG::qString::~qString((UFG::qString *)&result.States.p);
          if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &current_value, 0i64, 1, 0i64, -1) )
          {
            this->mActiveEdit = property_wrapper;
            UFG::qString::Set(&this->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
            index = UFG::qToInt32(this->mEditValue.mData, index);
            DNA::PropertyWrapper::Set(property_wrapper, v8, index, 0);
          }
          goto LABEL_90;
        }
        if ( UFG::DUIContext::Slider(this->mContext, &customCaption, &index, v49.mStringHash32) )
          DNA::PropertyWrapper::Set(property_wrapper, v8, index, 0);
        break;
      case -2067794966:
        *(float *)&index = 0.0;
        DNA::PropertyWrapper::Get(property_wrapper, v8, &index, 0);
        if ( this->mActiveEdit == property_wrapper )
        {
          UFG::qString::qString(&v43, &this->mEditValue);
          v13 = 16;
        }
        else
        {
          v12 = UFG::qString::FormatEx((UFG::qString *)&current_value.mMagic, "%d", index);
          v13 = 32;
        }
        UFG::qString::qString(&current_value, v12);
        if ( (v13 & 0x20) != 0 )
        {
          v13 &= ~0x20u;
          UFG::qString::~qString((UFG::qString *)&current_value.mMagic);
        }
        if ( (v13 & 0x10) != 0 )
          UFG::qString::~qString(&v43);
        if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &current_value, 0i64, 1, 0i64, -1) )
        {
          this->mActiveEdit = property_wrapper;
          UFG::qString::Set(&this->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
          index = UFG::qToUInt32(this->mEditValue.mData, index);
          DNA::PropertyWrapper::Set(property_wrapper, v8, index, 0);
        }
        goto LABEL_90;
      case 151281197:
        v49.mData = 0i64;
        DNA::PropertyWrapper::Get(property_wrapper, v8, (unsigned __int64 *)&v49.mData, 0);
        if ( this->mActiveEdit == property_wrapper )
        {
          UFG::qString::qString(&v41, &this->mEditValue);
          v11 = 64;
        }
        else
        {
          v10 = UFG::qString::FormatEx(&v45, "%d", v49.mData);
          v11 = 0x80;
        }
        UFG::qString::qString(&current_value, v10);
        if ( v11 < 0 )
        {
          v11 &= ~0x80u;
          UFG::qString::~qString(&v45);
        }
        if ( (v11 & 0x40) != 0 )
          UFG::qString::~qString(&v41);
        if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &current_value, 0i64, 1, 0i64, -1) )
        {
          this->mActiveEdit = property_wrapper;
          UFG::qString::Set(&this->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
          v49.mData = (char *)UFG::qToUInt64(this->mEditValue.mData, (unsigned __int64)v49.mData);
          DNA::PropertyWrapper::Set(property_wrapper, v8, (unsigned __int64)v49.mData, 0);
        }
LABEL_90:
        UFG::qString::~qString(&current_value);
        break;
    }
  }
  if ( this->mActiveEdit == property_wrapper && this->mContext->mCurrentID != this->mContext->mFocusedID )
    this->mActiveEdit = 0i64;
  if ( !*((_DWORD *)&current_value.mPrev->mPrev + v8) )
    UFG::DUIContext::PopColour(this->mContext, 0);
  if ( current_value.mPrev )
    operator delete[](current_value.mPrev);
}

// File Line: 571
// RVA: 0x1B59F0
void __fastcall DNA::DUIDNAInspector::UpdateUI(DNA::DUIDNAInspector *this, UFG::DUIContext *dui)
{
  __int64 v4; // rax
  bool v5; // zf
  DNA::PropertyBagWrapper *mWrapper; // rdx
  __int64 v7; // rax
  AMD_HD3D *v8; // rax

  DNA::Database::Instance();
  *(_BYTE *)(v4 + 48) = 1;
  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(dui);
  v5 = this->mWidget.mProperties == 0i64;
  this->mWidget.mContext = dui;
  if ( !v5 )
  {
    mWrapper = this->mWidget.mWrapper;
    if ( mWrapper )
      DNA::DUIDNAWidget::PopulateUIRecursive(&this->mWidget, mWrapper, 0i64);
  }
  this->mWidget.mContext = 0i64;
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndScrollView(dui);
  DNA::Database::Instance();
  *(_BYTE *)(v7 + 48) = 0;
  DNA::Database::Instance();
  _(v8);
}

// File Line: 613
// RVA: 0x1AFEB0
void __fastcall DNA::DUIReflectWidget::DUIReflectWidget(DNA::DUIReflectWidget *this)
{
  this->vfptr = (UFG::qReflectVisitorVtbl *)&UFG::qReflectVisitor::`vftable;
  this->mTrackedObjects.p = 0i64;
  *(_QWORD *)&this->mTrackedObjects.size = 0i64;
  this->mPatches.p = 0i64;
  *(_QWORD *)&this->mPatches.size = 0i64;
  this->mArrays.p = 0i64;
  *(_QWORD *)&this->mArrays.size = 0i64;
  this->vfptr = (UFG::qReflectVisitorVtbl *)&DNA::DUIReflectWidget::`vftable;
  this->mObject = 0i64;
  this->mFieldStack.p = 0i64;
  *(_QWORD *)&this->mFieldStack.size = 0i64;
  this->mTypeStack.p = 0i64;
  *(_QWORD *)&this->mTypeStack.size = 0i64;
  this->mArrayIndices.p = 0i64;
  *(_QWORD *)&this->mArrayIndices.size = 0i64;
  this->mExpandState.p = 0i64;
  *(_QWORD *)&this->mExpandState.size = 0i64;
  this->mSubObjects.mNode.mPrev = &this->mSubObjects.mNode;
  this->mSubObjects.mNode.mNext = &this->mSubObjects.mNode;
  this->mActiveEdit = 0i64;
  UFG::qString::qString(&this->mEditValue);
}

// File Line: 617
// RVA: 0x1B0900
void __fastcall DNA::DUIReflectWidget::~DUIReflectWidget(DNA::DUIReflectWidget *this)
{
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *p_mSubObjects; // rbx
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *mPrev; // rcx
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *mNext; // rax
  DNA::DUIReflectWidget::ExpandState *p; // rcx
  unsigned int *v6; // rcx
  UFG::qReflectType **v7; // rcx
  UFG::qReflectField **v8; // rcx

  this->vfptr = (UFG::qReflectVisitorVtbl *)&DNA::DUIReflectWidget::`vftable;
  p_mSubObjects = &this->mSubObjects;
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0>::DeleteNodes(&this->mSubObjects);
  UFG::qString::~qString(&this->mEditValue);
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0>::DeleteNodes(p_mSubObjects);
  mPrev = p_mSubObjects->mNode.mPrev;
  mNext = p_mSubObjects->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mSubObjects->mNode.mPrev = &p_mSubObjects->mNode;
  p_mSubObjects->mNode.mNext = &p_mSubObjects->mNode;
  p = this->mExpandState.p;
  if ( p )
    operator delete[](p);
  this->mExpandState.p = 0i64;
  *(_QWORD *)&this->mExpandState.size = 0i64;
  v6 = this->mArrayIndices.p;
  if ( v6 )
    operator delete[](v6);
  this->mArrayIndices.p = 0i64;
  *(_QWORD *)&this->mArrayIndices.size = 0i64;
  v7 = this->mTypeStack.p;
  if ( v7 )
    operator delete[](v7);
  this->mTypeStack.p = 0i64;
  *(_QWORD *)&this->mTypeStack.size = 0i64;
  v8 = this->mFieldStack.p;
  if ( v8 )
    operator delete[](v8);
  this->mFieldStack.p = 0i64;
  *(_QWORD *)&this->mFieldStack.size = 0i64;
  UFG::qReflectVisitor::~qReflectVisitor(this);
}

// File Line: 630
// RVA: 0x1B3B80
bool __fastcall DNA::DUIReflectWidget::DiscoverObjectField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  unsigned int mFlags; // eax

  mFlags = field->mFlags;
  return (mFlags & 0x80u) == 0 && (mFlags & 8) == 0;
}

// File Line: 641
// RVA: 0x1B3470
void __fastcall DNA::DUIReflectWidget::BeginField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  __int64 size; // rsi
  UFG::qArray<UFG::qReflectField const *,0> *p_mFieldStack; // rdi
  unsigned int capacity; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::qReflectField **p; // rax

  size = this->mFieldStack.size;
  p_mFieldStack = &this->mFieldStack;
  capacity = this->mFieldStack.capacity;
  v8 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v8; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v8 > 0x10000 )
      v9 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFieldStack,
      v9,
      "qArray.Add");
  }
  p = p_mFieldStack->p;
  p_mFieldStack->size = v8;
  p[size] = field;
}

// File Line: 646
// RVA: 0x1B3CF0
void __fastcall DNA::DUIReflectWidget::EndDiscoverField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  unsigned int size; // eax

  size = this->mFieldStack.size;
  if ( size > 1 )
    this->mFieldStack.size = size - 1;
  else
    this->mFieldStack.size = 0;
}

// File Line: 661
// RVA: 0x1B3590
char __fastcall DNA::DUIReflectWidget::BeginObjectField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  bool *ExpandedState; // rbx
  unsigned int mFlags; // eax
  bool *v11; // rbx
  char v12; // bl
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( (field->mFlags & 2) != 0 )
    return 1;
  if ( DNA::HasEditor(field, "ColourPicker") )
  {
    ExpandedState = DNA::DUIReflectWidget::GetExpandedState(this, field_type, field);
    DNA::DUIReflectWidget::GetDisplayName(this, &result, field);
    UFG::DUIContext::Collapsible(this->mContext, result.mData, ExpandedState);
    if ( *ExpandedState )
      ((void (__fastcall *)(DNA::DUIReflectWidget *, UFG::qReflectField *, UFG::qReflectType *, const char *, __int64))this->vfptr->BeginBytes)(
        this,
        field,
        field_type,
        object_data,
        -2i64);
    UFG::qString::~qString(&result);
    return 0;
  }
  mFlags = field->mFlags;
  if ( (mFlags & 0x80u) != 0 || (mFlags & 8) != 0 )
  {
    ((void (__fastcall *)(DNA::DUIReflectWidget *, UFG::qReflectField *, UFG::qReflectType *, const char *, __int64))this->vfptr->BeginBytes)(
      this,
      field,
      field_type,
      object_data,
      -2i64);
    return 0;
  }
  if ( DNA::IsHidden(this->mTypeStack.p[this->mTypeStack.size - 1], field) )
    return 0;
  v11 = DNA::DUIReflectWidget::GetExpandedState(this, field_type, field);
  DNA::DUIReflectWidget::GetDisplayName(this, &result, field);
  v12 = UFG::DUIContext::Collapsible(this->mContext, result.mData, v11);
  if ( v12 )
    UFG::DUIContext::BeginIndent(this->mContext);
  UFG::qString::~qString(&result);
  return v12;
}

// File Line: 706
// RVA: 0x1B3500
void __fastcall DNA::DUIReflectWidget::BeginObject(
        DNA::DUIReflectWidget *this,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  __int64 size; // rsi
  UFG::qArray<UFG::qReflectType const *,0> *p_mTypeStack; // rdi
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::qReflectType **p; // rax

  size = this->mTypeStack.size;
  p_mTypeStack = &this->mTypeStack;
  capacity = this->mTypeStack.capacity;
  v7 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v8 = 2 * capacity;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 <= 2 )
      v8 = 2;
    if ( v8 - v7 > 0x10000 )
      v8 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mTypeStack,
      v8,
      "qArray.Add");
  }
  p = p_mTypeStack->p;
  p_mTypeStack->size = v7;
  p[size] = field_type;
}

// File Line: 711
// RVA: 0x1B3D10
void __fastcall DNA::DUIReflectWidget::EndObject(
        DNA::DUIReflectWidget *this,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  unsigned int size; // eax

  size = this->mTypeStack.size;
  if ( size > 1 )
    this->mTypeStack.size = size - 1;
  else
    this->mTypeStack.size = 0;
}

// File Line: 716
// RVA: 0x1B3D30
void __fastcall DNA::DUIReflectWidget::EndObjectField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  if ( (field->mFlags & 2) == 0 )
    UFG::DUIContext::EndIndent(this->mContext);
}

// File Line: 724
// RVA: 0x1B3BA0
bool __fastcall DNA::DUIReflectWidget::DiscoverPointerField(
        DNA::DUIReflectWidget *this,
        UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *field,
        UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *field_type,
        const char *object_data)
{
  const char *v4; // rax
  unsigned __int64 i; // r15
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *v9; // r12
  unsigned __int64 IDForObject; // rax
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *v11; // r14
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *mNext; // rbx
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *p_mSubObjects; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *mPrev; // rax

  v4 = object_data;
  for ( i = 0i64; (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)i < field[6].mNext; ++i )
  {
    if ( (BYTE4(field_type[5].mNext) & 0x10) != 0 )
    {
      v9 = *(UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> **)&v4[8 * i];
      IDForObject = DNA::DUIReflectWidget::GetIDForObject(this);
      v11 = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)IDForObject;
      mNext = this->mSubObjects.mNode.mNext;
      p_mSubObjects = &this->mSubObjects;
      if ( mNext == (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)&this->mSubObjects )
      {
LABEL_8:
        v14 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
        mNext = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v14;
        if ( v14 )
        {
          v14->mNext = v14;
          v14[1].mNext = v14;
          v14[2].mNext = 0i64;
          v14[3].mNext = 0i64;
          v14[4].mNext = 0i64;
          v14[5].mNext = 0i64;
        }
        else
        {
          mNext = 0i64;
        }
        mNext[1].mNext = field;
        mNext[1].mPrev = field_type;
        v15 = UFG::qMalloc(0xC8ui64, UFG::gGlobalNewName, 0i64);
        if ( v15 )
          DNA::DUIReflectWidget::DUIReflectWidget((DNA::DUIReflectWidget *)v15);
        mNext[2].mNext = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v15;
        mNext[2].mPrev = v11;
        mPrev = p_mSubObjects->mNode.mPrev;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        mNext->mNext = &p_mSubObjects->mNode;
        p_mSubObjects->mNode.mPrev = mNext;
      }
      else
      {
        while ( mNext[1].mNext != field
             || mNext[1].mPrev != field_type
             || mNext[2].mPrev != (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)IDForObject )
        {
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)p_mSubObjects )
            goto LABEL_8;
        }
      }
      mNext[2].mNext[4].mPrev = v9;
      v4 = object_data;
    }
  }
  return 0;
}

// File Line: 740
// RVA: 0x1B36F0
bool __fastcall DNA::DUIReflectWidget::BeginPointerField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *object_data)
{
  unsigned __int64 i; // rdi
  DNA::DUIReflectWidget::SubObject *SubObject; // r14
  bool *ExpandedState; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  for ( i = 0i64; i < field->mArrayLength; ++i )
  {
    if ( (field_type->mFlags & 0x10) != 0 )
    {
      SubObject = DNA::DUIReflectWidget::GetSubObject(this, field_type, field);
      DNA::DUIReflectWidget::GetDisplayName(this, &result, field);
      ExpandedState = DNA::DUIReflectWidget::GetExpandedState(this, field_type, field);
      if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, result.mData, ExpandedState) )
      {
        UFG::DUIContext::BeginIndent(this->mContext);
        DNA::DUIReflectWidget::UpdateUI(SubObject->mWidget, this->mContext);
        UFG::DUIContext::EndIndent(this->mContext);
      }
      UFG::qString::~qString(&result);
    }
  }
  return 0;
}

// File Line: 762
// RVA: 0x1B3870
bool __fastcall DNA::DUIReflectWidget::DiscoverArrayField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *field_data)
{
  unsigned int capacity; // edx
  __int64 size; // rsi
  unsigned int v6; // ebx
  const char *v7; // r14
  unsigned int v10; // edx
  unsigned int *p; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mNext; // rbx
  UFG::ReflectionDB *v13; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v14; // rax
  UFG::qReflectField *v15; // r8
  unsigned __int64 v16; // r10
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v17; // r11
  UFG::qReflectType *v18; // r9
  const char *v19; // r13
  unsigned int v20; // ebp
  unsigned int v21; // r15d
  __int64 v22; // r12
  __int64 v23; // r14
  unsigned int v24; // ebx
  unsigned int v25; // esi
  unsigned int v26; // ebx
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  unsigned int *v29; // rbp
  __int64 i; // r9
  __int64 v31; // r8
  unsigned int *v32; // rax
  UFG::qReflectObject *v33; // rbx
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v37; // [rsp+20h] [rbp-68h]
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v38; // [rsp+28h] [rbp-60h]
  unsigned __int64 v39; // [rsp+30h] [rbp-58h]
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v40; // [rsp+38h] [rbp-50h]

  capacity = this->mArrayIndices.capacity;
  size = this->mArrayIndices.size;
  v6 = size + 1;
  v7 = field_data;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v10 = 2 * capacity;
    else
      v10 = 1;
    for ( ; v10 < v6; v10 *= 2 )
      ;
    if ( v10 <= 4 )
      v10 = 4;
    if ( v10 - v6 > 0x10000 )
      v10 = size + 65537;
    UFG::qArray<long,0>::Reallocate(&this->mArrayIndices, v10, "qArray.Add");
  }
  p = this->mArrayIndices.p;
  this->mArrayIndices.size = v6;
  p[size] = 0;
  mNext = field_type->mOrderedFields.mNode.mNext;
  v40 = mNext;
  v13 = UFG::ReflectionDB::Instance();
  v14 = UFG::ReflectionDB::GetType(v13, (const char *)mNext[4].mNext);
  v15 = field;
  v16 = 0i64;
  v17 = v14;
  v38 = v14;
  v39 = 0i64;
  if ( field->mArrayLength )
  {
    v18 = field_type;
    do
    {
      this->mArrayIndices.p[this->mArrayIndices.size - 1] = v16;
      v19 = &v7[v18->mNumBytes * v16];
      v20 = *((_DWORD *)v19 + 2);
      v37 = v20;
      if ( v20 && (BYTE4(v17[1].mTree.mHead.mNeighbours[0]) & 0x10) != 0 )
      {
        v21 = 0;
        v22 = 0i64;
        do
        {
          v23 = this->mArrayIndices.size;
          v24 = this->mArrayIndices.capacity;
          v25 = v23 + 1;
          if ( (int)v23 + 1 > v24 )
          {
            if ( v24 )
              v26 = 2 * v24;
            else
              v26 = 1;
            for ( ; v26 < v25; v26 *= 2 )
              ;
            if ( v26 <= 4 )
              v26 = 4;
            if ( v26 - v25 > 0x10000 )
              v26 = v23 + 65537;
            if ( v26 != (_DWORD)v23 )
            {
              v27 = 4i64 * v26;
              if ( !is_mul_ok(v26, 4ui64) )
                v27 = -1i64;
              v28 = UFG::qMalloc(v27, "qArray.Add", 0i64);
              v29 = (unsigned int *)v28;
              if ( this->mArrayIndices.p )
              {
                for ( i = 0i64;
                      (unsigned int)i < this->mArrayIndices.size;
                      *(_DWORD *)((char *)&v28->mNext + v31 * 4) = this->mArrayIndices.p[v31] )
                {
                  v31 = i;
                  i = (unsigned int)(i + 1);
                }
                operator delete[](this->mArrayIndices.p);
              }
              v15 = field;
              v18 = field_type;
              v17 = v38;
              this->mArrayIndices.p = v29;
              v20 = v37;
              this->mArrayIndices.capacity = v26;
            }
          }
          v32 = this->mArrayIndices.p;
          this->mArrayIndices.size = v25;
          v32[v23] = v21;
          if ( ((__int64)v40[7].mPrev & 0x4000) != 0 )
            v33 = *(UFG::qReflectObject **)(v22 + *(_QWORD *)v19);
          else
            v33 = (UFG::qReflectObject *)(*(_QWORD *)v19
                                        + (~(LODWORD(v17[1].mTree.mHead.mNeighbours[0]) - 1i64) & (LODWORD(v17[1].mTree.mHead.mNeighbours[0])
                                                                                                 + v21
                                                                                                 * (__int64)v17[1].mTree.mHead.mChildren[1]
                                                                                                 - 1)));
          DNA::DUIReflectWidget::GetSubObject(this, v18, v15)->mWidget->mObject = v33;
          v34 = this->mArrayIndices.size;
          if ( v34 > 1 )
            this->mArrayIndices.size = v34 - 1;
          else
            this->mArrayIndices.size = 0;
          v15 = field;
          v18 = field_type;
          v17 = v38;
          ++v21;
          v22 += 8i64;
        }
        while ( v21 < v20 );
        v16 = v39;
        v7 = field_data;
      }
      v39 = ++v16;
    }
    while ( v16 < v15->mArrayLength );
  }
  v35 = this->mArrayIndices.size;
  if ( v35 > 1 )
    this->mArrayIndices.size = v35 - 1;
  else
    this->mArrayIndices.size = 0;
  return 0;
}

// File Line: 814
// RVA: 0x1B2BF0
bool __fastcall DNA::DUIReflectWidget::BeginArrayField(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *field_data)
{
  UFG::qReflectField *v5; // r14
  UFG::qArray<unsigned long,0> *p_mArrayIndices; // rdi
  __int64 size; // rsi
  unsigned int v9; // ebx
  unsigned int capacity; // edx
  unsigned int v11; // edx
  UFG::qReflectField *mNext; // r15
  UFG::ReflectionDB *v13; // rax
  UFG::qReflectType *v14; // r13
  unsigned __int64 v15; // r12
  UFG::qReflectType *v16; // r9
  const char *v17; // rdx
  unsigned int v18; // r12d
  unsigned int mFlags; // eax
  unsigned int v20; // r15d
  __int64 v21; // r12
  __int64 v22; // r13
  unsigned int v23; // esi
  unsigned int v24; // ebx
  unsigned int v25; // ebx
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  unsigned int *v28; // r14
  __int64 i; // r9
  __int64 v30; // rbx
  DNA::DUIReflectWidget::SubObject *SubObject; // rsi
  unsigned __int64 v32; // rbx
  UFG::ReflectionDB *v33; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v34; // rax
  bool *ExpandedState; // rax
  UFG::qString *v36; // rcx
  DNA::DUIReflectWidget::SubObject *v37; // rbx
  bool *v38; // rax
  unsigned int v39; // esi
  __int64 v40; // r15
  __int64 v41; // r14
  unsigned int v42; // ebx
  unsigned int v43; // edx
  unsigned int v44; // edx
  UFG::qColour *v45; // rbx
  bool *v46; // rax
  bool HasEditor; // al
  UFG::DUIContext *mContext; // rcx
  unsigned int v49; // esi
  __int64 v50; // r14
  UFG::qSymbolUC *v51; // rbx
  const char *v53; // [rsp+30h] [rbp-138h]
  UFG::qReflectField *v54; // [rsp+38h] [rbp-130h]
  unsigned __int64 v55; // [rsp+40h] [rbp-128h]
  UFG::qReflectType *v56; // [rsp+48h] [rbp-120h]
  UFG::qString result; // [rsp+50h] [rbp-118h] BYREF
  __int64 v58; // [rsp+78h] [rbp-F0h]
  UFG::qString v59; // [rsp+80h] [rbp-E8h] BYREF
  UFG::qString v60; // [rsp+A8h] [rbp-C0h] BYREF
  UFG::qString v61; // [rsp+D0h] [rbp-98h] BYREF
  UFG::qString v62; // [rsp+F8h] [rbp-70h] BYREF
  unsigned int v63; // [rsp+170h] [rbp+8h]

  v58 = -2i64;
  v5 = field;
  p_mArrayIndices = &this->mArrayIndices;
  size = this->mArrayIndices.size;
  v9 = size + 1;
  capacity = this->mArrayIndices.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v11 = 2 * capacity;
    else
      v11 = 1;
    for ( ; v11 < v9; v11 *= 2 )
      ;
    if ( v11 <= 4 )
      v11 = 4;
    if ( v11 - v9 > 0x10000 )
      v11 = size + 65537;
    UFG::qArray<long,0>::Reallocate(p_mArrayIndices, v11, "qArray.Add");
  }
  p_mArrayIndices->size = v9;
  p_mArrayIndices->p[size] = 0;
  DNA::DUIReflectWidget::GetDisplayName(this, &result, this->mFieldStack.p[this->mFieldStack.size - 2]);
  UFG::DUIContext::BeginIndent(this->mContext);
  mNext = (UFG::qReflectField *)field_type->mOrderedFields.mNode.mNext;
  v54 = mNext;
  v13 = UFG::ReflectionDB::Instance();
  v14 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v13, mNext->mTypeName);
  v56 = v14;
  v15 = 0i64;
  v55 = 0i64;
  if ( v5->mArrayLength )
  {
    v16 = field_type;
    do
    {
      p_mArrayIndices->p[p_mArrayIndices->size - 1] = v15;
      v17 = &field_data[v15 * v16->mNumBytes];
      v53 = v17;
      v18 = *((_DWORD *)v17 + 2);
      v63 = v18;
      if ( v18 )
      {
        mFlags = v14->mFlags;
        if ( (mFlags & 0x10) != 0 )
        {
          v20 = 0;
          v21 = 0i64;
          do
          {
            v22 = p_mArrayIndices->size;
            v23 = v22 + 1;
            v24 = p_mArrayIndices->capacity;
            if ( (int)v22 + 1 > v24 )
            {
              if ( v24 )
                v25 = 2 * v24;
              else
                v25 = 1;
              for ( ; v25 < v23; v25 *= 2 )
                ;
              if ( v25 <= 4 )
                v25 = 4;
              if ( v25 - v23 > 0x10000 )
                v25 = v22 + 65537;
              if ( v25 != (_DWORD)v22 )
              {
                v26 = 4i64 * v25;
                if ( !is_mul_ok(v25, 4ui64) )
                  v26 = -1i64;
                v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
                v28 = (unsigned int *)v27;
                if ( p_mArrayIndices->p )
                {
                  for ( i = 0i64; (unsigned int)i < p_mArrayIndices->size; i = (unsigned int)(i + 1) )
                    *((_DWORD *)&v27->mNext + i) = p_mArrayIndices->p[i];
                  operator delete[](p_mArrayIndices->p);
                }
                p_mArrayIndices->p = v28;
                p_mArrayIndices->capacity = v25;
                v17 = v53;
                v5 = field;
                v16 = field_type;
              }
            }
            p_mArrayIndices->size = v23;
            p_mArrayIndices->p[v22] = v20;
            if ( (v54->mFlags & 0x4000) != 0 )
            {
              v30 = *(_QWORD *)(v21 + *(_QWORD *)v17);
              SubObject = DNA::DUIReflectWidget::GetSubObject(this, v16, v5);
              v32 = *(_QWORD *)(v30 + 56);
              v33 = UFG::ReflectionDB::Instance();
              v34 = UFG::ReflectionDB::GetType(v33, v32);
              UFG::qString::FormatEx(&v61, "%s[%d] [%s]", result.mData, v20, (const char *)v34->mTree.mCount);
              ExpandedState = DNA::DUIReflectWidget::GetExpandedState(this, field_type, v5);
              if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, v61.mData, ExpandedState) )
              {
                UFG::DUIContext::BeginIndent(this->mContext);
                DNA::DUIReflectWidget::UpdateUI(SubObject->mWidget, this->mContext);
                UFG::DUIContext::EndIndent(this->mContext);
              }
              v36 = &v61;
            }
            else
            {
              v37 = DNA::DUIReflectWidget::GetSubObject(this, v16, v5);
              UFG::qString::FormatEx(&v59, "%s[%d]", result.mData, v20);
              v38 = DNA::DUIReflectWidget::GetExpandedState(this, field_type, v5);
              if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, v59.mData, v38) )
              {
                UFG::DUIContext::BeginIndent(this->mContext);
                DNA::DUIReflectWidget::UpdateUI(v37->mWidget, this->mContext);
                UFG::DUIContext::EndIndent(this->mContext);
              }
              v36 = &v59;
            }
            UFG::qString::~qString(v36);
            if ( p_mArrayIndices->size > 1 )
              --p_mArrayIndices->size;
            else
              p_mArrayIndices->size = 0;
            ++v20;
            v21 += 8i64;
            v17 = v53;
            v16 = field_type;
          }
          while ( v20 < v63 );
          v14 = v56;
        }
        else
        {
          if ( (mFlags & 1) != 0 || (mFlags & 8) != 0 || (mFlags & 0x80u) != 0 )
          {
            v49 = 0;
            v50 = 0i64;
            do
            {
              v51 = (UFG::qSymbolUC *)(*(_QWORD *)v17
                                     + (~(v14->mAlignment - 1i64) & (v14->mAlignment + v50 * v14->mNumBytes - 1)));
              UFG::DUIContext::BeginGridLayout(this->mContext, 2, 1, LayoutFlag_DistributeCells);
              UFG::DUIContext::BeginIndent(this->mContext);
              UFG::qString::FormatEx(&v62, "%s[%d]", result.mData, v49);
              UFG::DUIContext::Label(this->mContext, v62.mData);
              UFG::DUIContext::EndIndent(this->mContext);
              DNA::DUIReflectWidget::AddBasicType(this, mNext, v14, v51);
              UFG::DUIContext::EndLayoutHorizontal(this->mContext);
              UFG::qString::~qString(&v62);
              ++v49;
              ++v50;
              v17 = v53;
            }
            while ( v49 < v18 );
            p_mArrayIndices = &this->mArrayIndices;
            v5 = field;
            v16 = field_type;
            goto LABEL_78;
          }
          v39 = 0;
          v40 = 0i64;
          do
          {
            v41 = p_mArrayIndices->size;
            v42 = v41 + 1;
            v43 = p_mArrayIndices->capacity;
            if ( (int)v41 + 1 > v43 )
            {
              if ( v43 )
                v44 = 2 * v43;
              else
                v44 = 1;
              for ( ; v44 < v42; v44 *= 2 )
                ;
              if ( v44 <= 4 )
                v44 = 4;
              if ( v44 - v42 > 0x10000 )
                v44 = v41 + 65537;
              UFG::qArray<long,0>::Reallocate(p_mArrayIndices, v44, "qArray.Add");
            }
            p_mArrayIndices->size = v42;
            p_mArrayIndices->p[v41] = v39;
            v45 = (UFG::qColour *)(*(_QWORD *)v53
                                 + (~(v14->mAlignment - 1i64) & (v14->mAlignment + v40 * v14->mNumBytes - 1)));
            UFG::qString::FormatEx(&v60, "%s[%d]", result.mData, v39);
            v5 = field;
            v46 = DNA::DUIReflectWidget::GetExpandedState(this, field_type, field);
            if ( (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, v60.mData, v46) )
            {
              HasEditor = DNA::HasEditor(v14, "ColourPicker");
              mContext = this->mContext;
              if ( HasEditor )
              {
                UFG::DUIContext::ColourPicker(mContext, &customCaption, v45, 1);
              }
              else
              {
                UFG::DUIContext::BeginIndent(mContext);
                UFG::qReflectVisitor::VisitObject(this, v14, (const char *)v45);
                UFG::DUIContext::EndIndent(this->mContext);
              }
            }
            if ( p_mArrayIndices->size > 1 )
              --p_mArrayIndices->size;
            else
              p_mArrayIndices->size = 0;
            UFG::qString::~qString(&v60);
            ++v39;
            ++v40;
          }
          while ( v39 < v18 );
          v16 = field_type;
        }
        mNext = v54;
      }
LABEL_78:
      v15 = v55 + 1;
      v55 = v15;
    }
    while ( v15 < v5->mArrayLength );
  }
  UFG::DUIContext::EndIndent(this->mContext);
  if ( p_mArrayIndices->size > 1 )
    --p_mArrayIndices->size;
  else
    p_mArrayIndices->size = 0;
  UFG::qString::~qString(&result);
  return 0;
}

// File Line: 939
// RVA: 0x1B3270
void __fastcall DNA::DUIReflectWidget::BeginBytes(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        const char *data)
{
  int v7; // ebx
  unsigned __int64 mArrayLength; // r14
  unsigned __int64 mNumBytes; // r12
  char *mData; // rdi
  bool *ExpandedState; // rax
  unsigned int v12; // ebp
  __int64 v13; // rdi
  UFG::qColour *v14; // rdi
  bool HasEditor; // al
  UFG::DUIContext *mContext; // rcx
  UFG::qString *v17; // rax
  UFG::qString result; // [rsp+28h] [rbp-D0h] BYREF
  __int64 v19; // [rsp+50h] [rbp-A8h]
  UFG::qString v20; // [rsp+58h] [rbp-A0h] BYREF
  UFG::qString v21; // [rsp+80h] [rbp-78h] BYREF
  UFG::qString v22; // [rsp+A8h] [rbp-50h] BYREF

  v19 = -2i64;
  v7 = 0;
  if ( !DNA::IsHidden(this->mTypeStack.p[this->mTypeStack.size - 1], field) )
  {
    mArrayLength = field->mArrayLength;
    mNumBytes = field_type->mNumBytes;
    DNA::DUIReflectWidget::GetDisplayName(this, &result, field);
    if ( mArrayLength <= 1
      || (mData = result.mData,
          ExpandedState = DNA::DUIReflectWidget::GetExpandedState(this, field_type, field),
          (unsigned __int8)UFG::DUIContext::Collapsible(this->mContext, mData, ExpandedState)) )
    {
      v12 = 0;
      if ( mArrayLength )
      {
        v13 = 0i64;
        do
        {
          v14 = (UFG::qColour *)&data[mNumBytes * v13];
          HasEditor = DNA::HasEditor(field, "ColourPicker");
          mContext = this->mContext;
          if ( HasEditor )
          {
            UFG::DUIContext::ColourPicker(mContext, &customCaption, v14, 1);
          }
          else
          {
            UFG::DUIContext::BeginGridLayout(mContext, 2, 1, LayoutFlag_DistributeCells);
            UFG::DUIContext::BeginIndent(this->mContext);
            if ( mArrayLength <= 1 )
            {
              UFG::qString::qString(&v21, &result);
              v7 |= 2u;
            }
            else
            {
              v17 = UFG::qString::FormatEx(&v22, "%s[%d]", result.mData, v12);
              v7 |= 1u;
            }
            UFG::qString::qString(&v20, v17);
            if ( (v7 & 2) != 0 )
            {
              v7 &= ~2u;
              UFG::qString::~qString(&v21);
            }
            if ( (v7 & 1) != 0 )
            {
              v7 &= ~1u;
              UFG::qString::~qString(&v22);
            }
            UFG::DUIContext::Label(this->mContext, v20.mData);
            UFG::DUIContext::EndIndent(this->mContext);
            DNA::DUIReflectWidget::AddBasicType(this, field, field_type, (UFG::qSymbolUC *)v14);
            UFG::DUIContext::EndLayoutHorizontal(this->mContext);
            UFG::qString::~qString(&v20);
          }
          v13 = ++v12;
        }
        while ( v12 < mArrayLength );
      }
    }
    UFG::qString::~qString(&result);
  }
}

// File Line: 982
// RVA: 0x1B5AF0
void __fastcall DNA::DUIReflectWidget::UpdateUI(DNA::DUIReflectWidget *this, UFG::DUIContext *dui)
{
  bool v2; // zf
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int *p; // rax
  unsigned __int64 mTypeUID; // rbx
  UFG::ReflectionDB *v10; // rax
  UFG::qReflectType *Type; // rax
  unsigned int v12; // eax

  v2 = this->mObject == 0i64;
  this->mContext = dui;
  if ( v2 )
  {
    this->mContext = 0i64;
  }
  else
  {
    size = this->mArrayIndices.size;
    capacity = this->mArrayIndices.capacity;
    v6 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v7 = 2 * capacity;
      else
        v7 = 1;
      for ( ; v7 < v6; v7 *= 2 )
        ;
      if ( v7 <= 4 )
        v7 = 4;
      if ( v7 - v6 > 0x10000 )
        v7 = size + 65537;
      UFG::qArray<long,0>::Reallocate(&this->mArrayIndices, v7, "qArray.Add");
    }
    p = this->mArrayIndices.p;
    this->mArrayIndices.size = v6;
    p[size] = 0;
    mTypeUID = this->mObject->mTypeUID;
    v10 = UFG::ReflectionDB::Instance();
    Type = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v10, mTypeUID);
    UFG::qReflectVisitor::TrackObject(this, Type, (const char *)this->mObject);
    UFG::qReflectVisitor::VisitObjects(this);
    this->mTrackedObjects.size = 0;
    this->mPatches.size = 0;
    this->mArrays.size = 0;
    v12 = this->mArrayIndices.size;
    if ( v12 > 1 )
      this->mArrayIndices.size = v12 - 1;
    else
      this->mArrayIndices.size = 0;
    this->mContext = 0i64;
  }
}

// File Line: 1003
// RVA: 0x1B3DD0
UFG::qString *__fastcall DNA::DUIReflectWidget::GetDisplayName(
        DNA::DUIReflectWidget *this,
        UFG::qString *result,
        UFG::qReflectField *field)
{
  DNA::GetDisplayName(result, this->mTypeStack.p[this->mTypeStack.size - 1], field);
  return result;
}

// File Line: 1023
// RVA: 0x1B3F70
bool *__fastcall DNA::DUIReflectWidget::GetExpandedState(
        DNA::DUIReflectWidget *this,
        UFG::qReflectType *type,
        UFG::qReflectField *field)
{
  unsigned __int64 IDForObject; // rax
  __int64 size; // rdi
  UFG::qArray<DNA::DUIReflectWidget::ExpandState,0> *p_mExpandState; // r15
  unsigned int v9; // r9d
  unsigned __int64 v10; // r14
  DNA::DUIReflectWidget::ExpandState *p; // rax
  unsigned int capacity; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  bool *result; // rax
  __int64 v16; // rcx

  IDForObject = DNA::DUIReflectWidget::GetIDForObject(this);
  size = this->mExpandState.size;
  p_mExpandState = &this->mExpandState;
  v9 = 0;
  v10 = IDForObject;
  if ( (_DWORD)size )
  {
    p = this->mExpandState.p;
    while ( p->mField != field || p->mType != type || p->mId != v10 )
    {
      ++v9;
      ++p;
      if ( v9 >= (unsigned int)size )
        goto LABEL_7;
    }
    return &p->mExpanded;
  }
  else
  {
LABEL_7:
    capacity = this->mExpandState.capacity;
    v13 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v14 = 2 * capacity;
      else
        v14 = 1;
      for ( ; v14 < v13; v14 *= 2 )
        ;
      if ( v14 - v13 > 0x10000 )
        v14 = size + 65537;
      UFG::qArray<DNA::DUIReflectWidget::ExpandState,0>::Reallocate(p_mExpandState, v14, "qArray.Add");
    }
    p_mExpandState->size = v13;
    v16 = (__int64)&p_mExpandState->p[size];
    *(_BYTE *)(v16 + 24) = 0;
    result = (bool *)(v16 + 24);
    *(_QWORD *)(v16 + 8) = field;
    *(_QWORD *)v16 = type;
    *(_QWORD *)(v16 + 16) = v10;
  }
  return result;
}

// File Line: 1043
// RVA: 0x1B4110
UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *__fastcall DNA::DUIReflectWidget::GetSubObject(
        DNA::DUIReflectWidget *this,
        UFG::allocator::free_link *type,
        UFG::allocator::free_link *field)
{
  unsigned __int64 IDForObject; // rbp
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *result; // rax
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *p_mSubObjects; // rsi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rbx
  UFG::allocator::free_link *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *mPrev; // rcx

  IDForObject = DNA::DUIReflectWidget::GetIDForObject(this);
  result = (UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *)this->mSubObjects.mNode.mNext;
  p_mSubObjects = &this->mSubObjects;
  while ( result != p_mSubObjects )
  {
    if ( (UFG::allocator::free_link *)result[1].mNode.mNext == field
      && (UFG::allocator::free_link *)result[1].mNode.mPrev == type
      && result[2].mNode.mPrev == (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)IDForObject )
    {
      return result;
    }
    result = (UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *)result->mNode.mNext;
  }
  v9 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v10 = v9;
  if ( v9 )
  {
    v9->mNext = v9;
    v9[1].mNext = v9;
    v11 = 0i64;
    v9[2].mNext = 0i64;
    v9[3].mNext = 0i64;
    v9[4].mNext = 0i64;
    v9[5].mNext = 0i64;
  }
  else
  {
    v11 = 0i64;
    v10 = 0i64;
  }
  v10[3].mNext = field;
  v10[2].mNext = type;
  v12 = UFG::qMalloc(0xC8ui64, UFG::gGlobalNewName, 0i64);
  if ( v12 )
  {
    DNA::DUIReflectWidget::DUIReflectWidget((DNA::DUIReflectWidget *)v12);
    v11 = v13;
  }
  v10[5].mNext = v11;
  v10[4].mNext = (UFG::allocator::free_link *)IDForObject;
  mPrev = p_mSubObjects->mNode.mPrev;
  mPrev->mNext = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v10;
  v10->mNext = (UFG::allocator::free_link *)mPrev;
  v10[1].mNext = (UFG::allocator::free_link *)p_mSubObjects;
  p_mSubObjects->mNode.mPrev = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v10;
  return (UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *)v10;
}

// File Line: 1063
// RVA: 0x1B4050
unsigned __int64 __fastcall DNA::DUIReflectWidget::GetIDForObject(DNA::DUIReflectWidget *this)
{
  __int64 v1; // rbp
  unsigned __int64 mUID; // rdi
  unsigned int i; // esi
  unsigned __int64 v5; // rax
  unsigned __int64 result; // rax
  char dest[256]; // [rsp+20h] [rbp-108h] BYREF

  v1 = 0i64;
  mUID = this->mObject->mBaseNode.mUID;
  for ( i = 0; i < this->mFieldStack.size; mUID = v5 )
    v5 = UFG::qStringHash64(this->mFieldStack.p[i++]->mName, mUID);
  if ( !this->mArrayIndices.size )
    return mUID;
  do
  {
    UFG::qSPrintf(dest, 256, "{%d}", this->mArrayIndices.p[v1]);
    result = UFG::qStringHash64(dest, mUID);
    v1 = (unsigned int)(v1 + 1);
    mUID = result;
  }
  while ( (unsigned int)v1 < this->mArrayIndices.size );
  return result;
}

// File Line: 1085
// RVA: 0x1B1DC0
void __fastcall DNA::DUIReflectWidget::AddBasicType(
        DNA::DUIReflectWidget *this,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        UFG::qSymbolUC *element_data)
{
  unsigned int mFlags; // eax
  unsigned __int64 mNumBytes; // rax
  __int64 mUID; // rax
  UFG::ReflectionDB *v11; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *Enum; // rax
  int v13; // r15d
  UFG::qTree64Base::BaseNode *v14; // rsi
  UFG::qTree64Base::BaseNode **i; // r12
  UFG::qString *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  UFG::qString *mNext; // rdx
  unsigned __int64 v24; // rax
  UFG::qString *j; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rcx
  unsigned int v29; // eax
  char *mData; // rax
  UFG::qSymbol *v31; // rax
  char *v32; // rax
  UFG::qWiseSymbol *v33; // rax
  char *v34; // rax
  unsigned __int64 mNameUID; // rax
  UFG::qString *v36; // rax
  unsigned int v37; // esi
  UFG::qString *v38; // rax
  unsigned int v39; // esi
  UFG::qString *v40; // rax
  unsigned int v41; // esi
  UFG::qString *v42; // rax
  unsigned int v43; // esi
  unsigned int v44; // eax
  UFG::qString *v45; // rax
  unsigned int v46; // esi
  UFG::qString *v47; // [rsp+8h] [rbp-79h]
  UFG::qString string_data; // [rsp+10h] [rbp-71h] BYREF
  UFG::qString options; // [rsp+38h] [rbp-49h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-21h] BYREF
  __int64 v51; // [rsp+88h] [rbp+7h]
  int current_index[2]; // [rsp+E8h] [rbp+67h] BYREF
  __int64 value_to_write[3]; // [rsp+F8h] [rbp+77h] BYREF

  v51 = -2i64;
  string_data.mStringHash32 = 0;
  mFlags = field_type->mFlags;
  if ( (mFlags & 4) != 0 )
  {
    value_to_write[0] = 0i64;
    mNumBytes = field_type->mNumBytes;
    if ( mNumBytes == 4 )
    {
      mUID = (int)element_data->mUID;
    }
    else
    {
      if ( mNumBytes != 8 )
      {
LABEL_7:
        UFG::qString::qString(&string_data);
        if ( !DNA::FindEnumStringFromValue(
                field_type->mName,
                (UFG::qTree64Base::BaseNode **)value_to_write,
                &string_data) )
          UFG::qPrintf(
            "Warning: AddBasicType() could not find enum value for field %s of type %s.  Replacing with an empty string.\n",
            field->mName,
            field_type->mName);
        current_index[0] = 0;
        options.mPrev = &options;
        v11 = UFG::ReflectionDB::Instance();
        Enum = UFG::ReflectionDB::GetEnum(v11, field_type->mName);
        if ( Enum )
        {
          v13 = 0;
          v14 = Enum[1].mTree.mHead.mChildren[0];
          for ( i = &Enum[1].mTree.mHead.mParent; v14 != (UFG::qTree64Base::BaseNode *)i; v14 = v14->mParent )
          {
            v16 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
            value_to_write[1] = (__int64)v16;
            if ( v16 )
            {
              UFG::qString::qString(v16, (const char *)v14->mChildren[0]);
              v18 = v17;
            }
            else
            {
              v18 = 0i64;
            }
            mPrev = options.mPrev;
            options.mPrev->mNext = v18;
            v18->mPrev = mPrev;
            v18->mNext = &options;
            options.mPrev = v18;
            v20 = UFG::qStringCompare((const char *)v14->mChildren[0], string_data.mData, -1);
            v21 = current_index[0];
            if ( !v20 )
              v21 = v13;
            current_index[0] = v21;
            ++v13;
          }
        }
        if ( UFG::DUIContext::ComboBox(
               this->mContext,
               current_index,
               (UFG::qList<UFG::qString,UFG::qString,1,0> *)&options,
               0i64,
               0xFFFFFFFF) )
        {
          v22 = 0;
          mNext = v47;
          if ( v47 != &options )
          {
            while ( v22 != current_index[0] )
            {
              ++v22;
              mNext = (UFG::qString *)mNext->mNext;
              if ( mNext == &options )
                goto LABEL_27;
            }
            if ( DNA::FindEnumValueFromString(field_type->mName, mNext, value_to_write) )
            {
              v24 = field_type->mNumBytes;
              if ( v24 == 4 )
              {
                element_data->mUID = value_to_write[0];
              }
              else if ( v24 == 8 )
              {
                *(_QWORD *)&element_data->mUID = value_to_write[0];
              }
            }
          }
        }
LABEL_27:
        for ( j = v47; v47 != &options; j = v47 )
        {
          v26 = j->mPrev;
          v27 = j->mNext;
          v26->mNext = v27;
          v27->mPrev = v26;
          j->mPrev = j;
          j->mNext = j;
          UFG::qString::~qString(j);
          operator delete[](j);
        }
        v28 = options.mPrev;
        options.mPrev->mNext = v47;
        v47->mPrev = v28;
        options.mPrev = &options;
        goto LABEL_118;
      }
      mUID = *(_QWORD *)&element_data->mUID;
    }
    value_to_write[0] = mUID;
    goto LABEL_7;
  }
  if ( (mFlags & 8) != 0 )
  {
    if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
    {
      UFG::qString::qString(&string_data, this->mEditValue.mData);
    }
    else if ( element_data[2].mUID )
    {
      UFG::qString::qString(&string_data, *(const char **)&element_data->mUID);
    }
    else
    {
      UFG::qString::qString(&string_data, &customCaption);
    }
    if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
    {
      this->mActiveEdit = (const char *)element_data;
      UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      UFG::qReflectString::Set((UFG::qReflectString *)element_data, string_data.mData);
    }
    goto LABEL_118;
  }
  if ( (mFlags & 0x80u) != 0 )
  {
    UFG::qString::qString(&string_data);
    v29 = field_type->mFlags;
    if ( (v29 & 0x100) != 0 )
    {
      if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
        mData = this->mEditValue.mData;
      else
        mData = UFG::qSymbol::as_cstr_dbg(element_data);
      UFG::qString::Set(&string_data, mData);
      if ( !(unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
        goto LABEL_118;
      this->mActiveEdit = (const char *)element_data;
      UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v31 = (UFG::qSymbol *)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)current_index, this->mEditValue.mData);
    }
    else
    {
      if ( (v29 & 0x200) != 0 )
      {
        if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
          v32 = this->mEditValue.mData;
        else
          v32 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)element_data);
        UFG::qString::Set(&string_data, v32);
        if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
        {
          this->mActiveEdit = (const char *)element_data;
          UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
          v33 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)current_index, this->mEditValue.mData);
          UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)element_data, v33);
          _((AMD_HD3D *)(unsigned int)current_index[0]);
        }
        goto LABEL_118;
      }
      if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
        v34 = this->mEditValue.mData;
      else
        v34 = UFG::qSymbol::as_cstr_dbg(element_data);
      UFG::qString::Set(&string_data, v34);
      if ( !(unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
        goto LABEL_118;
      this->mActiveEdit = (const char *)element_data;
      UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v31 = UFG::qSymbol::create_from_string((UFG::qSymbol *)current_index, this->mEditValue.mData);
    }
    element_data->mUID = v31->mUID;
    goto LABEL_118;
  }
  UFG::qString::qString(&string_data);
  mNameUID = field_type->mNameUID;
  if ( mNameUID == DNA::kBasicTypeUID_long_long )
  {
    if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
    {
      UFG::qString::qString(&result, &this->mEditValue);
      v37 = 1;
    }
    else
    {
      v36 = UFG::qString::FormatEx(&options, "%d", *(_QWORD *)&element_data->mUID);
      v37 = 2;
    }
    string_data.mStringHash32 = v37;
    UFG::qString::Set(&string_data, v36->mData, v36->mLength, 0i64, 0);
    if ( (v37 & 2) != 0 )
    {
      v37 &= ~2u;
      string_data.mStringHash32 = v37;
      UFG::qString::~qString(&options);
    }
    if ( (v37 & 1) != 0 )
    {
      string_data.mStringHash32 = v37 & 0xFFFFFFFE;
      UFG::qString::~qString(&result);
    }
    if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
    {
      this->mActiveEdit = (const char *)element_data;
      UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      *(_QWORD *)&element_data->mUID = UFG::qToInt64(this->mEditValue.mData, *(_QWORD *)&element_data->mUID);
    }
    goto LABEL_118;
  }
  if ( mNameUID == DNA::kBasicTypeUID_long || mNameUID == DNA::kBasicTypeUID_int )
  {
    LODWORD(value_to_write[0]) = 0;
    current_index[0] = 0;
    if ( DNA::HasRange(this->mTypeStack.p[this->mTypeStack.size - 1], field, (int *)value_to_write, current_index) )
    {
      *(float *)&string_data.mData = FLOAT_N1_0;
      string_data.mMagic = current_index[0];
      UFG::DUIContext::Slider(this->mContext, &customCaption, &element_data->mUID, value_to_write[0]);
      goto LABEL_118;
    }
    if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
    {
      UFG::qString::qString(&options, &this->mEditValue);
      v46 = 4;
    }
    else
    {
      v45 = UFG::qString::FormatEx(&result, "%d", element_data->mUID);
      v46 = 8;
    }
    string_data.mStringHash32 = v46;
    UFG::qString::Set(&string_data, v45->mData, v45->mLength, 0i64, 0);
    if ( (v46 & 8) != 0 )
    {
      v46 &= ~8u;
      string_data.mStringHash32 = v46;
      UFG::qString::~qString(&result);
    }
    if ( (v46 & 4) != 0 )
    {
      string_data.mStringHash32 = v46 & 0xFFFFFFFB;
      UFG::qString::~qString(&options);
    }
    if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
    {
      this->mActiveEdit = (const char *)element_data;
      UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v44 = UFG::qToInt32(this->mEditValue.mData, element_data->mUID);
      goto LABEL_117;
    }
  }
  else
  {
    if ( mNameUID == DNA::kBasicTypeUID_unsigned_long_long )
    {
      if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
      {
        UFG::qString::qString(&options, &this->mEditValue);
        v39 = 16;
      }
      else
      {
        v38 = UFG::qString::FormatEx(&result, "%d", *(_QWORD *)&element_data->mUID);
        v39 = 32;
      }
      string_data.mStringHash32 = v39;
      UFG::qString::Set(&string_data, v38->mData, v38->mLength, 0i64, 0);
      if ( (v39 & 0x20) != 0 )
      {
        v39 &= ~0x20u;
        string_data.mStringHash32 = v39;
        UFG::qString::~qString(&result);
      }
      if ( (v39 & 0x10) != 0 )
      {
        string_data.mStringHash32 = v39 & 0xFFFFFFEF;
        UFG::qString::~qString(&options);
      }
      if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
      {
        this->mActiveEdit = (const char *)element_data;
        UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
        *(_QWORD *)&element_data->mUID = UFG::qToUInt64(this->mEditValue.mData, *(_QWORD *)&element_data->mUID);
      }
      goto LABEL_118;
    }
    if ( mNameUID != DNA::kBasicTypeUID_unsigned_long && mNameUID != DNA::kBasicTypeUID_unsigned_int )
    {
      if ( mNameUID == DNA::kBasicTypeUID_float )
      {
        LODWORD(value_to_write[0]) = 0;
        current_index[0] = 0;
        if ( DNA::HasRange(
               this->mTypeStack.p[this->mTypeStack.size - 1],
               field,
               (float *)value_to_write,
               (float *)current_index) )
        {
          LODWORD(string_data.mData) = 0;
          string_data.mMagic = current_index[0];
          UFG::DUIContext::Slider(
            this->mContext,
            &customCaption,
            (float *)&element_data->mUID,
            *(float *)value_to_write);
        }
        else
        {
          if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
          {
            UFG::qString::qString(&options, &this->mEditValue);
            v41 = 256;
          }
          else
          {
            v40 = UFG::qString::FormatEx(&result, "%f", element_data->mUID);
            v41 = 512;
          }
          string_data.mStringHash32 = v41;
          UFG::qString::Set(&string_data, v40->mData, v40->mLength, 0i64, 0);
          if ( (v41 & 0x200) != 0 )
          {
            v41 &= ~0x200u;
            string_data.mStringHash32 = v41;
            UFG::qString::~qString(&result);
          }
          if ( (v41 & 0x100) != 0 )
          {
            string_data.mStringHash32 = v41 & 0xFFFFFEFF;
            UFG::qString::~qString(&options);
          }
          if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
          {
            this->mActiveEdit = (const char *)element_data;
            UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
            *(float *)&element_data->mUID = UFG::qToFloat(this->mEditValue.mData, *(float *)&element_data->mUID);
          }
        }
      }
      else if ( mNameUID == DNA::kBasicTypeUID_bool )
      {
        UFG::DUIContext::Checkbox(this->mContext, &customCaption, (bool *)element_data);
      }
      goto LABEL_118;
    }
    if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data )
    {
      UFG::qString::qString(&options, &this->mEditValue);
      v43 = 64;
    }
    else
    {
      v42 = UFG::qString::FormatEx(&result, "%d", element_data->mUID);
      v43 = 128;
    }
    string_data.mStringHash32 = v43;
    UFG::qString::Set(&string_data, v42->mData, v42->mLength, 0i64, 0);
    if ( (v43 & 0x80u) != 0 )
    {
      v43 &= ~0x80u;
      string_data.mStringHash32 = v43;
      UFG::qString::~qString(&result);
    }
    if ( (v43 & 0x40) != 0 )
    {
      string_data.mStringHash32 = v43 & 0xFFFFFFBF;
      UFG::qString::~qString(&options);
    }
    if ( (unsigned __int8)UFG::DUIContext::TextBox(this->mContext, &string_data, 0i64, 1, 0i64, -1) )
    {
      this->mActiveEdit = (const char *)element_data;
      UFG::qString::Set(&this->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v44 = UFG::qToUInt32(this->mEditValue.mData, element_data->mUID);
LABEL_117:
      element_data->mUID = v44;
    }
  }
LABEL_118:
  UFG::qString::~qString(&string_data);
  if ( (UFG::qSymbolUC *)this->mActiveEdit == element_data && this->mContext->mCurrentID != this->mContext->mFocusedID )
    this->mActiveEdit = 0i64;
}

// File Line: 1301
// RVA: 0x1B5170
void __fastcall DNA::DUIReflectInspector::OnPropertyChanged(
        UFG::qReflectObject *object,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        char *field_data)
{
  char *Name; // rax

  Name = UFG::qReflectObject::GetName(object);
  UFG::qPrintf("Property Changed on Object %s, Field %s, Type %s\n", Name, field->mName, field_type->mName);
}

// File Line: 1307
// RVA: 0x1B5150
void __fastcall DNA::DUIReflectInspector::OnObjectReloaded(char *object, _QWORD *user_data)
{
  if ( user_data[49] == *((_QWORD *)object + 1) )
    user_data[59] = object;
}

// File Line: 1329
// RVA: 0x1B5A90
void __fastcall DNA::DUIReflectInspector::UpdateUI(DNA::DUIReflectInspector *this, UFG::DUIContext *dui)
{
  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(dui);
  this->mWidget.mObject = this->mObjectHandle.mData;
  DNA::DUIReflectWidget::UpdateUI(&this->mWidget, dui);
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndScrollView(dui);
}

