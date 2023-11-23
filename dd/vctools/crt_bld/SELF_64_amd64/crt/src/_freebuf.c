// File Line: 45
// RVA: 0x12CD784
void __fastcall freebuf(_iobuf *stream)
{
  if ( (stream->_flag & 0x83) != 0 && (stream->_flag & 8) != 0 )
  {
    free(stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = 0i64;
    stream->_base = 0i64;
    stream->_cnt = 0;
  }
}

