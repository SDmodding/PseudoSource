// File Line: 881
// RVA: 0xA3F2A0
fbxsdk_2014_1::FbxColor *__fastcall fbxsdk_2014_1::FbxLayerElementArrayTemplate<fbxsdk_2014_1::FbxColor>::GetAt(fbxsdk_2014_1::FbxLayerElementArrayTemplate<fbxsdk_2014_1::FbxColor> *this, fbxsdk_2014_1::FbxColor *result, int pIndex)
{
  int v3; // edi
  fbxsdk_2014_1::FbxColor *v4; // rsi
  fbxsdk_2014_1::FbxLayerElementArrayTemplate<fbxsdk_2014_1::FbxColor> *v5; // rbx
  void *v7; // [rsp+58h] [rbp+20h]

  v3 = pIndex;
  v4 = result;
  v5 = this;
  fbxsdk_2014_1::FbxColor::FbxColor(result);
  v7 = v4;
  fbxsdk_2014_1::FbxLayerElementArray::GetAt((fbxsdk_2014_1::FbxLayerElementArray *)&v5->vfptr, v3, &v7, eFbxDouble4);
  return v4;
}

