// File Line: 58
// RVA: 0x95BC0
void __fastcall Illusion::ShaderUser::Init(Illusion::ShaderUser *this, Illusion::Shader *shader)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // esi
  Illusion::Shader *v4; // rdi
  Illusion::ShaderUser *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // edx
  UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *v11; // rcx
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax

  v2 = `UFG::qGetResourceInventory<Illusion::ShaderTemplate>'::`2'::result;
  v3 = shader->mNode.mUID;
  v4 = shader;
  v5 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::ShaderTemplate>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v6, 0x1FD4E5C5u);
    `UFG::qGetResourceInventory<Illusion::ShaderTemplate>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mShaderTemplateHandle.mPrev, 0x1FD4E5C5u, v3, v2);
  v7 = v4->mNode.mUID;
  if ( v7 == 522357802 || v7 == -996812339 )
  {
    v5->mIgnoreOverrides = 1;
  }
  else
  {
    v5->mIgnoreOverrides = 0;
    v8 = v4->mNode.mUID;
    if ( v8 == 1008569504
      || v8 == -1631833766
      || v8 == -1377613595
      || v8 == -321462988
      || v8 == -729810296
      || v8 == -824049412
      || v8 == -2071421796
      || v8 == 114301520
      || v8 == -398646125 )
    {
      v12 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
      {
        v13 = UFG::qResourceWarehouse::Instance();
        v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x8B5561A1);
        `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v12;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mOverride_OutputDepth.mPrev, 0x8B5561A1, 0x71A51007u, v12);
      v14 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
      {
        v15 = UFG::qResourceWarehouse::Instance();
        v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x8B5561A1);
        `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v14;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v5->mOverride_OutputDepthAlpha.mPrev,
        0x8B5561A1,
        0xF5C6CFC5,
        v14);
      v16 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
      {
        v17 = UFG::qResourceWarehouse::Instance();
        v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x8B5561A1);
        `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v16;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v5->mOverride_OutputDepthAlphaWind.mPrev,
        0x8B5561A1,
        0xF5C6CFC5,
        v16);
      v18 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
      {
        v19 = UFG::qResourceWarehouse::Instance();
        v18 = UFG::qResourceWarehouse::GetInventory(v19, 0x8B5561A1);
        `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v18;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v5->mOverride_OutputDepthWind.mPrev,
        0x8B5561A1,
        0x71A51007u,
        v18);
      v11 = (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputHighlight.mPrev;
      if ( v4->mNode.mUID == -398646125 )
        v10 = 1440915685;
      else
        v10 = -1634540862;
    }
    else
    {
      if ( v8 == 706303664 || v8 == 519983264 )
      {
        UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
          (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepth.mPrev,
          0xCEFAD263);
        UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
          (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlpha.mPrev,
          0xCEFAD263);
        UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
          (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlphaWind.mPrev,
          0xCEFAD263);
        UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
          (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthWind.mPrev,
          0xCEFAD263);
        v10 = 1890444835;
      }
      else
      {
        if ( v8 == 1934885740 )
        {
          UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
            (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepth.mPrev,
            0xA6717670);
          UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
            (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlpha.mPrev,
            0x71C30A2Bu);
          UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
            (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlphaWind.mPrev,
            0x787D7E76u);
          v9 = 1908607531;
        }
        else
        {
          if ( v8 != 1278767530 && v8 != -2079057366 )
          {
            UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
              (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepth.mPrev,
              0xA6717670);
            UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
              (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlpha.mPrev,
              0x71C30A2Bu);
            UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
              (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlphaWind.mPrev,
              0x787D7E76u);
            UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
              (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthWind.mPrev,
              0x71C30A2Bu);
            UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
              (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputHighlight.mPrev,
              0);
            return;
          }
          UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
            (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepth.mPrev,
            0xA6717670);
          UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
            (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlpha.mPrev,
            0x71C30A2Bu);
          UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
            (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthAlphaWind.mPrev,
            0x787D7E76u);
          v9 = -55286608;
        }
        UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(
          (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputDepthWind.mPrev,
          v9);
        v10 = 1771531069;
      }
      v11 = (UFG::qTypedResourceHandle<2337628577,Illusion::Shader> *)&v5->mOverride_OutputHighlight.mPrev;
    }
    UFG::qTypedResourceHandle<2337628577,Illusion::Shader>::Init(v11, v10);
  }
}

// File Line: 125
// RVA: 0x95B80
void __fastcall Illusion::ShaderUser::Close(Illusion::ShaderUser *this)
{
  UFG::qResourceInventory *v1; // rax
  Illusion::ShaderUser *v2; // rbx
  UFG::qResourceWarehouse *v3; // rax

  v1 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  v2 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v3, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v1;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mOverride_OutputDepth.mPrev, v1);
}

