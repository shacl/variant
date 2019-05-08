list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE
  ".*catch.*"
  ".*test.*"
  ".*c[+][+]"
  ".*shacl/trait.*hpp"
  ".*boost.*"
  ".*mpark.*")

list(APPEND CTEST_EXTRA_COVERAGE_GLOB ".*shacl/variant.*hpp")

list(APPEND CTEST_CUSTOM_TESTS_IGNORE
  "example.accessors"
  "example.adapt_adt"
  "example.adapt_struct"
  "example.adjust"
  "example.adjust_if"
  "example.all"
  "example.all_of"
  "example.and"
  "example.any"
  "example.any_of"
  "example.ap"
  "example.append"
  "example.at"
  "example.at_c"
  "example.at_key"
  "example.back"
  "example.basic_tuple.make"
  "example.cartesian_product"
  "example.chain"
  "example.comparing"
  "example.concat"
  "example.contains"
  "example.core.common.common"
  "example.core.common.common_t"
  "example.core.common.has_common"
  "example.core.convert.embedding"
  "example.core.convert.is_convertible"
  "example.core.convert.is_embedded"
  "example.core.convert.to"
  "example.core.default"
  "example.core.is_a"
  "example.core.make"
  "example.core.tag_of"
  "example.core.tag_of_t"
  "example.core.when"
  "example.core.when_valid"
  "example.count"
  "example.count_if"
  "example.cppcon_2014.comparable"
  "example.cppcon_2014.det"
  "example.cppcon_2014.functor"
  "example.cppcon_2014.matrix"
  "example.cppcon_2014.ring"
  "example.cycle"
  "example.define_struct"
  "example.detail.wrong"
  "example.div"
  "example.drop_back"
  "example.drop_front"
  "example.drop_front_exactly"
  "example.drop_while"
  "example.duplicate"
  "example.empty"
  "example.equal"
  "example.eval"
  "example.eval_if"
  "example.ext.std.array.comparable"
  "example.ext.std.array.foldable"
  "example.ext.std.array.iterable"
  "example.ext.std.array.orderable"
  "example.ext.std.integer_sequence.comparable"
  "example.ext.std.integer_sequence.foldable"
  "example.ext.std.integer_sequence.iterable"
  "example.ext.std.integer_sequence.searchable"
  "example.ext.std.integral_constant"
  "example.ext.std.pair"
  "example.ext.std.ratio.arithmetic"
  "example.ext.std.ratio.comparable"
  "example.ext.std.ratio.orderable"
  "example.ext.std.tuple"
  "example.extend"
  "example.extract"
  "example.fill"
  "example.filter"
  "example.find"
  "example.find_if"
  "example.first"
  "example.flatten"
  "example.fold"
  "example.fold_left"
  "example.fold_right"
  "example.foldable.to"
  "example.for_each"
  "example.front"
  "example.functional.always"
  "example.functional.apply"
  "example.functional.arg"
  "example.functional.capture"
  "example.functional.compose"
  "example.functional.curry"
  "example.functional.demux"
  "example.functional.fix"
  "example.functional.flip"
  "example.functional.id"
  "example.functional.infix"
  "example.functional.iterate"
  "example.functional.lockstep"
  "example.functional.on"
  "example.functional.overload"
  "example.functional.overload_linearly"
  "example.functional.partial"
  "example.functional.placeholder"
  "example.functional.reverse_partial"
  "example.fuse"
  "example.greater"
  "example.greater_equal"
  "example.group"
  "example.hash"
  "example.if"
  "example.in"
  "example.index_if"
  "example.insert"
  "example.insert_range"
  "example.integral_constant"
  "example.intersperse"
  "example.is_disjoint"
  "example.is_empty"
  "example.is_subset"
  "example.iterable.searchable"
  "example.lazy.comonad"
  "example.lazy.functor"
  "example.lazy.make"
  "example.lazy.monad"
  "example.length"
  "example.less"
  "example.less_equal"
  "example.lexicographical_compare"
  "example.lift"
  "example.map.comparable"
  "example.map.difference"
  "example.map.erase_key"
  "example.map.foldable"
  "example.map.insert"
  "example.map.intersection"
  "example.map.keys"
  "example.map.make"
  "example.map.map"
  "example.map.searchable"
  "example.map.symmetric_difference"
  "example.map.to"
  "example.map.union"
  "example.map.values"
  "example.max"
  "example.maximum"
  "example.maximum_by"
  "example.members"
  "example.min"
  "example.minimum"
  "example.minimum_by"
  "example.minus"
  "example.misc.dimensional_analysis"
  "example.misc.from_json"
  "example.misc.indexed_sort"
  "example.misc.infinite_list"
  "example.misc.infinite_set"
  "example.misc.lambda_tuple"
  "example.misc.nth"
  "example.misc.overload_linearly"
  "example.misc.printf"
  "example.misc.ref_tuple"
  "example.misc.restricted_function"
  "example.misc.tree"
  "example.mod"
  "example.monadic_compose"
  "example.monadic_fold_left"
  "example.monadic_fold_right"
  "example.mult"
  "example.negate"
  "example.none"
  "example.none_of"
  "example.not"
  "example.not_equal"
  "example.one"
  "example.optional.applicative.complex"
  "example.optional.applicative"
  "example.optional.comparable"
  "example.optional.foldable"
  "example.optional.functor"
  "example.optional.is_just"
  "example.optional.is_nothing"
  "example.optional.just"
  "example.optional.make"
  "example.optional.maybe"
  "example.optional.monad"
  "example.optional.monad_plus"
  "example.optional.nothing"
  "example.optional.orderable"
  "example.optional.searchable"
  "example.optional.sfinae"
  "example.optional.sfinae_friendly_metafunctions"
  "example.optional.value"
  "example.optional.value_or"
  "example.or"
  "example.ordering"
  "example.overview"
  "example.pair.comparable"
  "example.pair.foldable"
  "example.pair.make"
  "example.pair.orderable"
  "example.pair.product"
  "example.partition"
  "example.permutations"
  "example.plus"
  "example.power"
  "example.prefix"
  "example.prepend"
  "example.product"
  "example.product.comparable"
  "example.product.make"
  "example.range.comparable"
  "example.range.foldable"
  "example.range.iterable"
  "example.range.make"
  "example.range.range_c"
  "example.range.searchable"
  "example.remove"
  "example.remove_at"
  "example.remove_at_c"
  "example.remove_if"
  "example.remove_range"
  "example.remove_range_c"
  "example.repeat"
  "example.replace"
  "example.replace_if"
  "example.replicate"
  "example.reverse"
  "example.reverse_fold"
  "example.scan_left"
  "example.scan_right"
  "example.second"
  "example.sequence.applicative"
  "example.sequence.comparable"
  "example.sequence.foldable"
  "example.sequence.functor"
  "example.sequence.iterable"
  "example.sequence.make"
  "example.sequence.monad.ints"
  "example.sequence.monad.types"
  "example.sequence.monad_plus"
  "example.sequence.orderable"
  "example.sequence.searchable"
  "example.set.comparable"
  "example.set.difference"
  "example.set.erase_key"
  "example.set.foldable"
  "example.set.insert"
  "example.set.intersection"
  "example.set.make"
  "example.set.searchable"
  "example.set.symmetric_difference"
  "example.set.to"
  "example.set.union"
  "example.size"
  "example.slice"
  "example.slice_c"
  "example.sort"
  "example.span"
  "example.string.comparable"
  "example.string.foldable"
  "example.string.from_c_str"
  "example.string.hashable"
  "example.string.iterable"
  "example.string.literal"
  "example.string.macro"
  "example.string.make"
  "example.string.monoid"
  "example.string.orderable"
  "example.string.searchable"
  "example.string.string_c"
  "example.string.to"
  "example.struct.custom_accessor"
  "example.struct.mcd.nested"
  "example.struct.mcd.tag_dispatching"
  "example.struct.comparable"
  "example.struct.foldable"
  "example.struct.keys"
  "example.struct.searchable"
  "example.struct.to"
  "example.suffix"
  "example.sum"
  "example.take_back"
  "example.take_back_c"
  "example.take_front"
  "example.take_front_c"
  "example.take_while"
  "example.tap"
  "example.then"
  "example.transform"
  "example.tuple.foldable"
  "example.tuple.interop"
  "example.tuple.make"
  "example.tuple.tuple"
  "example.tuple.tuple_c"
  "example.tuple.tuple_t"
  "example.tutorial.algorithms"
  "example.tutorial.concepts"
  "example.tutorial.constant_side_effects"
  "example.tutorial.containers"
  "example.tutorial.ext.ratio_plus"
  "example.tutorial.include_ext"
  "example.tutorial.integral-branching"
  "example.tutorial.introspection.adapt"
  "example.tutorial.introspection"
  "example.tutorial.introspection.json"
  "example.tutorial.introspection.sfinae"
  "example.tutorial.quickstart"
  "example.tutorial.tag_dispatching"
  "example.type.alignof"
  "example.type.comparable"
  "example.type.decltype"
  "example.type.hashable"
  "example.type.integral"
  "example.type.is_valid"
  "example.type.make"
  "example.type.metafunction"
  "example.type.metafunction_class"
  "example.type.sizeof"
  "example.type.template"
  "example.type.trait"
  "example.type.typeid"
  "example.unfold_left"
  "example.unfold_right"
  "example.unique"
  "example.unpack"
  "example.value"
  "example.value_of"
  "example.version"
  "example.wandbox"
  "example.while"
  "example.zero"
  "example.zip"
  "example.zip_shortest"
  "example.zip_shortest_with"
  "example.zip_with"
  "test.issues.github_75"
  "test.assert.commas"
  "test.assert.constant"
  "test.assert.constexpr"
  "test.assert.flexible"
  "test.assert.lambdas"
  "test.assert.runtime"
  "test.basic_tuple.auto.all_of"
  "test.basic_tuple.auto.any_of"
  "test.basic_tuple.auto.ap"
  "test.basic_tuple.auto.at"
  "test.basic_tuple.auto.cartesian_product"
  "test.basic_tuple.auto.drop_back"
  "test.basic_tuple.auto.drop_front"
  "test.basic_tuple.auto.drop_while"
  "test.basic_tuple.auto.for_each"
  "test.basic_tuple.auto.group"
  "test.basic_tuple.auto.index_if"
  "test.basic_tuple.auto.insert"
  "test.basic_tuple.auto.insert_range"
  "test.basic_tuple.auto.intersperse"
  "test.basic_tuple.auto.is_empty"
  "test.basic_tuple.auto.length"
  "test.basic_tuple.auto.lexicographical_compare"
  "test.basic_tuple.auto.make"
  "test.basic_tuple.auto.none_of"
  "test.basic_tuple.auto.partition"
  "test.basic_tuple.auto.permutations"
  "test.basic_tuple.auto.remove_at"
  "test.basic_tuple.auto.remove_range"
  "test.basic_tuple.auto.reverse"
  "test.basic_tuple.auto.scans"
  "test.basic_tuple.auto.sequence"
  "test.basic_tuple.auto.slice"
  "test.basic_tuple.auto.sort"
  "test.basic_tuple.auto.span"
  "test.basic_tuple.auto.take_back"
  "test.basic_tuple.auto.take_front"
  "test.basic_tuple.auto.take_while"
  "test.basic_tuple.auto.transform"
  "test.basic_tuple.auto.unfolds"
  "test.basic_tuple.auto.unique"
  "test.basic_tuple.auto.zips"
  "test.basic_tuple.cnstr.copy"
  "test.basic_tuple.construct"
  "test.basic_tuple.laws"
  "test.basic_tuple.length"
  "test.basic_tuple.make"
  "test.basic_tuple.unpack"
  "test.builtin_array"
  "test.comparable"
  "test.concept.constant.arithmetic"
  "test.concept.constant.comparable"
  "test.concept.constant.laws"
  "test.concept.constant.logical"
  "test.concept.constant.mcd"
  "test.concept.constant.orderable"
  "test.concept.constant.to"
  "test.concept.integral_constant"
  "test.concept.sequence.iterable"
  "test.concept.sequence.monad"
  "test.concept.sequence.monad_plus"
  "test.concept.sequence.orderable"
  "test.concept.sequence.searchable"
  "test.concept.sequence.sequence"
  "test.concept.struct.any_of"
  "test.concept.struct.at_key"
  "test.concept.struct.equal"
  "test.concept.struct.find_if"
  "test.concept.struct.fold_left"
  "test.concept.struct.fold_right"
  "test.concept.struct.keys"
  "test.concept.struct.laws"
  "test.concept.struct.macro.adapt_adt"
  "test.concept.struct.macro.adapt_struct"
  "test.concept.struct.macro.define_struct"
  "test.concept.struct.member_function"
  "test.concept.struct.members"
  "test.concept.struct.unpack"
  "test.core.common"
  "test.core.default"
  "test.core.is_a"
  "test.core.is_embedded"
  "test.core.make"
  "test.core.tag_of"
  "test.core.to"
  "test.core.when"
  "test.deploy.main"
  "test.detail.algorithm"
  "test.detail.any_of"
  "test.detail.canonical_constant.laws"
  "test.detail.create"
  "test.detail.decay"
  "test.detail.ebo"
  "test.detail.fast_and"
  "test.detail.first_unsatisfied_index"
  "test.detail.has_duplicates"
  "test.detail.preprocessor"
  "test.detail.struct_macros"
  "test.detail.type_at"
  "test.detail.type_foldl1"
  "test.detail.type_foldr1"
  "test.detail.unpack_flatten"
  "test.detail.variadic.at"
  "test.detail.variadic.drop_into"
  "test.detail.variadic.foldl1"
  "test.detail.variadic.foldr1"
  "test.detail.variadic.reverse_apply"
  "test.detail.variadic.split_at"
  "test.detail.variadic.take"
  "test.euclidean_ring"
  "test.experimental.type_name"
  "test.experimental.types.at"
  "test.experimental.types.contains"
  "test.experimental.types.drop_front"
  "test.experimental.types.equal"
  "test.experimental.types.is_empty"
  "test.experimental.types.transform"
  "test.experimental.types.unpack"
  "test.experimental.view.empty.is_empty"
  "test.experimental.view.empty.length"
  "test.experimental.view.empty.unpack"
  "test.experimental.view.joined.at"
  "test.experimental.view.joined.is_empty"
  "test.experimental.view.joined.length"
  "test.experimental.view.joined.unpack"
  "test.experimental.view.single.at"
  "test.experimental.view.single.is_empty"
  "test.experimental.view.single.length"
  "test.experimental.view.single.unpack"
  "test.experimental.view.sliced.at"
  "test.experimental.view.sliced.is_empty"
  "test.experimental.view.sliced.length"
  "test.experimental.view.sliced.unpack"
  "test.experimental.view.transformed.ap"
  "test.experimental.view.transformed.at"
  "test.experimental.view.transformed.drop_front"
  "test.experimental.view.transformed.equal"
  "test.experimental.view.transformed.is_empty"
  "test.experimental.view.transformed.laziness"
  "test.experimental.view.transformed.length"
  "test.experimental.view.transformed.less"
  "test.experimental.view.transformed.transform"
  "test.experimental.view.transformed.unpack"
  "test.ext.std.array.at"
  "test.ext.std.array.comparable"
  "test.ext.std.array.foldable"
  "test.ext.std.array.issue_304"
  "test.ext.std.array.iterable"
  "test.ext.std.array.orderable"
  "test.ext.std.array.searchable"
  "test.ext.std.bugs.libcxx_19616"
  "test.ext.std.bugs.libcxx_22806"
  "test.ext.std.integer_sequence.drop_front_exactly"
  "test.ext.std.integer_sequence.equal"
  "test.ext.std.integer_sequence.find_if"
  "test.ext.std.integer_sequence.front"
  "test.ext.std.integer_sequence.is_empty"
  "test.ext.std.integer_sequence.laws"
  "test.ext.std.integer_sequence.unpack"
  "test.ext.std.integral_constant.arithmetic"
  "test.ext.std.integral_constant.comparable"
  "test.ext.std.integral_constant.constant"
  "test.ext.std.integral_constant.interop"
  "test.ext.std.integral_constant.logical"
  "test.ext.std.integral_constant.orderable"
  "test.ext.std.integral_constant.tag"
  "test.ext.std.pair.first_second"
  "test.ext.std.pair.issue_90"
  "test.ext.std.pair.laws"
  "test.ext.std.pair.make"
  "test.ext.std.ratio.div"
  "test.ext.std.ratio.equal"
  "test.ext.std.ratio.laws"
  "test.ext.std.ratio.less"
  "test.ext.std.ratio.minus"
  "test.ext.std.ratio.mod"
  "test.ext.std.ratio.mult"
  "test.ext.std.ratio.one"
  "test.ext.std.ratio.plus"
  "test.ext.std.ratio.to"
  "test.ext.std.ratio.zero"
  "test.ext.std.tuple.auto.all_of"
  "test.ext.std.tuple.auto.any_of"
  "test.ext.std.tuple.auto.ap"
  "test.ext.std.tuple.auto.at"
  "test.ext.std.tuple.auto.cartesian_product"
  "test.ext.std.tuple.auto.drop_back"
  "test.ext.std.tuple.auto.drop_front"
  "test.ext.std.tuple.auto.drop_while"
  "test.ext.std.tuple.auto.for_each"
  "test.ext.std.tuple.auto.group"
  "test.ext.std.tuple.auto.index_if"
  "test.ext.std.tuple.auto.insert"
  "test.ext.std.tuple.auto.insert_range"
  "test.ext.std.tuple.auto.intersperse"
  "test.ext.std.tuple.auto.is_empty"
  "test.ext.std.tuple.auto.length"
  "test.ext.std.tuple.auto.lexicographical_compare"
  "test.ext.std.tuple.auto.make"
  "test.ext.std.tuple.auto.none_of"
  "test.ext.std.tuple.auto.partition"
  "test.ext.std.tuple.auto.permutations"
  "test.ext.std.tuple.auto.remove_at"
  "test.ext.std.tuple.auto.remove_range"
  "test.ext.std.tuple.auto.reverse"
  "test.ext.std.tuple.auto.scans"
  "test.ext.std.tuple.auto.sequence"
  "test.ext.std.tuple.auto.slice"
  "test.ext.std.tuple.auto.sort"
  "test.ext.std.tuple.auto.span"
  "test.ext.std.tuple.auto.take_back"
  "test.ext.std.tuple.auto.take_front"
  "test.ext.std.tuple.auto.take_while"
  "test.ext.std.tuple.auto.transform"
  "test.ext.std.tuple.auto.unfolds"
  "test.ext.std.tuple.auto.unique"
  "test.ext.std.tuple.auto.zips"
  "test.ext.std.tuple.issue_90"
  "test.ext.std.tuple.laws"
  "test.ext.std.tuple.laws.functor"
  "test.ext.std.tuple.laws.searchable"
  "test.ext.std.vector"
  "test.fold_left.ref"
  "test.fold_right.ref"
  "test.foldable.fold_left_mcd.iterable"
  "test.foldable.fold_left_mcd.monad"
  "test.foldable.fold_left_mcd.monad_plus"
  "test.foldable.fold_left_mcd.orderable"
  "test.foldable.fold_left_mcd.searchable"
  "test.foldable.fold_left_mcd.sequence"
  "test.foldable.iterable_mcd.iterable"
  "test.foldable.iterable_mcd.monad"
  "test.foldable.iterable_mcd.monad_plus"
  "test.foldable.iterable_mcd.orderable"
  "test.foldable.iterable_mcd.searchable"
  "test.foldable.iterable_mcd.sequence"
  "test.foldable.unpack_mcd.iterable"
  "test.foldable.unpack_mcd.monad"
  "test.foldable.unpack_mcd.monad_plus"
  "test.foldable.unpack_mcd.orderable"
  "test.foldable.unpack_mcd.searchable"
  "test.foldable.unpack_mcd.sequence"
  "test.functional"
  "test.functional.apply"
  "test.functional.capture"
  "test.functional.demux"
  "test.functional.fix"
  "test.functional.iterate"
  "test.functional.lockstep"
  "test.functional.overload_linearly"
  "test.functional.partial"
  "test.functional.placeholder"
  "test.functional.reverse_partial"
  "test.group"
  "test.identity.applicative.full_mcd"
  "test.identity.applicative.monad_mcd"
  "test.identity.functor.adjust_mcd"
  "test.identity.functor.transform_mcd"
  "test.identity.monad.chain_mcd"
  "test.identity.monad.flatten_mcd"
  "test.if_.non_copyable"
  "test.index_if"
  "test.integral_constant.arithmetic"
  "test.integral_constant.comparable"
  "test.integral_constant.constant"
  "test.integral_constant.constexpr_init"
  "test.integral_constant.github_354"
  "test.integral_constant.hash"
  "test.integral_constant.hashable"
  "test.integral_constant.logical"
  "test.integral_constant.operators"
  "test.integral_constant.orderable"
  "test.integral_constant.std_api"
  "test.integral_constant.tag"
  "test.integral_constant.times"
  "test.integral_constant.udl"
  "test.issues.clang_20046"
  "test.issues.github_112"
  "test.issues.github_113"
  "test.issues.github_149"
  "test.issues.github_15"
  "test.issues.github_165"
  "test.issues.github_202"
  "test.issues.github_221"
  "test.issues.github_234"
  "test.issues.github_252"
  "test.issues.github_260"
  "test.issues.github_266"
  "test.issues.github_269"
  "test.issues.github_297"
  "test.issues.github_31"
  "test.issues.github_331"
  "test.issues.github_362"
  "test.issues.github_365"
  "test.issues.github_91"
  "test.lazy"
  "test.logical"
  "test.map.any_of"
  "test.map.assign.copy"
  "test.map.assign.move"
  "test.map.at_key.collisions"
  "test.map.at_key"
  "test.map.at_key.ref"
  "test.map.at_key.stackoverflow"
  "test.map.cnstr.copy"
  "test.map.cnstr.default"
  "test.map.cnstr.move"
  "test.map.cnstr.trap"
  "test.map.cnstr.variadic"
  "test.map.contains"
  "test.map.difference"
  "test.map.equal"
  "test.map.erase_key"
  "test.map.find_if"
  "test.map.fold_left"
  "test.map.fold_right"
  "test.map.insert"
  "test.map.intersection"
  "test.map.is_subset"
  "test.map.keys"
  "test.map.laws"
  "test.map.map"
  "test.map.symmetric_difference"
  "test.map.to"
  "test.map.union"
  "test.map.unpack"
  "test.map.values"
  "test.minimal_product"
  "test.monoid"
  "test.numeric.minus_mcd"
  "test.numeric.negate_mcd"
  "test.optional.any_of"
  "test.optional.ap"
  "test.optional.chain"
  "test.optional.concat"
  "test.optional.copy.trap_construct"
  "test.optional.empty"
  "test.optional.equal"
  "test.optional.find_if"
  "test.optional.flatten"
  "test.optional.fold_left"
  "test.optional.fold_right"
  "test.optional.is_just"
  "test.optional.is_nothing"
  "test.optional.laws"
  "test.optional.less"
  "test.optional.lift"
  "test.optional.make"
  "test.optional.maybe"
  "test.optional.nested_type"
  "test.optional.operator_arrow"
  "test.optional.operator_deref"
  "test.optional.representation"
  "test.optional.sfinae"
  "test.optional.transform"
  "test.optional.unpack"
  "test.optional.value"
  "test.optional.value_or"
  "test.orderable"
  "test.pair.assign.copy"
  "test.pair.assign.move"
  "test.pair.cnstr.copy"
  "test.pair.cnstr.default"
  "test.pair.cnstr.memberwise"
  "test.pair.cnstr.move"
  "test.pair.comparable"
  "test.pair.empty_storage"
  "test.pair.foldable"
  "test.pair.issue_90"
  "test.pair.make"
  "test.pair.orderable"
  "test.pair.product"
  "test.pair.tag_of"
  "test.range.at"
  "test.range.back"
  "test.range.contains"
  "test.range.drop_front"
  "test.range.drop_front_exactly"
  "test.range.equal"
  "test.range.find"
  "test.range.front"
  "test.range.is_empty"
  "test.range.laws"
  "test.range.length"
  "test.range.make"
  "test.range.maximum"
  "test.range.minimum"
  "test.range.product"
  "test.range.range_c"
  "test.range.sum"
  "test.range.unpack"
  "test.repeat"
  "test.ring"
  "test.searchable"
  "test.set.any_of"
  "test.set.cnstr.copy"
  "test.set.cnstr.default"
  "test.set.cnstr.move"
  "test.set.cnstr.trap"
  "test.set.difference"
  "test.set.equal"
  "test.set.erase_key"
  "test.set.find_if"
  "test.set.insert"
  "test.set.intersection"
  "test.set.is_subset"
  "test.set.laws"
  "test.set.make"
  "test.set.symmetric_difference"
  "test.set.to"
  "test.set.union"
  "test.set.unpack"
  "test.string.any_of"
  "test.string.at"
  "test.string.c_str"
  "test.string.cnstr.c_str"
  "test.string.cnstr.copy"
  "test.string.cnstr.default"
  "test.string.contains"
  "test.string.drop_front_exactly"
  "test.string.equal"
  "test.string.find"
  "test.string.find_if"
  "test.string.front"
  "test.string.hash"
  "test.string.is_empty"
  "test.string.laws"
  "test.string.length"
  "test.string.less"
  "test.string.macro"
  "test.string.make"
  "test.string.plus"
  "test.string.to"
  "test.string.udl"
  "test.string.unpack"
  "test.string.zero"
  "test.tuple.any_of.clang_ice"
  "test.tuple.assign.convert_copy"
  "test.tuple.assign.convert_move"
  "test.tuple.assign.copy"
  "test.tuple.assign.move"
  "test.tuple.at.const"
  "test.tuple.at.non_const"
  "test.tuple.at.rv"
  "test.tuple.auto.all_of"
  "test.tuple.auto.any_of"
  "test.tuple.auto.ap"
  "test.tuple.auto.at"
  "test.tuple.auto.cartesian_product"
  "test.tuple.auto.drop_back"
  "test.tuple.auto.drop_front"
  "test.tuple.auto.drop_while"
  "test.tuple.auto.for_each"
  "test.tuple.auto.group"
  "test.tuple.auto.index_if"
  "test.tuple.auto.insert"
  "test.tuple.auto.insert_range"
  "test.tuple.auto.intersperse"
  "test.tuple.auto.is_empty"
  "test.tuple.auto.length"
  "test.tuple.auto.lexicographical_compare"
  "test.tuple.auto.make"
  "test.tuple.auto.none_of"
  "test.tuple.auto.partition"
  "test.tuple.auto.permutations"
  "test.tuple.auto.remove_at"
  "test.tuple.auto.remove_range"
  "test.tuple.auto.reverse"
  "test.tuple.auto.scans"
  "test.tuple.auto.sequence"
  "test.tuple.auto.slice"
  "test.tuple.auto.sort"
  "test.tuple.auto.span"
  "test.tuple.auto.take_back"
  "test.tuple.auto.take_front"
  "test.tuple.auto.take_while"
  "test.tuple.auto.transform"
  "test.tuple.auto.unfolds"
  "test.tuple.auto.unique"
  "test.tuple.auto.zips"
  "test.tuple.cnstr.convert_copy"
  "test.tuple.cnstr.convert_move"
  "test.tuple.cnstr.copy"
  "test.tuple.cnstr.default"
  "test.tuple.cnstr.move"
  "test.tuple.cnstr.nested"
  "test.tuple.cnstr.trap"
  "test.tuple.cnstr.variadic_array"
  "test.tuple.cnstr.variadic_copy"
  "test.tuple.cnstr.variadic_forward"
  "test.tuple.empty_member"
  "test.tuple.hold_refs"
  "test.tuple.issue_90"
  "test.tuple.laws"
  "test.tuple.laws.functor"
  "test.tuple.laws.searchable"
  "test.tuple.move_only"
  "test.tuple.pair_interop"
  "test.tuple.smart_ptr"
  "test.tuple.special.drop_front_exactly"
  "test.tuple.special.empty"
  "test.tuple.special.equal"
  "test.tuple.special.fill"
  "test.tuple.special.fold_left"
  "test.tuple.special.fold_right"
  "test.tuple.special.front"
  "test.tuple.special.is_empty"
  "test.tuple.special.prepend"
  "test.tuple.special.transform"
  "test.tuple.to"
  "test.tuple.unpack"
  "test.tuple.usability_of_types"
  "test.type.adl"
  "test.type.alignof"
  "test.type.decltype"
  "test.type.equal"
  "test.type.hash"
  "test.type.inherit_basic_type"
  "test.type.integral"
  "test.type.is_valid"
  "test.type.laws"
  "test.type.make"
  "test.type.metafunction"
  "test.type.metafunction_class"
  "test.type.nested_type"
  "test.type.sizeof"
  "test.type.template"
  "test.type.traits"
  "test.type.typeid"
  "test.type.unary_plus")
