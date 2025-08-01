<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

namespace hack_ns2;

/**
 * Original thrift service:-
 * TestService
 */
interface TestServiceAsyncIf extends \foo\hack_ns\FooHackServiceAsyncIf {
  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg)
   *   throws (1: module.ExTypedef ex);
   */
  public function ping(string $str_arg): Awaitable<int>;

  /**
   * Original thrift definition:-
   * void
   *   voidMethod();
   */
  public function voidMethod(): Awaitable<void>;
}

/**
 * Original thrift service:-
 * TestService
 */
interface TestServiceAsyncClientIf extends TestServiceAsyncIf, \foo\hack_ns\FooHackServiceAsyncClientIf {
}

/**
 * Original thrift service:-
 * TestService
 */
interface TestServiceClientIf extends \foo\hack_ns\FooHackServiceClientIf {
  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg)
   *   throws (1: module.ExTypedef ex);
   */
  public function ping(string $str_arg): Awaitable<int>;

  /**
   * Original thrift definition:-
   * void
   *   voidMethod();
   */
  public function voidMethod(): Awaitable<void>;
}

/**
 * Original thrift service:-
 * TestService
 */
trait TestServiceClientBase {
  require extends \ThriftClientBase;

  /**
   * Original thrift definition:-
   * i32
   *   ping(1: string str_arg)
   *   throws (1: module.ExTypedef ex);
   */
  public async function ping(string $str_arg): Awaitable<int> {
    return (await $this->header_ping($str_arg))[0];
  }

  public async function header_ping(string $str_arg): Awaitable<(int, ?dict<string,string>)> {
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = \hack_ns2\TestService_ping_args::fromShape(shape(
      'str_arg' => $str_arg,
    ));
    await $this->asyncHandler_->genBefore(TestServiceStaticMetadata::THRIFT_SVC_NAME, "ping", $args);
    $currentseqid = $this->sendImplHelper($args, "ping", false, TestServiceStaticMetadata::THRIFT_SVC_NAME );
    return await $this->genAwaitResponse(\hack_ns2\TestService_ping_result::class, "ping", false, $currentseqid, $rpc_options);
  }

  /**
   * Original thrift definition:-
   * void
   *   voidMethod();
   */
  public async function voidMethod(): Awaitable<void> {
    await $this->header_voidMethod();
  }

  public async function header_voidMethod(): Awaitable<?dict<string,string>> {
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = \hack_ns2\TestService_voidMethod_args::withDefaultValues();
    await $this->asyncHandler_->genBefore(TestServiceStaticMetadata::THRIFT_SVC_NAME, "voidMethod", $args);
    $currentseqid = $this->sendImplHelper($args, "voidMethod", false, TestServiceStaticMetadata::THRIFT_SVC_NAME );
    return (await $this->genAwaitResponse(\hack_ns2\TestService_voidMethod_result::class, "voidMethod", true, $currentseqid, $rpc_options))[1];
  }

}

class TestServiceAsyncClient extends \foo\hack_ns\FooHackServiceAsyncClient implements TestServiceAsyncClientIf {
  use TestServiceClientBase;

  const string THRIFT_SVC_NAME = TestServiceStaticMetadata::THRIFT_SVC_NAME;

}

class TestServiceClient extends \foo\hack_ns\FooHackServiceClient implements TestServiceClientIf {
  use TestServiceClientBase;

  const string THRIFT_SVC_NAME = TestServiceStaticMetadata::THRIFT_SVC_NAME;

}

abstract class TestServiceAsyncProcessorBase extends \foo\hack_ns\FooHackServiceAsyncProcessorBase {
  use \GetThriftServiceMetadata;
  abstract const type TThriftIf as TestServiceAsyncIf;
  const classname<\IThriftServiceStaticMetadata> SERVICE_METADATA_CLASS = TestServiceStaticMetadata::class;
  const string THRIFT_SVC_NAME = TestServiceStaticMetadata::THRIFT_SVC_NAME;

  protected async function process_ping(int $seqid, \TProtocol $input, \TProtocol $output): Awaitable<void> {
    $handler_ctx = $this->eventHandler_->getHandlerContext('ping');
    $reply_type = \TMessageType::REPLY;
    $args = $this->readHelper(\hack_ns2\TestService_ping_args::class, $input, 'ping', $handler_ctx);
    $result = \hack_ns2\TestService_ping_result::withDefaultValues();
    try {
      $this->eventHandler_->preExec($handler_ctx, '\hack_ns2\TestService', 'ping', $args);
      $result->success = await $this->handler->ping($args->str_arg);
      $this->eventHandler_->postExec($handler_ctx, 'ping', $result);
    } catch (\Exception $ex) {
      if ($result->setException($ex)) {
        $this->eventHandler_->handlerException($handler_ctx, 'ping', $ex);
      } else {
        $reply_type = \TMessageType::EXCEPTION;
        $this->eventHandler_->handlerError($handler_ctx, 'ping', $ex);
        $result = new \TApplicationException($ex->getMessage()."\n".$ex->getTraceAsString());
      }
    }
    $this->writeHelper($result, 'ping', $seqid, $handler_ctx, $output, $reply_type);
  }
  protected async function process_voidMethod(int $seqid, \TProtocol $input, \TProtocol $output): Awaitable<void> {
    $handler_ctx = $this->eventHandler_->getHandlerContext('voidMethod');
    $reply_type = \TMessageType::REPLY;
    $args = $this->readHelper(\hack_ns2\TestService_voidMethod_args::class, $input, 'voidMethod', $handler_ctx);
    $result = \hack_ns2\TestService_voidMethod_result::withDefaultValues();
    try {
      $this->eventHandler_->preExec($handler_ctx, '\hack_ns2\TestService', 'voidMethod', $args);
      await $this->handler->voidMethod();
      $this->eventHandler_->postExec($handler_ctx, 'voidMethod', $result);
    } catch (\Exception $ex) {
      $reply_type = \TMessageType::EXCEPTION;
      $this->eventHandler_->handlerError($handler_ctx, 'voidMethod', $ex);
      $result = new \TApplicationException($ex->getMessage()."\n".$ex->getTraceAsString());
    }
    $this->writeHelper($result, 'voidMethod', $seqid, $handler_ctx, $output, $reply_type);
  }
  protected async function process_getThriftServiceMetadata(int $seqid, \TProtocol $input, \TProtocol $output): Awaitable<void> {
    $this->process_getThriftServiceMetadataHelper($seqid, $input, $output, TestServiceStaticMetadata::class);
  }
}
class TestServiceAsyncProcessor extends TestServiceAsyncProcessorBase {
  const type TThriftIf = TestServiceAsyncIf;
}

// HELPER FUNCTIONS AND STRUCTURES

class TestService_ping_args implements \IThriftSyncStruct, \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
    1 => shape(
      'var' => 'str_arg',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'str_arg' => 1,
  ];

  const type TConstructorShape = shape(
    ?'str_arg' => ?string,
  );

  const int STRUCTURAL_ID = 5542358918184482101;
  public string $str_arg;

  public function __construct(?string $str_arg = null)[] {
    $this->str_arg = $str_arg ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'str_arg'),
    );
  }

  public function getName()[]: string {
    return 'TestService_ping_args';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module2.ping_args",
        "fields" => vec[
          \tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "str_arg",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

class TestService_ping_result extends \ThriftSyncStructWithResult implements \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const type TResult = int;

  const \ThriftStructTypes::TSpec SPEC = dict[
    0 => shape(
      'var' => 'success',
      'type' => \TType::I32,
    ),
    1 => shape(
      'var' => 'ex',
      'type' => \TType::STRUCT,
      'class' => \foo\hack_ns\FooException::class,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'success' => 0,
    'ex' => 1,
  ];

  const type TConstructorShape = shape(
    ?'success' => ?this::TResult,
    ?'ex' => ?\foo\hack_ns\ExTypedef,
  );

  const int STRUCTURAL_ID = 8023834040554497270;
  public ?this::TResult $success;
  public ?\foo\hack_ns\ExTypedef $ex;

  public function __construct(?this::TResult $success = null, ?\foo\hack_ns\ExTypedef $ex = null)[] {
    $this->success = $success;
    $this->ex = $ex;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'success'),
      Shapes::idx($shape, 'ex'),
    );
  }

  public function getName()[]: string {
    return 'TestService_ping_result';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module2.TestService_ping_result",
        "fields" => vec[
          \tmeta_ThriftField::fromShape(
            shape(
              "id" => 0,
              "type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "success",
            )
          ),
          \tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_typedef" => \tmeta_ThriftTypedefType::fromShape(
                    shape(
                      "name" => "module.ExTypedef",
                      "underlyingType" => \tmeta_ThriftType::fromShape(
                        shape(
                          "t_struct" => \tmeta_ThriftStructType::fromShape(
                            shape(
                              "name" => "module.FooException",
                            )
                          ),
                        )
                      ),
                    )
                  ),
                )
              ),
              "name" => "ex",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function checkForException(): ?\TException {
    if ($this->ex !== null) {
      return $this->ex;
    }
    return null;
  }
  
  public function setException(\Exception $e): bool {
    if ($e is \foo\hack_ns\FooException) {
      $this->ex = $e;
      return true;
    }
    return false;
  }
}

class TestService_voidMethod_args implements \IThriftSyncStruct, \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct()[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'TestService_voidMethod_args';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module2.voidMethod_args",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

class TestService_voidMethod_result extends \ThriftSyncStructWithoutResult implements \IThriftStructMetadata {
  use \ThriftSerializationTrait;

  const \ThriftStructTypes::TSpec SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct()[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'TestService_voidMethod_result';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module2.TestService_voidMethod_result",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

class TestServiceStaticMetadata implements \IThriftServiceStaticMetadata {
  const string THRIFT_SVC_NAME = 'TestService';

  public static function getServiceMetadata()[]: \tmeta_ThriftService {
    return \tmeta_ThriftService::fromShape(
      shape(
        "name" => "module2.TestService",
        "functions" => vec[
          \tmeta_ThriftFunction::fromShape(
            shape(
              "name" => "ping",
              "return_type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "arguments" => vec[
                \tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 1,
                    "type" => \tmeta_ThriftType::fromShape(
                      shape(
                        "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                      )
                    ),
                    "name" => "str_arg",
                  )
                ),
              ],
              "exceptions" => vec[
                \tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 1,
                    "type" => \tmeta_ThriftType::fromShape(
                      shape(
                        "t_typedef" => \tmeta_ThriftTypedefType::fromShape(
                          shape(
                            "name" => "module.ExTypedef",
                            "underlyingType" => \tmeta_ThriftType::fromShape(
                              shape(
                                "t_struct" => \tmeta_ThriftStructType::fromShape(
                                  shape(
                                    "name" => "module.FooException",
                                  )
                                ),
                              )
                            ),
                          )
                        ),
                      )
                    ),
                    "name" => "ex",
                  )
                ),
              ],
            )
          ),
          \tmeta_ThriftFunction::fromShape(
            shape(
              "name" => "voidMethod",
              "return_type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_VOID_TYPE,
                )
              ),
            )
          ),
        ],
        "parent" => "module.FooHackService",
      )
    );
  }

  public static function getServiceMetadataResponse()[]: \tmeta_ThriftServiceMetadataResponse {
    return \tmeta_ThriftServiceMetadataResponse::fromShape(
      shape(
        'context' => \tmeta_ThriftServiceContext::fromShape(
          shape(
            'service_info' => self::getServiceMetadata(),
            'module' => \tmeta_ThriftModuleContext::fromShape(
              shape(
                'name' => 'module2',
              )
            ),
          )
        ),
        'metadata' => \tmeta_ThriftMetadata::fromShape(
          shape(
            'enums' => dict[
            ],
            'structs' => dict[
            ],
            'exceptions' => dict[
              'module.FooException' => \foo\hack_ns\FooException::getExceptionMetadata(),
            ],
            'services' => dict[
              'module.FooHackService' => \foo\hack_ns\FooHackServiceStaticMetadata::getServiceMetadata(),
            ],
          )
        ),
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TServiceAnnotations {
    return shape(
      'service' => dict[],
      'functions' => dict[
        'ping' => dict[
          '\facebook\thrift\annotation\hack\GenerateClientMethodsWithHeaders' => \facebook\thrift\annotation\hack\GenerateClientMethodsWithHeaders::fromShape(
            shape(
            )
          ),
        ],
        'voidMethod' => dict[
          '\facebook\thrift\annotation\hack\GenerateClientMethodsWithHeaders' => \facebook\thrift\annotation\hack\GenerateClientMethodsWithHeaders::fromShape(
            shape(
            )
          ),
        ],
      ],
    );
  }
}

