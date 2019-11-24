Object subclass: Point2 [
   | xCoordinate yCoordinate |

   Point2 [
      xCoordinate := nil.
      yCoordinate := nil.
   ]
   

   x: xValue [
      (xValue isNumber)
      ifTrue: [ xCoordinate := xValue. ]
      ifFalse: [ Transcript show: 'not a number'; cr. ]
   ]

   x [
       ^xCoordinate
   ]

   
   y: yValue [
      (yValue isNumber)
      ifTrue: [ yCoordinate := yValue. ]
      ifFalse: [ Transcript show: 'not a number'; cr. ]
   ]

   y [
       ^yCoordinate
   ]


   reflect [
      |xval yval|
      xval := xCoordinate negated.
      Transcript show: 'reflect x :', xval printString, '.'; cr.
      yval := yCoordinate negated.
      Transcript show: 'reflect y :', yval printString, '.'; cr.
   ]
   
   rotate [
      |xval yval|
      xval := yCoordinate.
      Transcript show: 'rotate x :', xval printString, '.'; cr.
      yval := xCoordinate negated.
      Transcript show: 'totate y :', yval printString, '.'; cr.
   ]

   rho [
      |xval yval dist sum|
      xval := xCoordinate squared.
      yval := yCoordinate squared.
      sum := xval + yval.
      dist := sum sqrt.
      Transcript show: 'distance :', dist printString, '.'; cr.
   ]
   
   equal: pt[
      ( xCoordinate = pt x & yCoordinate = pt y )
      ifTrue: [ Transcript show: 'Object is equal.'; cr.  ]
      ifFalse: [ Transcript show: 'Object is not equal.'; cr. ]
   ]

]

Point2 subclass: Triple2 [
   | zCoordinate |

   Triple2 [
      super new.
      zCoordinate := nil.
   ]
   
   z: zValue [
      (zValue isNumber)
      ifTrue: [ zCoordinate := zValue. ]
      ifFalse: [ Transcript show: 'not a number'; cr. ]
   ]

   z [
       ^zCoordinate
   ]

   phi [
      |xval yval zval xyval val val1 val2|
      xval := xCoordinate squared.
      yval := yCoordinate squared.
      xyval := xval + yval.
      val1 := xyval sqrt.

      zval := zCoordinate squared.
      val2 := xyval + zval.
      val2 := val2 sqrt.

      val := val1 / val2.
      val := val arcSin.
      val := val radiansToDegrees.
      Transcript show: 'The angle for the positive z axis :', val printString, '.'; cr.
   ]
]

Point2 subclass: Retangle2 [
   |areaVal|
   Retangle2[
      super new.
      XupperLeft := nil.
      YupperLeft := nil.
      XlowRight := nil.
      YlowRight := nil.
      areaVal := nil.
   ]
   
   upperLeft: setPoint [
      XupperLeft := setPoint x.
      YupperLeft := setPoint y.
   ]

   lowRight: setPoint [
      XlowRight := setPoint x.
      YlowRight := setPoint y.
   ]
   
   area[
      |xval yval|
      (XlowRight = XupperLeft & YlowRight = YupperLeft)
      ifTrue:[
      ^areaVal := 0.
      ]
      ifFalse:[
      xval := XlowRight - XupperLeft.
      xval := xval abs.
      yval := YlowRight - YupperLeft.
      yval := yval abs.
      ^areaVal := xval * yval.
      ]
   ]
   
  
   equal: pt [
      (pt area = areaVal)
      ifTrue: [ Transcript show: 'Object is equal.'; cr.  ]
      ifFalse: [ Transcript show: 'Object is not equal.'; cr. ]
   ]

]
