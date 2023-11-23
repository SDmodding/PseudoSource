// File Line: 271
// RVA: 0x1B0000
void __fastcall UITest::HandleTest::HandleTest(UITest::HandleTest *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::HandleTest,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::HandleTest::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mValueHandle);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mSubClassHandle);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mGenericHandle);
}

// File Line: 290
// RVA: 0x1AFF50
void __fastcall UITest::HandleArrayTest::HandleArrayTest(UITest::HandleArrayTest *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::UFG::qReflectObject::mHandles.mNode.mPrev = &this->UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::UFG::qReflectObject::mHandles.mNode;
  this->UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::UFG::qReflectObject::mHandles.mNode.mNext = &this->UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::UFG::qReflectObject::mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::HandleArrayTest::`vftable;
  `eh vector constructor iterator(
    this->mHandles,
    0x28ui64,
    5,
    (void (__fastcall *)(void *))UFG::qReflectHandle<UFG::qReflectObject>::qReflectHandle<UFG::qReflectObject>);
  this->mHandleArray.mData.mFlags = 2;
}

// File Line: 317
// RVA: 0x1B00C0
void __fastcall UITest::SymbolTest::SymbolTest(UITest::SymbolTest *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::SymbolTest::`vftable;
  _((AMD_HD3D *)this->mWiseSymbol.mUID);
  this->mSymbolArray.mData.mFlags = 2;
}

// File Line: 420
// RVA: 0x1B0150
void __fastcall UITest::UITestCase::UITestCase(UITest::UITestCase *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  UITest::ColourTest *p_mColours; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v5; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::UITestCase::`vftable;
  p_mColours = &this->mColours;
  v5 = &this->mColours.UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject>;
  v6 = v5->mBaseNode.mUID;
  v5->mBaseNode.mParent = &v5->mBaseNode;
  v5->mBaseNode.mChildren[0] = &v5->mBaseNode;
  v5->mBaseNode.mChildren[1] = &v5->mBaseNode;
  v5->mBaseNode.mNeighbours[0] = &v5->mBaseNode;
  v5->mBaseNode.mNeighbours[1] = &v5->mBaseNode;
  v5->mBaseNode.mUID = v6;
  p_mColours->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  p_mColours->mHandles.mNode.mPrev = &p_mColours->mHandles.mNode;
  p_mColours->mHandles.mNode.mNext = &p_mColours->mHandles.mNode;
  p_mColours->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ColourTest,UFG::qReflectObject>::`vftable;
  p_mColours->vfptr = (UFG::qReflectObjectVtbl *)&UITest::ColourTest::`vftable;
  p_mColours->mColours.mData.mFlags = 2;
  v7 = this->mValueTest.mBaseNode.mUID;
  this->mValueTest.mBaseNode.mParent = &this->mValueTest.mBaseNode;
  this->mValueTest.mBaseNode.mChildren[0] = &this->mValueTest.mBaseNode;
  this->mValueTest.mBaseNode.mChildren[1] = &this->mValueTest.mBaseNode;
  this->mValueTest.mBaseNode.mNeighbours[0] = &this->mValueTest.mBaseNode;
  this->mValueTest.mBaseNode.mNeighbours[1] = &this->mValueTest.mBaseNode;
  this->mValueTest.mBaseNode.mUID = v7;
  this->mValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mValueTest.mHandles.mNode.mPrev = &this->mValueTest.mHandles.mNode;
  this->mValueTest.mHandles.mNode.mNext = &this->mValueTest.mHandles.mNode;
  this->mValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::`vftable;
  this->mValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::ValueTest::`vftable;
  v8 = this->mValueSubClassTest.mBaseNode.mUID;
  this->mValueSubClassTest.mBaseNode.mParent = &this->mValueSubClassTest.mBaseNode;
  this->mValueSubClassTest.mBaseNode.mChildren[0] = &this->mValueSubClassTest.mBaseNode;
  this->mValueSubClassTest.mBaseNode.mChildren[1] = &this->mValueSubClassTest.mBaseNode;
  this->mValueSubClassTest.mBaseNode.mNeighbours[0] = &this->mValueSubClassTest.mBaseNode;
  this->mValueSubClassTest.mBaseNode.mNeighbours[1] = &this->mValueSubClassTest.mBaseNode;
  this->mValueSubClassTest.mBaseNode.mUID = v8;
  this->mValueSubClassTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mValueSubClassTest.mHandles.mNode.mPrev = &this->mValueSubClassTest.mHandles.mNode;
  this->mValueSubClassTest.mHandles.mNode.mNext = &this->mValueSubClassTest.mHandles.mNode;
  this->mValueSubClassTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::`vftable;
  this->mValueSubClassTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::ValueTest::`vftable;
  this->mValueSubClassTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::`vftable;
  this->mValueSubClassTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::ValueSubClass::`vftable;
  v9 = this->mPointerTest.mBaseNode.mUID;
  this->mPointerTest.mBaseNode.mParent = &this->mPointerTest.mBaseNode;
  this->mPointerTest.mBaseNode.mChildren[0] = &this->mPointerTest.mBaseNode;
  this->mPointerTest.mBaseNode.mChildren[1] = &this->mPointerTest.mBaseNode;
  this->mPointerTest.mBaseNode.mNeighbours[0] = &this->mPointerTest.mBaseNode;
  this->mPointerTest.mBaseNode.mNeighbours[1] = &this->mPointerTest.mBaseNode;
  this->mPointerTest.mBaseNode.mUID = v9;
  this->mPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mPointerTest.mHandles.mNode.mPrev = &this->mPointerTest.mHandles.mNode;
  this->mPointerTest.mHandles.mNode.mNext = &this->mPointerTest.mHandles.mNode;
  this->mPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::`vftable;
  this->mPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::PointerTest::`vftable;
  v10 = this->mStringTest.mBaseNode.mUID;
  this->mStringTest.mBaseNode.mParent = &this->mStringTest.mBaseNode;
  this->mStringTest.mBaseNode.mChildren[0] = &this->mStringTest.mBaseNode;
  this->mStringTest.mBaseNode.mChildren[1] = &this->mStringTest.mBaseNode;
  this->mStringTest.mBaseNode.mNeighbours[0] = &this->mStringTest.mBaseNode;
  this->mStringTest.mBaseNode.mNeighbours[1] = &this->mStringTest.mBaseNode;
  this->mStringTest.mBaseNode.mUID = v10;
  this->mStringTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mStringTest.mHandles.mNode.mPrev = &this->mStringTest.mHandles.mNode;
  this->mStringTest.mHandles.mNode.mNext = &this->mStringTest.mHandles.mNode;
  this->mStringTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::StringTest,UFG::qReflectObject>::`vftable;
  this->mStringTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::StringTest::`vftable;
  this->mStringTest.mString.mText.mData.mFlags = 2;
  v11 = this->mEnumValueTest.mBaseNode.mUID;
  this->mEnumValueTest.mBaseNode.mParent = &this->mEnumValueTest.mBaseNode;
  this->mEnumValueTest.mBaseNode.mChildren[0] = &this->mEnumValueTest.mBaseNode;
  this->mEnumValueTest.mBaseNode.mChildren[1] = &this->mEnumValueTest.mBaseNode;
  this->mEnumValueTest.mBaseNode.mNeighbours[0] = &this->mEnumValueTest.mBaseNode;
  this->mEnumValueTest.mBaseNode.mNeighbours[1] = &this->mEnumValueTest.mBaseNode;
  this->mEnumValueTest.mBaseNode.mUID = v11;
  this->mEnumValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mEnumValueTest.mHandles.mNode.mPrev = &this->mEnumValueTest.mHandles.mNode;
  this->mEnumValueTest.mHandles.mNode.mNext = &this->mEnumValueTest.mHandles.mNode;
  this->mEnumValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::`vftable;
  this->mEnumValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::EnumValueTest::`vftable;
  v12 = this->mArrayTest.mBaseNode.mUID;
  this->mArrayTest.mBaseNode.mParent = &this->mArrayTest.mBaseNode;
  this->mArrayTest.mBaseNode.mChildren[0] = &this->mArrayTest.mBaseNode;
  this->mArrayTest.mBaseNode.mChildren[1] = &this->mArrayTest.mBaseNode;
  this->mArrayTest.mBaseNode.mNeighbours[0] = &this->mArrayTest.mBaseNode;
  this->mArrayTest.mBaseNode.mNeighbours[1] = &this->mArrayTest.mBaseNode;
  this->mArrayTest.mBaseNode.mUID = v12;
  this->mArrayTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mArrayTest.mHandles.mNode.mPrev = &this->mArrayTest.mHandles.mNode;
  this->mArrayTest.mHandles.mNode.mNext = &this->mArrayTest.mHandles.mNode;
  this->mArrayTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ArrayTest,UFG::qReflectObject>::`vftable;
  this->mArrayTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::ArrayTest::`vftable;
  this->mArrayTest.mFloatValues.mData.mFlags = 2;
  this->mArrayTest.mData.mData.mFlags = 2;
  this->mArrayTest.mValues.mData.mFlags = 2;
  this->mArrayTest.mMyStringArray.mData.mFlags = 2;
  v13 = this->mArrayPointerTest.mBaseNode.mUID;
  this->mArrayPointerTest.mBaseNode.mParent = &this->mArrayPointerTest.mBaseNode;
  this->mArrayPointerTest.mBaseNode.mChildren[0] = &this->mArrayPointerTest.mBaseNode;
  this->mArrayPointerTest.mBaseNode.mChildren[1] = &this->mArrayPointerTest.mBaseNode;
  this->mArrayPointerTest.mBaseNode.mNeighbours[0] = &this->mArrayPointerTest.mBaseNode;
  this->mArrayPointerTest.mBaseNode.mNeighbours[1] = &this->mArrayPointerTest.mBaseNode;
  this->mArrayPointerTest.mBaseNode.mUID = v13;
  this->mArrayPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mArrayPointerTest.mHandles.mNode.mPrev = &this->mArrayPointerTest.mHandles.mNode;
  this->mArrayPointerTest.mHandles.mNode.mNext = &this->mArrayPointerTest.mHandles.mNode;
  this->mArrayPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::`vftable;
  this->mArrayPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::ArrayPointerTest::`vftable;
  this->mArrayPointerTest.mValues.mData.mFlags = 2;
  v14 = this->mMathValueTest.mBaseNode.mUID;
  this->mMathValueTest.mBaseNode.mParent = &this->mMathValueTest.mBaseNode;
  this->mMathValueTest.mBaseNode.mChildren[0] = &this->mMathValueTest.mBaseNode;
  this->mMathValueTest.mBaseNode.mChildren[1] = &this->mMathValueTest.mBaseNode;
  this->mMathValueTest.mBaseNode.mNeighbours[0] = &this->mMathValueTest.mBaseNode;
  this->mMathValueTest.mBaseNode.mNeighbours[1] = &this->mMathValueTest.mBaseNode;
  this->mMathValueTest.mBaseNode.mUID = v14;
  this->mMathValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mMathValueTest.mHandles.mNode.mPrev = &this->mMathValueTest.mHandles.mNode;
  this->mMathValueTest.mHandles.mNode.mNext = &this->mMathValueTest.mHandles.mNode;
  this->mMathValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::`vftable;
  this->mMathValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::MathValueTest::`vftable;
  UITest::HandleTest::HandleTest(&this->mHandleTest, f);
  UITest::HandleArrayTest::HandleArrayTest(&this->mHandleArrayTest, f);
  UITest::SymbolTest::SymbolTest(&this->mSymbolTest, f);
  v15 = this->mDefaultValueTest.mBaseNode.mUID;
  this->mDefaultValueTest.mBaseNode.mParent = &this->mDefaultValueTest.mBaseNode;
  this->mDefaultValueTest.mBaseNode.mChildren[0] = &this->mDefaultValueTest.mBaseNode;
  this->mDefaultValueTest.mBaseNode.mChildren[1] = &this->mDefaultValueTest.mBaseNode;
  this->mDefaultValueTest.mBaseNode.mNeighbours[0] = &this->mDefaultValueTest.mBaseNode;
  this->mDefaultValueTest.mBaseNode.mNeighbours[1] = &this->mDefaultValueTest.mBaseNode;
  this->mDefaultValueTest.mBaseNode.mUID = v15;
  this->mDefaultValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mDefaultValueTest.mHandles.mNode.mPrev = &this->mDefaultValueTest.mHandles.mNode;
  this->mDefaultValueTest.mHandles.mNode.mNext = &this->mDefaultValueTest.mHandles.mNode;
  this->mDefaultValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::DefaultValues,UFG::qReflectObject>::`vftable;
  this->mDefaultValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UITest::DefaultValues::`vftable;
  this->mDefaultValueTest.mString.mText.mData.mFlags = 2;
}

