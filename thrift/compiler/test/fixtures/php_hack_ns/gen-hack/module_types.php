<?hh // strict
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift enum:-
 * Status
 */
enum foo_php_ns_Status: int {
  Unknown = 0;
}

/**
 * Original thrift struct:-
 * TestStruct
 */
class foo_php_ns_TestStruct implements \IThriftStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'str_value',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'str_value' => 1,
  ];

  const type TConstructorShape = shape(
    ?'str_value' => ?string,
  );

  const int STRUCTURAL_ID = 7258556236863001185;
  /**
   * Original thrift field:-
   * 1: string str_value
   */
  public string $str_value;

  <<__Rx>>
  public function __construct(?string $str_value = null  ) {
    $this->str_value = $str_value ?? '';
  }

  <<__Rx>>
  public static function withDefaultValues(): this {
    return new static();
  }

  <<__Rx>>
  public static function fromShape(self::TConstructorShape $shape): this {
    return new static(
      Shapes::idx($shape, 'str_value'),
    );
  }

  public function getName(): string {
    return 'TestStruct';
  }

  public static function getAllStructuredAnnotations(): \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'str_value' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
      ],
    );
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }

}

