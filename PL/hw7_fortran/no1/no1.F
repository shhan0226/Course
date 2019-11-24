      program no1
      implicit none
      character*18 S
      character*3 str(6)
      integer i, j, k, l, m, n, cunt

      do i = 1, 6
        print *, 'input : '
        read *, str(i)
      end do

      cunt = 1
      print *, 'OK! GO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'

      do i = 1, 6
        do j = 1, 6
          if( i /= j ) then
            do k = 1, 6
              if( (k/=j) .and. (k/=i) )then
                do l = 1, 6
                  if( (l/=k) .and. (l/=j) .and. (l/=i) )then
                    do m = 1, 6
                if( (m/=l) .and. (m/=k) .and.(m/=j) .and. (m/=i) )then
                        do n = 1, 6
           if((n/=m).and.(n/=l).and.(n/=k).and.(n/=j).and.(n/=i) )then
                     S = str(i)//str(j)//str(k)//str(l)//str(m)//str(n)
                              print *,'count: ', cunt, S
                               call rep(S)
                              cunt = cunt + 1
                          end if
                        end do
                      end if
                    end do
                  end if
                end do
              end if
            end do
          end if
        end do
      end do
      end program
