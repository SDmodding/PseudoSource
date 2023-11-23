// File Line: 51
// RVA: 0x974490
void __fastcall Scaleform::Render::DICommand_Clear::ExecuteSW(
        Scaleform::Render::DICommand_Clear *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int Raw; // ebp
  unsigned int i; // esi
  unsigned int j; // ebx
  __int64 v11[3]; // [rsp+20h] [rbp-38h] BYREF
  int v12; // [rsp+38h] [rbp-20h]
  __int64 v13; // [rsp+40h] [rbp-18h]
  __int64 v14; // [rsp+48h] [rbp-10h]

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v11[2] = (__int64)dest;
  v11[1] = 0i64;
  v12 = 0;
  v13 = 0i64;
  v11[0] = v7;
  v14 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v11);
  Raw = this->FillColor.Raw;
  for ( i = 0; i < dest->pPlanes->Height; ++i )
  {
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v11[0] + 16i64))(v11[0], v11, i);
    for ( j = 0; j < dest->pPlanes->Width; ++j )
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v11[0] + 24i64))(v11[0], v11, j, Raw);
  }
}

// File Line: 87
// RVA: 0x974580
void __fastcall Scaleform::Render::DICommand_ColorTransform::ExecuteSW(
        Scaleform::Render::DICommand_ColorTransform *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // rax
  signed int Width; // ebx
  int Height; // edi
  Scaleform::Render::ImagePlane *v8; // r10
  int x1; // eax
  int v10; // r11d
  int v11; // r10d
  int v12; // r12d
  int y1; // r8d
  int v16; // r9d
  int y2; // ecx
  int x2; // edx
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // r8d
  __int128 v24; // xmm0
  __int128 v25; // xmm1
  int v26; // r9d
  int v27; // r12d
  Scaleform::Render::DrawableImage *pObject; // rax
  float v29; // xmm9_4
  float v30; // xmm10_4
  bool v31; // zf
  float v32; // xmm11_4
  float v33; // xmm13_4
  float v34; // xmm14_4
  float v35; // xmm15_4
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rax
  __int64 v39; // rbx
  __int64 v40; // rax
  int v41; // r15d
  signed int v42; // esi
  int v43; // r14d
  int v44; // ebx
  int v45; // edi
  unsigned __int8 v46; // cl
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  char v51; // dl
  __int64 v52; // rax
  int v53; // [rsp+20h] [rbp-E0h]
  float v54; // [rsp+24h] [rbp-DCh]
  __int128 v55; // [rsp+30h] [rbp-D0h] BYREF
  __int128 v56; // [rsp+40h] [rbp-C0h]
  __int64 v57; // [rsp+50h] [rbp-B0h]
  __int64 v58; // [rsp+58h] [rbp-A8h]
  int v59; // [rsp+60h] [rbp-A0h]
  int v60; // [rsp+64h] [rbp-9Ch]
  __int64 v61[3]; // [rsp+68h] [rbp-98h] BYREF
  int v62; // [rsp+80h] [rbp-80h]
  __int64 v63; // [rsp+88h] [rbp-78h]
  __int64 v64; // [rsp+90h] [rbp-70h]
  int v65; // [rsp+180h] [rbp+80h] BYREF
  unsigned int v66; // [rsp+190h] [rbp+90h]
  float v67; // [rsp+198h] [rbp+98h]

  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v8 = (*psrc)->pPlanes;
  x1 = this->SourceRect.x1;
  v10 = v8->Width;
  v11 = v8->Height;
  v12 = this->DestPoint.x - x1;
  y1 = this->SourceRect.y1;
  v16 = this->DestPoint.y - y1;
  v59 = v12;
  v65 = v16;
  if ( v11 >= y1 )
  {
    y2 = this->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->SourceRect.x2;
      if ( x2 >= 0 && v10 >= x1 )
      {
        if ( x1 < 0 )
          x1 = 0;
        if ( v10 > x2 )
          v10 = this->SourceRect.x2;
        if ( y1 < 0 )
          y1 = 0;
        v20 = v10 + v12;
        if ( v11 > y2 )
          v11 = y2;
        v21 = x1 + v12;
        v22 = y1 + v16;
        v23 = v11 + v16;
        if ( v11 + v16 >= 0 && Height >= v22 && Width >= v21 && v20 >= 0 )
        {
          v24 = *(_OWORD *)&this->Cx.M[0][0];
          v25 = *(_OWORD *)&this->Cx.M[1][0];
          v26 = 0;
          v27 = 0;
          if ( v21 > 0 )
            v26 = v21;
          if ( v20 > Width )
            v20 = Width;
          v60 = v26;
          if ( v22 > 0 )
            v27 = v22;
          pObject = this->pImage.pObject;
          v55 = v24;
          v56 = v25;
          v29 = *(float *)&v25;
          v30 = *((float *)&v25 + 1);
          if ( v23 > Height )
            v23 = Height;
          v31 = !pObject->Transparent;
          v66 = v20;
          v32 = *((float *)&v56 + 2);
          v33 = *(float *)&v55;
          v53 = v23;
          v34 = *((float *)&v55 + 1);
          v35 = *((float *)&v55 + 2);
          if ( v31 )
          {
            v54 = 0.0;
            v33 = *(float *)&v55 * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v29 = *(float *)&v25 * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v34 = *((float *)&v55 + 1) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v67 = *(float *)&FLOAT_1_0;
            v30 = *((float *)&v25 + 1) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v35 = *((float *)&v55 + 2) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v32 = *((float *)&v56 + 2) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
          }
          else
          {
            v54 = *((float *)&v25 + 3);
            v67 = *((float *)&v55 + 3);
          }
          v36 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
          v37 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v36 + 120i64))(v36);
          v61[2] = (__int64)dest;
          v61[1] = 0i64;
          v62 = 0;
          v63 = 0i64;
          v64 = 0i64;
          v61[0] = v37;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v37 + 8i64))(v37, v61);
          v38 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
          v39 = (__int64)*psrc;
          v40 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v38 + 120i64))(v38);
          *(_QWORD *)&v56 = v39;
          DWORD2(v56) = 0;
          v57 = 0i64;
          v58 = 0i64;
          v55 = (unsigned __int64)v40;
          (*(void (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v40 + 8i64))(v40, &v55);
          v41 = v53;
          if ( v27 < v53 )
          {
            v42 = v66;
            v43 = -v65;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v61[0] + 16i64))(
                v61[0],
                v61,
                (unsigned int)v27);
              (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v55 + 16i64))(
                v55,
                &v55,
                (unsigned int)(v43 + v27));
              v44 = v60;
              if ( v60 < v42 )
              {
                v45 = -v59;
                do
                {
                  (*(void (__fastcall **)(_QWORD, int *, __int128 *, _QWORD))(*(_QWORD *)v55 + 40i64))(
                    v55,
                    &v65,
                    &v55,
                    (unsigned int)(v45 + v44));
                  v46 = HIBYTE(v65);
                  if ( !this->pSource.pObject->Transparent )
                    v46 = -1;
                  HIBYTE(v65) = v46;
                  v47 = (float)(v54 + (float)((float)((float)v46 * 0.0039215689) * v67)) * 256.0;
                  if ( v47 >= 255.0 )
                  {
                    v47 = FLOAT_255_0;
                  }
                  else if ( v47 < 0.0 )
                  {
                    v47 = 0.0;
                  }
                  v48 = (float)(v32 + (float)((float)((float)(unsigned __int8)v65 * 0.0039215689) * v35)) * 256.0;
                  if ( v48 >= 255.0 )
                  {
                    v48 = FLOAT_255_0;
                  }
                  else if ( v48 < 0.0 )
                  {
                    v48 = 0.0;
                  }
                  v49 = (float)(v30 + (float)((float)((float)BYTE1(v65) * 0.0039215689) * v34)) * 256.0;
                  if ( v49 >= 255.0 )
                  {
                    v49 = FLOAT_255_0;
                  }
                  else if ( v49 < 0.0 )
                  {
                    v49 = 0.0;
                  }
                  v50 = (float)(v29 + (float)((float)((float)BYTE2(v65) * 0.0039215689) * v33)) * 256.0;
                  if ( v50 >= 255.0 )
                  {
                    v50 = FLOAT_255_0;
                  }
                  else if ( v50 < 0.0 )
                  {
                    v50 = 0.0;
                  }
                  v31 = !this->pImage.pObject->Transparent;
                  BYTE2(v66) = (int)v50;
                  BYTE1(v66) = (int)v49;
                  LOBYTE(v66) = (int)v48;
                  v51 = (int)v47;
                  v52 = *(_QWORD *)v61[0];
                  if ( v31 )
                    v51 = -1;
                  HIBYTE(v66) = v51;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(v52 + 24))(
                    v61[0],
                    v61,
                    (unsigned int)v44++,
                    v66);
                }
                while ( v44 < v42 );
                v41 = v53;
              }
              ++v27;
            }
            while ( v27 < v41 );
          }
        }
      }
    }
  }
}

// File Line: 156
// RVA: 0x974A90
void __fastcall Scaleform::Render::DICommand_Compare::ExecuteSW(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  __int64 v4; // r14
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 v14; // rax
  Scaleform::Render::ImageData *v15; // rbx
  __int64 v16; // rax
  unsigned int i; // edi
  unsigned int j; // ebx
  char v19; // al
  char v20; // r8
  char v21; // cl
  char v22; // dl
  char v23; // al
  char v24; // r9
  __int64 v25; // rax
  __int64 v26[3]; // [rsp+20h] [rbp-69h] BYREF
  int v27; // [rsp+38h] [rbp-51h]
  __int64 v28; // [rsp+40h] [rbp-49h]
  __int64 v29; // [rsp+48h] [rbp-41h]
  __int64 v30[3]; // [rsp+50h] [rbp-39h] BYREF
  int v31; // [rsp+68h] [rbp-21h]
  __int64 v32; // [rsp+70h] [rbp-19h]
  __int64 v33; // [rsp+78h] [rbp-11h]
  __int64 v34[3]; // [rsp+80h] [rbp-9h] BYREF
  int v35; // [rsp+98h] [rbp+Fh]
  __int64 v36; // [rsp+A0h] [rbp+17h]
  __int64 v37; // [rsp+A8h] [rbp+1Fh]
  char v38; // [rsp+F8h] [rbp+6Fh] BYREF
  char v39; // [rsp+F9h] [rbp+70h]
  char v40; // [rsp+FAh] [rbp+71h]
  char v41; // [rsp+FBh] [rbp+72h]
  char v42; // [rsp+100h] [rbp+77h] BYREF
  char v43; // [rsp+101h] [rbp+78h]
  char v44; // [rsp+102h] [rbp+79h]
  char v45; // [rsp+103h] [rbp+7Ah]
  unsigned int v46; // [rsp+108h] [rbp+7Fh]

  v4 = (__int64)*psrc;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 120i64))(v9);
  v34[2] = (__int64)dest;
  v34[1] = 0i64;
  v35 = 0;
  v36 = 0i64;
  v34[0] = v10;
  v37 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 8i64))(v10, v34);
  v11 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v12 = (__int64)*psrc;
  v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 120i64))(v11);
  v30[1] = 0i64;
  v30[2] = v12;
  v31 = 0;
  v32 = 0i64;
  v33 = 0i64;
  v30[0] = v13;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v13 + 8i64))(v13, v30);
  v14 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v15 = psrc[1];
  v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 120i64))(v14);
  v26[1] = 0i64;
  v26[2] = (__int64)v15;
  v27 = 0;
  v28 = 0i64;
  v29 = 0i64;
  v26[0] = v16;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v16 + 8i64))(v16, v26);
  for ( i = 0; i < *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4i64); ++i )
  {
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v34[0] + 16i64))(v34[0], v34, i);
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v30[0] + 16i64))(v30[0], v30, i);
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v26[0] + 16i64))(v26[0], v26, i);
    for ( j = 0; j < **(_DWORD **)(v4 + 16); ++j )
    {
      (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v30[0] + 40i64))(v30[0], &v38, v30, j);
      (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v26[0] + 40i64))(v26[0], &v42, v26, j);
      v19 = -1;
      v20 = -1;
      if ( this->pSource.pObject->Transparent )
        v19 = v41;
      if ( this->pImageCompare1.pObject->Transparent )
        v20 = v45;
      v21 = v39 - v43;
      v22 = v38 - v42;
      v23 = v19 - v20;
      v24 = v40 - v44;
      if ( v40 != v44 || v21 || v22 || !v23 )
      {
        v23 = -1;
      }
      else
      {
        v24 = -1;
        v21 = -1;
        v22 = -1;
      }
      BYTE1(v46) = v21;
      HIBYTE(v46) = v23;
      v25 = *(_QWORD *)v34[0];
      LOBYTE(v46) = v22;
      BYTE2(v46) = v24;
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(v25 + 24))(v34[0], v34, j, v46);
    }
  }
}

// File Line: 212
// RVA: 0x974CD0
void __fastcall Scaleform::Render::DICommand_CopyChannel::ExecuteSW(
        Scaleform::Render::DICommand_CopyChannel *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // rax
  signed int Width; // ebx
  signed int Height; // edi
  Scaleform::Render::ImagePlane *v8; // rax
  int v9; // r11d
  int v10; // r10d
  int x1; // eax
  int y1; // ecx
  int v13; // r9d
  int v14; // r13d
  int y2; // edx
  int x2; // r8d
  int v17; // r12d
  int v18; // r15d
  int v19; // edx
  int v20; // eax
  int v21; // esi
  int v22; // ebx
  __int64 SourceChannel; // rax
  char v24; // cl
  __int64 DestChannel; // rax
  char v26; // al
  void *v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rdi
  __int64 v31; // rax
  int v32; // r13d
  unsigned int v33; // esi
  int v34; // edi
  char v35; // cl
  char v36; // cl
  bool v37; // zf
  unsigned __int8 v38; // [rsp+20h] [rbp-79h]
  char v39[4]; // [rsp+24h] [rbp-75h] BYREF
  char v40[4]; // [rsp+28h] [rbp-71h] BYREF
  int v41; // [rsp+2Ch] [rbp-6Dh]
  int v42; // [rsp+30h] [rbp-69h]
  int v43; // [rsp+34h] [rbp-65h]
  int v44; // [rsp+38h] [rbp-61h]
  int v45; // [rsp+3Ch] [rbp-5Dh]
  __int64 v46[3]; // [rsp+40h] [rbp-59h] BYREF
  int v47; // [rsp+58h] [rbp-41h]
  __int64 v48; // [rsp+60h] [rbp-39h]
  __int64 v49; // [rsp+68h] [rbp-31h]
  char *v50; // [rsp+70h] [rbp-29h]
  __int64 v51[3]; // [rsp+80h] [rbp-19h] BYREF
  int v52; // [rsp+98h] [rbp-1h]
  __int64 v53; // [rsp+A0h] [rbp+7h]
  __int64 v54; // [rsp+A8h] [rbp+Fh]
  unsigned __int8 v55; // [rsp+100h] [rbp+67h]
  Scaleform::Render::ImageData *v57; // [rsp+110h] [rbp+77h] BYREF
  Scaleform::Render::ImageData **v58; // [rsp+118h] [rbp+7Fh]

  v58 = psrc;
  v57 = dest;
  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v8 = (*psrc)->pPlanes;
  v9 = v8->Height;
  v10 = v8->Width;
  x1 = this->SourceRect.x1;
  y1 = this->SourceRect.y1;
  v13 = this->DestPoint.x - x1;
  v14 = this->DestPoint.y - y1;
  v45 = v13;
  if ( v9 >= y1 )
  {
    y2 = this->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->SourceRect.x2;
      if ( x2 >= 0 && v10 >= x1 )
      {
        v17 = 0;
        if ( x1 < 0 )
          x1 = 0;
        if ( v10 > x2 )
          v10 = this->SourceRect.x2;
        if ( y1 < 0 )
          y1 = 0;
        v18 = v10 + v13;
        if ( v9 > y2 )
          v9 = this->SourceRect.y2;
        v19 = x1 + v13;
        v20 = y1 + v14;
        v21 = v9 + v14;
        if ( v9 + v14 >= 0 && Height >= v20 && Width >= v19 && v18 >= 0 )
        {
          if ( v19 > 0 )
            v17 = v19;
          if ( v18 > Width )
            v18 = Width;
          v22 = 0;
          if ( v20 > 0 )
            v22 = y1 + v14;
          SourceChannel = this->SourceChannel;
          if ( v21 > Height )
            v21 = Height;
          v42 = v17;
          v41 = v22;
          v44 = v21;
          if ( (int)SourceChannel > 8 )
            v24 = -1;
          else
            v24 = Scaleform::Render::ChannelIndexMap[SourceChannel];
          DestChannel = this->DestChannel;
          v55 = v24;
          if ( (int)DestChannel > 8 )
            v26 = -1;
          else
            v26 = Scaleform::Render::ChannelIndexMap[DestChannel];
          v38 = v26;
          if ( v24 != -1 && v26 != -1 )
          {
            v27 = context->pHAL->vfptr[61].__vecDelDtor(context->pHAL, Scaleform::Render::ChannelIndexMap);
            v28 = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)v27 + 120i64))(v27);
            v46[1] = 0i64;
            v47 = 0;
            v48 = 0i64;
            v46[2] = (__int64)v57;
            v49 = 0i64;
            v46[0] = v28;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v28 + 8i64))(v28, v46);
            v29 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
            v30 = (__int64)*v58;
            v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 120i64))(v29);
            v51[2] = v30;
            v51[1] = 0i64;
            v52 = 0;
            v53 = 0i64;
            v54 = 0i64;
            v51[0] = v31;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v31 + 8i64))(v31, v51);
            if ( v22 < v21 )
            {
              v32 = -v14;
              v43 = v32;
              do
              {
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v46[0] + 16i64))(
                  v46[0],
                  v46,
                  (unsigned int)v22);
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v51[0] + 16i64))(
                  v51[0],
                  v51,
                  (unsigned int)(v22 + v32));
                v33 = v17;
                if ( v17 < v18 )
                {
                  v50 = &v40[v55];
                  v34 = -v45;
                  do
                  {
                    (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD))(*(_QWORD *)v46[0] + 40i64))(
                      v46[0],
                      &v57,
                      v46,
                      v33);
                    (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v51[0] + 40i64))(
                      v51[0],
                      v39,
                      v51,
                      v34 + v33);
                    v35 = v39[3];
                    LOBYTE(v58) = BYTE2(v57);
                    BYTE1(v58) = BYTE1(v57);
                    BYTE2(v58) = (_BYTE)v57;
                    BYTE3(v58) = BYTE3(v57);
                    v40[0] = v39[2];
                    v40[1] = v39[1];
                    v40[2] = v39[0];
                    if ( !this->pSource.pObject->Transparent )
                      v35 = -1;
                    v40[3] = v35;
                    *((_BYTE *)&v58 + v38) = v40[v55];
                    v36 = BYTE3(v58);
                    v37 = !this->pImage.pObject->Transparent;
                    BYTE2(v57) = (_BYTE)v58;
                    if ( v37 )
                      v36 = -1;
                    BYTE3(v57) = v36;
                    LOBYTE(v57) = BYTE2(v58);
                    BYTE1(v57) = BYTE1(v58);
                    (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v46[0] + 24i64))(
                      v46[0],
                      v46,
                      v33++,
                      (unsigned int)v57);
                  }
                  while ( (int)v33 < v18 );
                  v22 = v41;
                  v17 = v42;
                  v32 = v43;
                }
                v41 = ++v22;
              }
              while ( v22 < v44 );
            }
          }
        }
      }
    }
  }
}

// File Line: 268
// RVA: 0x975020
void __fastcall Scaleform::Render::DICommand_CopyPixels::ExecuteSW(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // rax
  __int64 v5; // r15
  unsigned int Height; // ecx
  signed int Width; // r14d
  Scaleform::Render::ImagePlane *v9; // rax
  int v10; // ebx
  int y1; // edx
  int v12; // r10d
  int x1; // r11d
  int v14; // esi
  int v15; // r12d
  int y2; // r9d
  int x2; // r8d
  int v18; // r13d
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // r12d
  bool v23; // sf
  int v24; // ebx
  int v25; // r10d
  int v26; // r13d
  bool v27; // r14
  __int64 *v28; // rbx
  int x; // ecx
  int v30; // r9d
  int v31; // edx
  int v32; // r12d
  int v33; // r13d
  Scaleform::Render::ImagePlane *v34; // rax
  int v35; // r10d
  int v36; // r11d
  int *v37; // rax
  int v38; // r9d
  int v39; // r8d
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  int v44; // r13d
  __int64 v45; // rax
  __int64 v46; // rax
  __int64 v47; // rax
  __int64 v48; // rbx
  __int64 v49; // rax
  __int64 v50; // rax
  __int64 v51; // rax
  int v52; // r15d
  int v53; // ebx
  unsigned int v54; // ebx
  unsigned int v55; // esi
  int v56; // r13d
  int v57; // r15d
  int v58; // r12d
  char v59; // cl
  int *v60; // rax
  int v61; // eax
  int v62; // edx
  int v63; // ecx
  float v64; // xmm2_4
  __int64 v65; // [rsp+20h] [rbp-E0h]
  __int64 v66; // [rsp+20h] [rbp-E0h]
  __int64 v67; // [rsp+28h] [rbp-D8h]
  int v68; // [rsp+30h] [rbp-D0h]
  int v69; // [rsp+34h] [rbp-CCh]
  int v70; // [rsp+38h] [rbp-C8h]
  int v71; // [rsp+3Ch] [rbp-C4h]
  int v72; // [rsp+40h] [rbp-C0h]
  int v73; // [rsp+48h] [rbp-B8h] BYREF
  char v74[4]; // [rsp+4Ch] [rbp-B4h] BYREF
  __int64 v75[3]; // [rsp+50h] [rbp-B0h] BYREF
  int v76; // [rsp+68h] [rbp-98h]
  __int64 v77; // [rsp+70h] [rbp-90h]
  __int64 v78; // [rsp+78h] [rbp-88h]
  __int64 v79[3]; // [rsp+80h] [rbp-80h] BYREF
  int v80; // [rsp+98h] [rbp-68h]
  __int64 v81; // [rsp+A0h] [rbp-60h]
  __int64 v82; // [rsp+A8h] [rbp-58h]
  __int64 v83[3]; // [rsp+B0h] [rbp-50h] BYREF
  int v84; // [rsp+C8h] [rbp-38h]
  __int64 v85; // [rsp+D0h] [rbp-30h]
  __int64 v86; // [rsp+D8h] [rbp-28h]
  int y; // [rsp+150h] [rbp+50h]
  int v88; // [rsp+150h] [rbp+50h]
  int v89; // [rsp+150h] [rbp+50h]
  Scaleform::Render::ImageData *v91; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::Render::ImageData **v92; // [rsp+168h] [rbp+68h] BYREF

  v92 = psrc;
  v91 = dest;
  pPlanes = dest->pPlanes;
  v5 = (__int64)*psrc;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  v9 = (*psrc)->pPlanes;
  v10 = v9->Height;
  y1 = this->SourceRect.y1;
  v12 = v9->Width;
  x1 = this->SourceRect.x1;
  LODWORD(v65) = Height;
  y = this->DestPoint.y;
  v14 = y - y1;
  HIDWORD(v65) = this->DestPoint.x;
  v15 = HIDWORD(v65) - x1;
  v70 = HIDWORD(v65) - x1;
  if ( v10 >= y1 )
  {
    y2 = this->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->SourceRect.x2;
      if ( x2 >= 0 && v12 >= x1 )
      {
        v18 = 0;
        v19 = this->SourceRect.x1;
        v20 = this->SourceRect.y1;
        if ( x1 < 0 )
          v19 = 0;
        if ( v12 > x2 )
          v12 = this->SourceRect.x2;
        if ( y1 < 0 )
          v20 = 0;
        if ( v10 > y2 )
          v10 = this->SourceRect.y2;
        v21 = v15 + v19;
        v22 = v12 + v15;
        v23 = v14 + v10 < 0;
        v24 = v14 + v10;
        v25 = v20 + v14;
        if ( !v23 && (int)v65 >= v25 && Width >= v21 && v22 >= 0 )
        {
          if ( v21 > 0 )
            v18 = v21;
          if ( v22 > Width )
            v22 = Width;
          v71 = v18;
          v26 = 0;
          HIDWORD(v67) = v22;
          if ( v25 > 0 )
            v26 = v20 + v14;
          if ( v24 > (int)v65 )
            v24 = v65;
          v69 = v26;
          v27 = this->pAlphaSource.pObject != 0i64;
          v68 = v24;
          v28 = (__int64 *)v92;
          if ( !this->pAlphaSource.pObject )
          {
            v88 = y - y1;
            HIDWORD(v65) -= x1;
LABEL_52:
            v45 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
            v46 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v45 + 120i64))(v45);
            v75[1] = 0i64;
            v76 = 0;
            v77 = 0i64;
            v75[2] = (__int64)v91;
            v78 = 0i64;
            v75[0] = v46;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v46 + 8i64))(v46, v75);
            v47 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
            v48 = *v28;
            v49 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v47 + 120i64))(v47);
            v79[2] = v48;
            v79[1] = 0i64;
            v79[0] = v49;
            v80 = 0;
            v81 = 0i64;
            v82 = 0i64;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v49 + 8i64))(v49, v79);
            if ( !v27 )
              v5 = (__int64)*v92;
            v50 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
            v51 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v50 + 120i64))(v50);
            v83[1] = 0i64;
            v83[2] = v5;
            v84 = 0;
            v85 = 0i64;
            v86 = 0i64;
            v83[0] = v51;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v51 + 8i64))(v51, v83);
            if ( v26 < v68 )
            {
              v52 = v88 - v14;
              v53 = -v88;
              v89 = -v88;
              v72 = v52;
              do
              {
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v75[0] + 16i64))(
                  v75[0],
                  v75,
                  (unsigned int)v26);
                v54 = v26 + v53;
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v79[0] + 16i64))(v79[0], v79, v54 + v52);
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v83[0] + 16i64))(v83[0], v83, v54);
                v55 = v71;
                if ( v71 < v22 )
                {
                  v56 = HIDWORD(v67);
                  v57 = HIDWORD(v65) - v70;
                  v58 = -HIDWORD(v65);
                  do
                  {
                    (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData ***, __int64 *, _QWORD))(*(_QWORD *)v79[0] + 40i64))(
                      v79[0],
                      &v92,
                      v79,
                      v58 + v55 + v57);
                    v59 = BYTE3(v92);
                    if ( !this->pSource.pObject->Transparent )
                      v59 = -1;
                    BYTE3(v92) = v59;
                    if ( v27 )
                    {
                      (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v83[0] + 40i64))(
                        v83[0],
                        v74,
                        v83,
                        v58 + v55);
                      v60 = (int *)v74;
                    }
                    else
                    {
                      v73 = (int)v92;
                      v60 = &v73;
                    }
                    LODWORD(v65) = *v60;
                    (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD, __int64))(*(_QWORD *)v75[0] + 40i64))(
                      v75[0],
                      &v91,
                      v75,
                      v55,
                      v65);
                    if ( v27 )
                      v61 = BYTE3(v66) + 1;
                    else
                      v61 = 256;
                    v62 = (v61 * BYTE3(v92)) >> 8;
                    LOBYTE(v63) = (unsigned __int16)(v61 * BYTE3(v92)) >> 8;
                    if ( this->MergeAlpha )
                      v63 = (int)(float)((float)((float)((float)BYTE3(v91) * 0.0039215689)
                                               * (float)(255 - (unsigned __int8)v62))
                                       + (float)(unsigned __int8)v62);
                    if ( !this->pImage.pObject->Transparent )
                      LOBYTE(v63) = -1;
                    v64 = (float)(unsigned __int8)v62 / (float)(unsigned __int8)v63;
                    BYTE2(v67) = (int)(float)((float)((float)((float)((float)BYTE2(v92) - (float)BYTE2(v91)) * v64)
                                                    + (float)BYTE2(v91))
                                            + 0.5);
                    BYTE1(v67) = (int)(float)((float)((float)((float)((float)BYTE1(v92) - (float)BYTE1(v91)) * v64)
                                                    + (float)BYTE1(v91))
                                            + 0.5);
                    LOBYTE(v67) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v92
                                                                     - (float)(unsigned __int8)v91)
                                                             * v64)
                                                     + (float)(unsigned __int8)v91)
                                             + 0.5);
                    BYTE3(v67) = (int)(float)((float)((float)((float)((float)BYTE3(v92) - (float)BYTE3(v91)) * v64)
                                                    + (float)BYTE3(v91))
                                            + 0.5);
                    LODWORD(v66) = v67;
                    BYTE3(v66) = v63;
                    (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD, __int64, __int64))(*(_QWORD *)v75[0]
                                                                                                 + 24i64))(
                      v75[0],
                      v75,
                      v55++,
                      (unsigned int)v66,
                      v66,
                      v67);
                  }
                  while ( (int)v55 < v56 );
                  v26 = v69;
                  v22 = HIDWORD(v67);
                  v52 = v72;
                }
                v53 = v89;
                v69 = ++v26;
              }
              while ( v26 < v68 );
            }
            return;
          }
          x = this->AlphaPoint.x;
          v5 = (__int64)v92[1];
          v30 = y2 - y1;
          v31 = this->AlphaPoint.y;
          v32 = x2 - x1 + x;
          v88 = y - v31;
          v33 = v30 + v31;
          v34 = v91->pPlanes;
          v35 = v34->Width;
          v36 = v34->Height;
          v37 = *(int **)(v5 + 16);
          v38 = v37[1];
          v39 = *v37;
          v40 = HIDWORD(v65) - x;
          HIDWORD(v65) -= x;
          if ( v38 >= v31 && v33 >= 0 && v32 >= 0 && v39 >= x )
          {
            if ( x < 0 )
              x = 0;
            if ( v39 > v32 )
              v39 = v32;
            if ( v31 < 0 )
              v31 = 0;
            if ( v38 > v33 )
              v38 = v33;
            v22 = v39 + HIDWORD(v65);
            v41 = x + v40;
            v42 = v31 + v88;
            v43 = v38 + v88;
            if ( v38 + v88 >= 0 && v36 >= v42 && v35 >= v41 && v22 >= 0 )
            {
              v44 = 0;
              if ( v41 > 0 )
                v44 = v41;
              if ( v22 > v35 )
                v22 = v35;
              v71 = v44;
              v26 = 0;
              HIDWORD(v67) = v22;
              if ( v42 > 0 )
                v26 = v42;
              if ( v43 > v36 )
                v43 = v36;
              v69 = v26;
              v68 = v43;
              goto LABEL_52;
            }
          }
        }
      }
    }
  }
} v43;
              goto LABEL_52;
            }
          }
        }
      }
    }
  }
}

// File Line: 337
// RVA: 0x975630
void __fastcall Scaleform::Render::DICommand_FillRect::ExecuteSW(
        Scaleform::Render::DICommand_FillRect *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  Scaleform::Render::ImagePlane *pPlanes; // rax
  int y1; // edi
  int Height; // r15d
  int Width; // esi
  int y2; // eax
  int x2; // ecx
  int x1; // r14d
  unsigned int Raw; // ebp
  int i; // ebx
  __int64 v17[3]; // [rsp+20h] [rbp-48h] BYREF
  int v18; // [rsp+38h] [rbp-30h]
  __int64 v19; // [rsp+40h] [rbp-28h]
  __int64 v20; // [rsp+48h] [rbp-20h]

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v17[2] = (__int64)dest;
  v17[1] = 0i64;
  v18 = 0;
  v19 = 0i64;
  v17[0] = v7;
  v20 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v17);
  pPlanes = dest->pPlanes;
  y1 = this->ApplyRect.y1;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  if ( Height >= y1 )
  {
    y2 = this->ApplyRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->ApplyRect.x2;
      if ( x2 >= 0 )
      {
        x1 = this->ApplyRect.x1;
        if ( Width >= x1 )
        {
          if ( x1 < 0 )
            x1 = 0;
          if ( Width > x2 )
            Width = this->ApplyRect.x2;
          if ( y1 < 0 )
            y1 = 0;
          Raw = this->FillColor.Raw;
          if ( Height > y2 )
            Height = this->ApplyRect.y2;
          if ( !this->pImage.pObject->Transparent )
            Raw |= 0xFF000000;
          for ( ; y1 < Height; ++y1 )
          {
            (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v17[0] + 16i64))(
              v17[0],
              v17,
              (unsigned int)y1);
            for ( i = x1; i < Width; ++i )
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v17[0] + 24i64))(
                v17[0],
                v17,
                (unsigned int)i,
                Raw);
          }
        }
      }
    }
  }
}

// File Line: 365
// RVA: 0x975780
void __fastcall Scaleform::Render::DICommand_FloodFill::ExecuteSW(
        Scaleform::Render::DICommand_FloodFill *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::ImagePlane *pPlanes; // rax
  int Height; // r13d
  signed int Width; // r12d
  int x; // eax
  int y; // eax
  unsigned int Raw; // ecx
  __int64 v13; // rax
  __int64 v14; // rax
  int v15; // edi
  int v16; // esi
  Scaleform::String *Data; // rcx
  unsigned __int64 Size; // rcx
  int HeapTypeBits_high; // edi
  int pData; // esi
  int v21; // edx
  int v22; // r8d
  int v23; // ecx
  int v24; // eax
  int v25; // r14d
  int v26; // r15d
  int v27; // ebx
  unsigned __int64 v28; // rbx
  unsigned __int64 v29; // r8
  Scaleform::String *v30; // rcx
  unsigned __int64 v31; // rbx
  unsigned __int64 v32; // r8
  Scaleform::String *v33; // rcx
  unsigned __int64 v34; // rbx
  unsigned __int64 v35; // r8
  Scaleform::String *v36; // rcx
  unsigned __int64 v37; // rbx
  unsigned __int64 v38; // r8
  Scaleform::String *v39; // rcx
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::String *v41; // [rsp+38h] [rbp-61h]
  Scaleform::String *v42; // [rsp+40h] [rbp-59h]
  int v43; // [rsp+48h] [rbp-51h]
  void *p_pheapAddr; // [rsp+50h] [rbp-49h] BYREF
  __int64 v45[3]; // [rsp+58h] [rbp-41h] BYREF
  int v46; // [rsp+70h] [rbp-29h]
  __int64 v47; // [rsp+78h] [rbp-21h]
  __int64 v48; // [rsp+80h] [rbp-19h]
  __int64 v49[3]; // [rsp+88h] [rbp-11h] BYREF
  int v50; // [rsp+A0h] [rbp+7h]
  __int64 v51; // [rsp+A8h] [rbp+Fh]
  __int64 v52; // [rsp+B0h] [rbp+17h]
  __int64 v53; // [rsp+B8h] [rbp+1Fh]
  unsigned int v54; // [rsp+100h] [rbp+67h]
  int v55; // [rsp+110h] [rbp+77h] BYREF

  v53 = -2i64;
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  v43 = Height;
  Width = pPlanes->Width;
  x = this->Pt.x;
  if ( x <= Width && x >= 0 )
  {
    y = this->Pt.y;
    if ( y <= Height && y >= 0 )
    {
      Raw = this->FillColor.Raw;
      v54 = Raw;
      if ( !this->pImage.pObject->Transparent )
        v54 = Raw | 0xFF000000;
      v13 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
      v49[0] = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 120i64))(v13);
      v49[1] = 0i64;
      v49[2] = (__int64)dest;
      v50 = 0;
      v51 = 0i64;
      v52 = 0i64;
      (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v49[0] + 8i64))(v49[0], v49);
      v14 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
      v45[0] = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 120i64))(v14);
      v45[1] = 0i64;
      v45[2] = (__int64)dest;
      v46 = 0;
      v47 = 0i64;
      v48 = 0i64;
      (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v45[0] + 8i64))(v45[0], v45);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v45[0] + 16i64))(
        v45[0],
        v45,
        (unsigned int)this->Pt.y);
      (*(void (__fastcall **)(__int64, int *, __int64 *, _QWORD))(*(_QWORD *)v45[0] + 40i64))(
        v45[0],
        &v55,
        v45,
        (unsigned int)this->Pt.x);
      p_pheapAddr = &pheapAddr;
      memset(&pheapAddr, 0, sizeof(pheapAddr));
      v15 = this->Pt.y;
      v16 = this->Pt.x;
      Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        1ui64);
      pheapAddr.Size = 1i64;
      Data = pheapAddr.Data;
      p_pheapAddr = pheapAddr.Data;
      v41 = pheapAddr.Data;
      if ( pheapAddr.Data )
      {
        LODWORD(pheapAddr.Data->pData) = v16;
        HIDWORD(Data->HeapTypeBits) = v15;
      }
      Size = pheapAddr.Size;
      while ( pheapAddr.Size )
      {
        HeapTypeBits_high = HIDWORD(pheapAddr.Data[Size - 1].HeapTypeBits);
        pData = (int)pheapAddr.Data[Size - 1].pData;
        Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          (Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
          Size - 1);
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v24 = 0;
        v25 = HeapTypeBits_high + 1;
        v26 = pData + 1;
        if ( Height >= HeapTypeBits_high && v25 >= 0 && v26 >= 0 && Width >= pData )
        {
          v21 = pData;
          if ( pData < 0 )
            v21 = 0;
          v23 = Width;
          if ( Width > v26 )
            v23 = pData + 1;
          v22 = HeapTypeBits_high;
          if ( HeapTypeBits_high < 0 )
            v22 = 0;
          v24 = Height;
          if ( Height > v25 )
            v24 = HeapTypeBits_high + 1;
        }
        if ( (v23 - v21) * (v24 - v22) <= 0 )
          goto LABEL_59;
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v45[0] + 16i64))(
          v45[0],
          v45,
          (unsigned int)HeapTypeBits_high);
        v27 = v55;
        (*(void (__fastcall **)(__int64, void **, __int64 *, _QWORD))(*(_QWORD *)v45[0] + 40i64))(
          v45[0],
          &p_pheapAddr,
          v45,
          (unsigned int)pData);
        if ( (_DWORD)p_pheapAddr != v27 )
          goto LABEL_59;
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v49[0] + 16i64))(
          v49[0],
          v49,
          (unsigned int)HeapTypeBits_high);
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v49[0] + 24i64))(
          v49[0],
          v49,
          (unsigned int)pData,
          v54);
        v28 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v28 <= pheapAddr.Policy.Capacity )
            goto LABEL_32;
          v29 = v28 + (v28 >> 2);
        }
        else
        {
          if ( v28 >= pheapAddr.Policy.Capacity >> 1 )
            goto LABEL_32;
          v29 = pheapAddr.Size + 1;
        }
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v29);
LABEL_32:
        pheapAddr.Size = v28;
        v30 = &pheapAddr.Data[v28 - 1];
        v41 = v30;
        v42 = v30;
        if ( v30 )
        {
          LODWORD(v30->pData) = pData - 1;
          HIDWORD(v30->HeapTypeBits) = HeapTypeBits_high;
        }
        v31 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v31 <= pheapAddr.Policy.Capacity )
            goto LABEL_40;
          v32 = v31 + (v31 >> 2);
        }
        else
        {
          if ( v31 >= pheapAddr.Policy.Capacity >> 1 )
            goto LABEL_40;
          v32 = pheapAddr.Size + 1;
        }
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v32);
LABEL_40:
        pheapAddr.Size = v31;
        v33 = &pheapAddr.Data[v31 - 1];
        v42 = v33;
        v41 = v33;
        if ( v33 )
        {
          LODWORD(v33->pData) = pData;
          HIDWORD(v33->HeapTypeBits) = HeapTypeBits_high - 1;
        }
        v34 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v34 <= pheapAddr.Policy.Capacity )
            goto LABEL_48;
          v35 = v34 + (v34 >> 2);
        }
        else
        {
          if ( v34 >= pheapAddr.Policy.Capacity >> 1 )
            goto LABEL_48;
          v35 = pheapAddr.Size + 1;
        }
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v35);
LABEL_48:
        pheapAddr.Size = v34;
        v36 = &pheapAddr.Data[v34 - 1];
        v42 = v36;
        v41 = v36;
        if ( v36 )
        {
          LODWORD(v36->pData) = pData;
          HIDWORD(v36->HeapTypeBits) = v25;
        }
        v37 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v37 > pheapAddr.Policy.Capacity )
          {
            v38 = v37 + (v37 >> 2);
            goto LABEL_55;
          }
        }
        else if ( v37 < pheapAddr.Policy.Capacity >> 1 )
        {
          v38 = pheapAddr.Size + 1;
LABEL_55:
          Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v38);
        }
        pheapAddr.Size = v37;
        v39 = &pheapAddr.Data[v37 - 1];
        v42 = v39;
        v41 = v39;
        if ( v39 )
        {
          LODWORD(v39->pData) = v26;
          HIDWORD(v39->HeapTypeBits) = HeapTypeBits_high;
        }
        Height = v43;
LABEL_59:
        Size = pheapAddr.Size;
      }
      if ( pheapAddr.Data )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
  }
}

// File Line: 407
// RVA: 0x975BE0
void __fastcall Scaleform::Render::DICommand_GetColorBoundsRect::ExecuteSW(
        Scaleform::Render::DICommand_GetColorBoundsRect *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // ebx
  Scaleform::Render::ImagePlane *pPlanes; // rax
  char v10; // cl
  int Height; // r14d
  int Width; // r15d
  int v13; // r12d
  int v14; // r13d
  unsigned int v15; // esi
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  Scaleform::Render::Rect<long> *Result; // rax
  __int64 v22[3]; // [rsp+20h] [rbp-68h] BYREF
  int v23; // [rsp+38h] [rbp-50h]
  __int64 v24; // [rsp+40h] [rbp-48h]
  __int64 v25; // [rsp+48h] [rbp-40h]
  char v26; // [rsp+90h] [rbp+8h]
  int v27; // [rsp+98h] [rbp+10h] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v8 = 0;
  v22[2] = (__int64)dest;
  v22[1] = 0i64;
  v23 = 0;
  v24 = 0i64;
  v22[0] = v7;
  v25 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v22);
  pPlanes = dest->pPlanes;
  v10 = 0;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  v26 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  if ( Height )
  {
    do
    {
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v22[0] + 16i64))(v22[0], v22, v15);
      if ( dest->pPlanes->Width )
      {
        do
        {
          (*(void (__fastcall **)(__int64, int *, __int64 *, _QWORD))(*(_QWORD *)v22[0] + 40i64))(v22[0], &v27, v22, v8);
          v16 = v27 & this->Mask;
          if ( this->FindColor )
          {
            if ( v16 == this->SearchColor )
              goto LABEL_7;
          }
          else if ( v16 != this->SearchColor )
          {
LABEL_7:
            v17 = v8;
            v26 = 1;
            if ( Width < (int)v8 )
              v17 = Width;
            Width = v17;
            v18 = v15;
            if ( Height < (int)v15 )
              v18 = Height;
            Height = v18;
            v19 = v8 + 1;
            if ( (int)(v8 + 1) < v13 )
              v19 = v13;
            v13 = v19;
            v20 = v15 + 1;
            if ( (int)(v15 + 1) < v14 )
              v20 = v14;
            v14 = v20;
          }
          ++v8;
        }
        while ( v8 < dest->pPlanes->Width );
      }
      ++v15;
      v8 = 0;
    }
    while ( v15 < dest->pPlanes->Height );
    v10 = v26;
  }
  Result = this->Result;
  if ( Result )
  {
    if ( v10 )
    {
      Result->x1 = Width;
      Result->y1 = Height;
      Result->x2 = v13;
      Result->y2 = v14;
    }
    else
    {
      *(_QWORD *)&Result->x1 = 0i64;
      *(_QWORD *)&Result->x2 = 0i64;
    }
  }
}

// File Line: 442
// RVA: 0x975D70
void __fastcall Scaleform::Render::DICommand_GetPixel32::ExecuteSW(
        Scaleform::Render::DICommand_GetPixel32 *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8[3]; // [rsp+20h] [rbp-38h] BYREF
  int v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  __int64 v11; // [rsp+48h] [rbp-10h]
  Scaleform::Render::Color v12; // [rsp+60h] [rbp+8h] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v8[2] = (__int64)dest;
  v8[1] = 0i64;
  v9 = 0;
  v10 = 0i64;
  v11 = 0i64;
  v8[0] = v7;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v8);
  (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v8[0] + 16i64))(v8[0], v8, this->Y);
  if ( this->Result )
  {
    (*(void (__fastcall **)(__int64, Scaleform::Render::Color *, __int64 *, _QWORD))(*(_QWORD *)v8[0] + 40i64))(
      v8[0],
      &v12,
      v8,
      this->X);
    *this->Result = v12;
  }
}

// File Line: 450
// RVA: 0x975E10
void __fastcall Scaleform::Render::DICommand_GetPixels::ExecuteSW(
        Scaleform::Render::DICommand_GetPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  int i; // esi
  int j; // ebx
  __int64 v10[3]; // [rsp+20h] [rbp-38h] BYREF
  int v11; // [rsp+38h] [rbp-20h]
  __int64 v12; // [rsp+40h] [rbp-18h]
  __int64 v13; // [rsp+48h] [rbp-10h]
  unsigned int v14; // [rsp+60h] [rbp+8h] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v10[2] = (__int64)dest;
  v10[1] = 0i64;
  v11 = 0;
  v12 = 0i64;
  v13 = 0i64;
  v10[0] = v7;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v10);
  for ( i = this->SourceRect.y1; i < this->SourceRect.y2; ++i )
  {
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v10[0] + 16i64))(v10[0], v10, (unsigned int)i);
    for ( j = this->SourceRect.x1; j < this->SourceRect.x2; ++j )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v10[0] + 40i64))(
        v10[0],
        &v14,
        v10,
        (unsigned int)j);
      this->Provider->vfptr->WriteNextPixel(this->Provider, v14);
    }
  }
}

// File Line: 466
// RVA: 0x975EF0
void __fastcall Scaleform::Render::DICommand_Histogram::ExecuteSW(
        Scaleform::Render::DICommand_Histogram *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dst,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  int y1; // esi
  Scaleform::Render::ImagePlane *pPlanes; // rax
  int y2; // edx
  int x1; // ebx
  Scaleform::Render::ImagePlane *v12; // rax
  int x2; // edx
  unsigned int v14; // edx
  __int64 v15; // rcx
  Scaleform::Render::ImagePlane *v16; // rax
  int Width; // edx
  Scaleform::Render::ImagePlane *v18; // rax
  int Height; // edx
  __int64 v20[3]; // [rsp+20h] [rbp-48h] BYREF
  int v21; // [rsp+38h] [rbp-30h]
  __int64 v22; // [rsp+40h] [rbp-28h]
  __int64 v23; // [rsp+48h] [rbp-20h]
  unsigned int v24; // [rsp+70h] [rbp+8h] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v20[2] = (__int64)dst;
  v20[1] = 0i64;
  v21 = 0;
  v22 = 0i64;
  v20[0] = v7;
  v23 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v20);
  y1 = this->SourceRect.y1;
  pPlanes = dst->pPlanes;
  y2 = this->SourceRect.y2;
  if ( y1 < 0 )
    y1 = 0;
  if ( (signed int)pPlanes->Height < y2 )
    y2 = pPlanes->Height;
  if ( y1 < y2 )
  {
    do
    {
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v20[0] + 16i64))(v20[0], v20, (unsigned int)y1);
      x1 = this->SourceRect.x1;
      v12 = dst->pPlanes;
      x2 = this->SourceRect.x2;
      if ( x1 < 0 )
        x1 = 0;
      if ( (signed int)v12->Width < x2 )
        x2 = v12->Width;
      if ( x1 < x2 )
      {
        do
        {
          (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v20[0] + 40i64))(
            v20[0],
            &v24,
            v20,
            (unsigned int)x1);
          v14 = v24 >> 8;
          ++x1;
          ++this->Result[(unsigned __int8)v24 + 512];
          v15 = (unsigned int)(unsigned __int8)v14 + 256;
          v14 >>= 8;
          ++this->Result[v15];
          ++this->Result[(unsigned __int8)v14];
          ++this->Result[BYTE1(v14) + 768];
          v16 = dst->pPlanes;
          Width = this->SourceRect.x2;
          if ( (signed int)v16->Width < Width )
            Width = v16->Width;
        }
        while ( x1 < Width );
      }
      v18 = dst->pPlanes;
      Height = this->SourceRect.y2;
      ++y1;
      if ( (signed int)v18->Height < Height )
        Height = v18->Height;
    }
    while ( y1 < Height );
  }
}

// File Line: 487
// RVA: 0x976040
void __fastcall Scaleform::Render::DICommand_HitTest::ExecuteSW(
        Scaleform::Render::DICommand_HitTest *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  Scaleform::Render::ImagePlane *pPlanes; // rax
  signed int v12; // ecx
  int v13; // esi
  signed int v14; // eax
  int v15; // r12d
  int v16; // eax
  int v17; // edi
  int v18; // eax
  int v19; // ebx
  bool *Result; // rax
  __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // rbx
  __int64 v25; // rax
  Scaleform::Render::Image *pObject; // rdi
  unsigned int Height; // esi
  unsigned int Width; // ebx
  unsigned int *v29; // rax
  unsigned int v30; // r8d
  int y; // ecx
  unsigned int v32; // r13d
  int v33; // ebx
  int v34; // eax
  int v35; // esi
  int v36; // ebx
  int x; // ecx
  int v38; // ebx
  int v39; // edi
  int v40; // ebx
  bool *v41; // rax
  __int64 v42; // [rsp+20h] [rbp-39h] BYREF
  __int64 v43; // [rsp+28h] [rbp-31h]
  Scaleform::Render::ImageData *v44; // [rsp+30h] [rbp-29h]
  int v45; // [rsp+38h] [rbp-21h]
  __int64 v46; // [rsp+40h] [rbp-19h]
  __int64 v47; // [rsp+48h] [rbp-11h]
  char v48[8]; // [rsp+50h] [rbp-9h] BYREF
  char v49[8]; // [rsp+58h] [rbp-1h] BYREF
  __int64 v50[3]; // [rsp+60h] [rbp+7h] BYREF
  int v51; // [rsp+78h] [rbp+1Fh]
  __int64 v52; // [rsp+80h] [rbp+27h]
  __int64 v53; // [rsp+88h] [rbp+2Fh]
  unsigned int v54; // [rsp+C0h] [rbp+67h] BYREF

  vfptr = context->pHAL->vfptr;
  if ( this->SecondImage.pObject )
  {
    v21 = ((__int64 (*)(void))vfptr[61].__vecDelDtor)();
    v22 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v21 + 120i64))(v21);
    v44 = dest;
    v43 = 0i64;
    v45 = 0;
    v46 = 0i64;
    v42 = v22;
    v47 = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v22 + 8i64))(v22, &v42);
    v23 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
    v24 = (__int64)*psrc;
    v25 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v23 + 120i64))(v23);
    v50[1] = 0i64;
    v50[2] = v24;
    v51 = 0;
    v52 = 0i64;
    v53 = 0i64;
    v50[0] = v25;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v25 + 8i64))(v25, v50);
    pObject = this->SecondImage.pObject;
    Height = dest->pPlanes->Height;
    v54 = *((_DWORD *)pObject->vfptr[5].__vecDelDtor(pObject, (unsigned int)v48) + 1);
    Width = dest->pPlanes->Width;
    v29 = (unsigned int *)pObject->vfptr[5].__vecDelDtor(pObject, (unsigned int)v49);
    v30 = v54;
    y = this->SecondPoint.y;
    v32 = *v29;
    if ( Width < *v29 )
      v32 = Width;
    v33 = this->FirstPoint.y;
    if ( Height < v54 )
      v30 = Height;
    v34 = this->SecondPoint.y - v33;
    v35 = v34;
    v54 = v30;
    if ( v34 < 0 )
      v35 = 0;
    if ( v35 < (int)(v30 + v34) )
    {
      do
      {
        v36 = v35 + v33 - y;
        if ( v35 < 0
          || v35 >= (signed int)dest->pPlanes->Height
          || v36 < 0
          || v36 >= (signed int)(*psrc)->pPlanes->Height )
        {
          break;
        }
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v42 + 16i64))(v42, &v42, (unsigned int)v35);
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v50[0] + 16i64))(v50[0], v50, (unsigned int)v36);
        x = this->SecondPoint.x;
        v38 = this->FirstPoint.x;
        v39 = x - v38;
        if ( x - v38 < 0 )
          v39 = 0;
        if ( v39 < (int)(v32 + x - v38) )
        {
          do
          {
            v40 = v39 + v38 - x;
            if ( v39 < 0
              || v39 >= (signed int)dest->pPlanes->Width
              || v40 < 0
              || v40 >= (signed int)(*psrc)->pPlanes->Width )
            {
              break;
            }
            (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v42 + 40i64))(
              v42,
              v49,
              &v42,
              (unsigned int)v39);
            if ( (unsigned __int8)v49[3] >= this->FirstThreshold )
            {
              (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v50[0] + 40i64))(
                v50[0],
                v48,
                v50,
                (unsigned int)v40);
              if ( (unsigned __int8)v48[3] >= this->SecondThreshold )
              {
LABEL_20:
                Result = this->Result;
                if ( Result )
                  *Result = 1;
                return;
              }
            }
            x = this->SecondPoint.x;
            v38 = this->FirstPoint.x;
          }
          while ( ++v39 < (int)(v32 + x - v38) );
        }
        y = this->SecondPoint.y;
        v33 = this->FirstPoint.y;
        ++v35;
      }
      while ( v35 < (int)(v54 + y - v33) );
    }
  }
  else
  {
    v9 = ((__int64 (*)(void))vfptr[61].__vecDelDtor)();
    v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 120i64))(v9);
    v44 = dest;
    v43 = 0i64;
    v45 = 0;
    v46 = 0i64;
    v42 = v10;
    v47 = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 8i64))(v10, &v42);
    pPlanes = dest->pPlanes;
    v12 = pPlanes->Height;
    v13 = this->SecondArea.x2 - this->SecondArea.x1;
    v14 = pPlanes->Width;
    v15 = this->SecondArea.y2 - this->SecondArea.y1;
    if ( v14 < v13 )
      v13 = v14;
    if ( v12 < v15 )
      v15 = v12;
    v16 = this->SecondArea.y1 - this->FirstPoint.y;
    v17 = v16;
    if ( v16 < 0 )
      v17 = 0;
    if ( v17 < v15 + v16 )
    {
      do
      {
        if ( v17 < 0 || v17 >= (signed int)dest->pPlanes->Height )
          break;
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v42 + 16i64))(v42, &v42, (unsigned int)v17);
        v18 = this->SecondArea.x1 - this->FirstPoint.x;
        v19 = v18;
        if ( v18 < 0 )
          v19 = 0;
        if ( v19 < v13 + v18 )
        {
          do
          {
            if ( v19 < 0 || v19 >= (signed int)dest->pPlanes->Width )
              break;
            (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v42 + 40i64))(
              v42,
              &v54,
              &v42,
              (unsigned int)v19);
            if ( HIBYTE(v54) >= this->FirstThreshold )
              goto LABEL_20;
            ++v19;
          }
          while ( v19 < v13 + this->SecondArea.x1 - this->FirstPoint.x );
        }
        ++v17;
      }
      while ( v17 < v15 + this->SecondArea.y1 - this->FirstPoint.y );
    }
  }
  v41 = this->Result;
  if ( v41 )
    *v41 = 0;
}

// File Line: 559
// RVA: 0x9763B0
void __fastcall Scaleform::Render::DICommand_Merge::ExecuteSW(
        Scaleform::Render::DICommand_Merge *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // rax
  Scaleform::Render::DICommand_Merge *v5; // r13
  int Width; // ebx
  int Height; // edi
  Scaleform::Render::ImagePlane *v8; // r10
  int x1; // eax
  int y1; // ecx
  int v11; // r11d
  int v12; // r10d
  int v13; // r12d
  int v14; // r14d
  int y2; // edx
  int x2; // r8d
  int v17; // esi
  __int64 v18; // rdx
  __int64 v19; // r8
  int v20; // eax
  int v21; // r15d
  int v22; // ebx
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rdi
  __int64 v27; // rax
  int v28; // r14d
  int v29; // edi
  int v30; // ebx
  unsigned int RedMultiplier; // r8d
  unsigned int GreenMultiplier; // r11d
  unsigned int BlueMultiplier; // r15d
  __int16 v34; // r14
  __int16 v35; // r12
  bool Transparent; // r13
  char v37; // al
  unsigned int v38; // [rsp+20h] [rbp-79h]
  unsigned int v39; // [rsp+24h] [rbp-75h]
  int v40; // [rsp+28h] [rbp-71h]
  int v41; // [rsp+2Ch] [rbp-6Dh]
  int v42; // [rsp+30h] [rbp-69h]
  int v43; // [rsp+34h] [rbp-65h]
  int v44; // [rsp+38h] [rbp-61h]
  int v45; // [rsp+3Ch] [rbp-5Dh]
  __int64 v46[3]; // [rsp+48h] [rbp-51h] BYREF
  int v47; // [rsp+60h] [rbp-39h]
  __int64 v48; // [rsp+68h] [rbp-31h]
  __int64 v49; // [rsp+70h] [rbp-29h]
  __int64 v50[3]; // [rsp+78h] [rbp-21h] BYREF
  int v51; // [rsp+90h] [rbp-9h]
  __int64 v52; // [rsp+98h] [rbp-1h]
  __int64 v53; // [rsp+A0h] [rbp+7h]
  Scaleform::Render::ImageData *v56; // [rsp+110h] [rbp+77h] BYREF
  Scaleform::Render::ImageData **v57; // [rsp+118h] [rbp+7Fh] BYREF

  v57 = psrc;
  v56 = dest;
  pPlanes = dest->pPlanes;
  v5 = this;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v8 = (*psrc)->pPlanes;
  x1 = this->SourceRect.x1;
  y1 = this->SourceRect.y1;
  v11 = v8->Width;
  v12 = v8->Height;
  v13 = v5->DestPoint.x - x1;
  v14 = v5->DestPoint.y - y1;
  v44 = v13;
  if ( v12 >= y1 )
  {
    y2 = v5->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = v5->SourceRect.x2;
      if ( x2 >= 0 && v11 >= x1 )
      {
        if ( x1 < 0 )
          x1 = 0;
        if ( v11 > x2 )
          v11 = v5->SourceRect.x2;
        if ( y1 < 0 )
          y1 = 0;
        v17 = v11 + v13;
        if ( v12 > y2 )
          v12 = v5->SourceRect.y2;
        v18 = (unsigned int)(x1 + v13);
        v19 = (unsigned int)(y1 + v14);
        v20 = v12 + v14;
        if ( v12 + v14 >= 0 && Height >= (int)v19 && Width >= (int)v18 && v17 >= 0 )
        {
          v21 = 0;
          if ( (int)v18 > 0 )
            v21 = v18;
          if ( v17 > Width )
            v17 = Width;
          v22 = 0;
          if ( (int)v19 > 0 )
            v22 = y1 + v14;
          v43 = v21;
          if ( v20 > Height )
            v20 = Height;
          v42 = v17;
          v41 = v20;
          v40 = v22;
          v23 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, __int64, __int64, _QWORD))context->pHAL->vfptr[61].__vecDelDtor)(
                  context->pHAL,
                  v18,
                  v19,
                  0i64);
          v24 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v23 + 120i64))(v23);
          v46[1] = 0i64;
          v47 = 0;
          v48 = 0i64;
          v46[2] = (__int64)v56;
          v49 = 0i64;
          v46[0] = v24;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v24 + 8i64))(v24, v46);
          v25 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
          v26 = (__int64)*v57;
          v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 120i64))(v25);
          v50[2] = v26;
          v50[1] = 0i64;
          v51 = 0;
          v52 = 0i64;
          v53 = 0i64;
          v50[0] = v27;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v27 + 8i64))(v27, v50);
          if ( v22 < v41 )
          {
            v28 = -v14;
            v45 = v28;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v46[0] + 16i64))(
                v46[0],
                v46,
                (unsigned int)v22);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v50[0] + 16i64))(
                v50[0],
                v50,
                (unsigned int)(v28 + v22));
              v29 = v21;
              v39 = v21;
              if ( v21 < v17 )
              {
                v30 = -v13;
                do
                {
                  (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData ***, __int64 *, _QWORD))(*(_QWORD *)v46[0] + 40i64))(
                    v46[0],
                    &v57,
                    v46,
                    (unsigned int)v29);
                  (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD))(*(_QWORD *)v50[0] + 40i64))(
                    v50[0],
                    &v56,
                    v50,
                    (unsigned int)(v30 + v29));
                  RedMultiplier = v5->RedMultiplier;
                  GreenMultiplier = v5->GreenMultiplier;
                  BlueMultiplier = v5->BlueMultiplier;
                  v34 = BYTE3(v56);
                  v35 = BYTE3(v57);
                  if ( !v5->pSource.pObject->Transparent )
                    v34 = 255;
                  Transparent = v5->pImage.pObject->Transparent;
                  if ( !Transparent )
                    v35 = 255;
                  v37 = (unsigned __int16)(this->AlphaMultiplier * v34 + v35 * (256 - this->AlphaMultiplier)) >> 8;
                  if ( !Transparent )
                    v37 = -1;
                  HIBYTE(v38) = v37;
                  BYTE1(v38) = (unsigned __int16)(GreenMultiplier * BYTE1(v56) + BYTE1(v57) * (256 - GreenMultiplier)) >> 8;
                  LOBYTE(v38) = (unsigned __int16)(BlueMultiplier * (unsigned __int8)v56
                                                 + (unsigned __int8)v57 * (256 - BlueMultiplier)) >> 8;
                  BYTE2(v38) = (unsigned __int16)(RedMultiplier * BYTE2(v56) + BYTE2(v57) * (256 - RedMultiplier)) >> 8;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v46[0] + 24i64))(
                    v46[0],
                    v46,
                    v39,
                    v38);
                  v17 = v42;
                  v5 = this;
                  v29 = v39 + 1;
                  v39 = v29;
                }
                while ( v29 < v42 );
                v22 = v40;
                v28 = v45;
                v21 = v43;
                v13 = v44;
              }
              v40 = ++v22;
            }
            while ( v22 < v41 );
          }
        }
      }
    }
  }
}

// File Line: 612
// RVA: 0x976720
void __fastcall Scaleform::Render::DICommand_Noise::ExecuteSW(
        Scaleform::Render::DICommand_Noise *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  unsigned int Time; // eax
  unsigned int v8; // edx
  __int64 v9; // rax
  __int64 v10; // rax
  Scaleform::Render::ImagePlane *pPlanes; // rax
  unsigned int i; // esi
  unsigned int v13; // ebx
  __int64 v14; // rax
  __int64 v15; // r8
  unsigned int v16; // ecx
  unsigned __int64 v17; // rax
  int v18; // edx
  float v19; // xmm1_4
  __int64 v20; // rax
  __int64 v21; // r8
  unsigned int v22; // ecx
  unsigned __int64 v23; // rax
  int v24; // edx
  float v25; // xmm0_4
  int v26; // ecx
  unsigned int ChannelMask; // edx
  __int64 v28; // rax
  __int64 v29; // r9
  unsigned int v30; // ecx
  unsigned __int64 v31; // rax
  int v32; // r8d
  __int64 v33; // rax
  __int64 v34; // r9
  unsigned int v35; // ecx
  unsigned __int64 v36; // rax
  int v37; // r8d
  __int64 v38; // rax
  __int64 v39; // r9
  unsigned int v40; // ecx
  unsigned __int64 v41; // rax
  int v42; // r8d
  __int64 v43; // rax
  __int64 v44; // r8
  unsigned int v45; // ecx
  unsigned __int64 v46; // rax
  int v47; // edx
  Scaleform::Alg::Random::Generator v48; // [rsp+20h] [rbp-59h] BYREF
  __int64 v49[3]; // [rsp+48h] [rbp-31h] BYREF
  int v50; // [rsp+60h] [rbp-19h]
  __int64 v51; // [rsp+68h] [rbp-11h]
  __int64 v52; // [rsp+70h] [rbp-9h]
  unsigned int v53; // [rsp+E0h] [rbp+67h]

  v48.C = 362436;
  v48.I = 7;
  Time = timeGetTime();
  v8 = Time;
  if ( TimerOverrideInstance )
    v8 = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, Time);
  Scaleform::Alg::Random::Generator::SeedRandom(&v48, v8);
  Scaleform::Alg::Random::Generator::SeedRandom(&v48, this->RandomSeed);
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 120i64))(v9);
  v49[2] = (__int64)dest;
  v49[1] = 0i64;
  v50 = 0;
  v51 = 0i64;
  v49[0] = v10;
  v52 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 8i64))(v10, v49);
  pPlanes = dest->pPlanes;
  for ( i = 0; i < pPlanes->Width; ++i )
  {
    v13 = 0;
    if ( pPlanes->Height )
    {
      do
      {
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v49[0] + 16i64))(v49[0], v49, v13);
        v53 = 0;
        if ( this->GrayScale )
        {
          v14 = (LOBYTE(v48.I) + 1) & 7;
          v48.I = v14;
          v15 = (unsigned int)v14;
          v16 = v48.C + 716514398 * v48.Q[v14];
          v17 = (v48.C + 716514398 * (unsigned __int64)v48.Q[v14]) >> 32;
          v48.C = v17;
          v18 = v16 + v17;
          if ( v16 + (unsigned int)v17 < (unsigned int)v17 )
          {
            ++v18;
            v48.C = v17 + 1;
          }
          v48.Q[v15] = -2 - v18;
          v19 = (float)((unsigned int)(-2 - v18) >> 8) * 0.000000059604652;
          if ( (this->ChannelMask & 8) != 0 )
          {
            v20 = (LOBYTE(v48.I) + 1) & 7;
            v48.I = v20;
            v21 = (unsigned int)v20;
            v22 = v48.C + 716514398 * v48.Q[v20];
            v23 = (v48.C + 716514398 * (unsigned __int64)v48.Q[v20]) >> 32;
            v48.C = v23;
            v24 = v22 + v23;
            if ( v22 + (unsigned int)v23 < (unsigned int)v23 )
            {
              ++v24;
              v48.C = v23 + 1;
            }
            v48.Q[v21] = -2 - v24;
            v25 = (float)((unsigned int)(-2 - v24) >> 8) * 0.000000059604652;
          }
          else
          {
            v25 = *(float *)&FLOAT_1_0;
          }
          v26 = (int)(float)(v25 * 255.0);
          BYTE2(v53) = (int)(float)(v19 * 255.0);
          BYTE1(v53) = BYTE2(v53);
          LOBYTE(v53) = BYTE2(v53);
        }
        else
        {
          ChannelMask = this->ChannelMask;
          if ( (ChannelMask & 1) != 0 )
          {
            v28 = (LOBYTE(v48.I) + 1) & 7;
            v48.I = v28;
            v29 = (unsigned int)v28;
            v30 = v48.C + 716514398 * v48.Q[v28];
            v31 = (v48.C + 716514398 * (unsigned __int64)v48.Q[v28]) >> 32;
            v48.C = v31;
            v32 = v30 + v31;
            if ( v30 + (unsigned int)v31 < (unsigned int)v31 )
            {
              ++v32;
              v48.C = v31 + 1;
            }
            v48.Q[v29] = -2 - v32;
            BYTE2(v53) = (int)(float)((float)((float)((unsigned int)(-2 - v32) >> 8) * 0.000000059604652) * 255.0);
          }
          if ( (ChannelMask & 2) != 0 )
          {
            v33 = (LOBYTE(v48.I) + 1) & 7;
            v48.I = v33;
            v34 = (unsigned int)v33;
            v35 = v48.C + 716514398 * v48.Q[v33];
            v36 = (v48.C + 716514398 * (unsigned __int64)v48.Q[v33]) >> 32;
            v48.C = v36;
            v37 = v35 + v36;
            if ( v35 + (unsigned int)v36 < (unsigned int)v36 )
            {
              ++v37;
              v48.C = v36 + 1;
            }
            v48.Q[v34] = -2 - v37;
            BYTE1(v53) = (int)(float)((float)((float)((unsigned int)(-2 - v37) >> 8) * 0.000000059604652) * 255.0);
          }
          if ( (ChannelMask & 4) != 0 )
          {
            v38 = (LOBYTE(v48.I) + 1) & 7;
            v48.I = v38;
            v39 = (unsigned int)v38;
            v40 = v48.C + 716514398 * v48.Q[v38];
            v41 = (v48.C + 716514398 * (unsigned __int64)v48.Q[v38]) >> 32;
            v48.C = v41;
            v42 = v40 + v41;
            if ( v40 + (unsigned int)v41 < (unsigned int)v41 )
            {
              ++v42;
              v48.C = v41 + 1;
            }
            v48.Q[v39] = -2 - v42;
            LOBYTE(v53) = (int)(float)((float)((float)((unsigned int)(-2 - v42) >> 8) * 0.000000059604652) * 255.0);
          }
          if ( (ChannelMask & 8) != 0 )
          {
            v43 = (LOBYTE(v48.I) + 1) & 7;
            v48.I = v43;
            v44 = (unsigned int)v43;
            v45 = v48.C + 716514398 * v48.Q[v43];
            v46 = (v48.C + 716514398 * (unsigned __int64)v48.Q[v43]) >> 32;
            v48.C = v46;
            v47 = v45 + v46;
            if ( v45 + (unsigned int)v46 < (unsigned int)v46 )
            {
              ++v47;
              v48.C = v46 + 1;
            }
            v48.Q[v44] = -2 - v47;
            v26 = (int)(float)((float)((float)((unsigned int)(-2 - v47) >> 8) * 0.000000059604652) * 255.0);
          }
          else
          {
            LOBYTE(v26) = -1;
          }
        }
        if ( !this->pImage.pObject->Transparent )
          LOBYTE(v26) = -1;
        HIBYTE(v53) = v26;
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v49[0] + 24i64))(v49[0], v49, i, v53);
        ++v13;
      }
      while ( v13 < dest->pPlanes->Height );
    }
    pPlanes = dest->pPlanes;
  }
}

// File Line: 653
// RVA: 0x976B30
void __fastcall Scaleform::Render::DICommand_PaletteMap::ExecuteSW(
        Scaleform::Render::DICommand_PaletteMap *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // rax
  signed int Width; // ebx
  signed int Height; // esi
  Scaleform::Render::ImagePlane *v8; // rax
  int v9; // r11d
  int v10; // r10d
  int x1; // eax
  int y1; // ecx
  int v14; // r12d
  int v16; // r9d
  int y2; // edx
  int x2; // r8d
  int v20; // r8d
  int v21; // edx
  int v22; // eax
  int v23; // r9d
  int v24; // ecx
  int v25; // r12d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rbx
  __int64 v31; // rax
  int v32; // r13d
  int v33; // ebx
  int v34; // r14d
  unsigned __int8 v35; // r9
  unsigned int ChannelMask; // esi
  unsigned int v37; // ebx
  __int64 v38; // r10
  char *v39; // r11
  int *v40; // r8
  int v41; // eax
  __int64 v42; // r9
  int v43; // [rsp+20h] [rbp-69h]
  int v44; // [rsp+30h] [rbp-59h]
  int v45; // [rsp+34h] [rbp-55h]
  int v46; // [rsp+38h] [rbp-51h]
  int v47[4]; // [rsp+40h] [rbp-49h] BYREF
  __int64 v48[3]; // [rsp+50h] [rbp-39h] BYREF
  int v49; // [rsp+68h] [rbp-21h]
  __int64 v50; // [rsp+70h] [rbp-19h]
  __int64 v51; // [rsp+78h] [rbp-11h]
  __int64 v52[3]; // [rsp+80h] [rbp-9h] BYREF
  int v53; // [rsp+98h] [rbp+Fh]
  __int64 v54; // [rsp+A0h] [rbp+17h]
  __int64 v55; // [rsp+A8h] [rbp+1Fh]
  int v56; // [rsp+F0h] [rbp+67h] BYREF
  char v57; // [rsp+100h] [rbp+77h] BYREF
  char v58; // [rsp+101h] [rbp+78h]
  char v59; // [rsp+102h] [rbp+79h]
  unsigned __int8 v60; // [rsp+103h] [rbp+7Ah]
  int v61; // [rsp+108h] [rbp+7Fh]

  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v8 = (*psrc)->pPlanes;
  v9 = v8->Height;
  v10 = v8->Width;
  x1 = this->SourceRect.x1;
  y1 = this->SourceRect.y1;
  v14 = this->DestPoint.x - x1;
  v16 = this->DestPoint.y - y1;
  v45 = v14;
  v61 = v16;
  if ( v9 >= y1 )
  {
    y2 = this->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->SourceRect.x2;
      if ( x2 >= 0 && v10 >= x1 )
      {
        if ( x1 < 0 )
          x1 = 0;
        if ( v10 > x2 )
          v10 = this->SourceRect.x2;
        if ( y1 < 0 )
          y1 = 0;
        v20 = v10 + v14;
        if ( v9 > y2 )
          v9 = this->SourceRect.y2;
        v21 = x1 + v14;
        v22 = y1 + v16;
        v23 = v9 + v16;
        if ( v23 >= 0 && Height >= v22 && Width >= v21 && v20 >= 0 )
        {
          v24 = 0;
          v25 = 0;
          if ( v21 > 0 )
            v24 = v21;
          if ( v20 > Width )
            v20 = Width;
          v46 = v24;
          if ( v22 > 0 )
            v25 = v22;
          vfptr = context->pHAL->vfptr;
          if ( v23 > Height )
            v23 = Height;
          v56 = v20;
          v44 = v25;
          v43 = v23;
          v27 = ((__int64 (*)(void))vfptr[61].__vecDelDtor)();
          v28 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v27 + 120i64))(v27);
          v52[2] = (__int64)dest;
          v52[1] = 0i64;
          v53 = 0;
          v54 = 0i64;
          v55 = 0i64;
          v52[0] = v28;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v28 + 8i64))(v28, v52);
          v29 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
          v30 = (__int64)*psrc;
          v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 120i64))(v29);
          v48[1] = 0i64;
          v48[2] = v30;
          v49 = 0;
          v50 = 0i64;
          v51 = 0i64;
          v48[0] = v31;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v31 + 8i64))(v31, v48);
          if ( v25 < v43 )
          {
            v32 = v56;
            v33 = -v61;
            v61 = -v61;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v52[0] + 16i64))(
                v52[0],
                v52,
                (unsigned int)v25);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v48[0] + 16i64))(
                v48[0],
                v48,
                (unsigned int)(v33 + v25));
              v34 = v46;
              if ( v46 < v32 )
              {
                do
                {
                  (*(void (__fastcall **)(__int64, int *, __int64 *, _QWORD))(*(_QWORD *)v48[0] + 40i64))(
                    v48[0],
                    &v56,
                    v48,
                    (unsigned int)(v34 - v45));
                  v35 = HIBYTE(v56);
                  if ( !this->pSource.pObject->Transparent )
                    v35 = -1;
                  ChannelMask = this->ChannelMask;
                  HIBYTE(v56) = v35;
                  v59 = v56;
                  v60 = v35;
                  v47[2] = (unsigned __int8)v56;
                  v47[3] = v35 << 24;
                  v37 = 0;
                  v57 = BYTE2(v56);
                  v58 = BYTE1(v56);
                  v47[0] = BYTE2(v56) << 16;
                  v38 = 0i64;
                  v39 = &v57;
                  v40 = v47;
                  v47[1] = BYTE1(v56) << 8;
                  v41 = 1;
                  v42 = 4i64;
                  do
                  {
                    if ( (v41 & ChannelMask) != 0 )
                      *v40 = this->Channels[v38 + (unsigned __int8)*v39];
                    v41 = __ROL4__(v41, 1);
                    v37 += *v40++;
                    ++v39;
                    v38 += 256i64;
                    --v42;
                  }
                  while ( v42 );
                  if ( !this->pImage.pObject->Transparent )
                    v37 |= 0xFF000000;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v52[0] + 24i64))(
                    v52[0],
                    v52,
                    (unsigned int)v34++,
                    v37);
                }
                while ( v34 < v32 );
                v25 = v44;
                v33 = v61;
              }
              v44 = ++v25;
            }
            while ( v25 < v43 );
          }
        }
      }
    }
  }
}

// File Line: 729
// RVA: 0x9966A0
float __fastcall Scaleform::Render::PerlinGenerator::InterpolatedNoise(
        Scaleform::Render::PerlinGenerator *this,
        float x,
        float y)
{
  float v4; // xmm10_4
  float v5; // xmm8_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  float v8; // xmm6_4

  v4 = (float)(1.0 - cosf((float)(x - (float)(int)x) * 3.1415927)) * 0.5;
  v5 = (float)(1.0 - cosf((float)(y - (float)(int)y) * 3.1415927)) * 0.5;
  v6 = Scaleform::Render::PerlinGenerator::SmoothNoise(this, (int)x, (int)y);
  v7 = (float)((float)(v6 * (float)(1.0 - v4))
             + (float)(Scaleform::Render::PerlinGenerator::SmoothNoise(this, (int)x + 1, (int)y) * v4))
     * (float)(1.0 - v5);
  v8 = Scaleform::Render::PerlinGenerator::SmoothNoise(this, (int)x, (int)y + 1) * (float)(1.0 - v4);
  return v7
       + (float)((float)(v8 + (float)(Scaleform::Render::PerlinGenerator::SmoothNoise(this, (int)x + 1, (int)y + 1) * v4))
               * v5);
}

// File Line: 764
// RVA: 0x9B6980
float __fastcall Scaleform::Render::PerlinGenerator::SmoothNoise(
        Scaleform::Render::PerlinGenerator *this,
        int x,
        int y)
{
  unsigned int v3; // ebp
  int v4; // esi
  int v5; // r14d
  int v6; // r15d
  unsigned int v7; // r9d
  unsigned int v8; // ecx
  int v9; // r11d
  int v10; // r10d
  int v11; // ebx
  int v12; // edi
  int v13; // r8d
  int v14; // edx
  int v15; // r14d

  v3 = this->PrimeSet.primes[1];
  v4 = x + this->PrimeSet.primes[0] * (y - 1);
  v5 = x + this->PrimeSet.primes[0] * (y + 1);
  v6 = y * this->PrimeSet.primes[0] + x;
  v7 = this->PrimeSet.primes[2];
  v8 = this->PrimeSet.primes[3];
  v9 = ((v4 - 1) << 13) ^ (v4 - 1);
  v10 = ((v4 + 1) << 13) ^ (v4 + 1);
  v11 = ((v5 - 1) << 13) ^ (v5 - 1);
  v12 = ((v5 + 1) << 13) ^ (v5 + 1);
  v13 = ((v6 - 1) << 13) ^ (v6 - 1);
  v14 = ((v6 + 1) << 13) ^ (v6 + 1);
  v15 = (v5 << 13) ^ v5;
  return (float)((float)((float)((float)((float)((float)(1.0
                                                       - (float)((float)((v8 + v10 * (v7 + v10 * v10 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10))
                                               + (float)(1.0
                                                       - (float)((float)((v8 + v9 * (v7 + v9 * v9 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10)))
                                       + (float)(1.0
                                               - (float)((float)((v8 + v11 * (v7 + v11 * v11 * v3)) & 0x7FFFFFFF)
                                                       * 9.3132257e-10)))
                               + (float)(1.0
                                       - (float)((float)((v8 + v12 * (v7 + v12 * v12 * v3)) & 0x7FFFFFFF) * 9.3132257e-10)))
                       * 0.0625)
               + (float)((float)((float)((float)((float)(1.0
                                                       - (float)((float)((v8 + v14 * (v7 + v14 * v14 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10))
                                               + (float)(1.0
                                                       - (float)((float)((v8 + v13 * (v7 + v13 * v13 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10)))
                                       + (float)(1.0
                                               - (float)((float)((v8
                                                                + ((v4 << 13) ^ v4)
                                                                * (v7 + ((v4 << 13) ^ v4) * ((v4 << 13) ^ v4) * v3)) & 0x7FFFFFFF)
                                                       * 9.3132257e-10)))
                               + (float)(1.0
                                       - (float)((float)((v8 + v15 * (v7 + v15 * v15 * v3)) & 0x7FFFFFFF) * 9.3132257e-10)))
                       * 0.125))
       + (float)((float)(1.0
                       - (float)((float)((v8 + ((v6 << 13) ^ v6) * (v7 + ((v6 << 13) ^ v6) * ((v6 << 13) ^ v6) * v3)) & 0x7FFFFFFF)
                               * 9.3132257e-10))
               * 0.25);
}

// File Line: 797
// RVA: 0x976E30
void __fastcall Scaleform::Render::DICommand_PerlinNoise::ExecuteSW(
        Scaleform::Render::DICommand_PerlinNoise *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  unsigned int ChannelMask; // edi
  Scaleform::Render::ImageData *v5; // r12
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // r15d
  unsigned int v10; // ebx
  unsigned int v11; // esi
  int v12; // r14d
  int v13; // eax
  int v14; // edx
  bool v15; // zf
  unsigned int v16; // edx
  unsigned int NumOctaves; // r12d
  float v18; // xmm9_4
  float v19; // xmm6_4
  float v20; // xmm10_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  unsigned int v23; // edi
  __int64 v24; // rcx
  int v25; // eax
  float *Offsets; // rbx
  float v27; // xmm12_4
  int v28; // eax
  unsigned int OffsetCount; // r15d
  float v30; // xmm13_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm6_4
  int v35; // eax
  float v36; // xmm6_4
  unsigned int v37; // [rsp+20h] [rbp-E0h]
  int v38; // [rsp+28h] [rbp-D8h]
  unsigned int v39; // [rsp+30h] [rbp-D0h]
  unsigned int v40; // [rsp+34h] [rbp-CCh]
  unsigned int v41; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::PerlinGenerator v42; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v43[3]; // [rsp+50h] [rbp-B0h] BYREF
  int v44; // [rsp+68h] [rbp-98h]
  __int64 v45; // [rsp+70h] [rbp-90h]
  __int64 v46; // [rsp+78h] [rbp-88h]
  bool Transparent; // [rsp+160h] [rbp+60h]
  unsigned int v48; // [rsp+168h] [rbp+68h]

  ChannelMask = this->ChannelMask;
  v5 = dest;
  v37 = ChannelMask;
  if ( this->GrayScale )
  {
    ChannelMask = ChannelMask & 0xFFFFFFF8 | 1;
    v37 = ChannelMask;
  }
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v8 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 120i64))(v7);
  v43[2] = (__int64)v5;
  v43[1] = 0i64;
  v44 = 0;
  v45 = 0i64;
  v43[0] = v8;
  v46 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v8 + 8i64))(v8, v43);
  v9 = 0;
  v40 = 0;
  while ( v9 < v5->pPlanes->Height )
  {
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v43[0] + 16i64))(v43[0], v43, v9);
    v10 = 0;
    v39 = 0;
    if ( !v5->pPlanes->Width )
      goto LABEL_31;
    do
    {
      v11 = 0;
      v48 = -16777216;
      v12 = 1;
      Transparent = this->pImage.pObject->Transparent;
      LOBYTE(v13) = -1;
      v14 = Transparent;
      v15 = v14 == -3;
      v16 = v14 + 3;
      v41 = v16;
      if ( v15 )
        goto LABEL_28;
      LOBYTE(v38) = -1;
      do
      {
        if ( (v12 & ChannelMask) != 0 )
        {
          NumOctaves = this->NumOctaves;
          v18 = *(float *)&FLOAT_1_0;
          v19 = 0.0;
          v20 = 0.0;
          v21 = 2.0 / this->FrequencyX;
          v22 = 2.0 / this->FrequencyY;
          v23 = 0;
          v24 = (-3 * ((_BYTE)v11 + (unsigned __int8)this->RandomSeed)) & 7;
          v42.PrimeSet.primes[0] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[(-3
                                                                                        * ((_BYTE)v11
                                                                                         + (unsigned __int8)this->RandomSeed)) & 7].primes[0];
          v42.PrimeSet.primes[1] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[v24].primes[1];
          v42.PrimeSet.primes[2] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[v24].primes[2];
          v42.PrimeSet.primes[3] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[v24].primes[3];
          if ( NumOctaves )
          {
            v25 = v10;
            Offsets = this->Offsets;
            v27 = (float)v25;
            v28 = v9;
            OffsetCount = this->OffsetCount;
            v30 = (float)v28;
            do
            {
              v31 = v27 * v21;
              v32 = v30 * v22;
              if ( v23 < OffsetCount )
              {
                v31 = v31 + *Offsets;
                v32 = v32 + Offsets[1];
              }
              ++v23;
              Offsets += 2;
              v20 = v20 + v18;
              v21 = v21 * 2.0;
              v22 = v22 * 2.0;
              v33 = (float)((float)(Scaleform::Render::PerlinGenerator::InterpolatedNoise(&v42, v31, v32) + 1.0) * 0.5)
                  * v18;
              v18 = v18 * 0.5;
              v19 = v19 + v33;
            }
            while ( v23 < NumOctaves );
            v16 = v41;
            v10 = v39;
            v9 = v40;
          }
          v34 = v19 / v20;
          if ( this->GrayScale && v11 != 3 )
          {
            ChannelMask = v37;
            v35 = (int)(float)(v34 * 255.0);
            BYTE2(v48) = v35;
            LOBYTE(v48) = v35;
LABEL_24:
            BYTE1(v48) = v35;
            goto LABEL_25;
          }
          ChannelMask = v37;
          v36 = v34 * 255.0;
          if ( v11 == 1 )
          {
            v35 = (int)v36;
            goto LABEL_24;
          }
          if ( v11 == 2 )
          {
            LOBYTE(v48) = (int)v36;
          }
          else
          {
            v13 = (int)v36;
            if ( v11 == 3 )
            {
              v38 = (int)v36;
              goto LABEL_26;
            }
            BYTE2(v48) = (int)v36;
          }
        }
LABEL_25:
        LOBYTE(v13) = v38;
LABEL_26:
        v12 = __ROL4__(v12, 1);
        ++v11;
      }
      while ( v11 < v16 );
      v5 = dest;
LABEL_28:
      if ( !Transparent )
        LOBYTE(v13) = -1;
      HIBYTE(v48) = v13;
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v43[0] + 24i64))(v43[0], v43, v10++, v48);
      v39 = v10;
    }
    while ( v10 < v5->pPlanes->Width );
LABEL_31:
    v40 = ++v9;
  }
}

// File Line: 932
// RVA: 0x977210
void __fastcall Scaleform::Render::DICommand_PixelDissolve::ExecuteSW(
        Scaleform::Render::DICommand_PixelDissolve *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  __int64 v8; // rax
  __int64 v9; // rax
  unsigned int v10; // r12d
  Scaleform::Render::ImagePlane *pPlanes; // rax
  int y1; // ecx
  int Height; // esi
  int Width; // r15d
  int y2; // edx
  int x2; // r8d
  int x1; // eax
  unsigned int v18; // r15d
  int v19; // esi
  int v20; // ecx
  unsigned int v21; // esi
  int RandomSeed; // ebx
  const unsigned int *v23; // r13
  unsigned int *Result; // rax
  __int64 v25; // rax
  __int64 v26; // rbx
  __int64 v27; // rax
  Scaleform::Render::ImagePlane *v28; // rax
  int v29; // r10d
  int v30; // r15d
  int v31; // r8d
  Scaleform::Render::ImagePlane *v32; // rcx
  signed int v33; // ebx
  signed int v34; // r11d
  int v35; // r9d
  int v36; // eax
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  int v41; // ecx
  int v42; // r8d
  unsigned int v43; // r15d
  int v44; // esi
  const unsigned int *v45; // r13
  unsigned int v46; // edi
  unsigned int v47; // ebx
  unsigned int *v48; // rax
  __int64 v49[3]; // [rsp+20h] [rbp-60h] BYREF
  int v50; // [rsp+38h] [rbp-48h]
  __int64 v51; // [rsp+40h] [rbp-40h]
  __int64 v52; // [rsp+48h] [rbp-38h]
  __int64 v53[3]; // [rsp+50h] [rbp-30h] BYREF
  int v54; // [rsp+68h] [rbp-18h]
  __int64 v55; // [rsp+70h] [rbp-10h]
  __int64 v56; // [rsp+78h] [rbp-8h]
  unsigned int v57; // [rsp+C0h] [rbp+40h] BYREF
  int v58; // [rsp+C8h] [rbp+48h]

  v8 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 120i64))(v8);
  v10 = 0;
  v49[2] = (__int64)dest;
  v49[1] = 0i64;
  v50 = 0;
  v51 = 0i64;
  v49[0] = v9;
  v52 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v9 + 8i64))(v9, v49);
  if ( this->pImage.pObject == this->pSource.pObject )
  {
    pPlanes = dest->pPlanes;
    y1 = this->SourceRect.y1;
    Height = pPlanes->Height;
    Width = pPlanes->Width;
    if ( Height >= y1 )
    {
      y2 = this->SourceRect.y2;
      if ( y2 >= 0 )
      {
        x2 = this->SourceRect.x2;
        if ( x2 >= 0 )
        {
          x1 = this->SourceRect.x1;
          if ( Width >= x1 )
          {
            if ( x1 < 0 )
              x1 = 0;
            if ( Width > x2 )
              Width = this->SourceRect.x2;
            if ( y1 < 0 )
              y1 = 0;
            if ( Height > y2 )
              Height = this->SourceRect.y2;
            v18 = Width - x1;
            v19 = Height - y1;
            v20 = 0;
            v21 = v18 * v19;
            if ( v21 > 1 )
            {
              do
                ++v20;
              while ( v21 > 1 << v20 );
            }
            RandomSeed = this->RandomSeed;
            if ( this->NumPixels )
            {
              v23 = &Scaleform::Render::LFSR::FeedbackPoly[v20];
              do
              {
                do
                  RandomSeed = (RandomSeed >> 1) ^ *v23 & -(RandomSeed & 1);
                while ( RandomSeed > v21 );
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v49[0] + 16i64))(
                  v49[0],
                  v49,
                  (RandomSeed - 1) / v18);
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v49[0] + 24i64))(
                  v49[0],
                  v49,
                  (RandomSeed - 1) % v18,
                  this->Fill.Raw);
                ++v10;
              }
              while ( v10 < this->NumPixels );
            }
            Result = this->Result;
            if ( Result )
              *Result = RandomSeed;
            return;
          }
        }
      }
    }
LABEL_48:
    this->Result = 0i64;
    return;
  }
  v25 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v26 = (__int64)*psrc;
  v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 120i64))(v25);
  v53[1] = 0i64;
  v53[2] = v26;
  v54 = 0;
  v55 = 0i64;
  v56 = 0i64;
  v53[0] = v27;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v27 + 8i64))(v27, v53);
  v28 = dest->pPlanes;
  v29 = v28->Width - this->DestPoint.x - this->DestPoint.x;
  if ( v29 <= 0 )
    goto LABEL_48;
  v30 = v28->Height - this->DestPoint.y - this->DestPoint.y;
  if ( v30 <= 0 )
    goto LABEL_48;
  v31 = this->SourceRect.y2;
  v32 = (*psrc)->pPlanes;
  v33 = v32->Width;
  v34 = v32->Height;
  if ( v31 < 0 )
    goto LABEL_48;
  v35 = this->SourceRect.y1;
  if ( v34 < v35 )
    goto LABEL_48;
  v36 = this->SourceRect.x1;
  if ( v33 < v36 )
    goto LABEL_48;
  v37 = this->SourceRect.x2;
  if ( v37 < 0 )
    goto LABEL_48;
  v38 = 0;
  if ( v36 > 0 )
    v38 = this->SourceRect.x1;
  v39 = 0;
  if ( v37 > v33 )
    v37 = v33;
  if ( v35 > 0 )
    v39 = this->SourceRect.y1;
  if ( v31 > v34 )
    v31 = v34;
  v40 = v37 - v38;
  v41 = 0;
  v42 = v31 - v39;
  if ( v40 < v29 )
    v29 = v40;
  if ( v42 < v30 )
    v30 = v42;
  v58 = v29;
  v43 = v29 * v30;
  if ( v43 > 1 )
  {
    do
      ++v41;
    while ( v43 > 1 << v41 );
  }
  v44 = this->RandomSeed;
  if ( this->NumPixels )
  {
    v45 = &Scaleform::Render::LFSR::FeedbackPoly[v41];
    do
    {
      do
        v44 = (v44 >> 1) ^ *v45 & -(v44 & 1);
      while ( v44 > v43 );
      v46 = (v44 - 1) % (unsigned int)v29;
      v47 = (v44 - 1) / (unsigned int)v29;
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v53[0] + 16i64))(
        v53[0],
        v53,
        v47 + this->SourceRect.y1);
      (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v53[0] + 40i64))(
        v53[0],
        &v57,
        v53,
        v46 + this->SourceRect.x1);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v49[0] + 16i64))(
        v49[0],
        v49,
        v47 + this->DestPoint.y);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v49[0] + 24i64))(
        v49[0],
        v49,
        v46 + this->DestPoint.x,
        v57);
      v29 = v58;
      ++v10;
    }
    while ( v10 < this->NumPixels );
  }
  v48 = this->Result;
  if ( v48 )
    *v48 = v44;
}

// File Line: 993
// RVA: 0x977580
void __fastcall Scaleform::Render::DICommand_Scroll::ExecuteSW(
        Scaleform::Render::DICommand_Scroll *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  int x1; // ecx
  Scaleform::Render::ImagePlane *pPlanes; // rax
  int y1; // r10d
  int Width; // edx
  int Height; // r8d
  Scaleform::Render::ImagePlane *v11; // rax
  int v12; // r13d
  signed int v13; // r11d
  int v14; // ebx
  int v15; // edi
  int y2; // eax
  int x2; // r9d
  int v18; // r14d
  int v19; // r12d
  int v20; // eax
  int v21; // ecx
  int v22; // r15d
  int v23; // eax
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 v27; // rbx
  __int64 v28; // rax
  int v29; // r15d
  int v30; // ebx
  unsigned int v31; // r12d
  unsigned int v32; // edi
  __int64 v33[3]; // [rsp+20h] [rbp-49h] BYREF
  int v34; // [rsp+38h] [rbp-31h]
  __int64 v35; // [rsp+40h] [rbp-29h]
  __int64 v36; // [rsp+48h] [rbp-21h]
  __int64 v37[3]; // [rsp+50h] [rbp-19h] BYREF
  int v38; // [rsp+68h] [rbp-1h]
  __int64 v39; // [rsp+70h] [rbp+7h]
  __int64 v40; // [rsp+78h] [rbp+Fh]
  int v41; // [rsp+D0h] [rbp+67h]
  Scaleform::Render::ImageData *v43; // [rsp+E0h] [rbp+77h] BYREF
  Scaleform::Render::ImageData **v44; // [rsp+E8h] [rbp+7Fh]

  v44 = psrc;
  v43 = dest;
  x1 = this->SourceRect.x1;
  pPlanes = (*psrc)->pPlanes;
  y1 = this->SourceRect.y1;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v11 = dest->pPlanes;
  v12 = this->DestPoint.x - x1;
  v13 = v11->Width;
  v14 = v11->Height;
  v15 = this->DestPoint.y - y1;
  if ( Height >= y1 )
  {
    y2 = this->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->SourceRect.x2;
      if ( x2 >= 0 && Width >= x1 )
      {
        v18 = 0;
        if ( x1 < 0 )
          x1 = 0;
        if ( Width > x2 )
          Width = this->SourceRect.x2;
        if ( y1 < 0 )
          y1 = 0;
        v19 = Width + v12;
        if ( Height > y2 )
          Height = this->SourceRect.y2;
        v20 = x1 + v12;
        v21 = y1 + v15;
        v22 = Height + v15;
        if ( Height + v15 >= 0 && v14 >= v21 && v13 >= v20 && v19 >= 0 )
        {
          if ( v20 > 0 )
            v18 = v20;
          if ( v19 > v13 )
            v19 = v13;
          v23 = 0;
          if ( v21 > 0 )
            v23 = y1 + v15;
          if ( v22 > v14 )
            v22 = v14;
          v41 = v23;
          v24 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
          v25 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 120i64))(v24);
          v37[1] = 0i64;
          v38 = 0;
          v39 = 0i64;
          v37[2] = (__int64)v43;
          v40 = 0i64;
          v37[0] = v25;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v25 + 8i64))(v25, v37);
          v26 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
          v27 = (__int64)*v44;
          v28 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 120i64))(v26);
          v33[2] = v27;
          v33[1] = 0i64;
          v34 = 0;
          v35 = 0i64;
          v36 = 0i64;
          v33[0] = v28;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v28 + 8i64))(v28, v33);
          v29 = v22 - 1;
          if ( v29 >= v41 )
          {
            v30 = v19 - 1;
            LODWORD(v44) = v19 - 1;
            v31 = v29 - v15;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v37[0] + 16i64))(
                v37[0],
                v37,
                (unsigned int)v29);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v33[0] + 16i64))(v33[0], v33, v31);
              if ( v30 >= v18 )
              {
                v32 = v30 - v12;
                do
                {
                  (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD))(*(_QWORD *)v33[0] + 40i64))(
                    v33[0],
                    &v43,
                    v33,
                    v32);
                  if ( !this->pSource.pObject->Transparent || !this->pImage.pObject->Transparent )
                    BYTE3(v43) = -1;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v37[0] + 24i64))(
                    v37[0],
                    v37,
                    (unsigned int)v30--,
                    (unsigned int)v43);
                  --v32;
                }
                while ( v30 >= v18 );
              }
              v30 = (int)v44;
              --v29;
              --v31;
            }
            while ( v29 >= v41 );
          }
        }
      }
    }
  }
}

// File Line: 1037
// RVA: 0x9777F0
void __fastcall Scaleform::Render::DICommand_SetPixel32::ExecuteSW(
        Scaleform::Render::DICommand_SetPixel32 *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8[3]; // [rsp+20h] [rbp-38h] BYREF
  int v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  __int64 v11; // [rsp+48h] [rbp-10h]
  char v12; // [rsp+68h] [rbp+10h] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v8[2] = (__int64)dest;
  v8[1] = 0i64;
  v9 = 0;
  v10 = 0i64;
  v11 = 0i64;
  v8[0] = v7;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v8);
  (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v8[0] + 16i64))(v8[0], v8, this->Y);
  if ( !this->OverwriteAlpha )
    (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v8[0] + 40i64))(v8[0], &v12, v8, this->X);
  (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v8[0] + 24i64))(v8[0], v8, this->X);
}

// File Line: 1047
// RVA: 0x9778B0
void __fastcall Scaleform::Render::DICommand_SetPixels::ExecuteSW(
        Scaleform::Render::DICommand_SetPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // esi
  int y1; // ebp
  int x1; // edi
  unsigned int v11; // eax
  bool *Result; // rax
  bool *v13; // rax
  __int64 v14[3]; // [rsp+20h] [rbp-38h] BYREF
  int v15; // [rsp+38h] [rbp-20h]
  __int64 v16; // [rsp+40h] [rbp-18h]
  __int64 v17; // [rsp+48h] [rbp-10h]

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v8 = 0;
  v14[2] = (__int64)dest;
  v14[1] = 0i64;
  v15 = 0;
  v16 = 0i64;
  v14[0] = v7;
  v17 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, v14);
  y1 = this->DestRect.y1;
  if ( y1 >= this->DestRect.y2 )
  {
LABEL_6:
    Result = this->Result;
    if ( Result )
      *Result = 1;
  }
  else
  {
    while ( 1 )
    {
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v14[0] + 16i64))(v14[0], v14, (unsigned int)y1);
      x1 = this->DestRect.x1;
      if ( x1 < this->DestRect.x2 )
        break;
LABEL_5:
      if ( ++y1 >= this->DestRect.y2 )
        goto LABEL_6;
    }
    while ( v8 < this->Provider->vfptr->GetLength(this->Provider) )
    {
      v11 = this->Provider->vfptr->ReadNextPixel(this->Provider);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v14[0] + 24i64))(
        v14[0],
        v14,
        (unsigned int)x1++,
        v11);
      ++v8;
      if ( x1 >= this->DestRect.x2 )
        goto LABEL_5;
    }
    v13 = this->Result;
    if ( v13 )
      *v13 = 0;
  }
}

// File Line: 1070
// RVA: 0x9779C0
void __fastcall Scaleform::Render::DICommand_Threshold::ExecuteSW(
        Scaleform::Render::DICommand_Threshold *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // rax
  signed int Width; // edi
  int Height; // esi
  Scaleform::Render::ImagePlane *v9; // rax
  int y1; // ecx
  int v11; // r11d
  int v12; // r10d
  int x1; // eax
  int v14; // r14d
  int v16; // r15d
  int y2; // edx
  int x2; // r8d
  int v20; // edx
  int v21; // r15d
  int v22; // r8d
  int v23; // eax
  int v24; // ecx
  int v25; // r14d
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rsi
  __int64 v29; // rax
  __int64 v30; // rdi
  __int64 v31; // rax
  int v32; // r13d
  int v33; // r12d
  int v34; // edi
  int v35; // edi
  unsigned int Mask; // r8d
  unsigned int v37; // edx
  bool v38; // r9
  unsigned int v39; // r8d
  char v40; // cl
  __int64 ThresholdColor; // r9
  int v42; // [rsp+20h] [rbp-59h]
  int v43; // [rsp+24h] [rbp-55h]
  __int64 v44[3]; // [rsp+28h] [rbp-51h] BYREF
  int v45; // [rsp+40h] [rbp-39h]
  __int64 v46; // [rsp+48h] [rbp-31h]
  __int64 v47; // [rsp+50h] [rbp-29h]
  __int64 v48[3]; // [rsp+58h] [rbp-21h] BYREF
  int v49; // [rsp+70h] [rbp-9h]
  __int64 v50; // [rsp+78h] [rbp-1h]
  __int64 v51; // [rsp+80h] [rbp+7h]
  __int64 v52; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::Render::DICommandContext *v53; // [rsp+E8h] [rbp+6Fh]
  int v54; // [rsp+F0h] [rbp+77h]
  int v55; // [rsp+F8h] [rbp+7Fh]

  v53 = context;
  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v9 = (*psrc)->pPlanes;
  y1 = this->SourceRect.y1;
  v11 = v9->Height;
  v12 = v9->Width;
  x1 = this->SourceRect.x1;
  v14 = this->DestPoint.y - y1;
  v16 = this->DestPoint.x - x1;
  v54 = v14;
  v55 = v16;
  if ( v11 >= y1 )
  {
    y2 = this->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->SourceRect.x2;
      if ( x2 >= 0 && v12 >= x1 )
      {
        v52 = 0i64;
        if ( x1 < 0 )
          x1 = v52;
        if ( v12 > x2 )
          v12 = x2;
        if ( y1 < 0 )
          y1 = v52;
        if ( v11 > y2 )
          v11 = y2;
        v20 = x1 + v16;
        v21 = v12 + v16;
        v22 = v11 + v14;
        v23 = y1 + v14;
        if ( v11 + v14 >= 0 && Height >= v23 && Width >= v20 && v21 >= 0 )
        {
          v24 = v52;
          v25 = v52;
          if ( v20 > 0 )
            v24 = v20;
          if ( v21 > Width )
            v21 = Width;
          v43 = v24;
          if ( v23 > 0 )
            v25 = v23;
          if ( v22 > Height )
            v22 = Height;
          v42 = v22;
          v26 = ((__int64 (*)(void))context->pHAL->vfptr[61].__vecDelDtor)();
          v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 120i64))(v26);
          v28 = v52;
          v48[2] = (__int64)dest;
          v48[1] = v52;
          v49 = v52;
          v50 = v52;
          v51 = v52;
          v48[0] = v27;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v27 + 8i64))(v27, v48);
          v29 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v53->pHAL->vfptr[61].__vecDelDtor)(v53->pHAL);
          v30 = (__int64)*psrc;
          v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 120i64))(v29);
          v44[1] = v28;
          v44[2] = v30;
          v45 = v28;
          v46 = v28;
          v47 = v28;
          v44[0] = v31;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v31 + 8i64))(v31, v44);
          v32 = v42;
          if ( v25 < v42 )
          {
            v33 = v55;
            v34 = -v54;
            v54 = -v54;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v48[0] + 16i64))(
                v48[0],
                v48,
                (unsigned int)v25);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v44[0] + 16i64))(
                v44[0],
                v44,
                (unsigned int)(v34 + v25));
              v35 = v43;
              if ( v43 < v21 )
              {
                do
                {
                  (*(void (__fastcall **)(__int64, __int64 *, __int64 *, _QWORD))(*(_QWORD *)v44[0] + 40i64))(
                    v44[0],
                    &v52,
                    v44,
                    (unsigned int)(v35 - v33));
                  Mask = this->Mask;
                  v37 = v52 & Mask;
                  v38 = 0;
                  v39 = this->Threshold & Mask;
                  switch ( this->Operation )
                  {
                    case Operator_LT:
                      v38 = v37 < v39;
                      break;
                    case Operator_LE:
                      v38 = v37 <= v39;
                      break;
                    case Operator_GT:
                      v38 = v37 > v39;
                      break;
                    case Operator_GE:
                      v38 = v37 >= v39;
                      break;
                    case Operator_EQ:
                      v38 = v37 == v39;
                      break;
                    case Operator_NE:
                      v38 = v37 != v39;
                      break;
                    default:
                      break;
                  }
                  v40 = BYTE3(v52);
                  if ( !this->pSource.pObject->Transparent )
                    v40 = -1;
                  BYTE3(v52) = v40;
                  if ( v38 )
                    ThresholdColor = this->ThresholdColor;
                  else
                    ThresholdColor = (unsigned int)v52;
                  if ( !this->pImage.pObject->Transparent )
                    ThresholdColor = (unsigned int)ThresholdColor | 0xFF000000;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, __int64))(*(_QWORD *)v48[0] + 24i64))(
                    v48[0],
                    v48,
                    (unsigned int)v35++,
                    ThresholdColor);
                }
                while ( v35 < v21 );
                v33 = v55;
                v32 = v42;
              }
              v34 = v54;
              ++v25;
            }
            while ( v25 < v32 );
          }
        }
      }
    }
  }
}

