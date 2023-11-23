// File Line: 881
// RVA: 0xA3F2A0
fbxsdk_2014_1::FbxColor *__fastcall fbxsdk_2014_1::FbxLayerElementArrayTemplate<fbxsdk_2014_1::FbxColor>::GetAt(
        fbxsdk_2014_1::FbxLayerElementArrayTemplate<fbxsdk_2014_1::FbxColor> *this,
        fbxsdk_2014_1::FbxColor *result,
        int pIndex)
{
  void *v7; // [rsp+58h] [rbp+20h] BYREF

  fbxsdk_2014_1::FbxColor::FbxColor(result);
  v7 = result;
  fbxsdk_2014_1::FbxLayerElementArray::GetAt(this, pIndex, &v7, eFbxDouble4);
  return result;
}

