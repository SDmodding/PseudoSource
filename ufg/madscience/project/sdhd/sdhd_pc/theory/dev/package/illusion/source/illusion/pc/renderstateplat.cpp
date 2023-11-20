// File Line: 31
// RVA: 0xA1B270
void Illusion::HardwareState::Init(void)
{
  *(_DWORD *)Illusion::HardwareState::sBlendMode = 131073;
  word_142166D98 = 15;
  word_142166DA0 = 2;
  word_142166DA8 = 3;
  word_142166DB0 = 2;
  word_142166DE0 = 3;
  dword_142166DEC = 2;
  dword_142166DF0 = 3;
  dword_142166DF4 = 4;
  dword_142166DF8 = 5;
  dword_142166DFC = 6;
  dword_142166E00 = 7;
  dword_142166E04 = 8;
  dword_142166E4C = 10;
  dword_142166E68 = 11;
  dword_142166ED4 = 3;
  dword_142166ED8 = 2;
  dword_142166EDC = 4;
  dword_142166EE0 = 5;
  dword_142166EE4 = 5;
  dword_142166D84 = 262147;
  dword_142166D88 = 393221;
  dword_142166D8C = 524295;
  dword_142166D90 = 655369;
  dword_142166D94 = 917515;
  *(_DWORD *)Illusion::HardwareState::sCullMode = 196609;
  *(_DWORD *)Illusion::HardwareState::sCullModeI = 131073;
  *(_DWORD *)Illusion::HardwareState::sFillMode = 131075;
  *(_DWORD *)Illusion::HardwareState::sCompareFunction = 131073;
  dword_142166DBC = 262147;
  dword_142166DC0 = 393221;
  dword_142166DC4 = 524295;
  *(_DWORD *)Illusion::HardwareState::sCompareFunctionI = 458760;
  dword_142166DCC = 327686;
  dword_142166DD0 = 196612;
  dword_142166DD4 = 65538;
  *(_DWORD *)Illusion::HardwareState::sBlendEquation = 262145;
  dword_142166DDC = 131077;
  Illusion::HardwareState::sStencilOperation[0] = 1;
  Illusion::HardwareState::sTextureFormat[0] = 28;
  dword_142166E14 = 71;
  dword_142166E18 = 74;
  qword_142166E1C = 77i64;
  dword_142166E48 = 41;
  dword_142166E24 = 0;
  qword_142166E50 = 44i64;
  dword_142166E58 = 44;
  dword_142166E5C = 44;
  dword_142166E28 = 61;
  dword_142166E2C = 56;
  dword_142166E30 = 71;
  dword_142166E34 = 83;
  dword_142166E60 = 24;
  dword_142166E64 = 26;
  dword_142166E38 = 95;
  dword_142166E3C = 96;
  dword_142166E40 = 98;
  dword_142166E44 = 99;
  Illusion::HardwareState::sPrimType[0] = 1;
  dword_142166EEC = 33;
  dword_142166EF0 = 34;
  dword_142166EF4 = 35;
  dword_142166EF8 = 36;
  dword_142166EFC = 37;
  dword_142166F00 = 38;
  dword_142166F04 = 39;
  dword_142166F08 = 40;
  dword_142166F0C = 41;
  dword_142166F10 = 42;
  dword_142166F14 = 43;
  dword_142166F18 = 44;
  dword_142166F1C = 45;
  dword_142166F20 = 46;
  dword_142166F24 = 47;
  dword_142166F28 = 48;
  dword_142166F2C = 49;
  dword_142166F30 = 50;
  dword_142166F34 = 51;
  dword_142166F38 = 52;
  dword_142166F3C = 53;
  dword_142166F40 = 54;
  dword_142166F44 = 55;
  dword_142166F48 = 56;
  dword_142166F4C = 57;
  dword_142166F50 = 58;
  dword_142166F54 = 59;
  dword_142166F58 = 60;
  dword_142166F5C = 61;
  dword_142166F60 = 62;
  dword_142166F64 = 63;
  dword_142166F68 = 64;
}

// File Line: 166
// RVA: 0xA1E180
void __fastcall Illusion::AlphaState::OnAddPlat(Illusion::AlphaState *this)
{
  Illusion::AlphaStatePlat::OnAdd((Illusion::AlphaStatePlat *)&this[1]);
}

// File Line: 172
// RVA: 0xA1EDC0
void __fastcall Illusion::AlphaState::OnRemovePlat(Illusion::AlphaState *this)
{
  Illusion::AlphaState *v1; // rbx
  UFG::qBaseNodeRB *v2; // rcx

  v1 = this;
  v2 = this[1].mNode.mParent;
  if ( v2 )
  {
    ((void (*)(void))v2->mParent->mChild[1])();
    v1[1].mNode.mParent = 0i64;
  }
}

// File Line: 181
// RVA: 0xA1DE90
void __fastcall Illusion::AlphaStatePlat::OnAdd(Illusion::AlphaStatePlat *this)
{
  Illusion::AlphaStatePlat *v1; // rbx
  __int64 v2; // rdx
  __int64 v3; // r8
  char v4; // r9
  bool v5; // zf
  char v6; // dl
  __int64 Dst; // [rsp+20h] [rbp-118h]
  BOOL v8; // [rsp+28h] [rbp-110h]
  int v9; // [rsp+2Ch] [rbp-10Ch]
  int v10; // [rsp+30h] [rbp-108h]
  int v11; // [rsp+34h] [rbp-104h]
  int v12; // [rsp+38h] [rbp-100h]
  int v13; // [rsp+3Ch] [rbp-FCh]
  int v14; // [rsp+40h] [rbp-F8h]
  char v15; // [rsp+44h] [rbp-F4h]

  v1 = this;
  memset(&Dst, 0, 0x108ui64);
  v2 = BYTE1(v1[-3].mD3DBlendState);
  v3 = BYTE2(v1[-3].mD3DBlendState);
  v4 = (char)v1[-2].mD3DBlendState;
  v5 = LOBYTE(v1[-3].mD3DBlendState) == 0;
  Dst = 0i64;
  v8 = !v5;
  v9 = Illusion::HardwareState::sBlendMode[v2];
  v10 = Illusion::HardwareState::sBlendMode[v3];
  v11 = Illusion::HardwareState::sBlendEquation[BYTE3(v1[-3].mD3DBlendState)];
  if ( v4 )
  {
    LOBYTE(v2) = BYTE1(v1[-2].mD3DBlendState);
  }
  else
  {
    switch ( (_DWORD)v2 )
    {
      case 2:
        LOBYTE(v2) = 4;
        break;
      case 3:
        LOBYTE(v2) = 5;
        break;
      case 8:
        LOBYTE(v2) = 6;
        break;
      case 9:
        LOBYTE(v2) = 7;
        break;
    }
  }
  v12 = Illusion::HardwareState::sBlendMode[(unsigned __int8)v2];
  if ( v4 )
  {
    LOBYTE(v3) = BYTE2(v1[-2].mD3DBlendState);
  }
  else
  {
    switch ( (_DWORD)v3 )
    {
      case 2:
        LOBYTE(v3) = 4;
        break;
      case 3:
        LOBYTE(v3) = 5;
        break;
      case 8:
        LOBYTE(v3) = 6;
        break;
      case 9:
        LOBYTE(v3) = 7;
        break;
    }
  }
  v6 = BYTE3(v1[-2].mD3DBlendState);
  v13 = Illusion::HardwareState::sBlendMode[(unsigned __int8)v3];
  v14 = Illusion::HardwareState::sBlendEquation[BYTE4(v1[-3].mD3DBlendState)];
  v15 |= v6 & 8 | v6 & 4 | v6 & 2 | v6 & 1;
  ((void (__fastcall *)(ID3D11Device *, __int64 *, Illusion::AlphaStatePlat *))UFG::gD3D11Device->vfptr->VSSetSamplers)(
    UFG::gD3D11Device,
    &Dst,
    v1);
}

// File Line: 220
// RVA: 0xA1E190
void __fastcall Illusion::RasterState::OnAddPlat(Illusion::RasterState *this)
{
  Illusion::RasterStatePlat::OnAdd((Illusion::RasterStatePlat *)&this[1]);
}

// File Line: 226
// RVA: 0xA1EDF0
void __fastcall Illusion::RasterState::OnRemovePlat(Illusion::RasterState *this)
{
  Illusion::RasterState *v1; // rbx
  UFG::qBaseNodeRB *v2; // rcx
  UFG::qBaseNodeRB *v3; // rcx

  v1 = this;
  v2 = this[1].mNode.mChild[0];
  if ( v2 )
  {
    ((void (*)(void))v2->mParent->mChild[1])();
    v1[1].mNode.mChild[0] = 0i64;
  }
  v3 = v1[1].mNode.mParent;
  if ( v3 )
  {
    ((void (*)(void))v3->mParent->mChild[1])();
    v1[1].mNode.mParent = 0i64;
  }
}

// File Line: 234
// RVA: 0xA1DFE0
void __fastcall Illusion::RasterStatePlat::OnAdd(Illusion::RasterStatePlat *this)
{
  Illusion::RasterStatePlat *v1; // rbx
  __int64 v2; // rdx
  __int64 v3; // r8
  __int64 v4; // r9
  __int64 v5; // r10
  char v6; // cl
  int v7; // eax
  __int64 v8; // rax
  int v9; // [rsp+20h] [rbp-60h]
  int v10; // [rsp+24h] [rbp-5Ch]
  __int64 v11; // [rsp+28h] [rbp-58h]
  __int64 v12; // [rsp+30h] [rbp-50h]
  int v13; // [rsp+38h] [rbp-48h]
  __int64 v14; // [rsp+3Ch] [rbp-44h]
  int v15; // [rsp+44h] [rbp-3Ch]
  BOOL Dst; // [rsp+48h] [rbp-38h]
  BOOL v17; // [rsp+4Ch] [rbp-34h]
  int v18; // [rsp+50h] [rbp-30h]
  BOOL v19; // [rsp+54h] [rbp-2Ch]
  char v20; // [rsp+58h] [rbp-28h]
  char v21; // [rsp+59h] [rbp-27h]
  unsigned int v22; // [rsp+5Ch] [rbp-24h]
  unsigned int v23; // [rsp+60h] [rbp-20h]
  unsigned int v24; // [rsp+64h] [rbp-1Ch]
  int v25; // [rsp+68h] [rbp-18h]
  unsigned int v26; // [rsp+6Ch] [rbp-14h]
  unsigned int v27; // [rsp+70h] [rbp-10h]
  unsigned int v28; // [rsp+74h] [rbp-Ch]
  int v29; // [rsp+78h] [rbp-8h]

  v1 = this;
  memset(&Dst, 0, 0x34ui64);
  v2 = LOBYTE(v1[-2].mD3DRasterizerState);
  v3 = BYTE1(v1[-2].mD3DRasterizerState);
  v4 = HIBYTE(v1[-2].mD3DDepthState);
  v5 = BYTE6(v1[-2].mD3DDepthState);
  v6 = BYTE2(v1[-2].mD3DRasterizerState);
  v20 = -1;
  Dst = LOBYTE(v1[-3].mD3DRasterizerState) != 0;
  v17 = BYTE1(v1[-3].mD3DRasterizerState) != 0;
  v18 = Illusion::HardwareState::sCompareFunction[BYTE2(v1[-3].mD3DRasterizerState)];
  v19 = BYTE6(v1[-3].mD3DRasterizerState) != 0;
  v21 = BYTE1(v1[-1].mD3DDepthState);
  v22 = Illusion::HardwareState::sStencilOperation[v2];
  v23 = Illusion::HardwareState::sStencilOperation[v3];
  v24 = Illusion::HardwareState::sStencilOperation[v4];
  v25 = Illusion::HardwareState::sCompareFunction[v5];
  if ( v6 )
    LOBYTE(v2) = HIBYTE(v1[-2].mD3DRasterizerState);
  v26 = Illusion::HardwareState::sStencilOperation[(unsigned __int8)v2];
  if ( v6 )
    LOBYTE(v3) = v1[-1].mD3DDepthState;
  v27 = Illusion::HardwareState::sStencilOperation[(unsigned __int8)v3];
  if ( v6 )
    LOBYTE(v4) = BYTE6(v1[-2].mD3DRasterizerState);
  v28 = Illusion::HardwareState::sStencilOperation[(unsigned __int8)v4];
  if ( v6 )
    LOBYTE(v5) = BYTE5(v1[-2].mD3DRasterizerState);
  v29 = Illusion::HardwareState::sCompareFunction[(unsigned __int8)v5];
  ((void (__fastcall *)(ID3D11Device *, BOOL *, Illusion::RasterStatePlat *))UFG::gD3D11Device->vfptr->SetPredication)(
    UFG::gD3D11Device,
    &Dst,
    v1);
  memset(&v9, 0, 0x28ui64);
  v7 = Illusion::HardwareState::sFillMode[BYTE2(v1[-1].mD3DDepthState)];
  v11 = 1i64;
  v12 = 0i64;
  v9 = v7;
  v8 = BYTE3(v1[-3].mD3DRasterizerState);
  v13 = 1;
  LODWORD(v8) = Illusion::HardwareState::sCullMode[v8];
  v14 = 1i64;
  v15 = 0;
  v10 = v8;
  ((void (__fastcall *)(ID3D11Device *, int *, ID3D11RasterizerState **))UFG::gD3D11Device->vfptr->GSSetShaderResources)(
    UFG::gD3D11Device,
    &v9,
    &v1->mD3DRasterizerState);
}

