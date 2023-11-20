// File Line: 45
// RVA: 0x12CD784
void __fastcall freebuf(_iobuf *stream)
{
  _iobuf *v1; // rbx

  v1 = stream;
  if ( stream->_flag & 0x83 )
  {
    if ( stream->_flag & 8 )
    {
      free(stream->_base);
      v1->_flag &= 0xFFFFFBF7;
      v1->_ptr = 0i64;
      v1->_base = 0i64;
      v1->_cnt = 0;
    }
  }
}

