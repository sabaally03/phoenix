void OUT(void)
{
  set_bits();
  biggest();

  if (ro || ri)
  {
    while ((big_sensor_num < 8) && ( big_sensor_num >= 0))
    {

      biggest();
      set_bits();

      if (fo || fi)
      {
        if (fo) Move(9);
        else if (fi)
        {
          while (!fo)
          {

            set_bits();
            Move(9);
          }
        }
      }
      else if (bo || bi)
      {
        if (bo) Move(15);
        else if (bi)
        {
          while (!bo)
          {

            set_bits();
            Move(15);
          }
        }
      }
      else if (ro)
      {
        Move(12);
      }
      else if (ri)
      {
        while (!ro)
        {
          set_bits();
          Move(12);
        }
      }
      else
        STOP();
    }

    ////////////////////////////////////////// Khareje While /////////////////////////////////////////////////
   
    if (fo || fi)
    {
      if (fo) Move(9);
      else if (fi)
      {
        while (!fo)
        {
          set_bits();
          Move(9);
        }
      }
    }
    else if (bo || bi)
    {
      if (bo) Move(15);
      else if (bi)
      {
        while (!bo)
        {
          set_bits();
          Move(15);
        }
      }
    }
    else if (ro)
    {
      Move(12);
    }
    else if (ri)
    {
      while (!ro)
      {
        set_bits();
        Move(12);

      }
    }
    else STOP();

  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (lo || li)
  {

    while (big_sensor_num > 8 && big_sensor_num < 16)
    {
      biggest();
      set_bits();

      if (fo || fi)
      {
        if (fo) {
          Move(7);
        }
        else if (fi)
        {
          while (!fo)
          {
            set_bits();
            Move(7);
          }
        }
      }
      else if (bo || bi)
      {
        if (bo) Move(1);
        else if (bi)
        {
          while (!bo)
          {
            set_bits();
            Move(1);
          }
        }
      }
      else if (lo)
      {
        Move(4);
      }
      else if (li)
      {
        while (!lo)
        {
          set_bits();
          Move(4);
        }
      }
      else STOP();
    }
    /////////////////////////////////////////////////////////////////////
   
    if (fo|| fi)
    {
      if (fo) Move(7);
      else if (fi)
      {
        while (!fo)
        {
          set_bits();
          Move(7);
        }
      }
    }
   
    else if (bo || bi)
    {
      if (bo) Move(1);
      else if (bi)
      {
        while (!bo)
        {
          set_bits();
          Move(1);
        }
      }
    }
  else if (lo)
    {
      Move(4);
    }
    else if(li)
    {
      while (!lo)
      {
        set_bits();
        Move(4);

      }
    }
    else STOP();
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (fo || fi)
  {
    while (big_sensor_num > 11 || big_sensor_num < 5)
    {
      biggest();
      set_bits();
      
       if (ro || ri)
      {
        if (ro) Move(9);
        else if (ri)
        {
          while (!ro )
          {
            set_bits();
            Move(9);

          }
        }
      }
      else if (lo || li)
      {
        if (lo) Move(7);
        else if (li)
        {
          while (!lo)
          {
            set_bits();
            Move(7);
          }
        }
      }
      else if (fo)
      {
        Move(8);
      }
      else if (fi)
      {
        while (!fo)
        {
          set_bits();
          Move(8);
        }
      }
      else STOP();
    }
    ///////////////////////////////////////////////////////////////////////
   
     if (ro || ri)
    {
      if (ro) Move(9);
      else if (ri)
      {
        while (!ro)
        {
          set_bits();
          Move(9);

        }
      }
    }
    else if (lo || li)
    {
      if (lo) Move(7);
      else if (li)
      {
        while (!lo)
        {
          set_bits();
          Move(7);
        }
      }
    } 
    else if (fo)
    {
      Move(8);
    }
    else if (fi)
    {
      while (!fo)
      {
        set_bits();
        Move(8);

      }
    }
    else STOP();
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (bo|| bi)
  {
    while (big_sensor_num < 13 && big_sensor_num > 3)
    {
      biggest();
      set_bits();
  
       if (ro || ri)
      {
        if (ro) Move(15);
        else if (ri)
        {
          while (!ro)
          {
            set_bits();
            Move(15);

          }
        }
      }
      else if (lo || li)
      {
        if (lo) Move(1);
        else if (li)
        {
          while (!lo)
          {
            set_bits();
            Move(1);

          }
        }
      }
        else if (bo)
      {
        Move(0);
      }
      else if (bi)
      {
        while (!bo)
        {
          set_bits();
          Move(0);

        }
      }
      else STOP();
    }
    ////////////////////////////////////////////////////////////////
  
    if (ro || ri)
    {
      if (ro) Move(15);
      else if (ri)
      {
        while (!ro)
        {
          set_bits();
          Move(15);

        }
      }
    }
    else if (lo || li)
    {
      if (lo) Move(1);
      else if (li)
      {
        while (!lo)
        {
          set_bits();
          Move(1);

        }
      }
    } 
    else if (bo)
    {
      Move(0);
    }
    else if (bi)
    {
      while (!bo)
      {
        set_bits();
        Move(0);

      }
    }
    else STOP();
  }

  else
  {
 follow();
  }


}
